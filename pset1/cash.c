#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main()
{
    float cash;
    int cents; // cents 100 * cash
    int num_coins = 0; // answer
    do
    {
        
        cash = get_float("Change owed: "); // ask for change in float
   
    }
    while (cash < 0);
    
    cents = round(cash * 100); // cents = 100 * cash
    num_coins += cents / 25 - (cents / 25) % 1; // use as many quarters
    cents = cents % 25; // remaining cash
    num_coins += cents / 10 - (cents / 10) % 1; // use as many dimes
    cents = cents % 10; // remaining cash
    num_coins += cents / 5 - (cents / 5) % 1; // use as many nickels
    cents = cents % 5; // remaining cash
    num_coins += cents / 1; // use as many pennies
    // no remaining cash
    printf("%d\n", num_coins);
}
