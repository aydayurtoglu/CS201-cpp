#ifndef BOOK_H
#define BOOK_H
#include <string>

/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/
using namespace std;

class Book
{
    public:
        // constructors
        Book();
        Book( int thisId, string thisTitle, int thisYear);

        // destructor
        ~Book();

        // set & get functions
        int getId();
        string getTitle();
        int getYear();
        void setId( const int thisId);
        void setTitle( const string thisTitle);
        void setYear( const int thisYear);

    private:
        // properties
        int id;
        string title;
        int year;
};

#endif // BOOK_H
