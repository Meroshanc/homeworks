#include <iostream>
#include <cstdlib>

namespace part01 {
    int* arrayinit(int size)
    {
        return new int[size];
    }
    void usearray(int* array, int size)
    {
        for (int counter = 0; counter < size; counter++)
        {
            std::cout << "arr[" << counter << "] = ";
            std::cin >> array[counter];
        }
        std::cout << std::endl;
        std::cout << "Введённый массив: ";
        for (int counter = 0; counter < size; counter++)
        {
            std::cout << array[counter] << " ";
        }
    }
    void callpart01()
    {
        int size;
        std::cout << "Введите размер массива: ";
        std::cin >> size;
        std::cout << std::endl;
        int* array = arrayinit(size);
        usearray(array, size);
        std::cout << std::endl;
        delete[] array;
    }
}

namespace part02
{
    double* create_array(int size)
    {
        return new double[size]();
    }
    void arrayout(double* array, int size)
    {
        std::cout << "Массив: ";
        for (int counter = 0; counter < size; counter++)
        {
            std::cout << array[counter] << " ";
        }
    }
    void callpart02()
    {
        int size;
        std::cout << "Введите размер массива: ";
        std::cin >> size;
        double* doubleArr = create_array(size);
        std::cout << std::endl;
        arrayout(doubleArr, size);
        std::cout << std::endl;
        delete[] doubleArr;
    }
}

namespace part03
{
    int** create_two_dim_array(int cols, int rows)
    {
        int** array = new int* [rows];
        for (int counter = 0; counter < rows; counter++)
        {
            array[counter] = new int[cols];
        }
        return array;
    }
    void fill_two_dim_array(int** array, int cols, int rows)
    {
        for (int counterA = 1; counterA <= cols; counterA++)
        {
            for (int counterR = 1; counterR <= rows; counterR++)
            {
                array[counterA - 1][counterR - 1] = counterA * counterR;
            }
        }
    }
    void print_two_dim_array(int** array, int cols, int rows)
    {
        for (int counterA = 0; counterA < cols; counterA++)
        {
            for (int counterR = 0; counterR < rows; counterR++)
            {
                std::cout << array[counterA][counterR] << "\t";
            }
            std::cout << std::endl;
        }
    }
    void delete_two_dim_array(int** array, int cols, int rows)
    {
        for (int counter = 0; counter < cols; counter++)
        {
            delete[] array[counter];
        }
        delete[] array;
    }
    void callpart03()
    {
        int cols, rows;
        std::cout << "Введите количество строк: ";
        std::cin >> rows;
        std::cout << std::endl;
        std::cout << "Введите количество столбцов: ";
        std::cin >> cols;
        int** array = create_two_dim_array(cols, rows);
        fill_two_dim_array(array, cols, rows);
        std::cout << "Таблица умножения: " << std::endl;
        print_two_dim_array(array, cols, rows);
        std::cout << std::endl;
        delete_two_dim_array(array, cols, rows);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    part01::callpart01();
    part02::callpart02();
    part03::callpart03();
    return 0;
}
