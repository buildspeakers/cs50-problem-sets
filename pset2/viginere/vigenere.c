#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

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
    // Check for non alpha chars
    bool hasNonAlpha = false;
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            hasNonAlpha = true;
            break;
        }
    }
    if (hasNonAlpha)
    {
        printf("Argument must contain only alphabetical characters!!\n");
        return 1;
    }
    else
    {

        string keyString = argv[1];
        int keyLength = strlen(keyString);
        // Make array to store ints, same length as keyString
        int keyArray[keyLength];
        // Convert each letter to uppercase then integer
        for (int i = 0, l = strlen(keyString); i < l; i++)
        {
            keyString[i] = toupper(keyString[i]);
            keyArray[i] = (int) keyString[i] - 65;
        }

        // Get string
        string s = get_string("plaintext: ");

        printf("ciphertext: ");
        int keyIndex = 0;
        for (int i = 0, l = strlen(s); i < l; i++)
        {
            // Loop key index
            if (keyIndex >= keyLength)
            {
                keyIndex = keyIndex - keyLength;
            }

            // Current character
            int charInt = (int) s[i];
            // Key to apply
            int keyInt = keyArray[keyIndex];


            // If uppercase
            if (charInt > 64 && charInt < 91)
            {
                int newChar = charInt + keyInt;
                if (newChar > 90)
                {
                    newChar -= 26;
                }
                printf("%c", newChar);
                keyIndex++;
            }
            // If lowercase
            else if (charInt > 96 && charInt < 123)
            {
                int newChar = charInt + keyInt;
                if (newChar > 122)
                {
                    newChar -= 26;
                }
                printf("%c", newChar);
                keyIndex++;
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