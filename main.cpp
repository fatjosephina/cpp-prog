#include <iostream>
#include<cstdlib>

using namespace std;

void placeShips(int game[8][8], int ships)
{
    bool shouldWhileLoop = true;

    for (int i = 0; i < ships; i++)
    {
        while (shouldWhileLoop)
        {
            int row = rand() % 8;
            int col = rand() % 8;
            if (game[row][col] == 0)
            {
                game[row][col] = 1;
                shouldWhileLoop = false;
            }
        }
        shouldWhileLoop = true;
    }
}

string guessCoordinate(int game[8][8], int row, int col)
{
    if (game[row][col] == 1)
    {
        return "HIT";
    }
    else if (game[row + 1][col] == 1 || game[row][col + 1] == 1 || game[row - 1][col] == 1 || game[row][col - 1] == 1)
    {
        return "NEAR MISS";
    }
    else
    {
        return "MISS";
    }
}

void checkIfShipFound(int game[8][8], int gameboardDiscoveredSoFar[8][8], int i, int j, int shipsFound, int ships)
{
    if (shipsFound < ships)
    {
        string isShipFound = guessCoordinate(game, i, j);
        if (isShipFound == "HIT")
        {
            if (gameboardDiscoveredSoFar[i][j] != game[i][j])
            {
                cout << "Ship found at (" << i << ", " << j << "). \n";
                gameboardDiscoveredSoFar[i][j] = game[i][j];
                shipsFound++;
            }
        }
        else if (isShipFound == "NEAR MISS")
        {
            if (gameboardDiscoveredSoFar[i][j] != game[i][j])
            {
                //cout << "Ship nearly found at (" << i << ", " << j << "). \n";
                gameboardDiscoveredSoFar[i][j] = game[i][j];
                checkIfShipFound(game, gameboardDiscoveredSoFar, i + 1, j, shipsFound, ships);
                checkIfShipFound(game, gameboardDiscoveredSoFar, i, j + 1, shipsFound, ships);
                checkIfShipFound(game, gameboardDiscoveredSoFar, i - 1, j, shipsFound, ships);
                checkIfShipFound(game, gameboardDiscoveredSoFar, i, j - 1, shipsFound, ships);
            }
        }
        else if (isShipFound == "MISS")
        {
            if (gameboardDiscoveredSoFar[i][j] != game[i][j])
            {
                //cout << "Ship not found at (" << i << ", " << j << "). \n";
                gameboardDiscoveredSoFar[i][j] = game[i][j];
            }
        }
    }
}

void runAI(int game[8][8], int ships)
{
    int shipsFound = 0;

    int gameboardDiscoveredSoFar[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            checkIfShipFound(game, gameboardDiscoveredSoFar, i, j, shipsFound, ships);
            if (shipsFound >= ships)
            {
                return;
            }
        }
    }
}

int main()
{
    int gameboard[8][8] = { 0 };

    int numberOfShips = 1 + (rand() % 16);

    cout << numberOfShips << " ships will be placed on the board. \n";

    placeShips(gameboard, numberOfShips);
    runAI(gameboard, numberOfShips);

    return 0;
}

