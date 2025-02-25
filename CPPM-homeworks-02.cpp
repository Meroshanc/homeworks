#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

namespace part01
{
    enum months
    {
        January = 1, February, March,
        April, May, June,
        July, August, September,
        October, November, December
    };
    void print_string(string a)
    {
        cout << a;
    }
    void print_month(months month)
    {
        switch (month)
        {
        case January:
            print_string("Январь\n");
            break;
        case February:
            print_string("Февраль\n");
            break;
        case March:
            print_string("Март\n");
            break;
        case April:
            print_string("Апрель\n");
            break;
        case May:
            print_string("Май\n");
            break;
        case June:
            print_string("Июнь\n");
            break;
        case July:
            print_string("Июль\n");
            break;
        case August:
            print_string("Август\n");
            break;
        case September:
            print_string("Сентябрь\n");
            break;
        case October:
            print_string("Октябрь\n");
            break;
        case November:
            print_string("Ноябрь\n");
            break;
        case December:
            print_string("Декабрь\n");
            break;
        case 0:
            print_string("До свидания\n");
            break;
        default:
            print_string("Неправильный номер!\n");
            break;
        }


    }
    void exec()
    {
        int buffer;
        do
        {
            print_string("Введите номер месяца: ");
            cin >> buffer;
            print_month(static_cast<months>(buffer));

        } while (buffer > 0);
    }
}

namespace part02
{
    struct account
    {
        int num;
        string name;
        float balance;
    };

    void exec()
    {
        account user01;
        part01::print_string("Введите номер счета: ");
        cin >> user01.num;
        part01::print_string("\nВведите имя владельца: ");
        cin >> user01.name;
        part01::print_string("\nВведите баланс: ");
        cin >> user01.balance;
        part01::print_string("\nВведите новый баланс: ");
        cin >> user01.balance;
        part01::print_string("\nВаш счет: ");
        part01::print_string(user01.name); part01::print_string(", ");
        part01::print_string(to_string(user01.num)); part01::print_string(", ");
        part01::print_string(to_string(user01.balance)); part01::print_string("\n");
    }
}

namespace part03
{
    struct address
    {
        string city;
        string street;
        string house;
        string apt;
        string index;
    };
    void print_struct(address& a)
    {
        part01::print_string("Город: ");            part01::print_string(a.city);   part01::print_string("\n");
        part01::print_string("Улица: ");            part01::print_string(a.street); part01::print_string("\n");
        part01::print_string("Номер дома: ");       part01::print_string(a.house);  part01::print_string("\n");
        part01::print_string("Номер квартиры: ");   part01::print_string(a.apt);    part01::print_string("\n");
        part01::print_string("Индекс: ");           part01::print_string(a.index);  part01::print_string("\n");
    }
    void exec()
    {
        address address01 = { "Москва", "Арбат", "12", "8", "123456" };
        address address02 = { "Ижевск", "Пушкина", "59", "143", "953769" };
        print_struct(address01);
        part01::print_string("\n");
        print_struct(address02);
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    part01::exec();
    part01::print_string("\n");
    part02::exec();
    part01::print_string("\n");
    part03::exec();
}

