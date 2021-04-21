#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Book.h"
/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/
using namespace std;

class Student
{
    public:
        // constructors
        Student();
        Student ( int studentId, string studentName);

        // destructor
        ~Student();

        // set & get functions
        int getId();
        string getName();
        void setId( const int thisId);
        void setName( const string thisName);

        // book functions
        void checkoutBook( const int bookId, const string bookName, const int bookYear);
        void returnBook( const int bookId);
        void returnAllBooks();
        void show();
        bool isCheckedOut( const int bookId);

    private:
        // properties
        int id;
        string name;

        typedef Book ListItemType;
        struct BookNode{
            ListItemType item;
            BookNode *next;
        };

        ListItemType item;
        BookNode *next;

        int size;
        BookNode *head;

        // private functions for the list
        bool isListEmpty() const;
        int getListLength() const;
        BookNode *find( int index) const;
        bool retrieve( int index, ListItemType& dataItem) const;
        bool insert( int index, ListItemType newItem);
        bool remove( int index);
};

#endif // STUDENT_H
