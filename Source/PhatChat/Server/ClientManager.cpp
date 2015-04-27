#include <PhatChat/Server/ClientManager.hpp>
#include <PhatChat/Server/Application.hpp>
#include <iostream>

PhatChat::Server::ClientManager::ClientManager ( PhatChat::Server::Application & server ) :
    server ( server )
{
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

    // wait for data
    if ( this->selector.wait ( ) != sf::Socket::Done )
        return ;

    // check clients for any data
    for ( auto client : this->clients )
    {
        if ( this->selector.isReady ( client->getSocket ( ) ) )
        {
        	sf::Packet packet ;

            client->getSocket ( ).receive ( packet ) ;
            
            std::cout << "Received packet from " << client->getSocket ( ).getRemoteAddress ( ) << ":" << client->getSocket ( ).getRemotePort ( ) << "." << std::endl ;
        
        	client->handlePacket ( packet ) ;
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

            std::cout << "Connection from " << client->getSocket ( ).getRemoteAddress ( ) << ":" << client->getSocket ( ).getRemotePort ( ) << "." << std::endl ;
        }
    }
}
