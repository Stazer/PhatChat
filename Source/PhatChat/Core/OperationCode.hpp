#pragma once

namespace PhatChat
{
	namespace Server
	{
		enum class OperationCode
		{
		} ;
	}
	
	namespace Client
	{
		enum class OperationCode
		{
		} ;
	}
	
	enum class OperationCode
	{
		PING = 0x0 ,
		PONG = 0x1 ,
		
		HANDSHAKE_HELLO = 0x2 ,
		HANDSHAKE_BYE = 0x3 ,
		
		REQUEST_USERNAME = 0x4 ,
		RESPONSE_USERNAME = 0x5 ,
		
		MESSAGE = 0x6 ,
	} ;
}
