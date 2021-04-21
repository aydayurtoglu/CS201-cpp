#include <iostream>
#include <iomanip>
#include <cstddef>
#include "LibrarySystem.h"
#include "Book.h"
#include "Student.h"
using namespace std;

/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/

LibrarySystem::LibrarySystem(){
    studentList.size = 0;
    bookList.size = 0;

    studentList.head = NULL;
    bookList.head = NULL;
}

LibrarySystem::~LibrarySystem(){
    while(!isListEmpty1())
        remove1(1);

    while(!isListEmpty2())
        remove2(1);
}

void LibrarySystem::addBook( const int bookId, const string bookName, const int bookYear){
// checks if the given studentId is positive
    if ( bookId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given studentId exists in the list
    for ( int i = 1; i < (bookList.size)+1; i++){
        if ((find2(i) -> book).getId() == bookId){
            cout << "Book " << bookId << " already exists" << endl;
            return;
        }
    }

    // dynamically allocate a student object
    ListItemType2* newBook = new ListItemType2( bookId, bookName, bookYear);

    // add it to the student list
    insert2( getListLength2()+1, *newBook);
    cout << "Book " << bookId << " has been added" << endl;
    delete newBook;
}
void LibrarySystem::deleteBook( const int bookId){
    // checks if the given studentId is positive
    if ( bookId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given bookId exists in the list
    int index = -1; // index of the studentId
    for ( int i = 1; i < (bookList.size)+1; i++){
        if ((find2(i) -> book).getId() == bookId){
            index = i;
            i = (bookList.size)+1;
        }
    }

    if ( index == -1) {
        cout << "Book " << bookId << " does not exist" << endl;
        return;
    }
    // checks if the given book is checked out by a student
    int index1 = -1;
    for ( int i = 1; i < (studentList.size)+1; i++) {
        if ((find1(i)->student).isCheckedOut(bookId)){
            (find1(i)->student).returnBook(bookId);
            index1 = i;
            i = (studentList.size)+1;
        }
    }

    if(index1 == -1) {
        cout << "Book " << bookId << " has not been checked out" << endl;
    }

    // delete the student
    remove2(index);

    cout << "Book " << bookId << " has been deleted" << endl;
} // it should be possible to delete books

void LibrarySystem::addStudent( const int studentId, const string studentName){
    // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given studentId exists in the list
    for ( int i = 1; i < (studentList.size)+1; i++){
        if ((find1(i) -> student).getId() == studentId){
            cout << "Student " << studentId << " already exists" << endl;
            return;
        }
    }

    // dynamically allocate a student object
    ListItemType1* newStudent = new ListItemType1( studentId, studentName);

    // add it to the student list
    insert1( getListLength1()+1, *newStudent);
    cout << "Student " << studentId << " has been added" << endl;
    delete newStudent;
}
void LibrarySystem::deleteStudent( const int studentId){
    // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given studentId exists in the list
    int index = -1; // index of the studentId
    for ( int i = 1; i < (studentList.size)+1; i++){
        if ((find1(i) -> student).getId() == studentId){
            index = i;
            i = (studentList.size)+1;
        }
    }

    if ( index == -1) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    // return books of the students
    (find1(index) -> student).returnAllBooks();

    // delete the student
    remove1(index);

    cout << "Student " << studentId << " has been deleted" << endl;
}

void LibrarySystem::checkoutBook( const int bookId, const int studentId){
    if ( bookId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given bookId exists in the list
    int index2 = -1; // index of the studentId
    for ( int i = 1; i < (bookList.size)+1; i++){
        if ((find2(i) -> book).getId() == bookId){
            index2 = i;
            i = (bookList.size)+1;
        }
    }

    if ( index2 == -1) {
        cout << "Book " << bookId << " does not exist for checkout" << endl;
        return;
    }

    // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given studentId exists in the list
    int index1 = -1; // index of the studentId
    for ( int i = 1; i < (studentList.size)+1; i++){
        if ((find1(i) -> student).getId() == studentId){
            index1 = i;
            i = (studentList.size)+1;
        }
    }

    if ( index1 == -1) {
        cout << "Student " << studentId << " does not exist for checkout" << endl;
        return;
    }

    // checks if the book is checked out by another student
    for ( int i = 1; i < (studentList.size)+1; i++) {
        if ((find1(i)->student).isCheckedOut(bookId)){
            cout << "Book " << bookId << " has been already checked out by another student" << endl;
            return;
        }
    }
    // Now that both student and book exist in the system, the student checks out the book
    string title = (find2(index2)->book).getTitle();
    int year = (find2(index2)->book).getYear();
    (find1(index1)->student).checkoutBook(bookId, title, year);
}
void LibrarySystem::returnBook( const int bookId){
    if ( bookId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given bookId exists in the list
    int index2 = -1; // index of the book
    for ( int i = 1; i < (bookList.size)+1; i++){
        if ((find2(i) -> book).getId() == bookId){
            index2 = i;
            i = (bookList.size)+1;
        }
    }

    if ( index2 == -1) {
        cout << "Book " << bookId << " does not exist" << endl;
        return;
    }

    // checks if the book is checked out by another student
    int index1 = -1;

    for ( int i = 1; i < (studentList.size)+1; i++) {
        if ((find1(i)->student).isCheckedOut(bookId)){
            index1 = i;
            i = (studentList.size)+1;
        }
        else {
            cout << "Book " << bookId << " has not been checked out" << endl;
            return;
        }
    }
    // Now that both student and book exist in the system, the student checks out the book
    (find1(index1)->student).returnBook(bookId);
}

void LibrarySystem::showAllBooks() const{
    cout << left << setw(10) << "Book id" << left << setw(25) << "Book Name" << left << setw(10) << "Year" << left << setw(50) << "Status" << endl;


    for ( int i = 1; i < (bookList.size)+1; i++) {

        cout << left << setw(10) << (find2(i) -> book).getId()
            << left << setw(25) << (find2(i) -> book).getTitle()
            << left << setw(10) << (find2(i) -> book).getYear();

        bool checkedOut = false;
        for ( int j = 1; j < (studentList.size)+1; j++){
            if ((find1(j)->student).isCheckedOut((find2(i) -> book).getId())){
                cout << "Checked out by Student " << (find1(j)->student).getId() << endl;
                checkedOut = true;
            }
        }

        if (!checkedOut) {
            cout << "Not checked out" << endl;
        }
    }
}
void LibrarySystem::showBook( const int bookId) const{
    if ( bookId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given bookId exists in the list
    int index2 = -1; // index of the bookId
    for ( int i = 1; i < (bookList.size)+1; i++){
        if ((find2(i) -> book).getId() == bookId){
            index2 = i;
            i = (bookList.size)+1;
        }
    }

    if ( index2 == -1) {
        cout << "Book " << bookId << " does not exist" << endl;
        return;
    }

    cout << left << setw(10) << (find2(index2) -> book).getId()
        << left << setw(25) << (find2(index2) -> book).getTitle()
        << left<< setw(10) << (find2(index2) -> book).getYear();

    bool checkedOut = false;
    for ( int j = 1; j < (studentList.size)+1; j++){
        if ((find1(j)->student).isCheckedOut((find2(index2) -> book).getId())){
            cout << "Checked out by Student " <<(find1(j)->student).getId() << endl;
            checkedOut = true;
        }
    }

    if (!checkedOut) {
        cout << "Not checked out" << endl;
    }

}
void LibrarySystem::showStudent( const int studentId) const{
     // checks if the given studentId is positive
    if ( studentId <= 0){
        cout << "Enter a value greater than 0" << endl;
        return;
    }

    // checks if the given flightNo exists in the list
    int index = -1; // index of the flight no
    for ( int i = 1; i < (studentList.size)+1; i++){
        if ((find1(i) -> student).getId() == studentId){
            index = i;
            i = (studentList.size)+1;
        }
    }

    if ( index == -1) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }

    // if the student exists print the information
    (find1(index) -> student).show();
}

// private functions for student list

bool LibrarySystem::isListEmpty1() const{
    return studentList.size == 0;
}
int LibrarySystem::getListLength1() const{
    return studentList.size;
}
LibrarySystem::StudentNode* LibrarySystem::find1( int index) const{
    if ( (index < 1) || (index > getListLength1()) ) {
        return NULL;
    }

    else{
        StudentNode *cur = studentList.head;
        for ( int skip = 1; skip < index; ++skip)
            cur = cur-> next;
        return cur;
    }
}
bool LibrarySystem::insert1( int index, ListItemType1 newItem){
    int newLength = getListLength1() + 1;

    if ((index < 1) || (index > newLength)) {
        return false;
    }

    StudentNode *newPtr = new StudentNode;
    studentList.size = newLength;
    newPtr->student = newItem;

    if ( index == 1){
        newPtr->next = studentList.head;
        studentList.head = newPtr;
    }
    else{
        StudentNode *prev = find1(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}
bool LibrarySystem::remove1( int index){
    StudentNode *cur;

    if ((index < 1) || (index > getListLength1())){
        return false;
    }
    --(studentList.size);

    if (index == 1){
        cur = studentList.head;
        studentList.head = studentList.head->next;
    }
    else{
        StudentNode *prev = find1(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}

// private functions for book list

bool LibrarySystem::isListEmpty2() const{
    return bookList.size == 0;
}
int LibrarySystem::getListLength2() const{
    return bookList.size;
}
LibrarySystem::BookNode* LibrarySystem::find2( int index) const{
    if ( (index < 1) || (index > getListLength2()) ) {
        return NULL;
    }

    else{
        BookNode *cur = bookList.head;
        for ( int skip = 1; skip < index; ++skip)
            cur = cur-> next;
        return cur;
    }
}
bool LibrarySystem::insert2( int index, ListItemType2 newItem){
    int newLength = getListLength2() + 1;

    if ((index < 1) || (index > newLength)) {
        return false;
    }

    BookNode *newPtr = new BookNode;
    bookList.size = newLength;
    newPtr->book = newItem;

    if ( index == 1){
        newPtr->next = bookList.head;
        bookList.head = newPtr;
    }
    else{
        BookNode *prev = find2(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }

    return true;
}
bool LibrarySystem::remove2( int index){
    BookNode *cur;

    if ((index < 1) || (index > getListLength2())){
        return false;
    }
    --(bookList.size);

    if (index == 1){
        cur = bookList.head;
        bookList.head = bookList.head->next;
    }
    else{
        BookNode *prev = find2(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}

