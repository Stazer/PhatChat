#include <PhatChat/Core/ResponseUsernamePacket.hpp>
#include <PhatChat/Core/OperationCode.hpp>

PhatChat::ResponseUsernamePacket::ResponseUsernamePacket ( const std::string & username ) :
	username ( username )
{
}
			
void PhatChat::ResponseUsernamePacket::setUsername ( const std::string & username )
{
	this->username = username ;
}
const std::string & PhatChat::ResponseUsernamePacket::getUsername ( ) const
{
	return this->username ;
}
		
sf::Packet PhatChat::ResponseUsernamePacket::encode ( bool operationCode )
{
	sf::Packet packet ;

	if ( operationCode )
		packet << static_cast <unsigned char> ( PhatChat::OperationCode::RESPONSE_USERNAME ) ;
		
	packet << this->username ;
	
	return packet ;
}
PhatChat::ResponseUsernamePacket PhatChat::ResponseUsernamePacket::decode ( sf::Packet packet , bool operationCode )
{
	ResponseUsernamePacket requestUsernamePacket ;

	if ( operationCode )
	{
		unsigned char buffer = 0 ;
		packet >> buffer ;
	}
	
	packet >> requestUsernamePacket.username ;
	
	return requestUsernamePacket ;
}
