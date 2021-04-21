#include "Book.h"
#include <string>

/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/

using namespace std;

Book::Book(){
    id = 0;
    title = "";
    year = 0;
}

Book::Book( int thisId, string thisTitle, int thisYear){
    id = thisId;
    title = thisTitle;
    year = thisYear;
}

Book::~Book(){}

int Book::getId() {
    return id;
}

string Book::getTitle() {
    return title;
}

int Book::getYear() {
    return year;
}

void Book::setId( const int thisId) {
    id = thisId;
}

void Book::setTitle( const string thisTitle) {
    title = thisTitle;
}

void Book::setYear( const int thisYear) {
    year = thisYear;
}
