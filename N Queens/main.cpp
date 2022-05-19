#include <iostream>
using namespace std;

int ChessBoard[10][10];

void PrintBoard(int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            cout << ChessBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

bool isSafe(int col, int row, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (ChessBoard[i][col])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (ChessBoard[i][j])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; j++, i--)
    {
        if (ChessBoard[i][j])
        {
            return false;
        }
    }
    return true;
}

bool Solution(int n, int row)
{
    if (n == row)
    {
        PrintBoard(n);
        return true;
    }

    bool result = false;
    for (int i = 0; i <= n - 1; i++)
    {
        if (isSafe(i, row, n))
        {
            ChessBoard[row][i] = 1;
            result = Solution(n, row + 1) || result;
            ChessBoard[row][i] = 0;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cout << "Enter the number of queens: " << endl;
    cin >> n;
    if (n > 11)
    {
        cout << "The number of solutions is too large to show.";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ChessBoard[i][j] = 0;
        }
    }
    bool result = Solution(n, 0);
    if (result == false)
    {
        cout << "No valid solutions." << endl;
    }
    else
    {
        cout << endl;
    }
    return 0;
}
