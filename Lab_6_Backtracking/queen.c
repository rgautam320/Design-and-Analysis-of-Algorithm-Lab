/*
    Time Complexity of N Queen's Problem ==> O(N!)
*/

#include <stdio.h>
#include <stdbool.h>
#define N 8

// Function to print result
void PrintSolution(int chessBoard[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d ", chessBoard[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether it's a safe move or not
bool SafeMove(int chessBoard[N][N], int row, int col)
{
    int i, j;
    // Checking for the left column
    for (i = 0; i < col; i++)
    {
        if (chessBoard[row][i])
        {
            return false;
        }
    }
    // Checking for the left top diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chessBoard[i][j])
        {
            return false;
        }
    }
    // Checking for the left bottom diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (chessBoard[i][j])
        {
            return false;
        }
    }
    return true;
}

// Function to solve N Queen problem
bool QueenSolver(int chessBoard[N][N], int col)
{
    // If all Queens are already placed at correct position, then simply return true
    if (col >= N)
    {
        return true;
    }

    // Consider the column at 0th position and try placing the Queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        // If safe, place the Queen
        if (SafeMove(chessBoard, i, col))
        {
            chessBoard[i][col] = 1;

            // Recursive call to other Queens
            if (QueenSolver(chessBoard, col + 1))
            {
                return true;
            }
            chessBoard[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int board[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0}};

    if (QueenSolver(board, 0) == true)
    {
        printf("\nThe Queens can be placed where there are 1s \n\n");
        PrintSolution(board);
    }
    else
    {
        printf("Solution does not exist");
        return false;
    }
    return 0;
}