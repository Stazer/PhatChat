#pragma once

#include <vector>
#include <string>

namespace PhatChat
{
	class Application
	{
		public :
			virtual ~Application ( ) = default ;
			
			virtual int main ( const std::vector <std::string> & arguments ) = 0 ;
	} ;
}
