#include <iostream>
#include <limits>

using namespace std;

int checkInput(int numberToCheck)
{
    while (!(cin >> numberToCheck))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number.\n";
    }
    return numberToCheck;
}

void runCafe()
{
    float priceCoffee = 2.70;
    float priceCake = 4.15;
    float priceScone = 2.99;

    int numberCoffee, numberCake, numberScone;

    cout << "\nHow many coffees can I get for you?\n";
    numberCoffee = checkInput(numberCoffee);
    cout << "How many cakes can I get for you?\n";
    numberCake = checkInput(numberCake);
    cout << "How many scones can I get for you?\n";
    numberScone = checkInput(numberScone);

    float total = numberCoffee * priceCoffee + numberCake * priceCake + numberScone * priceScone;
    cout.precision(2);
    cout << "Great! Your total is $" << std::fixed << total << ".\n";

    int numberBills;

    cout << "How much money in dollar bills will you pay with?\n";
    numberBills = checkInput(numberBills);
    while (numberBills < total)
    {
        cout << "Please enter a number greater than or equal to the amount you need to pay!\n";
        numberBills = checkInput(numberBills);
    }

    float change = numberBills - total;

    cout << "Thank you! Your change is $" << std::fixed << change << ".\n";

    change = change + .01;

    int dollars = change / 1;
    change = change - dollars;
    int halfdollars = change / .50;
    change = change - halfdollars * .50;
    int quarters = change / .25;
    change = change - quarters * .25;
    int dimes = change / .10;
    change = change - dimes * .10;
    int nickels = change / .05;
    change = change - nickels * .05;
    int pennies = change / .01;
    change = change - pennies * .01;

    cout << "That amounts to:\n";
    if (dollars > 0)
    {
        cout << "- " << dollars << " dollar";
        if (dollars > 1)
        {
            cout << "s";
        }
        cout << ".\n";
    }
    if (halfdollars > 0)
    {
        cout << "- " << halfdollars << " half dollar";
        if (halfdollars > 1)
        {
            cout << "s";
        }
        cout << ".\n";
    }
    if (quarters > 0)
    {
        cout << "- " << quarters << " quarter";
        if (quarters > 1)
        {
            cout << "s";
        }
        cout << ".\n";
    }
    if (dimes > 0)
    {
        cout << "- " << dimes << " dime";
        if (dimes > 1)
        {
            cout << "s";
        }
        cout << ".\n";
    }
    if (nickels > 0)
    {
        cout << "- " << nickels << " nickel";
        if (nickels > 1)
        {
            cout << "s";
        }
        cout << ".\n";
    }
    if (pennies > 0)
    {
        if (pennies > 1)
        {
            cout << "- " << pennies << " pennies.\n";
        }
        else
        {
            cout << "- " << pennies << " penny.\n";
        }
    }

    cout << "\nThank you! Have a nice day!";
}

int main()
{
    cout << "~~~Joe Bro Cafe~~~\n";
    cout << "Daily Menu:\n- Coffee----------$2.70\n- Cake------------$4.15\n- Scone-----------$2.99\n";
    cout << "~~~~~~~~~~~~~~~~~~\nLet's get you something to drink and eat!\n";
    runCafe();

    return 0;
}
