#include <PhatChat/Client/Message.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Output.H>
#include <Fl/Fl_Widget.H>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Box.H>

#include <iostream>
class Fl_Text : Fl_Widget
{
    public :
        Fl_Text ( int x , int y , int w , int h , const char * label ) :
            Fl_Widget ( x , y , w , h , label )
        {
        }

        void draw ( )
        {
            fl_draw("test" , this->x() , this->y ( ) , this->w ( ) , this->h ( ) , FL_ALIGN_CENTER );
        }
} ;

void PhatChat::Client::message ( const std::string & title , const std::string & message )
{
	Fl_Window window ( 400 , 100 );
	window.label ( title.c_str ( ) ) ;
	Fl_Box box ( 0 , 0 , 400 , 100 , message.c_str ( ) ) ;

	//Fl_Text label ( 0 , 0 , 600 , 100 , message.c_str ( ) ) ;


	window.end ( ) ;
	window.show ( ) ;

	while ( Fl::wait ( ) ) ;
}
