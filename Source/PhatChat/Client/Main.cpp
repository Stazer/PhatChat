#include <PhatChat/Client/Application.hpp>

int main ( int amountOfArguments , char ** argumentStrings )
{
    std::vector <std::string> arguments ;

    for ( unsigned int argument = 0 ; argument < amountOfArguments ; ++argument )
    {
        arguments.push_back ( argumentStrings [ argument ] ) ;
    }

    return PhatChat::Client::Application ( ).main ( arguments ) ;
}
