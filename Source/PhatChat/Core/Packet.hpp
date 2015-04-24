#pragma once

#include <SFML/Network.hpp>

namespace PhatChat
{
    // abstract class for packets
	class Packet
	{
		public :
            // virtual destructor
			virtual ~Packet ( ) = default ;

            // pure virtual encode method; if operationCode is set the operation code is encoded
            virtual sf::Packet encode ( bool operationCode = true ) = 0 ;
	} ;
}
