#pragma once

#include <SFML/Network.hpp>

namespace PhatChat
{
    namespace Server
    {
        class ClientManager ;

        // client representation at the server application
        class Client
        {
            public :
                // constructor for setting the socket
                Client ( PhatChat::Server::ClientManager & clientManager ) ;

                // prevent copying
                Client ( const PhatChat::Server::Client & right ) = delete ;
                PhatChat::Server::Client & operator = ( const PhatChat::Server::Client & right ) = delete ;

                // accessor for clientManager
                PhatChat::Server::ClientManager & getClientManager ( ) ;
                // const accessor for clientManager
                const PhatChat::Server::ClientManager & getClientManager ( ) const ;

                // mutator for username
                void setUsername ( const std::string & username ) ;
                // accessor for username
                const std::string & getUsername ( ) const ;

                // accessor for socket
                sf::TcpSocket & getSocket ( ) ;
                // const accessor for socket
                const sf::TcpSocket & getSocket ( ) const ;

                // sends packet to the client
                // on any error false is returned, which means that the client connection should be closed
                // NOTE: keep the pass by value behaviour, since sf::TcpSocket::send WILL modify the passed object
                bool send ( sf::Packet packet ) ;
                // receives packet from client
                // on any error false is returned, which means that the client connection should be closed
                bool receive ( sf::Packet & packet ) ;

                // handles packet
                // NOTE: keep the pass by value behaviour, since PhatChat::Server::Client::handlePacket WILL modify the passed object
                void handlePacket ( sf::Packet packet ) ;
                
                // handles command
                void handleCommand ( const std::string & message ) ;

            private :
                PhatChat::Server::ClientManager & clientManager ;

                std::string username ;

                sf::TcpSocket socket ;

                friend PhatChat::Server::ClientManager ;
        } ;
    }
}
