#include <PhatChat/Core/RequestUsernamePacket.hpp>
#include <PhatChat/Core/OperationCode.hpp>

PhatChat::RequestUsernamePacket::RequestUsernamePacket ( const std::string & username ) :
	username ( username )
{
}
			
void PhatChat::RequestUsernamePacket::setUsername ( const std::string & username )
{
	this->username = username ;
}
const std::string & PhatChat::RequestUsernamePacket::getUsername ( ) const
{
	return this->username ;
}
		
sf::Packet PhatChat::RequestUsernamePacket::encode ( bool operationCode )
{
	sf::Packet packet ;

	if ( operationCode )
		packet << static_cast <unsigned char> ( PhatChat::OperationCode::REQUEST_USERNAME ) ;
		
	packet << this->username ;
	
	return packet ;
}
PhatChat::RequestUsernamePacket PhatChat::RequestUsernamePacket::decode ( sf::Packet packet , bool operationCode )
{
	RequestUsernamePacket requestUsernamePacket ;

	if ( operationCode )
	{
		unsigned char buffer = 0 ;
		packet >> buffer ;
	}
	
	packet >> requestUsernamePacket.username ;
	
	return requestUsernamePacket ;
}
