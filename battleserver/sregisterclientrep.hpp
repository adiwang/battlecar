#ifndef _SREGISTERCLIENTREP_H
#define _SREGISTERCLIENTREP_H

#include <string>
#include "protocol.h"
#include "protocolid.h"
#include "net_base.h"
#include "packet_sync.h"
#include "pb/netmessage.pb.h"
#include "tcpserver.h"

class SRegisterClientRep : public Protocol
{
	#include "protocol/sregisterclientrep"

	virtual void Process(const char* buf, int length, void* userdata)
	{
		UnMarshal(buf, length);
		if(_result != 0)
		{
			// TODO: error handling
		}
	}
};

#endif // end _SREGISTERCLIENTREP_H
