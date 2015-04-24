#include <PhatChat/Core/Application.hpp>
#include <SFML/System.hpp>

PhatChat::Application::Application ( )
{
    sf::err ( ).rdbuf ( nullptr ) ;
}
