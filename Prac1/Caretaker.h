#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <list>

class Caretaker
{
private:
    std::list<Memento *> prev;
    std::list<Memento *> post;

public:
    Caretaker();
    ~Caretaker();
    Memento *undo(Memento *post);
    Memento *redo(Memento *prev);
    void add(Memento *record);
    void continueAction();
};

#endif