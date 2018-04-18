// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Numerator
    char numStr[1];
    numStr[0] = fraction[0];
    float num = atoi(numStr);

    // Denominator
    char denStr[1];
    denStr[0] = fraction[2];
    float den = atoi(denStr);

    // Calculate absolute note length
    float note = num / den;

    // Return number of eighths
    return (float) note / 0.125;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                    };

    int acc = 0;
    bool isNoteSharp = false;
    bool isNoteFlat = false;
    bool isNoteNat = false;
    char octStr[1];
    int oct;
    int aIndex = 9;

    char letter = note[0];

    if (note[1] == '#')
    {
        acc = 1;
        isNoteSharp = true;
        octStr[0] = note[2];
        oct = atoi(octStr);
    }
    else if (note[1] == 'b')
    {
        acc = -1;
        isNoteFlat = true;
        octStr[0] = note[2];
        oct = atoi(octStr);
    }
    else
    {
        isNoteNat = true;
        octStr[0] = note[1];
        oct = atoi(octStr);
    }

    char natNote[1];
    char sharpNote[2];
    char flatNote[2];

    // Create abs note string
    if (acc == 0)
    {
        sprintf(natNote, "%c", letter);
    }
    else if (acc == 1)
    {
        sprintf(sharpNote, "%c%c", letter, '#');
    }
    else
    {
        sprintf(flatNote, "%c%c", letter, 'b');
    }

    // Get index of current note
    int noteIndex = 0;
    if (isNoteSharp)
    {
        for (int i = 0, n = sizeof(NOTES) / sizeof(string); i < n; i++)
        {
            if ( strcmp(NOTES[i], sharpNote) == 0 )
            {
                noteIndex = i;
            }
        }
    }
    else if (isNoteNat)
    {
        for (int i = 0, n = sizeof(NOTES) / sizeof(string); i < n; i++)
        {
            if ( strcmp(NOTES[i], natNote) == 0 )
            {
                noteIndex = i;
            }
        }
    }
    else
    {
        for (int i = 0, n = sizeof(NOTES) / sizeof(string); i < n; i++)
        {
            if ( NOTES[i][0] == flatNote[0] )
            {
                noteIndex = i - 1;
                break;
            }
        }
    }

    // Work out semitone difference including octave (n)
    double semitoneDiff = ((oct - 4) * 12) + (noteIndex - aIndex);

    // 2^n/12 * 440 where n is semitones to a4
    double freq = round(pow(2, (semitoneDiff / 12)) * 440);

    return (int) freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    string test = "";
    // TODO
    if (strcmp(s, test) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
