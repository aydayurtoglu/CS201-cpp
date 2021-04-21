#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
/**
    Name: Ayda Yurtoglu
    ID: 21903153
*/
using namespace std;

class City
{
    public:
        City();
        City(const string name1);
        ~City();

        bool isVisited();
        bool isVisited(const string city);
        string getName();
        int getCount();

        void setVisited( bool visited);
        void setVisitedFrom(string city);
        void setName(string name1);
        void unvisitAll();
        bool isVisitedByAll(const int no)const;
        string* getVisitedFrom();
        City& operator=( const City& right );

    private:
        string name;
        bool visited;
        string* previous;
        int countPrevious;
};

#endif // CITY_H
