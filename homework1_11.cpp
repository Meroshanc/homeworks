#include <iostream>
#include <string>
#include <Windows.h>

namespace part01 
{
    void callpart01()
    {
        std::string firstName, surName;
        std::cout << "Введите имя: ";
        std::cin >> firstName;
        std::cout << "\nВведите фамилию: ";
        std::cin >> surName;
        std::string greeting = "Здравствуйте, " + firstName + " " + surName + "!";
        std::cout << greeting << std::endl;
    }
}

namespace part02
{
    void callpart02()
    {
        std::string hiddenWord = "строка";
        std::string guessing;
        while (1)
        {
            std::cout << "Угадайте слово: ";
            std::cin >> guessing;
            if (guessing == hiddenWord)
            {
                std::cout << "Правильно! Вы победили! Загаданное слово - " << guessing << std::endl;
                return;
            }
            else
                std::cout << "Неправильно" << std::endl;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    part01::callpart01();
    part02::callpart02();
}
