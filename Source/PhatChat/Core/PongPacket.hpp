#pragma once

#include <SFML/Network.hpp>
#include <PhatChat/Core/Packet.hpp>

namespace PhatChat
{
	class PongPacket : public PhatChat::Packet
	{
		public :
			PongPacket ( ) = default ;
			PongPacket ( unsigned int value ) ;
			
			void setValue ( unsigned int value ) ;
			unsigned int getValue ( ) const ;
		
			sf::Packet encode ( bool operationCode = true ) ;
			static PhatChat::PongPacket decode ( sf::Packet packet , bool operationCode = false ) ;
			
		private :			
			unsigned int value = 0 ;
	} ;
}
