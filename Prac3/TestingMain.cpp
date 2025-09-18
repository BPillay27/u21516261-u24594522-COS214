#include "ChatRoom.h"
#include "Users.h"
#include "Iterator.h"
#include "Command.h"
#include "UserState.h"
#include <iostream>
#include <string>

int main(){
    //Create users
    Users* byron = new Byron();
    Users* kiegan = new Kiegan();
    Users* bob = new Bob();
    //Create chatrooms
    //No implementation for chatrooms yet
    ChatRoom* ctrlcat = new CtrlCat();
    ChatRoom* dogorithm = new Dogorithm();
    ChatRoom* parrotsort = new ParrotSort();

    //Using functions from Users class that doesn't require chatrooms
    std::cout << byron->getName() << " is currently byron at: "<<byron<<std::endl;
    std::cout << kiegan->getName() << " is currently " << kiegan->UserStatus() << std::endl;
    byron->setBusy();
    std::cout << byron->getName() << " is currently " << byron->UserStatus() << std::endl;
    byron->setBusy(); //Should not be able to set busy again
    std::cout << byron->getName() << " is currently " << byron->UserStatus() << std::endl;
    byron->setBusy(); //Should not be able to set busy again
    byron->log();
    kiegan->log();
    std::cout << kiegan->getName() << " is currently " << kiegan->UserStatus() << std::endl;
    std::cout << byron->getName() << " is currently " << byron->UserStatus() << std::endl;
    byron->log(); //Should not be able to log off again
    kiegan->setBusy();
    std::cout << byron->getName() << " is currently " << byron->UserStatus() << std::endl;
    std::cout << kiegan->getName() << " is currently " << kiegan->UserStatus() << std::endl;
    kiegan->addUnreadMessage("Test unread message 1");
    kiegan->addUnreadMessage("Test unread message 2");
    kiegan->printUnreadMessages();
    kiegan->printUnreadMessages(); //Should be no unread messages
    bob->setBusy();
    std::cout << bob->getName() << " is currently " << bob->UserStatus() << std::endl;
    //Testing the ChatRoom joining for Users
    byron->joinChatRoom(ctrlcat);
    byron->joinChatRoom(ctrlcat); //Should not be able to join again
    byron->joinChatRoom(dogorithm);
    kiegan->joinChatRoom(dogorithm);
    bob->joinChatRoom(ctrlcat);
    bob->joinChatRoom(parrotsort);
    kiegan->joinChatRoom(parrotsort);
    //kiegan is testing sending messages and recieving messages while offline. 
    kiegan->send("Hello everyone, I am Kiegan", dogorithm);
    //byron is testing sending messages and recieving messages while online. 
    byron->send("Hello everyone, I am Byron", ctrlcat);
    //bob is testing sending messages and recieving messages while busy. 
    bob->send("Hello everyone, I am Bob", ctrlcat);
    bob->send("Hello everyone, I am Bob", parrotsort);
    byron->leaveChatRoom(dogorithm); //byron leaving a room he is in
    byron->leaveChatRoom(dogorithm); //byron leaving a room he is not in
    byron->send("I have left the room", dogorithm); //byron sending message to a room he is not in

    //Must test Iterator and ChatRoom together as Iterator needs a list of users from ChatRoom
    //The userstauts and commands work with dumby class so if there is an error it is your fault


    delete byron;
    delete kiegan;
    delete bob;
    delete ctrlcat;
    delete dogorithm;
    delete parrotsort;
    return 0;
}