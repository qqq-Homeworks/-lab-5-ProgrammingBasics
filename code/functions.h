#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <iostream>


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

void bubbleSort(int *arrToSort, int size, int k, bool isPrintNeeded)
{
    //1 - increase, -1 - decrease
    int replaceCount = 0;
    int comparsionCount = 0;
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            comparsionCount++;
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

    std::cout << "sorted(" << size << ") with BubbleSort by ";
    k == 1 ? std::cout << "increace\n" : std::cout << "decreace\n";
    std::cout << "replaceCount = " << replaceCount << " comparsionCount = " << comparsionCount << '\n';
    if (isPrintNeeded)
        printArray(arrToSort, size);
}

void selectSort(int *arrToSort, int size, int k, bool isPrintNeeded)
{
    int replaceCount = 0;
    int comparsionCount = 0;
    int fixed;

    for (int i = 0; i < size - 1; i++)
    {
        fixed = i;
        for (int j = i + 1; j < size; j++)
        {
            comparsionCount++;
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
    std::cout << "sorted(" << size << ") with SelectSort by ";
    k == 1 ? std::cout << "increace\n" : std::cout << "decreace\n";
    std::cout << "replaceCount = " << replaceCount << " comparsionCount = " << comparsionCount << '\n';
    if (isPrintNeeded)
        printArray(arrToSort, size);
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