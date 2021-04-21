#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H
#include <string>
#include "SimpleStudent.h"
/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/
using namespace std;

class LibrarySystem
{
    public:
        // constructor
        LibrarySystem();
        // destructor
        ~LibrarySystem();

        // functions
        void addStudent( const int studentId, const string studentName);
        void deleteStudent( const int studentId);
        void showStudent( const int studentId) const;

    private:
        typedef Student ListItemType;

        struct ListNode{
            ListItemType item;
            ListNode *next;
        };

        ListItemType item;
        ListNode *next;

        int size;
        ListNode *head;

        // private functions for the list
        bool isListEmpty() const;
        int getListLength() const;
        ListNode *find( int index) const;
        bool retrieve( int index, ListItemType& dataItem) const;
        bool insert( int index, ListItemType newItem);
        bool remove( int index);
};

#endif // SIMPLELIBRARYSYSTEM_H
