#pragma once

#include <SFML/Network.hpp>
#include <PhatChat/Core/Packet.hpp>

namespace PhatChat
{
	// test request which sends a test integer value
	class PingPacket : public PhatChat::Packet
	{
		public :
			// constructor for setting the test integer value to value
			PingPacket ( unsigned int value = 0 ) ;

			// mutator for value
			void setValue ( unsigned int value ) ;

			// accessor for value
			unsigned int getValue ( ) const ;

			// encodes the data of PingPacket to sf::Packet
			// if operationCode is enabled the method will encode the operation code as well
			sf::Packet encode ( bool operationCode = true ) ;

			// decodes the data of sf::Packet to PingPacket
			// if operationCode is enabled the method will decode the operation code as well
			static PhatChat::PingPacket decode ( sf::Packet packet , bool operationCode = false ) ;

		private :
			unsigned int value = 0 ;
	} ;
}
