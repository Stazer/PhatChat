#include <PhatChat/Core/PingPacket.hpp>
#include <PhatChat/Server/ClientManager.hpp>
#include <PhatChat/Server/Application.hpp>
#include <cstdlib>
#include <iostream>

PhatChat::Server::ClientManager::ClientManager ( PhatChat::Server::Application & server ) :
    server ( server )
{
}

PhatChat::Server::ClientManager::iterator PhatChat::Server::ClientManager::begin ( )
{
    return this->clients.begin ( ) ;
}
PhatChat::Server::ClientManager::const_iterator PhatChat::Server::ClientManager::begin ( ) const
{
    return this->clients.begin ( ) ;
}
PhatChat::Server::ClientManager::const_iterator PhatChat::Server::ClientManager::cbegin ( ) const
{
    return this->clients.cbegin ( ) ;
}
PhatChat::Server::ClientManager::iterator PhatChat::Server::ClientManager::end ( )
{
    return this->clients.end ( ) ;
}
PhatChat::Server::ClientManager::const_iterator PhatChat::Server::ClientManager::end ( ) const
{
    return this->clients.end ( ) ;
}
PhatChat::Server::ClientManager::const_iterator PhatChat::Server::ClientManager::cend  ( ) const
{
    return this->clients.cend ( ) ;
}

PhatChat::Server::Application & PhatChat::Server::ClientManager::getServer ( )
{
    return this->server ;
}
const PhatChat::Server::Application & PhatChat::Server::ClientManager::getServer ( ) const
{
    return this->server ;
}

sf::SocketSelector & PhatChat::Server::ClientManager::getSelector ( )
{
    return this->selector ;
}
const sf::SocketSelector & PhatChat::Server::ClientManager::getSelector ( ) const
{
    return this->selector ;
}

void PhatChat::Server::ClientManager::disconnect ( std::vector <std::shared_ptr <PhatChat::Server::Client>>::iterator client )
{
	this->disconnect ( ** client ) ;
	this->clients.erase ( client ) ;
}
void PhatChat::Server::ClientManager::disconnect ( PhatChat::Server::Client & client )
{
	this->selector.remove ( client.getSocket ( ) ) ;
	std::cout << "Connection from " << client.getSocket ( ).getRemoteAddress ( ) << ":" << client.getSocket ( ).getRemotePort ( ) << " closed!" << std::endl ;
}

// update the client manager
void PhatChat::Server::ClientManager::update ( )
{
    // check if the server socket is added to the socket selector
    // this is the case when the update method is called the first time
    // we cannot add the socket when the ClientManager gets created, since the socket
    // is not initialized at this time
    if ( ! this->added )
    {
        this->added = true ;
        this->selector.add ( this->server.getSocket ( ) ) ;

        return ;
    }

	// check if pings need to be sent
    if ( this->pingClock.getElapsedTime ( ).asSeconds ( ) >= 5.0f )
    {
    	// build ping packet
    	sf::Packet packet ( PhatChat::PingPacket ( time ( nullptr ) ).encode ( ) ) ;

    	// send packet to all clients
    	for ( auto client = this->clients.begin ( ) ; client != this->clients.end ( ) ; ++client )
    	{
    		if ( ( * client )->getSocket ( ).send ( packet ) != sf::Socket::Done )
    		{
    			this->disconnect ( client ) ;
    			break ;
    		}
    	}

    	this->pingClock.restart ( ) ;
    }

    // wait for data 10ms
  	if ( ! this->selector.wait ( ) )
  		return ;

	// check clients for any data and check for dead clients handle the packet if one was received
	for ( auto client = this->clients.begin ( ) ; client != this->clients.end ( ) ; ++client )
    {
    	if ( this->selector.isReady ( ( * client )->getSocket ( ) ) )
    	{
    		sf::Packet packet ;

    		if ( ( * client )->getSocket ( ).receive ( packet ) == sf::Socket::Done )
    			( * client )->handlePacket ( packet ) ;
    		else
    		{
                this->disconnect ( client ) ;
                break ;
            }
    	}
    }

    // check server socket for any data
    if ( this->selector.isReady ( this->getServer ( ).getSocket ( ) ) )
    {
        std::shared_ptr <PhatChat::Server::Client> client ( new PhatChat::Server::Client ( * this ) ) ;

        if ( this->getServer ( ).getSocket ( ).accept ( client->getSocket ( ) ) == sf::Socket::Done )
        {
            this->clients.push_back ( client ) ;
            this->selector.add ( client->getSocket ( ) ) ;

            std::cout << "Connection from " << client->getSocket ( ).getRemoteAddress ( ) << ":" << client->getSocket ( ).getRemotePort ( ) << " opened!" << std::endl ;
        }
    }
}
