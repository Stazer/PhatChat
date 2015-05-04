#pragma once

#include <SFML/Network.hpp>
#include <PhatChat/Core/Packet.hpp>

namespace PhatChat
{
	// sends a message to the server and receives a message from the server
	class MessagePacket : public PhatChat::Packet
	{
		public :
			// constructor for setting the message
			MessagePacket ( const std::string & message = "" ) ;

			// mutator for message
			void setMessage ( const std::string & message ) ;

			// accessor for message
			const std::string & getMessage ( ) const ;

			// encodes the data of MessagePacket to sf::Packet
			// if operationCode is enabled the method will encode the operation code as well
			sf::Packet encode ( bool operationCode = true ) ;

			// decodes the data of sf::Packet to MessagePacket
			// if operationCode is enabled the method will decode the operation code as well
			static PhatChat::MessagePacket decode ( sf::Packet packet , bool operationCode = false ) ;

		private :
			std::string message ;
	} ;
}
