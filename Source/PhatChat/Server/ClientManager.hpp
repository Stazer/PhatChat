#pragma once

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <PhatChat/Server/Client.hpp>
#include <vector>
#include <memory>

namespace PhatChat
{
    namespace Server
    {
        class Application ;

        // manages all connected clients
        class ClientManager
        {
            public :
                using iterator = std::vector <std::shared_ptr <PhatChat::Server::Client>>::iterator ;
                using const_iterator = std::vector <std::shared_ptr <PhatChat::Server::Client>>::const_iterator ;

                // constructor
                ClientManager ( PhatChat::Server::Application & server ) ;

                // prevent copying
                ClientManager ( const PhatChat::Server::ClientManager & right ) = delete ;
                PhatChat::Server::ClientManager & operator = ( const PhatChat::Server::ClientManager & right ) = delete ;

                // prevent moving
                ClientManager ( PhatChat::Server::ClientManager && right ) = delete ;
                PhatChat::Server::ClientManager & operator = ( PhatChat::Server::ClientManager && right ) = delete ;

                // iterator methodss
                iterator begin ( ) ;
                const_iterator begin ( ) const ;
                const_iterator cbegin ( ) const ;
                iterator end ( ) ;
                const_iterator end ( ) const ;
                const_iterator cend  ( ) const ;


                // accessor for server
                PhatChat::Server::Application & getServer ( ) ;
                // const accessor for server
                const PhatChat::Server::Application & getServer ( ) const ;

                // accesor for selector
                sf::SocketSelector & getSelector ( ) ;
                // const accesor for selector
                const sf::SocketSelector & getSelector ( ) const ;

                // disconnect a client
                void disconnect ( std::vector <std::shared_ptr <PhatChat::Server::Client>>::iterator client ) ;
                void disconnect ( PhatChat::Server::Client & client ) ;

                // update the client manager
                void update ( ) ;

            private :
                PhatChat::Server::Application & server ;

                bool added = false ;

                sf::SocketSelector selector ;

				sf::Clock pingClock ;

                std::vector <std::shared_ptr <PhatChat::Server::Client>> clients ;
        } ;
    }
}
