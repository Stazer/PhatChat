#include <PhatChat/Server/Application.hpp>

int main ( int amountOfArguments , char ** argumentStrings )
{
    std::vector <std::string> arguments ;

    for ( unsigned int argument = 0 ; argument < amountOfArguments ; ++argument )
    {
        arguments.push_back ( argumentStrings [ argument ] ) ;
    }

    return PhatChat::Server::Application ( ).main ( arguments ) ;
}