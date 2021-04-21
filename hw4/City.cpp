#include "City.h"
#include <string>
#include <iostream>

using namespace std;
/**
    Name: Ayda Yurtoglu
    ID: 21903153
*/

City::City()
{
    name = "";
    previous = NULL;
    countPrevious = 0;
    visited = false;
}

City::City(const string name1)
{
    if ( name1 != ""){
    name = name1;
    previous = NULL;
    countPrevious = 0;
    setVisitedFrom(name);
    visited = false;
    }
}

City::~City()
{
    name = "";
    /*
    for (int i = 0; i < countPrevious; i++) {
        if( !previous[i].empty() ){
            previous[i] = "";
        }
    }*/
    if ( previous != NULL){
       delete []previous;
    }
}

bool City::isVisited() {

    return visited;


}

bool City::isVisited(const string city) {
    for (int i = 0; i < countPrevious; i++) {
        if( city == previous[i] ){
            return true;
        }
    }
    return false;
}

void City::setVisited( bool vis){
    visited = vis;
}
string City::getName() {
    if (name != ""){
        return name;
    }
}

int City::getCount() {
    return countPrevious;
}

void City::setVisitedFrom(const string city) {

    if ( countPrevious = 0) {
        previous = new string[1];
        previous[0] = name;
    }
    else if (!isVisited(city)){
        string* temp = new string [countPrevious+1];
        for ( int i = 0; i < countPrevious; i++) {
            temp[i] = previous[i];
        }

        delete []previous;

        temp[countPrevious] = city;
        previous = temp;
        countPrevious++;
    }
}

void City::setName(string name1) {
    name = name1;
}

void City::unvisitAll(){
    delete []previous;
    previous = NULL;
    countPrevious = 0;
    setVisitedFrom(name);
}

bool City::isVisitedByAll(const int no)const{

    if(countPrevious == no){
        return true;
    }

    return false;
}

string* City::getVisitedFrom(){
    return previous;
}

City& City::operator=( const City& right ) {

    if ( countPrevious != right.countPrevious ) {
        if ( countPrevious > 0 ) {
            delete []previous;
            countPrevious = right.countPrevious;
            previous = new string[countPrevious];
        }
        else
            previous = NULL;
    }
    for ( int i = 0; i < countPrevious; i++ )
        previous[i] = right.previous[i];
    if (right.name != "")
        name = (right.name).c_str();

    visited = right.visited;

    return *this;
}
