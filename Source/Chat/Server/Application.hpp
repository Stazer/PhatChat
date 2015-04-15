#pragma once

#include <Chat/Core/Application.hpp>

namespace Chat
{
	namespace Server
	{
		class Application : public Chat::Application
		{
			public :
				int main ( const std::vector <std::string> & arguments ) ;
		} ;
	}
}
