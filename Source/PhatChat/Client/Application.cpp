#include <PhatChat/Client/Application.hpp>
#include <SFML/Network.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int PhatChat::Client::Application::main ( const std::vector <std::string> & arguments )
{
	Fl_Window * window = new Fl_Window ( 340 , 180 ) ;
	
	Fl_Box * box = new Fl_Box ( 20 , 40 , 300 , 100 , "Hello World" ) ;
		
	window->end ( ) ;
	window->show ( ) ;

	return Fl::run ( ) ;
}
