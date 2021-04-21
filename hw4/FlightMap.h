#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include "City.h"
#include "FlightInfo.h"
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;
/**
    Name: Ayda Yurtoglu
    ID: 21903153
*/
class FlightMap {
    public:

        FlightMap( const string cityFile, const string flightFile );
        ~FlightMap();

        void displayAllCities() const;
        void displayAdjacentCities( const string cityName ) const;
        void displayFlightMap() const;
        void findFlights( const string deptCity, const string destCity ) const;
        void findLeastCostFlight( const string deptCity, const string destCity )const;
        void runFlightRequests( const string requestFile ) const;

    private:

        // to store the graph using adjacency matrix
        int no; // number of cities
        int edgeNo;
        FlightInfo ***adj;
        City** cities;

        void addEdge(int a, int b, string origin, string destination, int id, int cost);
        void setAllUnvisited()const;
        int countLine( const string file);
        bool isAdjacent(string origin, City* destination) const;
        bool flightsExist(string origin) const;
        bool findPath(const string deptCity, const string destCity, int &total, int &pathNo, string *&stackElements) const;
        string findAdj(string origin )const;
        bool findEdge(string origin, string dest, int &id, int &cost )const;
        bool flightsExistTo(string origin) const;
        //bool isVisitedByAll(City* dest) const;
        //bool transferExists(City* origin, City* dest) const;
};

#endif // FLIGHTMAP_H
