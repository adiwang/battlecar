#ifndef _CREGISTERCLIENTREQ_H
#define _CREGISTERCLIENTREQ_H
#include <string>
#include "protocol.h"
#include "protocolid.h"
#include "net_base.h"
#include "packet_sync.h"
#include "pb/netmessage.pb.h"
#include "tcpserver.h"
#include "sregisterclientrep.hpp"
#include "log.h"


class CRegisterClientReq : public Protocol
{
	#include "protocol/cregisterclientreq"

	virtual void Process(const char* buf, int length, void* userdata)
	{
		UnMarshal(buf, length);
		UVNET::SessionCtx* ctx = (UVNET::SessionCtx *)userdata;
		UVNET::TCPServer* server = (UVNET::TCPServer*)ctx->parent_server;

        LOG_TRACE("CRegisterClientReq|sid=%d, seq=%d", ctx->sid, _seq);

		SRegisterClientRep rep;
		rep.Marshal();
		server->_send(rep._marshal_data, ctx);
	}
};

#endif	// end _CREGISTERCLIENTREQ_H
