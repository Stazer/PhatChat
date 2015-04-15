#pragma once

#include <Chat/Core/Application.hpp>

namespace Chat
{
	namespace Client
	{
		class Application : public Chat::Application
		{
			public :
				int main ( const std::vector <std::string> & arguments ) ;
		} ;
	}
}
