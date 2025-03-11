#include <iostream>
using namespace std;
void print_board(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }
            else if (board[i][j] == 2)
            {
                cout << "x ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout << "|";
        cout << endl;
    }
    cout << "-----------\n";
}
void zero(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
}
void attack_area(int **board, int n, int row, int col)
{
    int temp_row = 0, temp_col = 0;
    while (temp_row < n) // vertical
    {
        if (board[temp_row][col] != 1)
        {
            board[temp_row][col] = 2;
        }
        temp_row++;
    }
    while (temp_col < n) // horizaontal
    {
        if (board[row][temp_col] != 1)
        {
            board[row][temp_col] = 2;
        }
        temp_col++;
    }
    temp_row = row;
    temp_col = col;
    while (temp_row >= 0 && temp_col < n) // NE
    {
        if (board[temp_row][temp_col] != 1)
        {
            board[temp_row][temp_col] = 2;
        }
        temp_row--;
        temp_col++;
    }
    temp_row = row;
    temp_col = col;
    while (temp_row < n && temp_col < n) // ES
    {
        if (board[temp_row][temp_col] != 1)
        {
            board[temp_row][temp_col] = 2;
        }
        temp_row++;
        temp_col++;
    }
    temp_row = row;
    temp_col = col;
    while (temp_row < n && temp_col >= 0) // sw
    {
        if (board[temp_row][temp_col] != 1)
        {
            board[temp_row][temp_col] = 2;
        }
        temp_row++;
        temp_col--;
    }
    temp_row = row;
    temp_col = col;
    while (temp_row >= 0 && temp_col >= 0) // WN
    {
        if (board[temp_row][temp_col] != 1)
        {
            board[temp_row][temp_col] = 2;
        }

        temp_row--;
        temp_col--;
    }
}
void place_queens(int **board, int n)
{
    int fail_flag = 0;
    for (int i = 0; i < n; i++)
    {
        zero(board, n);
        board[i][0] = 1;
        attack_area(board, n, i, 0);
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                fail_flag = 1;
                if (board[k][j] != 2)
                {
                    board[k][j] = 1;
                    attack_area(board, n, k, j);
                    if (j == n - 1)
                    {
                        print_board(board, n);
                    }
                    fail_flag = 0;
                    break;
                }
            }
            
            if (fail_flag)
            {
                break;
            }
        }
    }
}

int main()
{
    int n;
    cout << "enter size of n x n chess board: ";
    cin >> n;
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
    }
    place_queens(board, n);
    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}
