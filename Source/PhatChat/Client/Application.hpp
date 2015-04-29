#pragma once

#include <PhatChat/Core/Application.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

namespace PhatChat
{
	namespace Client
	{
		class Application : public PhatChat::Application
		{
			public :
				// default constructor
				Application ( ) ;
				
				// accessor for socket
				sf::TcpSocket & getSocket ( ) ;				
				// const accessor for socket
				const sf::TcpSocket & getSocket ( ) const ;
			
				// main function
				int main ( const std::vector <std::string> & arguments ) ;
				
				// handles packet
                // NOTE: keep the pass by value behaviour, since PhatChat::Server::Client::handlePacket WILL modify the passed object
				void handlePacket ( sf::Packet packet ) ;
				
			private :
				sf::TcpSocket socket ;
			
				sf::Thread receiveThreadHandle ;
				
				void receiveThreadFunction ( ) ;
				
				sf::Clock pingClock ;
		} ;
	}
}
