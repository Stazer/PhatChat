#include <PhatChat/Server/Client.hpp>

PhatChat::Server::Client::Client ( PhatChat::Server::ClientManager & clientManager ) :
    clientManager ( clientManager )
{
}

PhatChat::Server::ClientManager & PhatChat::Server::Client::getClientManager ( )
{
    return this->clientManager ;
}
const PhatChat::Server::ClientManager & PhatChat::Server::Client::getClientManager ( ) const
{
    return this->clientManager ;
}

sf::TcpSocket & PhatChat::Server::Client::getSocket ( )
{
    return this->socket ;
}
const sf::TcpSocket & PhatChat::Server::Client::getSocket ( ) const
{
    return this->socket ;
}

bool PhatChat::Server::Client::send ( sf::Packet packet )
{
    return this->socket.send ( packet ) == sf::Socket::Done ;
}
bool PhatChat::Server::Client::receive ( sf::Packet & packet )
{
    this->socket.receive ( packet ) == sf::Socket::Done ;
}

void PhatChat::Server::Client::handlePacket ( sf::Packet packet )
{
	unsigned char operationCode = 0 ;
}
