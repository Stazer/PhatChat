#include <PhatChat/Client/Message.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Widget.H>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Box.H>

void PhatChat::Client::message ( const std::string & title , const std::string & message )
{
	Fl_Window window ( 400 , 100 );
	window.label ( title.c_str ( ) ) ;
	Fl_Box box ( 0 , 0 , 400 , 100 , message.c_str ( ) ) ;

	window.end ( ) ;
	window.show ( ) ;

	while ( Fl::wait ( ) ) ;
}
