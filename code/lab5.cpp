#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <iostream>

using namespace std;

int iRandom(int a, int b);

void printArray(int *arrToPrint, int size);

void bubbleSort(int *arrToSort, int size, int k, bool isPrintNeeded);

void selectSort(int *arrToSort, int size, int k, bool isPrintNeeded);

void generateArrays(int *arrayToFill1, int *arrayToFill2, int size);

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

int iRandom(int a, int b) {
    return a + rand() % (b - a);
}

void printArray(int *arrToPrint, int size) {
    for (int i = 0; i < size; i++) {
        cout << arrToPrint[i] << ' ';
    }
    cout << "\n\n";
}

void bubbleSort(int *arrToSort, int size, int k, bool isPrintNeeded) {
    //1 - increase, -1 - decrease
    int replaceCount = 0;
    int comparsionCount = 0;
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            comparsionCount++;
            if (arrToSort[j] * k > arrToSort[j + 1] * k) {
                replaceCount++;
                swapped = true;
                swap(arrToSort[j], arrToSort[j + 1]);
            }

        }
        if (!swapped) {
            break;
        }
    }

    cout << "sorted(" << size << ") with BubbleSort by ";
    k == 1 ? cout << "increace\n" : cout << "decreace\n";
    cout << "replaceCount = " << replaceCount << " comparsionCount = " << comparsionCount << endl;
    if (isPrintNeeded)
        printArray(arrToSort, size);
}

void selectSort(int *arrToSort, int size, int k, bool isPrintNeeded) {
    int replaceCount = 0;
    int comparsionCount = 0;
    int fixed;

    for (int i = 0; i < size - 1; i++) {
        fixed = i;
        for (int j = i + 1; j < size; j++) {
            comparsionCount++;
            if (k * arrToSort[j] < k * arrToSort[fixed]) {
                fixed = j;
            }
        }
        if (fixed != i) {
            swap(arrToSort[fixed], arrToSort[i]);
            replaceCount++;
        }
    }
    cout << "sorted(" << size << ") with SelectSort by ";
    k == 1 ? cout << "increace\n" : cout << "decreace\n";
    cout << "replaceCount = " << replaceCount << " comparsionCount = " << comparsionCount << endl;
    if (isPrintNeeded)
        printArray(arrToSort, size);
}

void generateArrays(int *arrayToFill1, int *arrayToFill2, int size) {

    srand((unsigned int) time(NULL));
    rand();
    for (int i = 0; i < size; i++) {
        arrayToFill1[i] = iRandom(1, 9);
        arrayToFill2[i] = arrayToFill1[i];
    }
}