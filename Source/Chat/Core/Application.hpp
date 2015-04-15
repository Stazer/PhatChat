#pragma once

#include <vector>

namespace Chat
{
	class Application
	{
		public :
			virtual ~Application ( ) = default ;
			
			virtual int main ( const std::vector <std::string> & arguments ) = 0 ;
	} ;
}
