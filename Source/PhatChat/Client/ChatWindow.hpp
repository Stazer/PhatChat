#pragma once

#include <SFML/Network.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Editor.H>
//#include <FL/Fl_Pack.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Display.H>
#include <string>


class ChatWindow{
	
	public:
    
		ChatWindow();
        bool isSendPushed();
        Fl_Window phatwindow;
        Fl_Tile phatTile;
        Fl_Input phatInput; 
        Fl_Text_Display phatDisp; 
        Fl_Return_Button phatReturn; 
        //this boolean  method makes a copy of sendPushed value
        //then it set sendPushed to false
        //return the copy to the sender's output window
    
        std::string getMessage();
        //creates a copy of the text boxs value
        //sets the text box value to ""
        //returns the copy
    
        void addMessage(const std::string&);
    
        //username is concatenated to the input string
    
        //get ride of sidebar
        //reach Justus over email
    
    
	private:
    
       
    

        bool sendPushed = false ;
        Fl_Text_Buffer tbuff;
    
        //call back for the send button
        //boolean value: sendPushed();
		
		
		
};



#include "PhatChat/Client/Application.cpp"







    