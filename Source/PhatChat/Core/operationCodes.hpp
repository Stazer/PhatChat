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
		PING = 0x00 ,
		PONG = 0x01 ,
		HANDSHAKE = 0x02 ,
	} ;
}
