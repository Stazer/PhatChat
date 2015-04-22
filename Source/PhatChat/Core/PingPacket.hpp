#pragma once

#include <SFML/Network.hpp>

namespace PhatChat
{
	class PingPacket : public PhatChat::Packet
	{
		public :
			PingPacket ( ) = default ;
			PingPacket ( unsigned int value ) ;
			
			void setValue ( unsigned int value ) ;
			unsigned int getValue ( ) const ;
		
			sf::Packet encode ( bool operationCode = true ) ;
			static PingPacket decode ( sf::Packet packet , bool operationCode = false ) ;
			
		private :			
			unsigned int value = 0 ;
	} ;
}
