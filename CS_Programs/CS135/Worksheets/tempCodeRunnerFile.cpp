/*
 * Alec Him
 * CS 135 - Worksheet 16
 * Description:
 * Input: String
 * Output:
 */
#include <iostream>
#include <iomanip>
#include <fstream>

void rowSumCalculator(int myArrayp[][10], int rowCount, int colCount);
void openFile(std::ifstream& iFile, std::string prompt);

void openFile(std::ifstream& iFile, std::string fileName)
{
    do{
        std::cout << "Enter file to process: ";
        std::cin >> fileName;
        iFile.open(fileName);
        if(!iFile.is_open())
            std::cout << "Error - \"" << fileName << "\" did not open.\n";
    } while(!iFile.is_open());
}

void rowSumCalculator(int array[][10], int row, int col)
{
    // Variables
    int sum = 0;
    for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++)
        {
            std::cout << std::setw(4) << array[r][c] << " ";
            sum += array[r][c];
        }
    std::cout << " = " << std::setw(4) << sum << std::endl;
}

int main()
{
    // Variables
    std::ifstream iFile;
    std::string file = "";
    int array[7][10];
    int row = 7, col = 10;

    openFile(iFile, file);
    if(iFile.is_open())
    {
        while(!iFile.eof())
            for(int r = 0; r < row; r++)
                for(int c = 0; c < col; c++)
                    iFile >> array[r][c];
    }
    rowSumCalculator(array, row, col);

    return 0;
}