#pragma once

#include <string>

namespace PhatChat
{
	class PongPacket
	{
		public :
			sf::Packet encode ( bool operationCode = true ) ;
			static PingPacket decode ( sf::Packet packet , bool operationCode = false ) ;
			
		private :
			PongPacket ( ) = default ;
	} ;
}
