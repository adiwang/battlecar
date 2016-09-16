/***************************************
* @file     protocol.h
* @brief    protocol pure base class,need to subclass.
* @details  
* @author   adiwang, adiwang@outlook.com
****************************************/
#ifndef _PROTOCOL_H
#define _PROTOCOL_H

class Protocol
{
public:
    Protocol(){}
    virtual ~Protocol(){}
    virtual void Process(const char* buf, int length, void* userdata) = 0;
    virtual Protocol* Clone() = 0;
};

#endif//_PROTOCOL_H
