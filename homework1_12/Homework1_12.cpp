#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

namespace part01
{
    void call()
    {
        std::string inputData;
        std::ifstream textFile("in_part01.txt");
        if (textFile.is_open())
        {
            while (!textFile.eof())
            {
                textFile >> inputData;
                std::cout << inputData << std::endl;
            }
        }
        else
        {
            std::cout << "Error!";
        }
        textFile.close();
    }
}

namespace part02
{
    void reverseOut(int* array, int size)
    {
        for (int i = size; i > 0; i--)
        {
            std::cout << array[i - 1] << " ";
        }
    }
    void call()
    {
        std::string data;
        int pcs;
        std::ifstream textFile("in_part02.txt");
        if (textFile.is_open())
        {
            int counter(0);
            textFile >> data;
            pcs = stoi(data);
            if (pcs < 1)
            {
                std::cout << "Error!";
                std::abort();
            }
            std::cout << pcs << std::endl;
            int* arr = new int[pcs]();
            do 
            {
                textFile >> data;
                if (counter < pcs)
                {
                    arr[counter] = stoi(data);
                }
                counter++;

            } while (!textFile.eof());
            /*if (pcs - 1 > counter)
            {
                std::cout << "Expected " << pcs << " elements, but only " << counter << " exists!" << std::endl;
            }*/
            //reverseOut(arr, pcs-counter);
            reverseOut(arr, pcs);
            std::cout << std::endl;
            delete[] arr;
        }
        else
        {
            std::cout << "Error!";
        }
        textFile.close();
    }
}

namespace part03
{
    void fillArray(int* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "arr[" << i << "] = ";
            std::cin >> arr[i];
            std::cout << std::endl;
        }
    }
    void reverseOutToFile(int* arr, int size)
    {
        std::string outString = "\n";
        std::ofstream textFile("out_part03.txt");
        if (textFile.is_open())
        {
            for (int i = size; i > 0; i--)
            {
                outString += std::to_string(arr[i - 1]) + " ";
            }
            textFile << size << outString;
        }
        else
        {
            std::cout << "Error!";
        }
        textFile.close();
    }
    void call()
    {
        int size;
        std::cout << "Введите размер массива: ";
        std::cin >> size;
        int* array = new int[size];
        fillArray(array, size);
        reverseOutToFile(array, size);
        std::cout << std::endl;
        delete[] array;
    }
}

namespace part04
{
    int** create2DArray(int cols, int rows)
    {
        int** array = new int* [rows];
        for (int counter = 0; counter < rows; counter++)
        {
            array[counter] = new int[cols];
        }
        return array;
    }
    void reversePrint2Darray(int** array, int cols, int rows)
    {
        for (int c = 0; c < cols; c++)
        {
            for (int r = rows; r > 0; r--)
            {
                std::cout << array[c][r-1] << " ";
            }
            std::cout << std::endl;
        }
    }
    void fill2DArrFromFile(int**& array, int& cols, int& rows)
    {
        std::string data;
        std::ifstream textFile("in_part04.txt");
        if (textFile.is_open())
        {
            int counter(0);
            textFile >> data;
            rows = stoi(data);
            textFile >> data;
            cols = stoi(data);
            std::cout << rows << " " << cols << std::endl;
            array = create2DArray(rows, cols);
            for (int c = 0; c < cols; c++)
            {
                for (int r = 0; r < rows; r++)
                {
                    textFile >> data;
                    array[c][r] = stoi(data);
                }
            }
            textFile.close();
        }
        else
        {
            std::cout << "Error!";
        }
        textFile.close();
    }
    void call()
    {
        int** array = new int*;
        int cols, rows;
        fill2DArrFromFile(array, cols, rows);
        reversePrint2Darray(array, cols, rows);
    }
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    part01::call();
    part02::call();
    part03::call();
    part04::call();
    return 0;
}
