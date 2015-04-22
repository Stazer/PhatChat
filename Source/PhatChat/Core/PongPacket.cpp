#include <PhatChat/Core/PongPacket.hpp>
#include <PhatChat/Core/OperationCode.hpp>

PhatChat::PongPacket::PongPacket ( unsigned int value ) :
	value ( value )
{
}
			
void PhatChat::PongPacket::setValue ( unsigned int value )
{
	this->value = value ;
}
unsigned int PhatChat::PongPacket::getValue ( ) const
{
	return this->value ;
}
		
sf::Packet PhatChat::PongPacket::encode ( bool operationCode )
{
	sf::Packet packet ;

	if ( operationCode )
		packet << static_cast <unsigned char> ( PhatChat::OperationCode::PONG ) ;
		
	packet << this->value ;
}
PhatChat::PongPacket PhatChat::PongPacket::decode ( sf::Packet packet , bool operationCode )
{
	PhatChat::PongPacket pongPacket ;

	if ( operationCode )
	{
		unsigned char buffer = 0 ;
		packet >> buffer ;
	}
	
	packet >> pongPacket.value ;
	
	return pongPacket ;
}
