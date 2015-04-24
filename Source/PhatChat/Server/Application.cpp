#include <PhatChat/Server/Application.hpp>
#include <PhatChat/Core/DefaultPort.hpp>
#include <SFML/Network.hpp>
#include <iostream>

PhatChat::Server::Application::Application ( ) :
    clientManager ( * this )
{
}

sf::TcpListener & PhatChat::Server::Application::getSocket ( )
{
    return this->socket ;
}
const sf::TcpListener & PhatChat::Server::Application::getSocket ( ) const
{
    return this->socket ;
}

PhatChat::Server::ClientManager & PhatChat::Server::Application::getClientManager ( )
{
    return this->clientManager ;
}
const PhatChat::Server::ClientManager & PhatChat::Server::Application::getClientManager ( ) const
{
    return this->clientManager ;
}

void PhatChat::Server::Application::setRunning ( bool running )
{
    this->running = running ;
}
bool PhatChat::Server::Application::isRunning ( ) const
{
    return this->running ;
}

int PhatChat::Server::Application::main ( const std::vector <std::string> & arguments )
{
    // fetch port from command line parameters, use 20900 as default and start listening for
    // data on the socket
    const unsigned short port = arguments.size ( ) > 1 ? std::atoi ( arguments [ 1 ].c_str ( ) ) : PhatChat::defaultPort ;
    if ( this->socket.listen ( port ) != sf::Socket::Done )
    {
        std::cout << port << " is already in use!\n" ;
        return -1 ;
    }
    std::cout << "listening on port " << port << "\n" ;

    while ( this->isRunning ( ) )
    {
        this->clientManager.update ( ) ;
    }

	return 0 ;
}

void PhatChat::Server::Application::stop ( )
{
    this->setRunning ( false ) ;
}