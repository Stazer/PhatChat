#include <PhatChat/Core/MessagePacket.hpp>
#include <PhatChat/Core/OperationCode.hpp>

PhatChat::MessagePacket::MessagePacket ( const std::string & message ) :
	message ( message )
{
}
			
void PhatChat::MessagePacket::setMessage ( const std::string & message )
{
	this->message = message ;
}
const std::string & PhatChat::MessagePacket::getMessage ( ) const
{
	return this->message ;
}
		
sf::Packet PhatChat::MessagePacket::encode ( bool operationCode )
{
	sf::Packet packet ;

	if ( operationCode )
		packet << static_cast <unsigned char> ( PhatChat::OperationCode::MESSAGE ) ;
		
	packet << this->message ;
	
	return packet ;
}
PhatChat::MessagePacket PhatChat::MessagePacket::decode ( sf::Packet packet , bool operationCode )
{
	MessagePacket requestMessagePacket ;

	if ( operationCode )
	{
		unsigned char buffer = 0 ;
		packet >> buffer ;
	}
	
	packet >> requestMessagePacket.message ;
	
	return requestMessagePacket ;
}
