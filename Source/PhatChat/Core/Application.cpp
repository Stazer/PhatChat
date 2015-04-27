#include <PhatChat/Core/Application.hpp>
#include <SFML/System.hpp>

PhatChat::Application::Application ( )
{
    sf::err ( ).rdbuf ( nullptr ) ;
}

void PhatChat::Application::setRunning ( bool running )
{
    this->running = running ;
}
bool PhatChat::Application::isRunning ( ) const
{
    return this->running ;
}
