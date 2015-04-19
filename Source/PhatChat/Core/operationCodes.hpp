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

void onreceive ( )
{
char buffer [ 1024 ]  ;
socket.receive ( buffer ) ;

if ( buffer [ 0 ] == MESSAGE )
{
	MessagePacket packet = MessagePacket::encode ( textBox->getValue ( ) ) ;
	
	socket->send ( packet ) ;
	
	textBox->addLine ( packet.getMessage ( ) ) ;
}
}
