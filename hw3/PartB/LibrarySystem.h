#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <string>
#include "Book.h"
#include "Student.h"
/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/
using namespace std;

class LibrarySystem
{
    public:
        LibrarySystem();
        ~LibrarySystem();

        void addBook( const int bookId, const string bookName, const int bookYear);
        void deleteBook( const int bookId);

        void addStudent( const int studentId, const string studentName);
        void deleteStudent( const int studentId);

        void checkoutBook( const int bookId, const int studentId);
        void returnBook( const int bookId);

        void showAllBooks() const;
        void showBook( const int bookId) const;
        void showStudent( const int studentId) const;

    private:
        typedef Student ListItemType1; // aha bura sıkıntılı
        typedef Book ListItemType2;

        // student list
        struct StudentNode{
            ListItemType1 student;
            StudentNode *next;
        };

        struct StudentList{
            ListItemType1 student;
            StudentNode *next;

            int size;
            StudentNode *head;
        };
        bool isListEmpty1() const;
        int getListLength1() const;
        StudentNode *find1( int index) const;
        bool insert1( int index, ListItemType1 newItem);
        bool remove1( int index);

        StudentList studentList;

        // book list
        struct BookNode{
            ListItemType2 book;
            BookNode *next;
        };

        struct BookList{
            ListItemType2 book;
            BookNode *next;

            int size;
            BookNode *head;
        };

        bool isListEmpty2() const;
        int getListLength2() const;
        BookNode *find2( int index) const;
        bool insert2( int index, ListItemType2 newItem);
        bool remove2( int index);

        BookList bookList;
};

#endif // LIBRARYSYSTEM_H
