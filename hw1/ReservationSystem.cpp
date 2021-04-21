#include <iostream>
using namespace std;
#include "ReservationSystem.h"

/**
    Name: Ayda Yurtoğlu
    ID: 21903153
*/

// constructors
ReservationSystem::ReservationSystem() {
    totalFlightNo = 0;
    totalResNo = 0;
    flightsArr = NULL;
}

ReservationSystem::~ReservationSystem() {
    for ( int i = 0; i < totalFlightNo; i++) {
        delete flightsArr[i];
    }

    if ( flightsArr != NULL) {
        delete[] flightsArr;
    }
}

// functions

void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo ){ // WORKS

    // checks if the numbers are positive
    if ( flightNo <= 0 || rowNo <= 0 || seatNo <= 0) {
        cout << "invalid input" << endl;
        return;
    }

    // checks if the flight no exists
    for ( int i  = 0; i < totalFlightNo; i++){
        if ( flightsArr[i] -> getFlightNo() == flightNo){
            cout << "Flight "<< flightNo << " already exists. \n" << endl;
            return;
        }
    }

    // adds the flight to the list
    Flight** temp = new Flight* [totalFlightNo+1];
    for ( int i = 0; i < totalFlightNo; i++) {
        temp[i] = flightsArr[i];
    }

    delete []flightsArr;

    temp[totalFlightNo] = new Flight( flightNo, rowNo, seatNo);
    flightsArr = temp;
    totalFlightNo++;

    cout << flightNo << " has been added to the list." << endl;
}

void ReservationSystem::cancelFlight( const int flightNo ) { // WORKS

    // checks if the given flightNo is positive
    if ( flightNo <= 0){
        cout << "invalid input" << endl;
    }
    else {

    // checks if the given flightNo exists in the list
    int index = -1; // index of the flight no
    for ( int i = 0; i < totalFlightNo; i++){
        if ( flightsArr[i] -> getFlightNo() == flightNo){
            index = i;
            i = totalFlightNo;
        }
    }

    if ( index == -1) {
        cout << "Flight number " << flightNo << " does not exist." << endl;
        return;
    }

    // cancels the flight
    Flight** temp = new Flight*[totalFlightNo-1];

    for ( int i = 0; i < index; i++) {
        temp[i] = flightsArr[i];
    }

    for ( int i = index + 1; i < totalFlightNo; i++) {
        temp[i-1] = flightsArr[i];
    }

    delete flightsArr[index];
    delete[] flightsArr;

    flightsArr = temp;
    totalFlightNo--;

    res.cancelAllResFor( flightNo);

    cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;
    }
}

void ReservationSystem::showAllFlights() { // NEEDS ADJUSTMENT
    if ( totalFlightNo == 0) {
        cout << "No flights exist. \n" << endl;
    }
    else {
        cout << "Flights currently operated: " << endl;
        for ( int i = 0; i < totalFlightNo; i++) {
            cout << "Flight " << flightsArr[i] -> getFlightNo() << " (" << flightsArr[i] -> getAvailableSeatNo() << " available seats)" << endl;
        }
        cout << endl;
    }
}

void ReservationSystem::showFlight( const int flightNo ) { // NEEDS ADJUSTMENT
    // checks if the given flightNo is positive
    if ( flightNo <= 0){
        cout << "invalid input" << endl;
    }
    else {

    // checks if the given flightNo exists in the list
    int index = -1; // index of the flight no in the array

    for ( int i = 0; i < totalFlightNo; i++){
        if ( flightsArr[i] -> getFlightNo() == flightNo){
            index = i;
            i = totalFlightNo;
        }
    }

    if ( index == -1) {
        cout << "Flight number " << flightNo << " does not exist." << endl;
        return;
    }

    // shows details
    cout << "Flight " << flightsArr[index] -> getFlightNo() << " has " << flightsArr[index] -> getAvailableSeatNo() << " available seats." << endl;

    showDetailedInformation( flightNo);

    }
}

int ReservationSystem::makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol ) {

    int index = -1; // index of the flight no
    for ( int i = 0; i < totalFlightNo; i++){
        if ( flightsArr[i] -> getFlightNo() == flightNo){
            index = i;
            i = totalFlightNo;
        }
    }

    if ( index == -1) {
        cout << "Flight number " << flightNo << " does not exist." << endl;
        return -1;
    }

    int rno = flightsArr[index] -> getRowNo();
    int sno = flightsArr[index] -> getSeatNo();



    int resCode = res.addRes( flightNo, numPassengers, seatRow, seatCol, rno, sno);

    if ( resCode != -1 ) {

        flightsArr[index] -> increaseResNoBy( numPassengers);
        totalResNo++;

        return totalResNo;
    }
    else {
        return resCode;
    }

}

void ReservationSystem::cancelReservation( const int resCode) {

    int flightNo = res.getFlightNo( resCode);
    int numPassengers = res.getPassangerNo( resCode);

    int index = -1; // index of the flight no
    for ( int i = 0; i < totalFlightNo; i++){
        if ( flightsArr[i] -> getFlightNo() == flightNo){
            index = i;
            i = totalFlightNo;
        }
    }

    res.cancelRes( resCode);
    if ( index == -1) {
        return;
    }
    flightsArr[index] -> decreaseResNoBy( numPassengers);

}

void ReservationSystem::showReservation( const int resCode) {
    return res.showRes( resCode);
}

void ReservationSystem::showDetailedInformation( const int flightNo) {

    if( totalFlightNo != 0)
    {
        for( int i = 0 ; i < totalFlightNo ; i++)
        {
            if( flightsArr[i] -> getFlightNo() == flightNo )
            {
                for( int j = 0 ; j < flightsArr[i] -> getSeatNo() + 1 ; j++)
                {
                    if( j == 0 )
                    {
                            cout << "   ";
                    }
                    else
                    {
                        cout << intToLetter(j-1) << "  " ;
                    }
                }
                cout << endl;

                for( int j = 0 ; j < flightsArr[i] -> getRowNo() ; j++)
                {
                   cout << j + 1 << "  " ;

                    if( !res.flightHasRes(flightNo))
                    {
                        for( int k = 0 ; k < flightsArr[i] -> getSeatNo() ; k++)
                        {
                            cout << "o  ";
                        }
                        cout << endl;
                    }
                    else
                    {
                        for( int k = 0 ; k < flightsArr[i] -> getSeatNo() ; k++)
                        {
                            if( res.seatIsReserved( flightNo, j + 1, k ))
                            {
                                cout << "x  ";
                            }
                            else
                            {
                                cout <<"o  ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
}

char ReservationSystem::intToLetter( const int number )
{
    if (number >= 0 && number <= 25 )
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[number];
    }
    return '-';
}

