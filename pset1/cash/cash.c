#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get user input
    float change = get_float("Change owed: ");

    // Convert to rounded int
    int changeInt = round(change * 100);

    // Count coins needed
    int coins = 0;

    // Add number of quarters
    coins = coins + changeInt / 25;
    // Work out change left
    int changeLeft = changeInt % 25;

    // If change left work out and add dimes
    if (changeLeft != 0)
    {
        // Add number of dimes
        coins = coins + changeLeft / 10;
        // Work out change left
        changeLeft = changeLeft % 10;

        // Check if change left
        if (changeLeft != 0)
        {
            // Add number of nickels
            coins = coins + changeLeft / 5;
            // Work out change left
            changeLeft = changeLeft % 5;

            if (changeLeft != 0)
            {
                // Add number of pennies
                coins = coins + changeLeft / 1;
            }
        }
    }

    // Print answer
    printf("%i\n", coins);
}