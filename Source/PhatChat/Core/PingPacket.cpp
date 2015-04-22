#include <PhatChat/Core/PingPacket.hpp>
#include <PhatChat/Core/OperationCode.hpp>

PhatChat::PingPacket::PingPacket ( unsigned int value ) :
	value ( value )
{
}
			
void PhatChat::PingPacket::setValue ( unsigned int value )
{
	this->value = value ;
}
unsigned int PhatChat::PingPacket::getValue ( ) const
{
	return this->value ;
}
		
sf::Packet PhatChat::PingPacket::encode ( bool operationCode )
{
	sf::Packet packet ;

	if ( operationCode )
		packet << static_cast <unsigned char> ( PhatChat::OperationCode::PING ) ;
		
	packet << this->value ;
}
PhatChat::PingPacket PhatChat::PingPacket::decode ( sf::Packet packet , bool operationCode )
{
	PingPacket pingPacket ;

	if ( operationCode )
	{
		unsigned char buffer = 0 ;
		packet >> buffer ;
	}
	
	packet >> pingPacket.value ;
	
	return pingPacket ;
}
