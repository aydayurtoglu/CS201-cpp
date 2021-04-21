#include "FlightInfo.h"
#include <iostream>

using namespace std;

FlightInfo::FlightInfo()
{
    origin = "";
    destination = "";
    id = 0;
    cost = 0;
}

FlightInfo::FlightInfo( string origin1, string destination1, int id1, int cost1)
{
    origin = origin1;
    destination = destination1;
    id = id1;
    cost = cost1;
}

FlightInfo::~FlightInfo()
{
    origin = "";
    destination = "";
    id = 0;
    cost = 0;
}

string FlightInfo::getOrigin(){
    return origin;
}
string FlightInfo::getDestination(){
    return destination;
}
int FlightInfo::getId(){
    return id;
}
int FlightInfo::getCost(){
    return cost;
}
