#include "Stack.h"
#include "City.h"
#include <iostream>
#include <string>
/**
    Name: Ayda Yurtoglu
    ID: 21903153
*/
using namespace std;

Stack::Stack()
{
    topPtr = NULL;
}

Stack::~Stack()
{
    while (!isEmpty())
        pop();
}

bool Stack::isEmpty() const{
    return topPtr == NULL;

}
bool Stack::push(StackItemType newItem){

    StackNode *newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;
}
bool Stack::pop(){
    if (isEmpty())
        return false;

    else{
        StackNode *temp = topPtr;
        topPtr = topPtr->next;

        temp->next = NULL;

        delete temp;
        return true;
    }
}
bool Stack::pop(StackItemType& stackTop){
    if (isEmpty())
        return false;

    else{
        stackTop = topPtr->item;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;

        temp->next = NULL;
        delete temp;
        return true;
    }
}
bool Stack::getTop(StackItemType& stackTop) const{
    if (isEmpty())
        return false;
    else {
        stackTop = topPtr->item;
        return true;
    }
}

string* Stack::getItems(int length){

   /* City** items = new City*[length];
    string* items2 = new string[length];

    Stack temp;
    int index = length;
    int value = length;

    for (int i = 0; i < value; i++){
        StackItemType *item = new City();
        this->pop(*item);
        items[index-1] = item;
        index--;
        temp.push(*item);
        delete item;
    }
    for (int i = 0; i < value; i++ ){
        StackItemType *item = new City();
        temp.pop(*item);
        items2[i] = item->getName();
        delete item;
    }

    if ( items != NULL)
        delete []items;

    return items2;*/
  //  num = numberOfItems;
    string* str = new string[length];
    Stack temp;
    int index = length;
    int value = length;
    for (int i = 0; i < value; i++){
        StackItemType item;
        this->pop(item);
        str[index-1] = item;
        index--;
        temp.push(item);
    }
    for (int i = 0; i < value; i++ ){
        StackItemType item;
        temp.pop(item);
        this->push(item);
    }
    return str;
}
