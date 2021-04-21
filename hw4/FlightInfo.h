#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H
#include <iostream>
#include <string>

using namespace std;

class FlightInfo
{
    public:
        FlightInfo();
        FlightInfo( string origin1, string destination1, int id1, int cost1);
        ~FlightInfo();

        // get functions
        string getOrigin();
        string getDestination();
        int getId();
        int getCost();

        // set functions
        void setOrigin( const string city);
        void setDestination( const string city);
        void setId( const int thisId);
        void setCost( const int thisCost);

    private:
        string origin;
        string destination;
        int id;
        int cost;
};

#endif // FLIGHTINFO_H
