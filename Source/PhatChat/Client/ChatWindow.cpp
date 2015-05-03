//#include <PhatChat/Client/ChatWindow.hpp> 

ChatWindow::ChatWindow()
			:phatwindow(10, 10, 800, 800, "PhatChat"), phatTile(10, 10 ,800, 800),
			phatInput (10,510,700,300), phatDisp(10, 10, 800, 500, "Display"),
			phatReturn( 710, 510, 100, 300, "Enter")
{

	phatwindow.end();
    phatwindow.show();
    return Fl::run ( ); 

	//foo
}


bool ChatWindow::isSendPushed(){
    
    bool resultOfSend = sendPushed;
    return resultOfSend;

}



string ChatWindow::getMessage(){
    
    std::string chatMessage = phatInput.value();
    return chatMessage;
    
    
}


void ChatWindow::addMessage(const std::string& phatMessage){
    
    tbuff = text(phatMessage);
    phatDisp = buffer(tbuff);
    
    
}



