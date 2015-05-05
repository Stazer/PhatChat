#include <PhatChat/Client/ChatWindow.hpp>

PhatChat::Client::ChatWindow::ChatWindow ( ) :
	window ( 800 , 600 ) ,
	log ( 10 , 10 , 780 , 540 ) ,
	message ( 10 , 560 , 670 , 30 ) ,
	send ( 690 , 560 , 100 , 30 , "Send" )
{
	this->window.label ( "PhatChat" ) ;

	this->send.callback ( PhatChat::Client::ChatWindow::onSendPushed , this ) ;

	this->window.end ( ) ;
}

void PhatChat::Client::ChatWindow::hide ( )
{
	this->window.hide ( ) ;
}
void PhatChat::Client::ChatWindow::show ( )
{
	this->window.show ( ) ;
}

void PhatChat::Client::ChatWindow::reset ( )
{
    this->message.value ( "" ) ;
	this->sendPushed = false ;
}

bool PhatChat::Client::ChatWindow::isSendPushed ( ) const
{
	bool pushed = sendPushed ;
	this->sendPushed = false ;

	return pushed ;
}

std::string PhatChat::Client::ChatWindow::getMessage ( ) const
{
	std::string message = this->message.value ( ) ;
	this->message.value ( "" ) ;

	return message ;
}

void PhatChat::Client::ChatWindow::addMessage(const std::string& message )
{
    this->log.insert ( message.c_str ( ) , this->log.size ( ) ) ;
}

void PhatChat::Client::ChatWindow::onSendPushed ( Fl_Widget * widget , void * data )
{
	reinterpret_cast <PhatChat::Client::ChatWindow *> ( data )->sendPushed = true ;
}
