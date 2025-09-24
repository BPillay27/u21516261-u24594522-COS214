#include "ChatRoom.h"

ChatRoom::ChatRoom()
{
    chatHistory = new ChatHistory();
    users = new UserList();
}

ChatRoom::~ChatRoom()
{
    if (chatHistory != nullptr)
    {
        delete chatHistory;
        chatHistory = nullptr;
    }

    if (users != nullptr)
    {
        delete users;
        users = nullptr;
    }
}

void ChatRoom::sendMessage(std::string message, Users *fromUser)
{
    if (fromUser == nullptr || !fromUser->IsInChatRoom(this))
        return;
    UserIterator *iter = dynamic_cast<UserIterator *>(users->createIterator());

    while (!iter->isDone())
    {
        if (iter->currentItem() != fromUser)
        {
            iter->currentItem()->receive(message, fromUser, this);
        }
        iter->next();
    }

    saveMessage(message, fromUser);
    delete iter;
}

void ChatRoom::saveMessage(std::string message, Users *fromUser)
{
    if (message != "" && fromUser!=nullptr && fromUser->IsInChatRoom(this))
    {
        chatHistory->add(message);
    }
}

void ChatRoom::displayChatHistory()
{
    ChatHistoryIterator *chatIt = dynamic_cast<ChatHistoryIterator *>(chatHistory->createIterator());
    while (!chatIt->isDone())
    {
        std::cout << chatIt->currentItem() << std::endl;
        chatIt->next();
    }
    delete chatIt;
}

CtrlCat::CtrlCat() : ChatRoom()
{
    // this->chatHistory = new ChatHistory();
    // this->users = new UserList();
}

void CtrlCat::registerUser(Users *user)
{
    this->chatHistory->add(user->getName() + " has joined the CtrlCat room.");
    this->users->addUser(user);
}

void CtrlCat::removeUser(Users *user)
{
    this->chatHistory->add(user->getName() + " has left the CtrlCat room.");
    this->users->removeUser(user);
}

void Dogorithm::registerUser(Users *user)
{
    this->chatHistory->add(user->getName() + " has joined the Dogorithm room.");
    this->users->addUser(user);
}

Dogorithm::Dogorithm() : ChatRoom()
{
    // this->chatHistory = new ChatHistory();
    // this->users = new UserList();
}

void Dogorithm::removeUser(Users *user)
{
    this->chatHistory->add(user->getName() + " has left the Dogorithm room.");
    this->users->removeUser(user);
}
Dogorithm::~Dogorithm()
{
    if (this->chatHistory != nullptr)
    {
        delete this->chatHistory;
        this->chatHistory = nullptr;
    }

    if (this->users != nullptr)
    {
        delete this->users;
        this->users = nullptr;
    }
}

CtrlCat::~CtrlCat()
{
    if (this->chatHistory != nullptr)
    {
        delete this->chatHistory;
        this->chatHistory = nullptr;
    }

    if (this->users != nullptr)
    {
        delete this->users;
        this->users = nullptr;
    }
}
