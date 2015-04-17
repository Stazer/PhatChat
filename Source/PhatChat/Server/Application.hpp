#pragma once

#include <PhatChat/Core/Application.hpp>

namespace PhatChat
{
	namespace Server
	{
		class Application : public PhatChat::Application
		{
			public :
				int main ( const std::vector <std::string> & arguments ) ;
		} ;
	}
}
