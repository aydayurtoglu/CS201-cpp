#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H
#include <string>
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

    private:
        // properties
        int id;
        string name;
};

#endif // SIMPLESTUDENT_H
