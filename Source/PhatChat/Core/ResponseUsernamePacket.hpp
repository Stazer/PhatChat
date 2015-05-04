#pragma once

#include <SFML/Network.hpp>
#include <PhatChat/Core/Packet.hpp>

namespace PhatChat
{
	// responses an username to client
	class ResponseUsernamePacket : public PhatChat::Packet
	{
		public :
			// constructor for setting the username
			ResponseUsernamePacket ( const std::string & value = "" ) ;

			// mutator for username
			void setUsername ( const std::string & username ) ;

			// accessor for username
			const std::string & getUsername ( ) const ;

			// encodes the data of ResponseUsernamePacket to sf::Packet
			// if operationCode is enabled the method will encode the operation code as well
			sf::Packet encode ( bool operationCode = true ) ;

			// decodes the data of sf::Packet to ResponseUsernamePacket
			// if operationCode is enabled the method will decode the operation code as well
			static PhatChat::ResponseUsernamePacket decode ( sf::Packet packet , bool operationCode = false ) ;

		private :
			std::string username ;
	} ;
}
