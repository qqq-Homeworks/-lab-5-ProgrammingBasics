#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <iostream>
#include "functions.h"


using namespace std;


int main() {

    // 5 elements
    int n = 5;
    int *a1 = new int[n];
    int *a2 = new int[n];
    generateArrays(a1, a2, 5);

    cout << "Array before sort:\n";
    printArray(a1, 5);
    cout << "\n\t\tSORTING DEFAULT RANDOM ARRAY:\n";
    bubbleSort(a1, 5, -1, true);
    selectSort(a2, 5, -1, true);
    cout << "\n\t\tSORTING INCREASED ARRAY:\n";
    bubbleSort(a1, 5, -1, true);
    selectSort(a2, 5, -1, true);
    cout << "\n\t\tSORTING DECREASED ARRAY:\n";
    bubbleSort(a1, 5, 1, true);
    selectSort(a2, 5, 1, true);

    delete[] a1;
    delete[] a2;

    // 50 elements
    n = 50;
    a1 = new int[n];
    a2 = new int[n];
    generateArrays(a1, a2, 50);

    cout << "\n\t\tSORTING DEFAULT RANDOM ARRAY:\n";
    bubbleSort(a1, 50, -1, false);
    selectSort(a2, 50, -1, false);
    cout << "\n\t\tSORTING INCREASED ARRAY:\n";
    bubbleSort(a1, 50, -1, false);
    selectSort(a2, 50, -1, false);
    cout << "\n\t\tSORTING DECREASED ARRAY:\n";
    bubbleSort(a1, 50, 1, false);
    selectSort(a2, 50, 1, false);

    delete[] a1;
    delete[] a2;

    // 500 elements
    n = 500;
    a1 = new int[n];
    a2 = new int[n];
    generateArrays(a1, a2, 500);

    cout << "\n\t\tSORTING DEFAULT RANDOM ARRAY:\n";
    bubbleSort(a1, 500, -1, false);
    selectSort(a2, 500, -1, false);
    cout << "\n\t\tSORTING INCREASED ARRAY:\n";
    bubbleSort(a1, 500, -1, false);
    selectSort(a2, 500, -1, false);
    cout << "\n\t\tSORTING DECREASED ARRAY:\n";
    bubbleSort(a1, 500, 1, false);
    selectSort(a2, 500, 1, false);

    delete[] a1;
    delete[] a2;


    return 0;
}

