#include <stdio.h>
#include <cs50.h> // For using the cs50 library for input validation

int main(void)
{
    // Array of coin values in cents (quarters, dimes, nickels, pennies)
    int coins[] = {25, 10, 5, 1};
    int num_coins = 4; // Number of different types of coins

    // Prompt user for input until valid input is received
    int change;
    do
    {
        change = get_int("Change owed (in cents): ");
    }
    while (change < 0); // Ensure change is non-negative

    // Variable to count total number of coins
    int count = 0;

    // Calculate minimum number of coins
    for (int i = 0; i < num_coins; i++)
    {
        count += change / coins[i];
        change %= coins[i];
    }

    // Print the total number of coins
    printf("%d\n", count);

    return 0;
}
