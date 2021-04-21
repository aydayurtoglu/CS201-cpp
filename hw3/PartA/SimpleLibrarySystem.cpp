#include <iostream>
#include <cstddef>
#include "SimpleLibrarySystem.h"
#include "SimpleStudent.h"

using namespace std;

/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/
LibrarySystem::LibrarySystem()
{
    size = 0;
    head = NULL;
}

LibrarySystem::~LibrarySystem()
{
    while(!isListEmpty())
        remove(1);
}

void LibrarySystem::addStudent( const int studentId, const string studentName) {
    // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0." << endl;
        return;
    }

    // checks if the given studentId exists in the list
    for ( int i = 1; i < size+1; i++){
        if ((find(i) -> item).getId() == studentId){
            cout << "Student id " << studentId << " already exists." << endl;
            return;
        }
    }

    // dynamically allocate a student object
    ListItemType* newStudent = new ListItemType( studentId, studentName);

    // add it to the student list
    insert( getListLength()+1, *newStudent);
    cout << "Student " << studentId << " has been added." << endl;
    delete newStudent;
}

void LibrarySystem::deleteStudent( const int studentId) {
    // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0." << endl;
        return;
    }

    // checks if the given studentId exists in the list
    int index = -1; // index of the studentId
    for ( int i = 1; i < size+1; i++){
        if ((find(i) -> item).getId() == studentId){
            index = i;
            i = size+1;
        }
    }

    if ( index == -1) {
        cout << "Student " << studentId << " does not exist." << endl;
        return;
    }

    // delete the student
    remove (index);

    cout << "Student " << studentId << " is deleted from the list." << endl;
}

void LibrarySystem::showStudent( const int studentId) const {
    // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0." << endl;
        return;
    }

    // checks if the given flightNo exists in the list
    int index = -1; // index of the flight no
    for ( int i = 1; i < size+1; i++){
        if ((find(i) -> item).getId() == studentId){
            index = i;
            i = size+1;
        }
    }

    if ( index == -1) {
        cout << "Student id " << studentId << " does not exist." << endl;
        return;
    }

    cout << "Student id: " << (find(index) -> item).getId() << " Student name: " << (find(index) -> item).getName() << endl;
}

bool LibrarySystem::isListEmpty() const{
    return size == 0;
}

int LibrarySystem::getListLength() const{
    return size;
}

LibrarySystem::ListNode* LibrarySystem::find( int index) const{
    if ( (index < 1) || (index > getListLength()) ) {
        return NULL;
    }

    else{
        ListNode *cur = head;
        for ( int skip = 1; skip < index; ++skip)
            cur = cur-> next;
        return cur;
    }
}

bool LibrarySystem::retrieve( int index, ListItemType& dataItem) const{
    if ((index < 1) || (index > getListLength())) {
        return false;
    }

    ListNode *cur = find(index);
    dataItem = cur->item;

    return true;
}

bool LibrarySystem::insert( int index, ListItemType newItem) {
    int newLength = getListLength() + 1;

    if ((index < 1) || (index > newLength)) {
        return false;
    }

    ListNode *newPtr = new ListNode;
    size = newLength;
    newPtr->item = newItem;

    if ( index == 1){
        newPtr->next = head;
        head = newPtr;
    }
    else{
        ListNode *prev = find(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }

    return true;
}

bool LibrarySystem::remove( int index){
    ListNode *cur;

    if ((index < 1) || (index > getListLength())){
        return false;
    }
    --size;

    if (index == 1){
        cur = head;
        head = head->next;
    }
    else{
        ListNode *prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}
