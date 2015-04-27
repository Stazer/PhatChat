#pragma once

namespace PhatChat
{
	// operation codes of packets
	enum class OperationCode : unsigned char
	{
		PING = 0x0 ,
		PONG = 0x1 ,
		
		REQUEST_USERNAME = 0x2 ,
		RESPONSE_USERNAME = 0x3 ,
		
		MESSAGE = 0x4 ,
		
		UNKNOWN ,
	} ;
}
