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
				ConnectionWindow ( ) ;

				void hide ( ) ;
				void show ( ) ;

				void reset ( ) ;

                bool isConnectPushed ( ) const ;

                void setUsername ( const std::string & username ) ;
				std::string getUsername ( ) const ;

				void setHostAddress ( const std::string & hostAddress ) ;
				std::string getHostAddress ( ) const ;

                void setPort ( unsigned short port ) ;
				unsigned short getPort ( ) const ;

                void setSocketAddress ( const std::string & socketAddress ) ;
                std::string getSocketAddress ( ) const ;

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
