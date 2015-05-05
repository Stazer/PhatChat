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

                // mutator for running
                void setRunning ( bool running ) ;
                // accessor for running
                bool isRunning ( ) const ;

                // accessor for socket
                sf::TcpListener & getSocket ( ) ;
                // const accessor for socket
                const sf::TcpListener & getSocket ( ) const ;

                // accessor for clientManager
                PhatChat::Server::ClientManager & getClientManager ( ) ;
                // const accessor for clientManager
                const PhatChat::Server::ClientManager & getClientManager ( ) const ;

                // main function
				int main ( const std::vector <std::string> & arguments ) ;

            private :
                bool running = true ;

                sf::TcpListener socket ;

                PhatChat::Server::ClientManager clientManager ;
		} ;
	}
}
