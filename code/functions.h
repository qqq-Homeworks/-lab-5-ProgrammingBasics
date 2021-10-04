#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <iostream>
#include <iomanip>

int iRandom(int a, int b)
{
    return a + rand() % (b - a);
}

void printArray(int *arrToPrint, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arrToPrint[i] << ' ';
    }
    std::cout << "\n\n";
}

void bubbleSort(int *arrToSort, int size, int k, int &replaceCount, int &comparasionCount, bool isPrintNeeded)
{
    //1 - increase, -1 - decrease
    replaceCount = 0;
    comparasionCount = 0;
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            comparasionCount++;
            if (arrToSort[j] * k > arrToSort[j + 1] * k)
            {
                replaceCount++;
                swapped = true;
                std::swap(arrToSort[j], arrToSort[j + 1]);
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    if (isPrintNeeded)
    {
        std::cout << "sorted(" << size << ") with BubbleSort by ";
        k == 1 ? std::cout << "increace\n" : std::cout << "decreace\n";
        std::cout << "replaceCount = " << replaceCount << " comparsionCount = " << comparasionCount << '\n';
        printArray(arrToSort, size);
    }
}

void selectSort(int *arrToSort, int size, int k, int &replaceCount, int &comparasionCount, bool isPrintNeeded)
{
    replaceCount = 0;
    comparasionCount = 0;
    int fixed;

    for (int i = 0; i < size - 1; i++)
    {
        fixed = i;
        for (int j = i + 1; j < size; j++)
        {
            comparasionCount++;
            if (k * arrToSort[j] < k * arrToSort[fixed])
            {
                fixed = j;
            }
        }
        if (fixed != i)
        {
            std::swap(arrToSort[fixed], arrToSort[i]);
            replaceCount++;
        }
    }
    if (isPrintNeeded)
    {
        std::cout << "sorted(" << size << ") with SelectSort by ";
        k == 1 ? std::cout << "increace\n" : std::cout << "decreace\n";
        std::cout << "replaceCount = " << replaceCount << " comparsionCount = " << comparasionCount << '\n';
        printArray(arrToSort, size);
    }
}

void generateArrays(int *arrayToFill1, int *arrayToFill2, int size)
{
    srand((unsigned int)time(NULL));
    rand();
    for (int i = 0; i < size; i++)
    {
        arrayToFill1[i] = iRandom(1, 9);
        arrayToFill2[i] = arrayToFill1[i];
    }
}
void task1(int n)
{
    int *a1 = new int[n];
    int *a2 = new int[n];
    int replaceCount, comparsionCount;
    int &rc = replaceCount;
    int &cc = comparsionCount;
    generateArrays(a1, a2, n);
    std::cout << "Array before sort:\n";
    printArray(a1, n);
    std::cout << "\n\t\tSORTING DEFAULT RANDOM ARRAY:\n";
    bubbleSort(a1, n, -1,rc, cc, 1);
    selectSort(a2, n, -1, rc, cc, 1);
    std::cout << "\n\t\tSORTING INCREASED ARRAY:\n";
    bubbleSort(a1, n, -1, rc, cc, 1);
    selectSort(a2, n, -1, rc, cc, 1);
    std::cout << "\n\t\tSORTING DECREASED ARRAY:\n";
    bubbleSort(a1, n, 1, rc, cc, 1);
    selectSort(a2, n, 1, rc, cc, 1);
    delete[] a1;
    delete[] a2;
}
void task2()
{
    std::cout << "\t\tN\treplaces\tcomparions\n";
    int replaceCount, comparsionCount;
    int &rc = replaceCount;
    int &cc = comparsionCount;
    for (int i = 5; i < 501; i *= 10)
    {
        int *a1 = new int[i];
        int *a2 = new int[i];

        generateArrays(a1, a2, i);
        bubbleSort(a1, i, 1, rc, cc, 0);
        std::cout << "buble sort:  " << std::setw(5) << i << std::setw(12) << replaceCount << std::setw(16) << comparsionCount << std::endl;
        selectSort(a2, i, 1, rc, cc, 0);
        std::cout << "select sort: " << std::setw(5) << i << std::setw(12) << replaceCount << std::setw(16) << comparsionCount << std::endl;
        delete[] a1;
        delete[] a2;
        std::cout << "------------------------------------------------------------\n";
    }
}