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
				// default constructor
				ConnectionWindow ( ) ;

				// accessor for open
				bool isOpen ( ) const ;

				// hide window
				void hide ( ) ;

				// show window
				void show ( ) ;

				// reset fields
				void reset ( ) ;

				// accessor for connectPushed
                bool isConnectPushed ( ) const ;

				// mutator for username
                void setUsername ( const std::string & username ) ;
				// accessor for username
				std::string getUsername ( ) const ;

				// mutator for hostAddress
				void setHostAddress ( const std::string & hostAddress ) ;
				// accessorcfor hostAddress
				std::string getHostAddress ( ) const ;

				// mutator for port
                void setPort ( unsigned short port ) ;
                // accessor for port
				unsigned short getPort ( ) const ;

				// mutator for socketAddress
                void setSocketAddress ( const std::string & socketAddress ) ;
                // accessor for socketAddress
                std::string getSocketAddress ( ) const ;

			private :
				// callback
                static void onConnectPushed ( Fl_Widget * widget , void * data ) ;

				Fl_Window window ;

				Fl_Input username ;
				Fl_Input socketAddress ;

				Fl_Button connect ;
                bool connectPushed = false ;
		} ;
	}
}
