#include <iostream>
#include <iomanip>
using namespace std;

#include "Student.h"
/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/

Student::Student(){
    id = 0;
    name = "";
    size = 0;
    head = NULL;
}

Student::Student(int studentId, string studentName){
    id = studentId;
    name = studentName;
    size = 0;
    head = NULL;
}

Student::~Student(){
    while(!isListEmpty())
        remove(1);
}

int Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

void Student::setId( const int thisId) {
    id = thisId;
}

void Student::setName( const string thisName) {
    name = thisName;
}

void Student::checkoutBook( const int bookId, const string bookName, const int bookYear) {
    // checks if the given BookId is positive
    if ( bookId <= 0){
        cout << "Enter a value greater than 0." << endl;
        return;
    }

    // checks if the given studentId exists in the list
    for ( int i = 1; i < size+1; i++){
        if ((find(i) -> item).getId() == bookId){
            cout << "Book id " << bookId << " already exists." << endl;
            return;
        }
    }

    // dynamically allocate a student object
    ListItemType* newBook = new ListItemType( bookId, bookName, bookYear);

    // add it to the student list
    insert( getListLength()+1, *newBook);
    cout << "Book " << bookId << " has been checked out by student " << id << endl;
    delete newBook;
}

void Student::returnBook( const int bookId){
    if ( isCheckedOut(bookId)){
        // delete book
        int index = -1; // index of the bookId
        for ( int i = 1; i < size+1; i++){
            if ((find(i) -> item).getId() == bookId){
                index = i;
                i = size+1;
            }
        }
        remove (index);
        cout << "Book " << bookId << " has been returned" << endl;
    }
    else {
        cout << "Book " << bookId << " has not been checked out by student " << id << endl;
    }
}

void Student::returnAllBooks() {

    while (!isListEmpty()) {
        int i = 1;
        returnBook((find(i) -> item).getId());
    }
}

void Student::show(){
    cout << "Student id: " << id << " Student name: " << name << endl;

    if ( isListEmpty()){
        cout << "Student " << id << " has no books" << endl;
    }
    else {
        cout << "Student " << id << " has checked out the following books:" << endl;

        cout << left << setw(10) << "Book id" << left << setw(25) << "Book Name" << left << setw(10) << "Year" << endl;
        for ( int i = 1; i < size+1; i++) {
            cout << left << setw(10) << (find(i) -> item).getId()
            << left << setw(25) << (find(i) -> item).getTitle()
            << left<< setw(10) << (find(i) -> item).getYear() << endl;;
        }
    }
}

bool Student::isCheckedOut( const int bookId) {
    // checks if the given bookId is positive
    if ( bookId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return false;
    }

    // checks if the given bookId exists in the list
    for ( int i = 1; i < size+1; i++){
        if ((find(i) -> item).getId() == bookId){
            return true;
        }
    }
    return false;
}

bool Student::isListEmpty() const{
    return size == 0;
}

int Student::getListLength() const{
    return size;
}

Student::BookNode* Student::find( int index) const{
    if ( (index < 1) || (index > getListLength()) ) {
        return NULL;
    }

    else{
        BookNode *cur = head;
        for ( int skip = 1; skip < index; ++skip)
            cur = cur-> next;
        return cur;
    }
}

bool Student::retrieve( int index, ListItemType& dataItem) const{
    if ((index < 1) || (index > getListLength())) {
        return false;
    }

    BookNode *cur = find(index);
    dataItem = cur->item;

    return true;
}

bool Student::insert( int index, ListItemType newItem) {
    int newLength = getListLength() + 1;

    if ((index < 1) || (index > newLength)) {
        return false;
    }

    BookNode *newPtr = new BookNode;
    size = newLength;
    newPtr->item = newItem;

    if ( index == 1){
        newPtr->next = head;
        head = newPtr;
    }
    else{
        BookNode *prev = find(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }

    return true;
}

bool Student::remove( int index){
    BookNode *cur;

    if ((index < 1) || (index > getListLength())){
        return false;
    }
    --size;

    if (index == 1){
        cur = head;
        head = head->next;
    }
    else{
        BookNode *prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}

