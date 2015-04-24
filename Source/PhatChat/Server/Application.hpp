#pragma once

#include <PhatChat/Core/Application.hpp>
#include <PhatChat/Server/ClientManager.hpp>
#include <SFML/Network.hpp>

namespace PhatChat
{
	namespace Server
	{
        // class for the server application
		class Application : public PhatChat::Application
		{
			public :
                // default constructor
                Application ( ) ;

                // accessor for socket
                sf::TcpListener & getSocket ( ) ;
                // const accessor for socket
                const sf::TcpListener & getSocket ( ) const ;

                // accessor for clientManager
                PhatChat::Server::ClientManager & getClientManager ( ) ;
                // const accessor for clientManager
                const PhatChat::Server::ClientManager & getClientManager ( ) const ;

                // mutator for running
                void setRunning ( bool running ) ;
                // accessor for running
                bool isRunning ( ) const ;

                // main function
				int main ( const std::vector <std::string> & arguments ) ;

                // stops the server, setting running to false
				void stop ( ) ;

            private :
                bool running = true ;

                sf::TcpListener socket ;

                PhatChat::Server::ClientManager clientManager ;
		} ;
	}
}
