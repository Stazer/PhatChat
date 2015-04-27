#include <PhatChat/Client/Application.hpp>
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
	this->receiveThreadHandle.launch ( ) ;

	return 0 ;
	/*Fl_Window * window = new Fl_Window ( 340 , 180 ) ;

	Fl_Box * box = new Fl_Box ( 20 , 40 , 300 , 100 , "Hello World" ) ;

	window->end ( ) ;
	window->show ( ) ;

	return Fl::run ( ) ;*/
}

void PhatChat::Client::Application::receiveThreadFunction ( )
{
	while ( this->isRunning ( ) )
	{
		
	}
}
