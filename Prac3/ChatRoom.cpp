#include "ChatRoom.h"

/**
 * @brief Constructor for the ChatRoom class.
 * @details Initialises a ChatRoom with an empty UserList and an empty ChatHistory.
 */

ChatRoom::ChatRoom()
{
    chatHistory = new ChatHistory();
    users = new UserList();
}

/**
 * @brief Destructor for the ChatRoom class.
 * @details This is the destructor of the ChatRoom class which checks if `users` and `chatHistory` are `not nullptr`.
 * If they are `not nullptr`, deletes them and sets their pointer to `nullptr`.
 * Declared as virtual for inheritance purposes.
 */

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

/**
 * @brief Handles sending a `message` to the `chatRoom`.
 *
 * @details
 * 1. Checks if the `fromUser` is not a member of the `chatRoom`. If true, the function returns.
 * 2. Checks if the `message` is an empty string. If true, the function returns.
 * 3. Creates a `UserIterator` for `users` and steps through the `users`. If the `User` is not `fromUser`, calls `receive(message, fromUser, this)` on that `User`.
 * 4. Calls `saveMessage(message, fromUser)` to store the sent message.
 * 5. Deletes the `UserIterator` to free dynamically allocated memory.
 *
 * @param message The string being sent from `fromUser` to the other `users` in the `ChatRoom`.
 * @param fromUser The `User` sending a message to the `ChatRoom`.
 */

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

    delete iter;
}

/**
 * @brief Stores a `message` in `chatHistory'.
 *
 * @details This function is used by `sendMessage(std::string message, Users *fromUser)` to store a sent `message`.
 * 1. Checks if `message` is not an empty string.
 * 2. Checks if `fromUser` is not `nullptr`.
 * 3. Checks if `fromUser` is a member of the Chatroom.
 * 4. If all of the above is true, calls `chatHistory->add(message)` to add the `message` to the `chatHistory`.
 *
 * @param message The string being sent from `fromUser` to the other `users` in the `chatRoom`.
 * @param fromUser The `User` sending a message to the `chatRoom`.
 */

void ChatRoom::saveMessage(std::string message, Users *fromUser)
{
    if (message != "" && fromUser != nullptr && fromUser->IsInChatRoom(this))
    {
        chatHistory->add(fromUser->getName()+" : "+message);
    }
}

/**
 * @brief Prints the `chatHistory` to the console.
 *
 * @details 
 * 1. Creates a `ChatHistoryIterator` to step through `chatHistory`. 
 * 2. For each `message` in `chatHistory`, prints the `message` to the console. 
 * 3. Deletes the `ChatHistoryIterator` to free allocated memory.
 */

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

/**
 * @brief Constructor for the subclass `CtrlCat`.
 *
 * @details This is the constructor for the `CtrlCat` class, a subclass of the `ChatRoom` class. Calls the base class constructor.
 */

CtrlCat::CtrlCat() : ChatRoom()
{
}

/**
 * @brief Adds a `User` to the `CtrlCat`.
 *
 * @details 1. Calls `chatHistory->add(user->getName() + " has joined the CtrlCat room.")` to alert all `Users` that this user has entered the chat.
 * 2. Calls `users->addUser(user)` to add the user to the `UserList`.
 *
 * @param user This is the `Users` object to add to the `UserList`
 *
 */

void CtrlCat::registerUser(Users *user)
{
    if (user == nullptr)
        return;
    this->chatHistory->add(user->getName() + " has joined the CtrlCat room.");
    this->users->addUser(user);
}

/**
 * @brief Removes a `User` from the `UserList`.
 *
 * @details 1. Calls `chatHistory->add(user->getName() + " has left the CtrlCat room.")` to record a user leaving and notify users in the `UserList` that the user left.
 * 2. Calls users->removeUser(user) to remove the user from the `UserList`.
 * @param user The user to be removed from `UserList`.
 *
 * @note This function does not do anything if user is not a member of `CtrlCat`.
 */

void CtrlCat::removeUser(Users *user)
{
    if(user->IsInChatRoom(this) == false) {
        return;
    }
    this->chatHistory->add(user->getName() + " has left the CtrlCat room.");
    this->users->removeUser(user);
    user->leaveChatRoom(this);
}

/**
 * @brief Registers (adds) a user to the `UserList`.
 *
 * @details 1. Calls chatHistory->add(user->getName() + " has joined the Dogorithm room.") to inform users in `UserList` that a new user has joined and record a new user joining.
 * 2. Calls `users->addUser(user)`
 *
 * @param user The user to be added to `UserList`.
 *
 */

void Dogorithm::registerUser(Users *user)
{
    this->chatHistory->add(user->getName() + " has joined the Dogorithm room.");
    this->users->addUser(user);
}

/**
 * @brief Constructor for the subclass `Dogorithm`.
 *
 * @details This is the constructor for the `Dogorithm` class, a subclass of the `ChatRoom` class. Calls the base class constructor.
 */

Dogorithm::Dogorithm() : ChatRoom()
{
}

/**
 * @brief Method to remove a user from the `Dogorithm`
 * @details 1. Calls `chatHistory->add(user->getName() + " has left the Dogorithm room.")` to notify users of a new member and record the member joining.
 * 2. Calls `users->removeUser(user)` to add the user to the `UserList`.
 *
 * @param user The user you wish to add to the `UserList`
 */

void Dogorithm::removeUser(Users *user)
{
    if(user->IsInChatRoom(this) == false) {
        return;
    }
    this->chatHistory->add(user->getName() + " has left the Dogorithm room.");
    this->users->removeUser(user);
    user->leaveChatRoom(this);
}

/**
 * @brief Destructor for the `Dogorithm` Class
 * 
 * @details 1. Checks if `chatHistory` is `nullptr`. If not, deletes `chatHistory` and sets the pointer to `nullptr`.
 * 2. Checks if `users` is `nullptr`. If not, deletes `users` and sets the pointer to `nullptr`.
 */

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

/**
 * @brief Destructor for the `CtrlCat` Class
 * 
 * @details 1. Checks if `chatHistory` is `nullptr`. If not, deletes `chatHistory` and sets the pointer to `nullptr`.
 * 2. Checks if `users` is `nullptr`. If not, deletes `users` and sets the pointer to `nullptr`.
 */

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
