#pragma once

#include <SFML/Network.hpp>
#include <PhatChat/Core/Packet.hpp>

namespace PhatChat
{
	// requests an username from server
	class RequestUsernamePacket : public PhatChat::Packet
	{
		public :
			// constructor for setting the username
			RequestUsernamePacket ( const std::string & value = 0 ) ;

			// mutator for username
			void setUsername ( const std::string & username ) ;

			// accessor for username
			const std::string & getUsername ( ) const ;

			// encodes the data of RequestUsernamePacket to sf::Packet
			// if operationCode is enabled the method will encode the operation code as well
			sf::Packet encode ( bool operationCode = true ) ;

			// decodes the data of sf::Packet to RequestUsernamePacket
			// if operationCode is enabled the method will decode the operation code as well
			static PhatChat::RequestUsernamePacket decode ( sf::Packet packet , bool operationCode = false ) ;

		private :
			std::string username ;
	} ;
}
