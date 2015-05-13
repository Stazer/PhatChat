#include <PhatChat/Client/Application.hpp>
#include <PhatChat/Client/Message.hpp>
#include <PhatChat/Core/OperationCode.hpp>
#include <PhatChat/Core/DefaultPort.hpp>
#include <PhatChat/Core/PongPacket.hpp>
#include <PhatChat/Core/PingPacket.hpp>
#include <PhatChat/Core/MessagePacket.hpp>
#include <PhatChat/Core/RequestUsernamePacket.hpp>
#include <PhatChat/Core/ResponseUsernamePacket.hpp>
#include <iostream>

PhatChat::Client::Application::Application ( ) :
	receiveThreadHandle ( & PhatChat::Client::Application::receiveThreadFunction , this )
{
}

int PhatChat::Client::Application::main ( const std::vector <std::string> & arguments )
{
	// change FLTK design
	Fl::scheme ( "gtk+" ) ;

	// enable multihreading support
	Fl::lock ( ) ;

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

            while ( this->connectionWindow.isOpen ( ) && ! this->connectionWindow.isConnectPushed ( ) )
            {
                Fl::wait ( ) ;
            }

            this->connectionWindow.hide ( ) ;

            if ( ! this->connectionWindow.isConnectPushed ( ) )
                break ;

            username = connectionWindow.getUsername ( ) ;
            hostAddress = connectionWindow.getHostAddress ( ) ;
            port = connectionWindow.getPort ( ) ;
        }

        // connect to server
        if ( this->socket.connect ( hostAddress , port ) != sf::Socket::Done )
        {
            std::cout << "Cannot connect to " << hostAddress << ":" << port << "!\n" ;
            PhatChat::Client::message ( "Error" , ( "Cannot connect to " + hostAddress + ":" + std::to_string ( port ) + "!" ).c_str ( ) ) ;
        }
        else
        {
            std::cout << "Connection to " << this->socket.getRemoteAddress ( ) << ":" << this->socket.getRemotePort ( ) << " opened!\n" ;
            
            this->chatWindow.addMessage ( "Connection to " + this->socket.getRemoteAddress ( ).toString ( ) + ":" + std::to_string ( this->socket.getRemotePort ( ) ) + " opened!" ) ;

            // send username request
            this->username = this->connectionWindow.getUsername ( ) ;
            sf::Packet packet = PhatChat::RequestUsernamePacket ( this->username ).encode ( ) ;
            this->socket.send ( packet ) ;

            // launch receive thread
            this->chatWindow.reset ( ) ;
            this->receiveThreadHandle.launch ( ) ;
            this->chatWindow.show ( ) ;

            while ( this->chatWindow.isOpen ( ) )
            {
                Fl::wait ( ) ;

            	if ( this->chatWindow.isSendPushed ( ) )
            	{
            		std::string message = this->chatWindow.getMessage ( ) ;

            		if ( message.empty ( ) )
                        continue ;

            		sf::Packet packet = PhatChat::MessagePacket ( "" , message ).encode ( ) ;
            		this->socket.send ( packet ) ;
            	}
            }

            this->socket.disconnect ( ) ;
            this->chatWindow.hide ( ) ;
            this->receiveThreadHandle.terminate ( ) ;

            std::cout << "Connection to " << this->socket.getRemoteAddress ( ) << ":" << this->socket.getRemotePort ( ) << " closed!\n" ;
        }
    }

	return 0 ;
}

void PhatChat::Client::Application::receiveThreadFunction ( )
{
	while ( true )
	{
		// fetch packet
		sf::Packet packet ;
		if ( this->socket.receive ( packet ) == sf::Socket::Done )
        	this->handlePacket ( packet ) ;
		else
        {
            this->chatWindow.addMessage ( "Connection to " + this->socket.getRemoteAddress ( ).toString ( ) + ":" + std::to_string ( this->socket.getRemotePort ( ) ) + " closed!" ) ;
            break ;
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

		this->socket.send ( newPacket ) ;
	}
	else if ( operationCode == PhatChat::OperationCode::PONG )
	{
		PhatChat::PongPacket pongPacket = PhatChat::PongPacket::decode ( packet ) ;
		std::cout << "Received pong packet with value " << pongPacket.getValue ( ) << "!" << std::endl ;
	}
	else if ( operationCode == PhatChat::OperationCode::RESPONSE_USERNAME )
	{
		PhatChat::ResponseUsernamePacket responseUsenamePacket = PhatChat::ResponseUsernamePacket::decode ( packet ) ;
		this->username = responseUsenamePacket.getUsername ( ) ;
		std::cout << "Your username was set to " << this->username << "!\n" ;
		this->chatWindow.addMessage ( "Your username was set to " + this->username + "!" ) ;
    }
	else if ( operationCode == PhatChat::OperationCode::MESSAGE )
	{
		PhatChat::MessagePacket messagePacket ( PhatChat::MessagePacket::decode ( packet ) ) ;
        std::cout << "Received message from " << username << " saying \"" << messagePacket.getMessage ( ) << "\"!" << std::endl ;

		std::string header = ! messagePacket.getUsername ( ).empty ( ) ? messagePacket.getUsername ( ) + "> " : "" ;
		this->chatWindow.addMessage ( header + messagePacket.getMessage ( ) ) ;
	}
	else
		std::cout << "Operation code is unknown! Skip " << packet.getDataSize ( ) << " bytes." << std::endl ;
}
