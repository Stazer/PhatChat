#include <PhatChat/Client/Application.hpp>
#include <PhatChat/Client/Message.hpp>
#include <PhatChat/Core/OperationCode.hpp>
#include <PhatChat/Core/DefaultPort.hpp>
#include <PhatChat/Core/PongPacket.hpp>
#include <PhatChat/Core/PingPacket.hpp>
#include <PhatChat/Client/ChatWindow.hpp>
#include <iostream>

PhatChat::Client::Application::Application ( ) :
	receiveThreadHandle ( & PhatChat::Client::Application::receiveThreadFunction , this )
{
}

int PhatChat::Client::Application::main ( const std::vector <std::string> & arguments )
{
	// change FLTK design
	//Fl::scheme ( "gtk+" ) ;
	ChatWindow::ChatWindow FirstAttempt; 
	return 0; 


	// fetch hostname and port from command line arguments only if all command line arguments were given, use 20900 as default port and
	// 127.0.0.1 as default hostname and connect to the server
	unsigned short port = arguments.size ( ) > 3 ? std::atoi ( arguments [ 3 ].c_str ( ) ) : PhatChat::defaultPort ;
    std::string hostAddress = arguments.size ( ) > 3 ? arguments [ 2 ] : "127.0.0.1" ;
    std::string username = arguments.size ( ) > 3 ? arguments [ 1 ] : "username" ;

    while ( true )
    {
        if ( arguments.size ( ) < 4 )
        {
            this->connectionWindow.reset ( ) ;

            this->connectionWindow.setUsername ( username ) ;
            this->connectionWindow.setHostAddress ( hostAddress ) ;
            this->connectionWindow.setPort ( port ) ;

            this->connectionWindow.show ( ) ;

            while ( Fl::wait ( ) && ! this->connectionWindow.isConnectPushed ( ) ) ;

            this->connectionWindow.hide ( ) ;

            if ( ! this->connectionWindow.isConnectPushed ( ) )
                break ;

            username = connectionWindow.getUsername ( ) ;
            hostAddress = connectionWindow.getHostAddress ( ) ;
            port = connectionWindow.getPort ( ) ;
        }

        if ( this->socket.connect ( hostAddress , port ) != sf::Socket::Done )
        {
            std::cout << "Cannot connect to " << hostAddress << ":" << port << "!\n" ;
            PhatChat::Client::message ( "Error" , ( "Cannot connect to " + hostAddress + ":" + std::to_string ( port ) + "!" ).c_str ( ) ) ;
        }
        else
        {
            std::cout << "Connection to " << this->socket.getRemoteAddress ( ) << ":" << this->socket.getRemotePort ( ) << " opened!\n" ;

            // launch receive thread
            this->receiveThreadHandle.launch ( ) ;

            while ( Fl::wait ( ) ) ;

            std::cout << "Connection to " << this->socket.getRemoteAddress ( ) << ":" << this->socket.getRemotePort ( ) << " closed!\n" ;
        }
    }

    this->setRunning ( false ) ;

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
