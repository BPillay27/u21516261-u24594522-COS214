#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include "Users.h"
#include <list>
#include <iostream>
#include "Container.h"
class Users;
class ChatHistory;
class UserList;
class UserIterator;

/**
 * @defgroup Mediator_Pattern
 * @brief Classes that belong to the Mediator Design Pattern
 *
 * This group is the collection of all classes that are used by the Mediator design pattern. In the pattern, the following are the participants:
 * ChatRoom is the Mediator, Dogorithm and CtrlCat are ConcreteMediators and Users is the Colleague.
 */

/**
 * @defgroup Mediators
 * @brief Abstract Mediator classes for the Mediator Pattern
 * @ingroup Mediator_Pattern
 */

/**
 * @class ChatRoom
 *
 * @brief Abstract base class for a chatroom of users. This class manages its own chat history and user list.
 *
 * @ingroup Mediators
 *
 * @details The ChatRoom is a Mediator (abstract) from which Concrete Mediators will inherit. Mediates communication between a group of Users.
 *
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 */

class ChatRoom {
    //friend class UserIterator; if there are issues with visibility, uncomment this line
    protected:
        /**
         * @brief Stores the history of messages sent to this `ChatRoom`.
         */
        ChatHistory* chatHistory;

        /**
         * @brief List of `Users` that are members of this `ChatRoom`.
         */
        
        UserList* users;    
    public:
        ChatRoom();
        virtual void registerUser(Users* user)=0;
        void sendMessage(std::string message, Users* fromUser);
        void saveMessage(std::string message, Users* fromUser);
        void displayChatHistory();
        virtual void removeUser(Users* user)=0;
        virtual ~ChatRoom();
};

/**
 * @defgroup Concrete_Mediators
 * @brief Concrete subclasses of the abstract `Mediator` class (`ChatRoom`). 
 * 
 * @details This group contains all concrete mediators which inherit from the base class `ChatRoom`, which is the `Mediator`.
 * 
 * **Participants:**
 * -`CtrlCat`: A Concrete Mediator for ChatRooms involving cats.
 * -`Dogorith`: A Concrete Mediator for ChatRooms involving dogs.
 * 
 * @ingroup Mediator_Pattern
 */

/**
 * @class CtrlCat
 * @brief `ChatRoom` for cat-related content
 * 
 * @details CtrlCat inherits from its base class, ChatRoom, and has its own implementations of the pure virtual functions `void registerUser(Users* user)` and `void removeUser(Users* user)`
 * 
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup Concrete_Mediators
 * 
 */

class CtrlCat:public ChatRoom{
    public:
        CtrlCat();
        void registerUser(Users* user) override;
        void removeUser(Users* user) override;
        ~CtrlCat();
};

/**
 * @class Dogorithm
 * @brief `ChatRoom` for dog-related content
 * 
 * @details Dogorithm inherits from its base class, ChatRoom, and has its own implementations of the pure virtual functions `void registerUser(Users* user)` and `void removeUser(Users* user)`
 * @author Byron Pillay and Kiegan Lewis
 * @date 2025-09-25
 * @ingroup Concrete_Mediators
 * 
 */

class Dogorithm:public ChatRoom{
    public:
        Dogorithm();
        void registerUser(Users* user) override;
        void removeUser(Users* user) override;
        ~Dogorithm();
};



#include "Iterator.h"

#endif // CHATROOM_H
