#pragma once

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <PhatChat/Core/Application.hpp>
#include <PhatChat/Client/ConnectionWindow.hpp>

namespace PhatChat
{
	namespace Client
	{
		class Application : public PhatChat::Application
		{
			public :
				// default constructor
				Application ( ) ;

				// main function
				int main ( const std::vector <std::string> & arguments ) ;

				// handles packet
                // NOTE: keep the pass by value behaviour, since PhatChat::Server::Client::handlePacket WILL modify the passed object
				void handlePacket ( sf::Packet packet ) ;

			private :
                PhatChat::Client::ConnectionWindow connectionWindow ;

				sf::TcpSocket socket ;

				sf::Thread receiveThreadHandle ;

				void receiveThreadFunction ( ) ;

				sf::Clock pingClock ;
		} ;
	}
}
