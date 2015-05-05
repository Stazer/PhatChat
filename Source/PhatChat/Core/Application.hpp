#pragma once

#include <vector>
#include <string>

namespace PhatChat
{
	class Application
	{
		public :
            // default constructor
            Application ( ) ;

            // virtual destructor
			virtual ~Application ( ) = default ;

			// prevent copying
            Application ( const PhatChat::Application & right ) = delete ;
            PhatChat::Application & operator = ( const PhatChat::Application & right ) = delete ;

            // prevent moving
            Application ( PhatChat::Application && right ) = delete ;
            PhatChat::Application & operator = ( PhatChat::Application && right ) = delete ;


            // pure virtual main function
			virtual int main ( const std::vector <std::string> & arguments ) = 0 ;

		private :
	} ;
}
