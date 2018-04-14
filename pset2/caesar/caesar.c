#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check for single arg
    if (argc < 2)
    {
        printf("No argument provided!!\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Too many arguments, just the one thankyou!!\n");
        return 1;
    }
    else
    {
        // Convert arg to int
        int k = atoi(argv[1]);

        while (k > 26)
        {
            k -= 26;
        }

        // Get input
        string s = get_string("plaintext: ");

        printf("ciphertext: ");
        for (int i = 0, l = strlen(s); i < l; i++)
        {
            // If uppercase
            if ((int) s[i] > 64 && (int) s[i] < 91)
            {
                int newChar = (int) s[i] + k;
                if (newChar > 90)
                {
                    newChar -= 26;
                }
                printf("%c", newChar);
            }
            // If lowercase
            else if ((int) s[i] > 96 && (int) s[i] < 123)
            {
                int newChar = (int) s[i] + k;
                if (newChar > 122)
                {
                    newChar -= 26;
                }
                printf("%c", newChar);
            }
            // If non alpha
            else
            {
                printf("%c", (int) s[i]);
            }
        }
        printf("\n");
        return 0;
    }
}