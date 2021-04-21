#include <iostream>
using namespace std;

#include "SimpleStudent.h"
/**
    Name: Ayda Yurtoglu
    ID: 21903153
    Section: 01
*/

Student::Student(){
    id = 0;
    name = "";
}

Student::Student(int studentId, string studentName){
    id = studentId;
    name = studentName;
}

Student::~Student(){}

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

