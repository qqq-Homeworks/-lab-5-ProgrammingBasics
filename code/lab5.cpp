#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{

    // 5 elements
    int n = 5;
    int *a1 = new int[n];
    int *a2 = new int[n];
    taskFor5(a1, a2);
    delete[] a1;
    delete[] a2;

    // 50 elements
    n = 50;
    a1 = new int[n];
    a2 = new int[n];
    taskFor50(a1, a2);
    delete[] a1;
    delete[] a2;

    // 500 elements
    n = 500;
    a1 = new int[n];
    a2 = new int[n];
    taskFor500(a1, a2);
    delete[] a1;
    delete[] a2;

    return 0;
}

