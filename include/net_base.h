﻿#ifndef _NET_BASE_H
#define _NET_BASE_H
#include <stdint.h>
#include <string.h>
#if defined (WIN32) || defined (_WIN32)
#include <WinSock2.h>
#include <stdlib.h>
#ifdef _MSC_VER
#pragma comment(lib,"Ws2_32.lib")
#endif //_MSC_VER
#else
#include <sys/types.h>
#include <netinet/in.h>
#endif

//判断是否小端字节序，是返回true
inline bool  IsLittleendian()
{
    int i = 0x1;
    return *(char *)&i == 0x1;
}

//判断是否32位系统，是返回true
inline bool IsSystem32()
{
    unsigned short x64 = 0;
#if defined(_MSC_VER)
    __asm mov x64,gs  // vs
#else
    asm("mov %%gs, %0" : "=r"(x64)); // gcc
#endif
    return x64 == 0;
}

namespace UVNET 
{
//htonll与ntohll win8才支持，linux支持也不全，所以自己实现
inline uint64_t htonll(uint64_t num)
{
    int i = 0x1;
    uint64_t retval;
    if(*(char *)&i == 0x1) {
#if defined (WIN32) || defined (_WIN32)
        retval = _byteswap_uint64(num);//比htonl快
#elif defined(__linux__ )
        retval = __builtin_bswap64(num);
#else
        retval = ((uint64_t)htonl(num & 0x00000000ffffffffULL)) << 32;
        retval |= htonl((num & 0xffffffff00000000ULL) >> 32);
#endif
    } else {
        return num;
    }
    return retval;
}

inline uint64_t ntohll(uint64_t num)
{
    int i = 0x1;
    uint64_t retval;
    if(*(char *)&i == 0x1) {
#if defined (WIN32) || defined (_WIN32)
        retval = _byteswap_uint64(num);
#elif defined(__linux__ )
        retval = __builtin_bswap64(num);
#else
        retval = ((uint64_t)ntohl(num & 0x00000000ffffffffULL)) << 32;
        retval |= ntohl((num & 0xffffffff00000000ULL) >> 32);
#endif
    } else {
        return num;
    }
    return retval;
}
}
//把32位的int保存在char[4]中.先转为网络字节序，然后int的最高位保存为char[0],最低位保存于char[3]
inline bool Int32ToChar(const uint32_t intnum,char* charnum)
{
    unsigned long network_byteorder=htonl(intnum);//转换为网络字节序
    charnum[0]=(unsigned char)((network_byteorder & 0xff000000)>>24);//int的最高位
    charnum[1]=(unsigned char)((network_byteorder & 0x00ff0000)>>16);//int的次高位
    charnum[2]=(unsigned char)((network_byteorder & 0x0000ff00)>>8); //int的次低位;
    charnum[3]=(unsigned char)((network_byteorder & 0x000000ff));    //int的最低位;
    return true;
}

//把char[4]转换为32位的int。int的最高位保存为char[0],最低位保存于char[3]，然后转为主机字节序
inline bool CharToInt32(const char* charnum, uint32_t& intnum)
{
    intnum =  (charnum[0] << 24) + (charnum[1] << 16) + (charnum[2] << 8) + charnum[3];
    intnum = ntohl(intnum);//转换为网络字节序
    return true;
}

//把64位的int保存在char[8]中.先转为网络字节序，然后int的最高位保存为char[0],最低位保存于char[7]
inline bool Int64ToChar(const uint64_t intnum,char* charnum)
{
    uint64_t network_byteorder=UVNET::htonll(intnum);//转换为网络字节序
    charnum[0]=(unsigned char)((network_byteorder & 0xff00000000000000ULL)>>56);//int的最高位
    charnum[1]=(unsigned char)((network_byteorder & 0x00ff000000000000ULL)>>48);//int的次高位
    charnum[2]=(unsigned char)((network_byteorder & 0x0000ff0000000000ULL)>>40);
    charnum[3]=(unsigned char)((network_byteorder & 0x000000ff00000000ULL)>>32);
    charnum[4]=(unsigned char)((network_byteorder & 0x00000000ff000000ULL)>>24);
    charnum[5]=(unsigned char)((network_byteorder & 0x0000000000ff0000ULL)>>16);
    charnum[6]=(unsigned char)((network_byteorder & 0x000000000000ff00ULL)>>8); //int的次低位;
    charnum[7]=(unsigned char)((network_byteorder & 0x00000000000000ffULL));    //int的最低位;
    return true;
}

//把char[8]转换为64位的int。int的最高位保存为char[0],最低位保存于char[7]，然后转为主机字节序
inline bool CharToInt64(const char* charnum, uint64_t& intnum)
{
    intnum =  ((uint64_t)charnum[0] << 56) + ((uint64_t)charnum[1] << 48) + ((uint64_t)charnum[2] << 40) + ((uint64_t)charnum[3] << 32) +
              (charnum[4] << 24) + (charnum[5] << 16) + (charnum[6] << 8) + charnum[7];
    intnum=UVNET::ntohll(intnum);//转换为网络字节序
    return true;
}

// 一个数据包的内存结构
//增加包头与包尾数据，用于检测包的完整性。检验值用于检测包的完全性。
//|-----head----|--------------------------pack header-------------------|--------------------pack data------------|-----tail----|
//|--包头1字节--|--[version][head][tail][check][type][datalen][reserve]--|--datalen长度的内存数据(根据type去解析)--|--包尾1字节--|
#pragma pack(1)//将当前字节对齐值设为1

#define NET_PACKAGE_VERSION 0x01
typedef struct _NetPacket{//传输自定义数据包头结构
	int32_t version;        //封包的版本号，不同版本包的定义可能不同  :0-3
	unsigned char header;   //包头-可自定义，例如0x02                 :4
	unsigned char tail;     //包尾-可自定义，例如0x03                 :5
	unsigned char check[16];//pack data校验值-16字节的md5二进制数据   :6-21
	int32_t type;           //包数据的类型                            :22-25
	int32_t datalen;        //包数据的内容长度-不包括此包结构和包头尾 :26-29
	int32_t reserve;        //包数据保留字段-暂时不使用               :30-33
}NetPacket;
#define NET_PACKAGE_HEADLEN sizeof(NetPacket)//包头长度，为固定大小34字节

#pragma pack()//将当前字节对齐值设为默认值(通常是4)

//NetPackage转为char*数据，chardata必须有38字节的空间
inline bool NetPacketToChar(const NetPacket& package, char* chardata){
	if(!Int32ToChar((uint32_t)package.version,chardata)){
		return false;
	}
	chardata[4]=package.header;
	chardata[5]=package.tail;
	memcpy(chardata+6,package.check,sizeof(package.check));

	if(!Int32ToChar((uint32_t)package.type,chardata+22)){
		return false;
	}
	if(!Int32ToChar((uint32_t)package.datalen,chardata+26)){
		return false;
	}
	if(!Int32ToChar((uint32_t)package.reserve,chardata+30)){
		return false;
	}
	return true;
}

//char*转为NetPackage数据，chardata必须有38字节的空间
inline bool CharToNetPacket(const char* chardata, NetPacket& package){
	uint32_t tmp32;
	if(!CharToInt32(chardata,tmp32)){
		return false;
	}
	package.version = tmp32;
	package.header = chardata[4];
	package.tail = chardata[5];
	memcpy(package.check,chardata+6,sizeof(package.check));
	if(!CharToInt32(chardata+22,tmp32)){
		return false;
	}
	package.type = tmp32;
	if(!CharToInt32(chardata+26,tmp32)){
		return false;
	}
	package.datalen = tmp32;
	if(!CharToInt32(chardata+30,tmp32)){
		return false;
	}
	package.reserve = tmp32;
	return true;
}
#endif // _NET_BASE_H
