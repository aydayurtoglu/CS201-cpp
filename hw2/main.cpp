#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

void func1( int*, int*, int, int*&);
void func2( int*, int*, int, int*&);

void printArray( int*, int);

int main()
{
    int n = 10;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers between 0 and 10
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 100 + 1; // Random numbers are between 0 and 100
        arr2[i] = rand() % 100 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 100;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 100 + 1; // Random numbers are between 0 and 100
        arr2[i] = rand() % 100 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 1000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000 + 1; // Random numbers are between 0 and 1000
        arr2[i] = rand() % 1000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 5000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000 + 1; // Random numbers are between 0 and 1000
        arr2[i] = rand() % 1000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 10000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000 + 1; // Random numbers are between 0 and 1000
        arr2[i] = rand() % 1000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 25000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 5000 + 1; // Random numbers are between 0 and 5000
        arr2[i] = rand() % 5000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 50000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 8000 + 1; // Random numbers are between 0 and 8000
        arr2[i] = rand() % 8000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;
    cout << endl;
    n = 75000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 8000 + 1; // Random numbers are between 0 and 8000
        arr2[i] = rand() % 8000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 100000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 8000 + 1; // Random numbers are between 0 and 8000
        arr2[i] = rand() % 8000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 200000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1

    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 8000 + 1; // Random numbers are between 0 and 8000
        arr2[i] = rand() % 8000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;
    n = 500000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // Codes for function1 are commented because they took hours to be completed
    // FUNC1
/*    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
*/
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
/*    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;
*/
    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1
/*
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;
*/
    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 8000 + 1; // Random numbers are between 0 and 8000
        arr2[i] = rand() % 8000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    cout << endl;

    n = 5000000;
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    cout << "INPUT N = " << n << endl;
    // CASE 1: all numbers in arr1 are smaller than arr2
    // FUNC1
/*    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    cout << "Case i, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
*/
    for ( int i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i+n;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case i, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 2: all numbers in arr2 are smaller than arr1
    // FUNC1
/*
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;
*/
    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];

    for ( int i = 0; i < n; i++) {
        arr1[i] = i+n;
        arr2[i] = i;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }
    cout << "Case ii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    // CASE 3: initialize arrays with rand() and sort() functions, case (iii)
    // FUNC1
/*
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];


    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 10 + 1; // Random numbers
        arr2[i] = rand() % 10 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    cout << "Case iii, func1" << endl;
    func1( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;
*/
    // FUNC2
    arr1 = new int[n];
    arr2 = new int[n];
    arr3 = new int[2*n];
    for ( int i = 0; i < n; i++) {
        arr1[i] = rand() % 8000 + 1; // Random numbers are between 0 and 8000
        arr2[i] = rand() % 8000 + 1;
    }

    for ( int i = 0; i < 2*n; i++) {
        arr3[i] = 0;
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    // call function 2
    cout << "Case iii, func2" << endl;
    func2( arr1, arr2, n, arr3);

    delete []arr1;
    delete []arr2;
    delete []arr3;

    return 0;
}

void func1( int* arr1, int* arr2, int n, int *&arr3) {
    std::chrono::time_point< std::chrono::system_clock > startTime1 = std::chrono::system_clock::now();


    for ( int i = 0; i < n; i++){
        arr3[i] = arr1[i];
    }

    int arraySize = n;

    for ( int i = 0 ; i < n; i++) {

        int item = arr2[i];
        int k = 0;

        while( k < arraySize ){
            if ( item <= arr3[k] ){
                // shifting arr3 items
                for ( int j = arraySize-1; j >= k; j--) {
                    arr3[j+1] = arr3[j];
                }
                arr3[k] = item;
                arraySize++;
                k = arraySize;
            }
            else {
                k++;
            }
        }
    }

    while (arraySize < 2*n) {
        arr3[arraySize] = arr2[arraySize-n];
        arraySize++;
    }

    std::chrono::duration< double, std::milli > elapsedTime1 = std::chrono::system_clock::now() - startTime1;
    cout << "Time difference = " << elapsedTime1.count() << " milliseconds." << endl;
}

void func2 ( int* arr1, int* arr2, int n, int *&arr3){

    std::chrono::time_point< std::chrono::system_clock > startTime1 = std::chrono::system_clock::now();


    int i, j, k = 0;
    for ( i, j = 0; i < n && j < n; k++) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        }
        else {
            arr3[k] = arr2[j];
            j++;
        }
    }

    // copy the remaining elements of arr1 or arr2 to arr3
    while ( i < n) {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while ( j < n) {
        arr3[k] = arr2[j];
        k++;
        j++;
    }

    std::chrono::duration< double, milli > elapsedTime1 = std::chrono::system_clock::now() - startTime1;
    cout << "Time difference = " << elapsedTime1.count() << " milliseconds." << endl;
}
