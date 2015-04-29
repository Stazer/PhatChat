#include <PhatChat/Client/ConnectionWindow.hpp>

PhatChat::Client::ConnectionWindow::ConnectionWindow ( const std::string & username , const std::string & hostAddress , unsigned short port ) :
	window ( 400 , 170 ) ,
	username ( 10 , 10 , 380 , 30 ) ,
	socketAddress ( 10 , 50 , 380 , 30 ) ,
	connect ( 10 , 130 , 380 , 30 , "Connect" )
{
	this->window.label ( "PhatChat" ) ;

	this->username.value ( username.c_str ( ) ) ;
	this->socketAddress.value ( ( hostAddress + ":" + std::to_string ( port ) ).c_str ( ) ) ;

	this->connect.callback ( PhatChat::Client::ConnectionWindow::onConnectPushed , this ) ;

	this->window.end ( ) ;
	this->window.show ( ) ;
}

bool PhatChat::Client::ConnectionWindow::isConnectPushed ( ) const
{
    return this->connectPushed ;
}

std::string PhatChat::Client::ConnectionWindow::getUsername ( ) const
{
	return this->username.value ( ) ;
}
std::string PhatChat::Client::ConnectionWindow::getHostAddress ( ) const
{
	std::string content = this->socketAddress.value ( ) ;
	return content.substr ( 0 , content.find ( ':' ) ) ;
}
unsigned short PhatChat::Client::ConnectionWindow::getPort ( ) const
{
	std::string content = this->socketAddress.value ( ) ;
	return std::atoi ( content.substr ( content.find ( ':' ) + 1 ).c_str ( ) ) ;
}

void PhatChat::Client::ConnectionWindow::onConnectPushed ( Fl_Widget * widget , void * data )
{
    static_cast <PhatChat::Client::ConnectionWindow *> ( data )->connectPushed = true ;
}