#pragma once

class HandshakePacket
{
	public :
		sf::Packet encode ( bool operationCode = true ) ;
		static HandshakePacket decode ( sf::Packet packet , bool operationCode = false ) ;

	private :
		std::string username ;

} ;
