#include <PhatChat/Client/ConnectionWindow.hpp>

PhatChat::Client::ConnectionWindow::ConnectionWindow ( ) :
	window ( 400 , 170 ) ,
	username ( 10 , 10 , 380 , 30 ) ,
	socketAddress ( 10 , 50 , 380 , 30 ) ,
	connect ( 10 , 130 , 380 , 30 , "Connect" )
{
	this->window.label ( "PhatChat" ) ;

	this->connect.callback ( PhatChat::Client::ConnectionWindow::onConnectPushed , this ) ;

	this->window.end ( ) ;

	this->window.hide ( ) ;
}

bool PhatChat::Client::ConnectionWindow::isOpen ( ) const
{
    return this->window.visible ( ) ;
}

void PhatChat::Client::ConnectionWindow::hide ( )
{
    this->window.hide ( ) ;
}
void PhatChat::Client::ConnectionWindow::show ( )
{
	this->window.show ( ) ;
}

void PhatChat::Client::ConnectionWindow::reset ( )
{
    this->setSocketAddress ( "" ) ;
    this->setUsername ( "" ) ;

    this->connectPushed = false ;
}

bool PhatChat::Client::ConnectionWindow::isConnectPushed ( ) const
{
    return this->connectPushed ;
}

void PhatChat::Client::ConnectionWindow::setUsername ( const std::string & username )
{
    this->username.value ( username.c_str ( ) ) ;
}
std::string PhatChat::Client::ConnectionWindow::getUsername ( ) const
{
	return this->username.value ( ) ;
}

void PhatChat::Client::ConnectionWindow::setHostAddress ( const std::string & hostAddress )
{
    this->setSocketAddress ( hostAddress + ":" + std::to_string ( this->getPort ( ) ) ) ;
}
std::string PhatChat::Client::ConnectionWindow::getHostAddress ( ) const
{
	std::string content = this->socketAddress.value ( ) ;
	return content.substr ( 0 , content.find ( ':' ) ) ;
}

void PhatChat::Client::ConnectionWindow::setPort ( unsigned short port )
{
    this->setSocketAddress ( this->getHostAddress ( ) + ":" + std::to_string ( port ) ) ;
}
unsigned short PhatChat::Client::ConnectionWindow::getPort ( ) const
{
	std::string content = this->socketAddress.value ( ) ;
	return atoi ( content.substr ( content.find ( ':' ) + 1 ).c_str ( ) ) ;
}

void PhatChat::Client::ConnectionWindow::setSocketAddress ( const std::string & socketAddress )
{
    this->socketAddress.value ( socketAddress.c_str ( ) ) ;
}
std::string PhatChat::Client::ConnectionWindow::getSocketAddress ( ) const
{
    return this->socketAddress.value ( ) ;
}

void PhatChat::Client::ConnectionWindow::onConnectPushed ( Fl_Widget * widget , void * data )
{
    static_cast <PhatChat::Client::ConnectionWindow *> ( data )->connectPushed = true ;
}
