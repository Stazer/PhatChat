#pragma once

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

namespace PhatChat
{
	namespace Client
	{
		class ConnectionWindow
		{
			public :
				ConnectionWindow ( const std::string & username , const std::string & socketAddress , unsigned short port ) ;

                bool isConnectPushed ( ) const ;

				int main ( ) ;

				std::string getUsername ( ) const ;
				std::string getHostAddress ( ) const ;
				unsigned short getPort ( ) const ;

			private :
                static void onConnectPushed ( Fl_Widget * widget , void * data ) ;

				Fl_Window window ;

				Fl_Input username ;
				Fl_Input socketAddress ;

				Fl_Button connect ;
                bool connectPushed = false ;
		} ;
	}
}
