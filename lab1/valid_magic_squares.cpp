#include <iostream>
using namespace std;
void print(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << "-----------\n";
}
bool from_one_to_nine(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] < 1 || arr[i][j] > 9)
                return false;
        }
    }
    return true;
}
bool have_duplicate(int arr[3][3])
{
    int count[10] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = arr[i][j];

            if (num < 1 || num > 9 || count[num]++)
                return true;
        }
    }
    return false;
}
void copy(int dst[3][3], int src[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}
int main()
{
    int table[3][3] = {0};
    int tempo[3][3] = {0};
    int zeros[3][3] = {0};
    int result = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (i == 5)
            continue;
        copy(table,zeros); // make array elements - zero
        table[1][1] = 5;    // magic number=15
        table[0][0] = i;
        table[2][2] = 10 - i;
        for (int j = 1; j <= 9; j++)
        {
            if (j == i || j == 10 - i || j == 5)
                continue;
            copy(tempo,table);
            tempo[2][0] = j;
            tempo[0][2] = 10 - j;
            tempo[1][0] = 15 - tempo[0][0] - tempo[2][0];
            tempo[0][1] = 15 - tempo[0][0] - tempo[0][2];
            tempo[1][2] = 15 - tempo[0][2] - tempo[2][2];
            tempo[2][1] = 15 - tempo[2][0] - tempo[2][2];
            if (!have_duplicate(tempo) && from_one_to_nine(tempo))
            {
                print(tempo);
                result++;
            }
        }
    }
    cout << "Total valid magic squares: " << result << endl;
}
