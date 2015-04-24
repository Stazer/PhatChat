#pragma once

#include <SFML/Network.hpp>
#include <PhatChat/Core/Packet.hpp>

namespace PhatChat
{
	// test response which sends a test integer value
	class PongPacket : public PhatChat::Packet
	{
		public :
			// constructor for setting the test integer value to value
			PongPacket ( unsigned int value = 0 ) ;

			// mutator for value
			void setValue ( unsigned int value ) ;

			// accessor for value
			unsigned int getValue ( ) const ;

			// encodes the data of PongPacket to sf::Packet
			// if operationCode is enabled the method will encode the operation code as well
			sf::Packet encode ( bool operationCode = true ) ;

			// decodes the data of sf::Packet to PongPacket
			// if operationCode is enabled the method will decode the operation code as well
			static PhatChat::PongPacket decode ( sf::Packet packet , bool operationCode = false ) ;

		private :
			unsigned int value = 0 ;
	} ;
}
