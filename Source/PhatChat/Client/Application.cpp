#include <PhatChat/Client/Application.hpp>
#include <PhatChat/Core/OperationCode.hpp>
#include <PhatChat/Core/DefaultPort.hpp>
#include <PhatChat/Core/PongPacket.hpp>
#include <PhatChat/Core/PingPacket.hpp>
#include <iostream>
#include <SFML/Network.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

PhatChat::Client::Application::Application ( ) :
	receiveThreadHandle ( & PhatChat::Client::Application::receiveThreadFunction , this )
{
}

sf::TcpSocket & PhatChat::Client::Application::getSocket ( )
{
	return this->socket ;
}	
const sf::TcpSocket & PhatChat::Client::Application::getSocket ( ) const
{
	return this->socket ;
}

int PhatChat::Client::Application::main ( const std::vector <std::string> & arguments )
{
	// fetch hostname and port from command line arguments, use 20900 as default port and 127.0.0.1 as default hostname and connect
	// to the server
    const unsigned short port = arguments.size ( ) > 2 ? std::atoi ( arguments [ 2 ].c_str ( ) ) : PhatChat::defaultPort ;
    const std::string hostname = arguments.size ( ) > 1 ? arguments [ 1 ] : "127.0.0.1" ;
    if ( this->socket.connect ( hostname , port ) != sf::Socket::Done )
    {
    	std::cout << "Cannot connect to " << hostname << ":" << port << "!\n" ;
		return -1 ;
    }
    std::cout << "Connected to " << this->socket.getRemoteAddress ( ) << ":" << this->socket.getRemotePort ( ) << " opened!\n" ;
        
	// launch receive thread
	this->receiveThreadHandle.launch ( ) ;
	
	while ( this->isRunning ( ) )
	{
		sf::sleep ( sf::seconds ( 0 )  ) ;
	}
	
    std::cout << "Connected to " << this->socket.getRemoteAddress ( ) << ":" << this->socket.getRemotePort ( ) << " closed!\n" ;

	return 0 ;
}

void PhatChat::Client::Application::receiveThreadFunction ( )
{
	while ( this->isRunning ( ) )
	{
		// fetch packet
		sf::Packet packet ;
		if ( this->socket.receive ( packet ) == sf::Socket::Done )
		{
        	this->handlePacket ( packet ) ;
		}
	}
}

void PhatChat::Client::Application::handlePacket ( sf::Packet packet )
{
	unsigned char operationCodeValue = 0 ;
	packet >> operationCodeValue ;
	PhatChat::OperationCode operationCode = static_cast <PhatChat::OperationCode> ( operationCodeValue ) ;
	
	// handle Ping
	if ( operationCode == PhatChat::OperationCode::PING )
	{
		PhatChat::PingPacket pingPacket ( PhatChat::PingPacket::decode ( packet ) ) ;
		std::cout << "Received ping packet with value " << pingPacket.getValue ( ) << "!\n" ;
		
		sf::Packet newPacket ( PhatChat::PongPacket ( pingPacket.getValue ( ) ).encode ( ) ) ;
		
		if ( this->socket.send ( newPacket ) != sf::Socket::Done )
			this->setRunning ( false ) ;
	}
	else
		std::cout << "Operation code is unknown! Skip " << packet.getDataSize ( ) << " bytes." << std::endl ;
}
