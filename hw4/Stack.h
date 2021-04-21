#ifndef STACK_H
#define STACK_H
#include "City.h"
#include <iostream>

using namespace std;

typedef string StackItemType;

class Stack
{
    public:
        Stack();
        ~Stack();

        bool isEmpty() const;
        bool push(StackItemType newItem) ;
        bool pop();
        bool pop(StackItemType& stackTop);
        bool getTop(StackItemType& stackTop) const;
        string* getItems(int length);

    private:

        struct StackNode { // a node on the stack
            StackItemType item; // a data item on the stack
            StackNode *next; // pointer to next node
        };

        StackNode *topPtr;
};

#endif // STACK_H
