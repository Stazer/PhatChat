#include <PhatChat/Server/Client.hpp>
#include <PhatChat/Server/ClientManager.hpp>
#include <PhatChat/Core/OperationCode.hpp>
#include <PhatChat/Core/PingPacket.hpp>
#include <PhatChat/Core/PongPacket.hpp>
#include <PhatChat/Core/MessagePacket.hpp>
#include <PhatChat/Core/RequestUsernamePacket.hpp>
#include <PhatChat/Core/ResponseUsernamePacket.hpp>
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

void PhatChat::Server::Client::setUsername ( const std::string & username )
{
    this->username = username ;
}
const std::string & PhatChat::Server::Client::getUsername ( ) const
{
    return this->username ;
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
	{
		PhatChat::PingPacket pingPacket ( PhatChat::PingPacket::decode ( packet ) ) ;
		std::cout << "Received ping packet with value " << pingPacket.getValue ( ) << "!" << std::endl ;

		sf::Packet newPacket ( PhatChat::PongPacket ( pingPacket.getValue ( ) ).encode ( ) ) ;

        this->socket.send ( newPacket ) ;
	}
	else if ( operationCode == PhatChat::OperationCode::PONG )
	{
		PhatChat::PongPacket pongPacket = PhatChat::PongPacket::decode ( packet ) ;
		std::cout << "Received pong packet with value " << pongPacket.getValue ( ) << "!" << std::endl ;
	}
	else if ( operationCode == PhatChat::OperationCode::REQUEST_USERNAME )
	{
        PhatChat::RequestUsernamePacket requestUsernamePacket = PhatChat::RequestUsernamePacket::decode ( packet ) ;
        this->setUsername ( requestUsernamePacket.getUsername ( ) ) ;
	}
	else if ( operationCode == PhatChat::OperationCode::MESSAGE )
	{
        PhatChat::MessagePacket messagePacket = PhatChat::MessagePacket::decode ( packet ) ;
        std::string username = this->username.empty ( ) ? messagePacket.getUsername ( ) : this->username ;
        std::cout << "Received message from " << username << " saying \"" << messagePacket.getMessage ( ) << "\"!" << std::endl ;

        messagePacket.setUsername ( username ) ;

        for ( auto client : this->clientManager )
        {
            packet = messagePacket.encode ( ) ;
            client->getSocket ( ).send ( packet ) ;
        }
	}
	else
		std::cout << "Operation code is unknown! Skip " << packet.getDataSize ( ) << " bytes." << std::endl ;
}