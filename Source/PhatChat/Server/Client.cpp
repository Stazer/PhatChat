#include <PhatChat/Server/Client.hpp>
#include <PhatChat/Core/OperationCode.hpp>
#include <iostream>

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
	unsigned char operationCodeValue = 0 ;
	packet >> operationCodeValue ;
	PhatChat::OperationCode operationCode = static_cast <PhatChat::OperationCode> ( operationCodeValue ) ;
	
	if ( operationCode == PhatChat::OperationCode::PING )
		;
	else
		std::cout << "Operation code is unknown! Skip ." << packet.getDataSize ( ) << " bytes." << std::endl ;
}
