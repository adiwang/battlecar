#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <signal.h>

#include "tcpserver.h"
#include "cregisterclientreq.hpp"
#include "configfile.h"


void Initialize()
{
}

void RegisterProtocol(UVNET::TCPServer& server)
{
	server.AddProtocol(PROTOCOL_ID_CREGISTERCLIENTREQ, new CRegisterClientReq());
}

int main (int argc, char **argv) 
{
	if(argc < 2)
	{
	    fprintf(stdout,"Usage:\n\t%s <conf_file>", argv[0]);
	    return 1;
	}
	ConfigFile& cf = ConfigFile::GetInstance();
	if(!cf.LoadConf(argv[1]))
	{
		fprintf(stdout,"load conf file %s error", argv[1]);
		return 2;
	}
	// 加载配置
	std::string logfile = cf.Value("Global", "LogFile", "./log");
	std::string ip = cf.Value("Global", "Address", "127.0.0.1");
	std::string port = cf.Value("Global", "Port", "12345");

	UVNET::TCPServer server(0xF0,0x0F);
	UVNET::TCPServer::StartLog(LL_DEBUG, "casd", logfile.c_str());

	// 初始化
	Initialize();

	// 注册协议
	RegisterProtocol(server);

	if(!server.Start(ip.c_str(), atoi(port.c_str()))) 
	{
	    fprintf(stdout,"Start Server error:%s\n",server.GetLastErrMsg());
	}
	server.SetKeepAlive(1,60);//enable Keepalive, 60s
	
	signal(SIGPIPE, SIG_IGN);
	while(true) ThreadSleep(10);
	return 0;
}

