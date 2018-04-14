#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get pyramid height
    int h = get_int("Enter desired height of pyramid in blocks: ");
    while (h < 0 || h > 23)
    {
        h = get_int("Enter desired height of pyramid in blocks: ");
    }


    // number of # is 1 + 1 for each new line
    int pound = 1;

    // Build pyramid
    while (h > 0)
    {
        // Number of spaces is h minus 1
        int spaces = h - 1;
        // Print spaces
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        // Print pounds
        for (int i = 0; i < pound; i++)
        {
            printf("#");
        }
        // Print gap
        printf("  ");
        // Print pounds again
        for (int i = 0; i < pound; i++)
        {
            printf("#");
        }
        printf("\n");
        h--;
        pound++;
    }
}