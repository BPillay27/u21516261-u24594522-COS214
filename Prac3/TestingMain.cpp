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
    //kiegan is testing sending messages and recieving messages while offline. 
    kiegan->send("Hello everyone, I am Kiegan", dogorithm);
    //byron is testing sending messages and recieving messages while online. 
    byron->send("Hello everyone, I am Byron", ctrlcat);
    //bob is testing sending messages and recieving messages while busy. 
    bob->send("Hello everyone, I am Bob", ctrlcat);
    byron->leaveChatRoom(dogorithm); //byron leaving a room he is in
    byron->leaveChatRoom(dogorithm); //byron leaving a room he is not in
    byron->send("I have left the room", dogorithm); //byron sending message to a room he is not in

    //Testing the containers
    std::cout << "\nTesting the UserList container and UserIterator:\n";
    UserList* userList = new UserList();
    userList->addUser(byron);
    userList->addUser(kiegan);
    userList->addUser(bob);
    userList->addUser(byron); //Should not be able to add again
    UserIterator* it =dynamic_cast<UserIterator*>(userList->createIterator());
    std::cout << "Users in the UserList:" << std::endl;
    while(!it->isDone()) {
        Users* user =(it)->currentItem();
        if(user != nullptr) {
            std::cout << "- " << user->getName() << std::endl;
        }
        it->next();
    }
    

    std::cout << "Testing first- " << (it)->first()->getName() << std::endl;
    

    userList->removeUser(kiegan);
    userList->removeUser(kiegan); //Should not be able to remove again
    delete it;
    it =dynamic_cast<UserIterator*>(userList->createIterator());
    std::cout << "Users in the UserList:" << std::endl;
    while(!it->isDone()) {
        Users* user =(it)->currentItem();
        if(user != nullptr) {
            std::cout << "- " << user->getName() << std::endl;
        }
        it->next();
    }
    delete it;

    std::cout<<"Testing ChatHistory container and ChatHistoryIterator:\n";
    ChatHistory* chatHistory = new ChatHistory();
    chatHistory->add("This is the first message in chat history.");
    chatHistory->add("This is the second message in chat history.");
    chatHistory->add("This is the third message in chat history.");
    ChatHistoryIterator* chatIt = dynamic_cast<ChatHistoryIterator*>(chatHistory->createIterator());
    std::cout << "Chat History Messages:" << std::endl;
    while(!chatIt->isDone()) {
        std::cout << "- " << chatIt->currentItem() << std::endl;
        
        chatIt->next();
    }
    std::cout << "Testing first- " << chatIt->first() << std::endl;
    chatHistory->remove("This is the second message in chat history.");
    delete chatIt;
    chatIt = dynamic_cast<ChatHistoryIterator*>(chatHistory->createIterator());
    std::cout << "Chat History Messages after removal:" << std::endl;
    while(!chatIt->isDone()) {
        std::cout << "- " << chatIt->currentItem() << std::endl;
        chatIt->next();
    }
    delete chatIt;
    //... The iterators work and containers work. and Don't touch them >:)
    dogorithm->displayChatHistory();
    std::cout<<"Cat chatroomm timne:"<<std::endl;
    ctrlcat->displayChatHistory();
    ctrlcat->removeUser(byron);
    ctrlcat->removeUser(byron); 
    ctrlcat->displayChatHistory();
    ctrlcat->removeUser(bob);
    dogorithm->removeUser(kiegan);
    dogorithm->removeUser(kiegan);
    dogorithm->displayChatHistory();


    delete chatHistory;
    delete userList;
    delete byron;
    delete kiegan;
    delete bob;
    delete ctrlcat;
    delete dogorithm;
    return 0;
}