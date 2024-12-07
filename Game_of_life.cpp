#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <windows.h>

bool** fieldInit(int columns, int rows)
{
    bool** array = new bool* [rows];
    for (int counter = 0; counter < rows; counter++)
    {
        array[counter] = new bool[columns]();
    }
    return array;
}
void purgeField(bool**& matrix, int columns, int rows)
{
    for (int counter = 0; counter < rows; counter++)
    {
        delete[] matrix[counter];
    }
    delete[] matrix;
}
void draw2Dfield(bool**& matrix, int columns, int rows)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (matrix[r][c])
            {
                std::cout << "*" << ' ';
            }
            else
            {
                std::cout << "-" << ' ';
            }
        }
        std::cout << '\n';
    }
}
void initEntitiesFromFile(bool**& arrayA, bool**& arrayB, int& cols, int& rows)
{
    std::string data;
    std::ifstream textFile("input.txt");
    if (textFile.is_open())
    {
        int bufferRows, bufferCols;
        textFile >> data;
        rows = stoi(data);
        textFile >> data;
        cols = stoi(data);
        arrayA = fieldInit(cols, rows);
        arrayB = fieldInit(cols, rows);
        do
        {
            textFile >> data;
            bufferRows = stoi(data);
            textFile >> data;
            bufferCols = stoi(data);
            arrayA[bufferRows][bufferCols] = true;
            arrayB[bufferRows][bufferCols] = true;
        } while (!textFile.eof());
        textFile.close();
    }
    else
    {
        std::cout << "Error!";
        textFile.close();
    }
}
void arrayCopy(bool**& arrayFrom, bool**& arrayTo, int sizeX, int sizeY)
{
    for (int rws = 0; rws < sizeY; rws++)
    {
        for (int cols = 0; cols < sizeX; cols++)
        {
            arrayTo[rws][cols] = arrayFrom[rws][cols];
        }
    }
}
bool isTheSame(bool**& array1, bool**& array2, int sizeX, int sizeY)
{
	for (int rws = 0; rws < sizeY; rws++)
	{
		for (int cols = 0; cols < sizeX; cols++)
		{
			if (!(array1[rws][cols] == array2[rws][cols]))
                return false;
		}
	}
	return true;
}
int cellsAlive(bool**& array, int sizeX, int sizeY)
{
	int alive = 0;
	for (int rws = 0; rws < sizeY; rws++)
	{
		for (int cols = 0; cols < sizeX; cols++)
		{
			if (array[rws][cols] == true)
				alive++;
		}
	}
	return alive;
}
void calcNextState(bool**& arrayCur, bool**& arrayNext, int sizeX, int sizeY)
{
    for (int rws = 0; rws < sizeY; rws++)
    {
        for (int cols = 0; cols < sizeX; cols++)
        {
            int cellsAliveNearby = 0;
            for (int curRow = -1; curRow < 2; curRow++)
            {
                for (int curCol = -1; curCol < 2; curCol++)
                {
                    if ((rws + curRow >= 0 && cols + curCol >= 0) && (rws + curRow < sizeY && cols + curCol < sizeX))
                    {
                        if (&arrayCur[rws + curRow][cols + curCol] != &arrayCur[rws][cols])
                        {
                            if (arrayCur[rws + curRow][cols + curCol])
                                cellsAliveNearby++;
                        }
                    }
                }
            }
            switch (cellsAliveNearby)
            {
            case 2:
                arrayNext[rws][cols] = arrayNext[rws][cols];
                break;
            case 3:
                arrayNext[rws][cols] = true;
                break;
            default:
                arrayNext[rws][cols] = false;
            }
        }
    }
}
void callTheGame()
{
    static bool** entities = new bool*;
    static bool** entitiesNext = new bool*;
    static int columns, rows, gen(1), alive(0);
    initEntitiesFromFile(entities, entitiesNext, columns, rows);
    do 
    {
        std::system("cls");
        draw2Dfield(entities, columns, rows);
        alive = cellsAlive(entities, columns, rows);
        std::cout << "Generation: " << gen << ". Alive cells: " << alive;
        if (alive == 0)
        {
            std::cout << "\nAll cells are dead. Game Over!";
            break;
        }
        calcNextState(entities, entitiesNext, columns, rows);
        if (isTheSame(entities, entitiesNext, columns, rows))
        {
            Sleep(1000);
            std::system("cls");
            draw2Dfield(entities, columns, rows);
            alive = cellsAlive(entities, columns, rows);
            gen++;
            std::cout << "Generation: " << gen << ". Alive cells: " << alive;
            std::cout << "\nThe world has stagnated. Game Over!";
            break;
        }
        else
            arrayCopy(entitiesNext, entities, columns, rows);
        gen++;
        Sleep(1000);
    } while (1);
    purgeField(entities, columns, rows);
    purgeField(entitiesNext, columns, rows);
}

int main()
{
    callTheGame();
    return 0;
}