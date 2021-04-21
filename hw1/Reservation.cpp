#include <iostream>
#include <iomanip>
using namespace std;
#include "Reservation.h"

/**
    Name: Ayda Yurtoğlu
    ID: 21903153
*/

// constructor
Reservation::Reservation() {
    totalResNo = 0;
    reservedRowsArr = NULL;
    reservedColsArr = NULL;
    flightNoArr = NULL;
    passangerNoArr = NULL;
}
// destructor
Reservation::~Reservation() {
    delete[] flightNoArr;

    delete[] passangerNoArr ;


    for ( int i = 0; i < ( sizeof(reservedRowsArr) / sizeof(int)); i++) {
        delete reservedRowsArr[i];
    }

    delete[] reservedRowsArr;


    for ( int i = 0; i < ( sizeof(reservedColsArr) / sizeof(int)); i++) {
        delete reservedColsArr[i];
    }
    delete[] reservedColsArr;

}

// functions
int Reservation::addRes( const int flightNo, const int passangerNo, const int *seatRow, const char *seatCol, const int rno, const int sno){
        if ( totalResNo == 0) {

            flightNoArr = new int[1];
            passangerNoArr = new int[1];
            reservedRowsArr = new int*[1];
            reservedColsArr = new int*[1];

            passangerNoArr[totalResNo] = passangerNo;
            flightNoArr[totalResNo] = flightNo;
            reservedRowsArr[totalResNo] = new int[passangerNo];
            reservedColsArr[totalResNo] = new int[passangerNo];


            for ( int i = 0; i < passangerNo; i++) {
                reservedRowsArr[totalResNo][i] = seatRow[i];
            }

            for ( int i = 0; i < passangerNo; i++) {
                reservedColsArr[totalResNo][i] = letterToInt(seatCol[i]);
            }

            totalResNo++;
            return totalResNo;
        }
        else {
            int reservedSeatCount = 0;
            bool isReserved = false;
            // reserve

            for ( int i = 0; i < passangerNo; i++) {

                if ( seatIsReserved( flightNo, seatRow[i], letterToInt(seatCol[i]))) {

                    cout << seatRow[i] << seatCol[i] << " ";
                    reservedSeatCount++;
                    isReserved = true;
                }
            }

            if ( isReserved) {
                if ( reservedSeatCount == 1) {
                    cout << "is not available." << endl;
                    return -1;
                }
                else {
                    cout << "are not available." << endl;
                    return -1;
                }

            }
            else {
                int* tempFlightNoArr = flightNoArr;
                int* tempPassangerNoArr = passangerNoArr;
                int** tempRows = reservedRowsArr;
                int** tempCols = reservedColsArr;

                tempFlightNoArr = new int [totalResNo+1];
                tempPassangerNoArr = new int [totalResNo+1];
                tempRows = new int*[totalResNo+1];
                tempCols = new int*[totalResNo+1];


                for ( int i = 0; i < totalResNo; i++) {
                    tempFlightNoArr[i] = flightNoArr[i];
                    tempPassangerNoArr[i] = passangerNoArr[i];
                    tempRows[i] = new int[passangerNoArr[i]];
                    tempCols[i] = new int[passangerNoArr[i]];

                    for ( int j = 0; j < passangerNoArr[i]; j++) {

                        tempRows[i][j] = reservedRowsArr[i][j];
                        tempCols[i][j] = reservedColsArr[i][j];
                    }
                }


            for (int i = 0 ; i < totalResNo ; i++)
            {
                delete[] reservedRowsArr[i];
                delete[] reservedColsArr[i];
            }
            delete []reservedRowsArr;
            delete []reservedColsArr;
            delete []flightNoArr;
            delete []passangerNoArr;

            tempFlightNoArr[totalResNo] = flightNo;
            flightNoArr = tempFlightNoArr;

            tempPassangerNoArr[totalResNo] = passangerNo;
            passangerNoArr = tempPassangerNoArr;

            tempRows[totalResNo] = new int[passangerNo];
            tempCols[totalResNo] = new int[passangerNo];

            for ( int i = 0; i < passangerNo; i++) {
                tempRows[totalResNo][i] = seatRow[i];
                tempCols[totalResNo][i] = letterToInt(seatCol[i]);
            }

            reservedRowsArr = tempRows;
            reservedColsArr = tempCols;

            totalResNo++;
            return totalResNo;
        }
    }
}


void Reservation::cancelRes( int resCode) {
    // checks if the given resCode exists in the list
    if ( resCode <= 0 || resCode > totalResNo) {
        cout << "No reservations are found under Code " << resCode << endl;
        cout << endl;
        return;
    }
    else {
        resCode--;
        cout << "Reservation for the seats ";
        for ( int i = 0; i < passangerNoArr[resCode]; i++) {
             cout << reservedRowsArr[resCode][i] << intToLetter(reservedColsArr[resCode][i]) << " ";
        }
        cout << "is canceled in Flight " << flightNoArr[resCode] << endl;


        flightNoArr[resCode] = 0;
        passangerNoArr[resCode] = 0;

        delete reservedRowsArr[resCode];
        delete reservedColsArr[resCode];

        reservedRowsArr[resCode] = NULL;
        reservedColsArr[resCode] = NULL;

        totalResNo--;
    }
}

void Reservation::showRes( const int resCode) {

    if ( resCode <= 0 || resCode > totalResNo) {
        cout << "No reservations under Code " << resCode << endl;
        cout << endl;
        return;
    }
    else {
            if ( passangerNoArr[resCode-1] == 0){
                cout << "No reservations under Code " << resCode << endl;
                cout << endl;
                return;
            }
            else {
                cout << "Reservations under Code " << resCode << " in Flight " << flightNoArr[resCode-1] << ": ";

                for ( int i = 0; i < passangerNoArr[resCode-1]; i++) {
                    cout << reservedRowsArr[resCode-1][i] << intToLetter(reservedColsArr[resCode-1][i]) << " ";
                }
                cout << "\n" << endl;
            }
    }
}

void Reservation::cancelAllResFor( const int flightNo) {
    if ( totalResNo <= 0) {
        cout << "There are no reservations to cancel" << endl;
    }
    else {
        for ( int i = 0; i < totalResNo; i++) {
            if ( flightNoArr[i] == flightNo){
                flightNoArr[i] = 0;
                passangerNoArr[i] = 0;

                delete reservedRowsArr[i];
                delete reservedColsArr[i];

                reservedRowsArr[i] = NULL;
                reservedColsArr[i] = NULL;
            }
        }
    }
}

bool Reservation::flightHasRes( const int flightNo) {
    if ( totalResNo == 0) {
        return false;
    }

    for ( int i = 0; i < totalResNo; i++){
        if ( flightNoArr[i] == flightNo) {
            return true;
        }
    }

    return false;
}

bool Reservation::seatIsReserved( const int flightNo , const int row, const int col) {

    if ( totalResNo == 0 ) {
        return false;
    }
    else {

        for( int i = 0 ; i < totalResNo; i++) {
            for ( int j = 0 ; j < passangerNoArr[i]; j++) {
                if ( reservedRowsArr[i][j] == row && reservedColsArr[i][j] == col ){
                    return true;
                }
            }
        }
    }
    return false;
}

int Reservation::getFlightNo( const int resCode) {
    if ( resCode > 0 && resCode <= totalResNo) {
        return flightNoArr[resCode-1];
    }
    return -1;
}

int Reservation::getPassangerNo( const int resCode) {
    if ( resCode > 0 && resCode <= totalResNo) {
        return passangerNoArr[resCode-1];
    }
    return -1;
}

int Reservation::letterToInt( const char character) {
    return (int) ( character - 'A' );
}

char Reservation::intToLetter( const int number ) {
    if ( number >= 0 && number <= 25 )
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[number];
    }
    return '-';
}


