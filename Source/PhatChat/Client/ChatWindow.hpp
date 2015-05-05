#pragma once

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>

namespace PhatChat
{
	namespace Client
	{
		class ChatWindow
		{
			public:
				// default constructor
				ChatWindow ( ) ;

				// hide the window
				void hide ( ) ;

				// show the window
				void show ( ) ;

				// accesor for open
				bool isOpen ( ) const ;

				// resets all values
				void reset ( ) ;

				// accessor for sendPushed
				bool isSendPushed ( ) const ;

				// accessor for the message
				std::string getMessage ( ) const ;

				// adds message to the gui
				void addMessage ( const std::string & message ) ;

			private :
                mutable sf::Mutex mutex ;

				Fl_Window window ;
				Fl_Text_Buffer buffer ;
				Fl_Text_Display log ;
				mutable Fl_Input message ;
				Fl_Button send ;

				mutable bool sendPushed = false ;

				static void onSendPushed ( Fl_Widget * widget , void * data ) ;
		};
	}
}
