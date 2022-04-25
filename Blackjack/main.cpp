#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string cardName(int cardNumber)
{
    string name;
    if (cardNumber == 1)
    {
        name = "ACE";
    }
    else if (cardNumber == 10)
    {
        int randNum = (rand() % 4) + 1;
        if (randNum == 1)
        {
            name = std::to_string(cardNumber);
        }
        else if (randNum == 2)
        {
            name = "JACK";
        }
        else if (randNum == 3)
        {
            name = "QUEEN";
        }
        else
        {
            name = "KING";
        }
    }
    else
    {
        name = std::to_string(cardNumber);
    }

    return name;
}

int totalOfHand(int hand[52])
{
    int total = 0;
    int numberToAdd = 0;
    int aceCounter = 0;
    for (int i = 0; i < 52; i++)
    {
        numberToAdd = hand[i];
        if (hand[i] == 1) { numberToAdd = 11; aceCounter += 1; }
        total += numberToAdd;
    }

    while (total > 21 && aceCounter > 0)
    {
        total -= 10;
        aceCounter -= 1;
    }

    return total;
}

void simulateGame(int gameNumber)
{
    //DECK CREATION
    int deck[52];
    int cardCounter = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            deck[cardCounter] = j;
            cardCounter++;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        deck[cardCounter] = 10;
        cardCounter++;
    }

    //SHUFFLE DECK
    random_shuffle(std::begin(deck), std::end(deck));

    //DEAL HANDS
    int dealerHand[52] = { 0 };
    int playerHand[52] = { 0 };
    cardCounter = 0;
    while (totalOfHand(dealerHand) < 17)
    {
        dealerHand[cardCounter] = deck[cardCounter];
        cardCounter++;
    }

    while (totalOfHand(playerHand) < 17)
    {
        playerHand[cardCounter] = deck[cardCounter];
        string name = cardName(deck[cardCounter]);
        cout << "Player was dealt " << name << ".\n";
        if (totalOfHand(playerHand) < 17)
        {
            cout << "Player chose HIT.\n";
        }
        else if (totalOfHand(playerHand) <= 21)
        {
            cout << "Player chose STAY.\n";
        }
        cardCounter++;
    }

    //PRINT RESULTS
    string winState = "";
    cout << "Total of player's hand is " << totalOfHand(playerHand) << ".\n";
    if (totalOfHand(playerHand) > 21)
    {
        cout << "Player BUSTED.\n";
        winState = "LOSS";
    }
    else if (totalOfHand(dealerHand) > 21)
    {
        cout << "Total of dealer's hand is " << totalOfHand(dealerHand) << ".\n";
        cout << "Dealer BUSTED.\n";
        winState = "WIN";
    }
    else if (totalOfHand(playerHand) == totalOfHand(dealerHand))
    {
        cout << "Total of dealer's hand is " << totalOfHand(dealerHand) << ".\n";
        winState = "DRAW";
    }
    else if (totalOfHand(playerHand) > totalOfHand(dealerHand))
    {
        cout << "Total of dealer's hand is " << totalOfHand(dealerHand) << ".\n";
        winState = "WIN";
    }
    else if (totalOfHand(playerHand) < totalOfHand(dealerHand))
    {
        cout << "Total of dealer's hand is " << totalOfHand(dealerHand) << ".\n";
        winState = "LOSS";
    }

    if (winState != "DRAW")
    {
        cout << "Result of game " << gameNumber << " is player " << winState << ".\n";
    }
    else
    {
        cout << "Result of game " << gameNumber << " is " << winState << ".\n";
    }

}

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        simulateGame(i);
    }
    return 0;
}
