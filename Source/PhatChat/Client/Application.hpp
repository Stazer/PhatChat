#pragma once

#include <PhatChat/Core/Application.hpp>

namespace PhatChat
{
	namespace Client
	{
		class Application : public PhatChat::Application
		{
			public :
				int main ( const std::vector <std::string> & arguments ) ;
		} ;
	}
}
