#include "Caretaker.h"

Caretaker::Caretaker()
{
    post = std::list<Memento *>(); // Initialize my fake queue
    prev = std::list<Memento *>(); // Initialize my fake queue
}

Caretaker::~Caretaker()
{
    for (auto memento : prev)
    {
        delete memento;
    }
    for (auto memento : post)
    {
        delete memento;
    }
    post.clear();
    prev.clear();
}

void Caretaker::add(Memento *record)
{
    if (post.size() > 0)
    {
        Caretaker::continueAction(); // Clear the post list
    }
    if (prev.size() > 10)
    {
        delete prev.back(); // Remove the oldest memento if we exceed the limit
        prev.pop_back();
    }
    prev.push_front(record); // Add the new memento to the front of the list
}

void Caretaker::continueAction()
{
    for (auto memento : post)
    {
        delete memento; // Clear the post list
    }
    post.clear();
}

Memento *Caretaker::undo(Memento *post)
{
    if (post == nullptr)
    {
        if (prev.empty())
        {
            return nullptr; // No previous state to undo to
        }
        else
        {
            Memento *last = prev.front();
            prev.pop_front();
            return last;
        }
    }
    if (prev.empty())
    {
        return nullptr;
    }
    Memento *last = prev.front();
    prev.pop_front();
    this->post.push_front(post); // Add the current state to the post list
    return last;                 // Return the last memento
}

Memento *Caretaker::redo(Memento *prev)
{
    if (prev == nullptr)
    {
        if (post.empty())
        {
            return nullptr; // No next state to redo to
        }
        else
        {
            Memento *first = post.front();
            post.pop_front();
            return first;
        }
    }
    if (post.empty())
    {
        return nullptr;
    }
    Memento *first = post.front();
    post.pop_front();
    if (this->prev.size() > 10)
    {
        this->prev.push_front(prev);
        this->prev.pop_back();
    }
    else
    {
        this->prev.push_front(prev);
    }
    return first;
}
