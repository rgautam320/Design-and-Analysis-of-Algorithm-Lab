/*
    Time Complexity of Sudoku Puzzle using Backtracking ==> O(N^M)
        where   N = Size of Matrix (Generally 9 in classic Sudoku)
                M = Number of blank spaces
*/

#include <stdio.h>
#include <stdbool.h>
#define N 9

// Function to print result
void PrintSolution(int sudokuBoard[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d ", sudokuBoard[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether it's legal or not
bool SudokuCheck(int sudokuBoard[N][N], int row, int col, int num)
{
    // If we find the same number in similar row, then we will return 0
    for (int i = 0; i < N; i++)
    {
        if (sudokuBoard[row][i] == num)
        {
            return false;
        }
    }
    // If we find the same number in similar column, then we will return 0
    for (int i = 0; i < N; i++)
    {
        if (sudokuBoard[i][col] == num)
        {
            return false;
        }
    }
    // If we find the same number in particular 3x3 matrix, then we will return 0
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudokuBoard[i + startRow][j + startCol] == num)
            {
                return 0;
            }
        }
    }
    return true;
}

// Funtion to solve Sudoku puzzle
bool SudokuSolver(int sudokuBoard[N][N], int row, int col)
{
    // If we have reached the 8th row and 8th column, we are returing true to avoid backtracking
    if (row == N - 1 && col == N)
    {
        return true;
    }
    // If column becomes 9th, we set it to 0 and move to next row
    if (col == N)
    {
        row++;
        col = 0;
    }
    // If current position value > 0, we iterate for next column
    if (sudokuBoard[row][col] > 0)
    {
        return SudokuSolver(sudokuBoard, row, col + 1);
    }

    for (int num = 1; num <= N; num++)
    {
        if (SudokuCheck(sudokuBoard, row, col, num))
        {
            // Assigning the number
            sudokuBoard[row][col] = num;

            //Checking for possibility with next column
            if (SudokuSolver(sudokuBoard, row, col + 1))
            {
                return true;
            }
        }
        // Removing assigned number since our assumption was wrong. We will go for next assumption with different value
        sudokuBoard[row][col] = 0;
    }
    return false;
}

int main()
{
    int unsolvedSoduku[N][N] = {{0, 3, 0, 0, 1, 0, 0, 6, 0},
                                {7, 5, 0, 0, 3, 0, 0, 4, 8},
                                {0, 0, 6, 9, 8, 4, 3, 0, 0},
                                {0, 0, 3, 0, 0, 0, 8, 0, 0},
                                {9, 1, 2, 0, 0, 0, 6, 7, 4},
                                {0, 0, 4, 0, 0, 0, 5, 0, 0},
                                {0, 0, 1, 6, 7, 5, 2, 0, 0},
                                {6, 8, 0, 0, 9, 0, 0, 1, 5},
                                {0, 9, 0, 0, 4, 0, 0, 3, 0}};

    if (SudokuSolver(unsolvedSoduku, 0, 0) == true)
    {
        printf("\nThe Solved Soduku Puzzle will look like: \n\n");
        PrintSolution(unsolvedSoduku);
    }
    else
    {
        printf("No Solution Exists");
    }

    return 0;
}