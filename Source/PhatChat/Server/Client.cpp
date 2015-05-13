#include <PhatChat/Server/Client.hpp>
#include <PhatChat/Server/ClientManager.hpp>
#include <PhatChat/Core/OperationCode.hpp>
#include <PhatChat/Core/PingPacket.hpp>
#include <PhatChat/Core/PongPacket.hpp>
#include <PhatChat/Core/MessagePacket.hpp>
#include <PhatChat/Core/RequestUsernamePacket.hpp>
#include <PhatChat/Core/ResponseUsernamePacket.hpp>
#include <ctime>
#include <iostream>

// CUSTOM ALGORITHMS AND HELPERS
namespace std
{
	template <typename t1 , typename t2>
	t1 linear_search ( t1 from , t1 to , const t2 & value )
	{
		for ( ; from != to ; ++from )
		{
			if ( * from == value )
				return from ;
		}

		return to ;
	}
	
	template <typename t1 , typename t2>
	t1 linear_search ( t1 from1 , t1 to1 , t2 from2 , t2 to2 )
	{
		for ( ; from1 != to1 ; ++from1 )
		{
			t1 iterator1 = from1 ;
			t2 iterator2 = from2 ;

			while ( true )
			{
				if ( iterator2 == to2 )
					return from1 ;

				if ( * iterator1 != * iterator2 )
					break ;

				++iterator1 ;
				++iterator2 ;
			}
		}

		return to1 ;
	}

	template <typename t1>
	bool starts_with ( const t1 & left , const t1 & right )
	{
		return std::equal ( left.begin ( ) , left.begin ( ) + right.size ( ) , right.begin ( ) ) ;
	}

	template <typename t1>
	std::vector <t1> explode ( const t1 & data , const t1 & delimiter )
	{
		std::vector <t1> array ;

		typename t1::const_iterator from = data.begin ( ) ;
		typename t1::const_iterator to = from ;

		if ( std::starts_with ( data , delimiter ) )
		    from += delimiter.size ( ) ;

		while ( to != data.end ( ) )
		{
			to = std::linear_search ( ++to , data.end ( ) , delimiter.begin ( ) , delimiter.end ( ) ) ;

			array.push_back ( t1 ( from , to ) ) ;

			from = to + 1 ;
		}

		return array ;
	}
	char* myTime ( const struct tm * timeptr )
	{
  		static const char wday_name [ ] [ 4 ] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" } ;
	  	static const char mon_name [ ] [ 4 ] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" ,
										   		 "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" } ;
	  	static char result [ 26 ] ;
	  	sprintf ( result , "%.3s %.3s%3d %.2d:%.2d:%.2d %d" ,
				  wday_name [ timeptr->tm_wday ] ,
				  mon_name [ timeptr->tm_mon ] ,
				  timeptr->tm_mday , timeptr->tm_hour ,
				  timeptr->tm_min , timeptr->tm_sec ,
				  1900 + timeptr->tm_year ) ;
	  	return result ;
	}
}

PhatChat::Server::Client::Client ( PhatChat::Server::ClientManager & clientManager ) :
    clientManager ( clientManager )
{
}

PhatChat::Server::ClientManager & PhatChat::Server::Client::getClientManager ( )
{
    return this->clientManager ;
}
const PhatChat::Server::ClientManager & PhatChat::Server::Client::getClientManager ( ) const
{
    return this->clientManager ;
}

void PhatChat::Server::Client::setUsername ( const std::string & username )
{
	std::string newUsername = username ;
	
	for ( auto client : clientManager )
	{
		if ( client->getUsername ( ) == newUsername )
			newUsername += "." ;
	}
	
	this->username = newUsername ;
    
	PhatChat::ResponseUsernamePacket responseUsernamePacket ( this->getUsername ( ) ) ;
    sf::Packet packet = responseUsernamePacket.encode ( ) ;
    this->socket.send ( packet ) ;
}
const std::string & PhatChat::Server::Client::getUsername ( ) const
{
    return this->username ;
}

sf::TcpSocket & PhatChat::Server::Client::getSocket ( )
{
    return this->socket ;
}
const sf::TcpSocket & PhatChat::Server::Client::getSocket ( ) const
{
    return this->socket ;
}

bool PhatChat::Server::Client::send ( sf::Packet packet )
{
    return this->socket.send ( packet ) == sf::Socket::Done ;
}
bool PhatChat::Server::Client::receive ( sf::Packet & packet )
{
    this->socket.receive ( packet ) == sf::Socket::Done ;
}

void PhatChat::Server::Client::handlePacket ( sf::Packet packet )
{
	unsigned char operationCodeValue = 0 ;
	packet >> operationCodeValue ;
	PhatChat::OperationCode operationCode = static_cast <PhatChat::OperationCode> ( operationCodeValue ) ;

	if ( operationCode == PhatChat::OperationCode::PING )
	{
		PhatChat::PingPacket pingPacket ( PhatChat::PingPacket::decode ( packet ) ) ;
		std::cout << "Received ping packet with value " << pingPacket.getValue ( ) << "!" << std::endl ;

		sf::Packet newPacket ( PhatChat::PongPacket ( pingPacket.getValue ( ) ).encode ( ) ) ;

        this->socket.send ( newPacket ) ;
	}
	else if ( operationCode == PhatChat::OperationCode::PONG )
	{
		PhatChat::PongPacket pongPacket = PhatChat::PongPacket::decode ( packet ) ;
		std::cout << "Received pong packet with value " << pongPacket.getValue ( ) << "!" << std::endl ;
	}
	else if ( operationCode == PhatChat::OperationCode::REQUEST_USERNAME )
	{
        PhatChat::RequestUsernamePacket requestUsernamePacket = PhatChat::RequestUsernamePacket::decode ( packet ) ;
        this->setUsername ( requestUsernamePacket.getUsername ( ) ) ;
	}
	else if ( operationCode == PhatChat::OperationCode::MESSAGE )
	{
        PhatChat::MessagePacket messagePacket = PhatChat::MessagePacket::decode ( packet ) ;
        
        std::string username = this->username.empty ( ) ? messagePacket.getUsername ( ) : this->username ;
        std::cout << "Received message from " << username << " saying \"" << messagePacket.getMessage ( ) << "\"!" << std::endl ;
        
        if ( * messagePacket.getMessage ( ).begin ( ) == '/' )
        	this->handleCommand ( messagePacket.getMessage ( ) ) ;
        else
		{
        	messagePacket.setUsername ( username ) ;
        	
		    for ( auto client : this->clientManager )
		    {
		        packet = messagePacket.encode ( ) ;
		        client->getSocket ( ).send ( packet ) ;
		    }
		 }
	}
	else
		std::cout << "Operation code is unknown! Skip " << packet.getDataSize ( ) << " bytes." << std::endl ;
}

void PhatChat::Server::Client::handleCommand ( const std::string & message )
{
	if ( message == "/who" )
	{
		PhatChat::MessagePacket messagePacket ;
		
		std::string users ;
		
		for ( auto client : this->clientManager )
		{
			users += client->getUsername ( ) + "; " ;
		}
		
		messagePacket.setMessage ( users ) ;
		
		sf::Packet packet = messagePacket.encode ( ) ;
		this->socket.send ( packet ) ;
	}
	else if ( message == "/time" )
	{
		PhatChat::MessagePacket messagePacket ;
		
		std::time_t time = 0 ;
		struct tm * timeInfo = nullptr ;
		
		std::time ( & time ) ;
		timeInfo = std::localtime ( & time ) ;
		messagePacket.setMessage ( std::myTime ( timeInfo ) ) ;
		
		sf::Packet packet = messagePacket.encode ( ) ;
		this->socket.send ( packet ) ;
	}
	else if ( message == "/help" )
	{
		PhatChat::MessagePacket messagePacket ;
		messagePacket.setMessage ( "Command reference\n/help prints command reference\n/time prints localtime of server\n/who prints users who are online\n/w <Username> <Message> sends private message\n/quit closes connection" ) ;
		sf::Packet packet = messagePacket.encode ( ) ;
		this->socket.send ( packet ) ;
	}
	else if ( message == "/quit" )
	{
		this->socket.disconnect ( ) ;
	}
	else if ( std::starts_with ( message , std::string ( "/w" ) ) )
	{
		std::vector <std::string> arguments ( std::explode ( message , std::string ( " " ) ) ) ;
		
		if ( arguments.size ( ) > 2 )
		{
			for ( auto client : this->clientManager )
			{
				if ( client->getUsername ( ) == arguments [ 1 ] )
				{
					PhatChat::MessagePacket messagePacket ;
					messagePacket.setUsername ( this->getUsername ( ) + " to " + client->getUsername ( ) ) ;
					
					std::string totalMessage ;
					for ( auto message = arguments.begin ( ) + 2 ; message != arguments.end ( ) ; ++message )
						totalMessage += * message + " " ;
						
					messagePacket.setMessage ( totalMessage ) ;
					sf::Packet packet = messagePacket.encode ( ) ;
					client->getSocket ( ).send ( packet ) ;
					packet = messagePacket.encode ( ) ;
					this->socket.send ( packet ) ;
				
					break ;
				}
			}
		}
	}
	else if ( std::starts_with ( message , std::string ( "/set" ) ) )
	{
		std::vector <std::string> arguments ( std::explode ( message , std::string ( " " ) ) ) ;
		if ( arguments.size ( ) == 2 )
			this->setUsername ( arguments [ 1 ] ) ;
	}
	else
	{
		PhatChat::MessagePacket messagePacket ;
		messagePacket.setMessage ( "Command not found!\nCheck /help for command reference!" ) ;
		sf::Packet packet = messagePacket.encode ( ) ;
		this->socket.send ( packet ) ;
	}
}
