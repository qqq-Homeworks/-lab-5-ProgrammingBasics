#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <iostream>
#include "functions.h"
#include "template.h"

const int minTaskNumber = 1;
const int maxTaskNumber = 2;

using namespace std;

int main()
{

    introduce("Danila Polyakov", "polyakovdd@student.bmstu.ru");
    bool continueq = true;
    int selectedTask = -1;
    while (continueq)
    {
        enterTaskNumber(selectedTask, minTaskNumber, maxTaskNumber);

        switch (selectedTask)
        {
        case 1:
            task1(5);
            break;
        case 2:
            task2();
            break;
        case -1:
        {
            exit(continueq);
            break;
        }

        default:
            break;
        }
    }

    return 0;
}
