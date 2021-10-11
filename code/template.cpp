#include "template.h"

void introduce(const std::string &authorsName, int sex)
{
    std::cout << "\n\n\tПриветствую!\n\n";

    std::cout << '\t' << authorsName << " выполнил";
    if (sex == FEMALE)
        std::cout << 'a';
    std::cout << " данную лабораторную работу.\n\n";
}
void exit(bool &continueq)
{
    std::cout << "exit " << std::flush;
    for (int i = 0; i < 3; i++)
    {
        std::cout << ". " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    continueq = false;
}
void introduce(const std::string &authorsName, const std::string &email, int sex)
{
    std::cout << "\n\n\tПриветствую!\n\n";

    std::cout << '\t' << authorsName << " выполнил";
    if (sex == FEMALE)
        std::cout << 'a';
    std::cout << " данную лабораторную работу.\n\n";

    std::cout << '\t' << "По всем вопросам прошу обращаться по данному адресу: "
              << "\n\t\t" << email
              << std::endl
              << std::endl
              << std::endl;
}

void enterTaskNumber(int &selectedTask, const int &minTaskNumber, const int &maxTaskNumber)
{
    while (true)
    {
        std::cout << "Введите номер задания(-1 для выхода): ";
        std::cin >> selectedTask;

        if (selectedTask == -1)
        {
            break;
        }
        else

            if (minTaskNumber <= selectedTask && selectedTask <= maxTaskNumber)
        {
            std::cout << "Номер задания корректный."
                      << std::endl
                      << std::endl
                      << std::endl
                      << std::endl;
            break;
        }
        else
        {
            std::cout << "Номер задания некоректный! Выберите от " << minTaskNumber << " до " << maxTaskNumber
                      << " (включительно)" << std::endl;
        }
    }
}
