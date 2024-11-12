#include <iostream>

namespace part01 
{
    void print(int* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void runPrg()
    {
        int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int arr2[]{ 6, 5, 4, 8 };
        int arr3[]{ 1, 4, 3, 7, 5 };
        print(arr1, sizeof(arr1)/4);
        print(arr2, sizeof(arr2)/4);
        print(arr3, sizeof(arr3)/4);
    }
}

namespace part02 
{
    void swap(int &num1, int& num2)
    {
        num1 = num1 + num2;
        num2 = num1 - num2;
        num1 = num1 - num2;

    }
    void runPrg()
    {
        int a = 5, b = 8;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
    }
}

namespace part03 
{
    void swap(int& num1, int& num2)
    {
        num1 = num1 + num2;
        num2 = num1 - num2;
        num1 = num1 - num2;

    }
    void reverse(int* arr, int size)
    {
        for (int j = 0; j < size; j++)
        {
            for (int i = 0; i < size - 1; i++)
            {
                if (arr[i] < arr[i + 1])
                    swap(arr[i], arr[i + 1]);
            }
        }
    }
    void arrOut(int* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    void runPrg()
    {
        int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
        std::cout << "До функции reverse: ";
        arrOut(arr, sizeof(arr) / 4);
        reverse(arr, sizeof(arr) / 4);
        std::cout << "\nПосле функции reverse: ";
        arrOut(arr, sizeof(arr) / 4);

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    part01::runPrg();
    part02::runPrg();
    part03::runPrg();
}

