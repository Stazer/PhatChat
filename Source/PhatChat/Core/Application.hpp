#pragma once

#include <vector>
#include <string>

namespace PhatChat
{
	class Application
	{
		public :
            // virtual destructor
			virtual ~Application ( ) = default ;

			// prevent PhatChat::Application from beeing copied
            Application ( const PhatChat::Application & right ) = delete ;
            PhatChat::Application & operator = ( const PhatChat::Application & right ) = delete ;

            // prevent PhatChat::Application from beeing moved
            Application ( PhatChat::Application && right ) = delete ;
            PhatChat::Application & operator = ( PhatChat::Application && right ) = delete ;

            // pure virtual
			virtual int main ( const std::vector <std::string> & arguments ) = 0 ;
	} ;
}
