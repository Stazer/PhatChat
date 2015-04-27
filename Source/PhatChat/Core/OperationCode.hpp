#pragma once

namespace PhatChat
{
	// operation codes of packets
	enum class OperationCode
	{
		UNKNOWN = 0x0 ,
		
		PING = 0x1
		PONG = 0x2 ,
		
		REQUEST_USERNAME = 0x3 ,
		RESPONSE_USERNAME = 0x4 ,
		
		MESSAGE = 0x5 ,
	} ;
}
