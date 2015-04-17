#pragma once

#include <vector>

namespace PhatChat
{
	class Application
	{
		public :
			virtual ~Application ( ) = default ;
			
			virtual int main ( const std::vector <std::string> & arguments ) = 0 ;
	} ;
}
