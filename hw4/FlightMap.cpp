#include "FlightMap.h"
#include "FlightInfo.h"
#include "City.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
/**
    Name: Ayda Yurtoglu
    ID: 21903153
*/
using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile)
{
    ifstream cityfile(cityFile.c_str());
    ifstream flightfile(flightFile.c_str());

    // initialize graph
    no = countLine(cityFile);
    edgeNo = 0;

    // adding cities to array
    cities = new City*[no];
    string city;
    for( int i = 0; getline(cityfile,city); i++)
    {
        cities[i] = new City(city);
    }

    adj = new FlightInfo**[no];

    for( int i = 0; i < no; i++) {
        adj[i] = new FlightInfo*[no];

        for( int j = 0; j < no; j++) {
            adj[i][j] = new FlightInfo();
        }
    }

    // add edges according to the flightFile
    // set properties of flightInfo
    string stringId;
    string stringCost;
    string origin;
    string destination;
    int id;
    int cost;

    string line;
    for( int i = 0; getline(flightfile,line); i++)
    {
        stringstream   linestream(line);
        string         text;

        for( int j = 0; getline(linestream, text, ','); j++)
        {
            switch(j) {
                case 0: origin = text;
                case 1: destination = text;
                case 2: stringId = text;
                default: cout << "";
            }

        }
        stringCost = text;

        stringstream ssid(stringId);
        ssid >> id;

        stringstream sscost( stringCost);
        sscost >> cost;

        for (int a = 0; a < no; a++) {

            for (int b = 0; b < no; b++) {

                if ( cities[a] -> getName() == origin && cities[b] -> getName() == destination) {
                    addEdge(a, b, origin, destination, id, cost);

                }
            }
        }
    }
}

FlightMap::~FlightMap()
{
    for (int a = 0; a < no; a++) {
        for (int b = 0; b < no; b++) {
            delete adj[a][b];
        }
        delete []adj[a];
    }

    if ( adj != NULL) {
        delete []adj;
    }

    for ( int i = 0; i < no; i++) {
        delete cities[i];
    }

    if ( cities != NULL) {
        delete []cities;
    }

}

// public functions
void FlightMap::displayAllCities() const{
    for (int i = 0; i < no; i++) {
        cout << cities[i] -> getName() << ", ";
    }
    cout << endl;
}

void FlightMap::displayAdjacentCities( const string cityName ) const{
    cout << cityName << " -> ";

    for( int i = 0; i < no; i++){
        if( isAdjacent(cityName, cities[i])){
            cout << cities[i] -> getName()<< ", ";
        }
    }
}
void FlightMap::displayFlightMap() const{
    for (int i = 0; i < no; i++) {
        string cityName = cities[i]-> getName();

        cout << cityName << " -> ";

        for( int i = 0; i < no; i++){
            if( isAdjacent(cityName, cities[i])){
                cout << cities[i]-> getName() << ", ";
            }
        }
        cout << endl;
    }
    setAllUnvisited();

}
void FlightMap::findFlights( const string deptCity, const string destCity ) const{
    int pathNo = 0;
    string* arr = new string[0];
    int cost = 0;
    int index2 = -1;
    for ( int i = 0; i < no; i++){
        if ( destCity == cities[i]-> getName() ){
            index2 = i;
            i = no;
        }
    }
    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;
    while(findPath(deptCity,destCity,cost, pathNo, arr)){

    }
    delete []arr;
    setAllUnvisited();

}
void FlightMap::findLeastCostFlight( const string deptCity, const string destCity )const{


    int minPathNo = 0;
    int pathNo = 0;
    int minCost = 0;
    int totalCost = 0;

    int index2 = -1;
    for ( int i = 0; i < no; i++){
        if ( destCity == cities[i]-> getName() ){
            index2 = i;
            i = no;
        }
    }

    int count = 0;

    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;

    string *arr = new string[pathNo];
    bool check = findPath(deptCity, destCity, totalCost, pathNo, arr);
    for (int i = 0; i < pathNo; i++){

    }
    minCost = totalCost;
    minPathNo = pathNo;

    string* minArr = new string[minPathNo];

    for (int i = 0; i < minPathNo; i++){
        minArr[i] = arr[i];
    }

    if (check){
        while(findPath(deptCity, destCity, totalCost, pathNo, arr)){
            if (totalCost < minCost){
                minCost = totalCost;
                minPathNo = pathNo;

                delete []minArr;
                minArr = new string[minPathNo];

                for (int i = 0; i < minPathNo; i++){
                    minArr[i] = arr[i];
                }
            }
        }
    }

    cout << "A least cost path from " << deptCity << " to " << destCity << " is ";

    for (int i = 0; i < minPathNo; i++){
        cout << minArr[i] << "->"<<endl;
    }

    cout << " and its cost is " << minCost << " TL" << endl;

    if ( arr != NULL)
        delete []arr;

    if ( minArr != NULL)
        delete []minArr;

    setAllUnvisited();
}

void FlightMap::runFlightRequests( const string requestFile ) const{

    ifstream request(requestFile.c_str());

    string deptCity;
    string destCity;

    string line;
    for( int i = 0; getline(request,line); i++)
    {
        stringstream   linestream(line);

        getline(linestream, deptCity, ',');
        getline(linestream, destCity);
        findLeastCostFlight(deptCity,destCity);
    }

}

// private functions
void FlightMap::addEdge(int a, int b, string origin, string destination, int id, int cost){

    delete adj[a][b];
    delete adj[b][a];

    adj[a][b] = new FlightInfo( origin, destination, id, cost);
    adj[b][a] = new FlightInfo( origin, destination, id, cost);
}


void FlightMap::setAllUnvisited() const{
    for ( int i = 0; i < no; i++){
       cities[i]->unvisitAll();
    }
}

int FlightMap::countLine(const string file) {
    ifstream file1(file.c_str());
    int count = 0;
    string line1;
    while(getline(file1, line1))
        count++;

    return count;
}

bool FlightMap::isAdjacent( string origin, City* destination) const {

    int index = -1;
    for ( int i = 0; i < no; i++){
        if ( origin == cities[i]-> getName() ){
            index = i;
            i = no;
        }
    }

    for ( int i = 0; i < no; i++){
       if(adj[index][i] -> getDestination() == destination -> getName() && origin != destination-> getName() && !destination->isVisited(origin)){
            return true;
       }
    }
    return false;
}

bool FlightMap::flightsExist(string origin) const {

    for ( int i = 0; i < no; i++){
        if ( isAdjacent(origin, cities[i])){
            return true;
        }
    }
    return false;
}


bool FlightMap::findPath(const string deptCity, const string destCity, int &total, int &pathNo, string *&stackElements) const {

    Stack searchStack;
    int index = -1;
    for ( int i = 0; i < no; i++){
        if ( deptCity == cities[i]-> getName() ){
            index = i;
            i = no;
        }
    }
    //cout << cities[index]->getName() << " pushed"<<endl;
    searchStack.push(cities[index]->getName());

    // find the destination city object
    int index2 = -1;
    for ( int i = 0; i < no; i++){
        if ( destCity == cities[i]-> getName() ){
            index2 = i;
            i = no;
        }
    }
    int cost = 0;
    int id = 0;
    string nextCity = deptCity;
    string topC = "";
    searchStack.getTop(topC);
    int length = 1;

    // search algorithm
        while (!searchStack.isEmpty() && nextCity != destCity ) {
            searchStack.getTop(topC);

            if (  !flightsExist(topC) ){

                int index5 = -1;
                for ( int i = 0; i < no; i++){
                    if ( topC == cities[i]-> getName() ){
                        index5 = i;
                        i = no;
                    }
                }
                searchStack.pop();
                //cout << topC << " popped1" << endl;

                string top = "";
                searchStack.getTop(top);
                cities[index2]->setVisitedFrom(topC);
                length--;

                cities[index5]->setVisitedFrom(top);

            }
            else {
                bool resume = true;

                string* path = searchStack.getItems(length);

                for ( int i = 0; i < length; i++){
                    if(findAdj(topC)==path[i]){
                        resume = false;
                    }

                }
                delete []path;

                if(resume){


                    searchStack.push(findAdj(topC));

                    nextCity = findAdj(topC);
                    //cout << nextCity << " pushed" << endl;

                    int index5 = -1;
                    for ( int i = 0; i < no; i++){
                        if ( nextCity == cities[i]-> getName() ){
                            index5 = i;
                            i = no;
                        }
                    }


                    cities[index5] -> setVisitedFrom(topC);
                   // cout << nextCity << " setvisitedfrom "<< topC<<endl;
                    length++;
                }
                else {
                    searchStack.pop();

                    int index3 = -1;
                    for ( int i = 0; i < no; i++){
                        if ( topC == cities[i]-> getName() ){
                            index3 = i;
                            i = no;
                        }
                    }

                   //cout << topC << " p1opped" << endl;
                    string top = "";
                    searchStack.getTop(top);
                    cities[index3]->setVisitedFrom(top);
                    length--;
                }
            }
        }

        if (nextCity == destCity){

          /*  if(flightsExistTo(topC)){
                //cities[index2]->unvisitAll();
               string top = "";

                //searchStack.pop();
                searchStack.getTop(top);

                int index3 = -1;
                for ( int i = 0; i < no; i++){
                    if ( topC == cities[i]-> getName() ){
                        index3 = i;
                        i = no;
                    }
                }


                cities[index3]->setVisitedFrom(deptCity);
            }*/


            string* path = searchStack.getItems(length);
            int totalCost = 0;
            if (stackElements != NULL) {
                delete []stackElements;
            }
            stackElements = new string[length];

            for (int i = 0; i < length; i++) {
                stackElements[i] = path[i];
            }
            for ( int i = 0; i < length-1; i++) {

                findEdge(path[i], path[i+1], id, cost);

                totalCost = totalCost + cost;
                cout << "Flight #" << id << " from " << path[i] << " to " << path[i+1]<< " Cost: " << cost << " TL" << endl;
            }
            cout << "Total " << "............" << totalCost << " TL" << endl;
            total = totalCost;
            cout << endl;

            if ( path != NULL)
                delete []path;
        }
        else {
            if (total == 0){
             cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
             cout << endl;
            }
        }
    if (nextCity == destCity){
        return true;
    }
    else {
        return false;
    }
}

string FlightMap::findAdj(string origin )const{
    if (origin != "") {
        for ( int i = 0; i < no; i++){

            if (isAdjacent(origin, cities[i])) {
                return cities[i]->getName();
            }
        }
    }
    return "";
}

bool FlightMap::findEdge(string origin, string dest, int &id, int &cost )const{

    int index = -1; // index of origin
    for ( int i = 0; i < no; i++){
        if ( origin == cities[i] -> getName() ){
            index = i;
            i = no;
        }
    }

    for ( int i = 0; i < no; i++){

        if (adj[index][i]->getDestination()== dest) {

            id = adj[index][i] -> getId();
            cost = adj[index][i] -> getCost();

            return true;
        }
    }
    return false;
}

bool FlightMap::flightsExistTo(string origin) const{
    for (int i = 0; i < no; i++){
        if(findAdj(cities[i]->getName()) != "") {
           if( findAdj(cities[i]->getName()) == origin){
                return true;
           }
        }
    }
    return false;
}

//bool FlightMap::isVisitedByAll(City* dest) const {
//    int index = -1; // index of destination
//    for ( int i = 0; i < no; i++){
//        if ( dest-> getName() == cities[i] -> getName() ){
//            index = i;
//            i = no;
//        }
//    }
//
//    for ( int i = 0; i < no; i++){
//
//        if (adj[index][i]->getDestination()== dest-> getName()) {
//
//           if (!dest->isVisited(adj[index][i]->getOrigin())){
//                return false;
//           }
//        }
//    }
//    return true;
//}
//
//bool FlightMap::transferExists(City* origin, City* dest) const{
//
//    return false;
//}
