#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "arlen.c"

// Prototypes stacked alphabetically
char *_case(char *s);
bool _islowercase(char *s);
bool _isuppercase(char *s);
bool look_for_letters(char *s);
void found_no_letters(char *function);

char *_lower(char *s, int size)
{
    // Counts all characters (except the NULL character)
    int length = arlen(s, size);

    char *copy = malloc(length + 1);
    if (copy == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(s[i]))
        {
            copy[i] = s[i];
        }
        else if (!islower(s[i]))
        {
            copy[i] = tolower(s[i]);
        }
        else
        {
            copy[i] = s[i];
        }
    }
    return copy;
}

char *_upper(char *s, int size)
{
    // Counts all characters (except the NULL character)
    int length = arlen(s, size);

    char *copy = malloc(length + 1);
    if (copy == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(s[i]))
        {
            copy[i] = s[i];
        }
        else if (!isupper(s[i]))
        {
            copy[i] = toupper(s[i]);
        }
        else
        {
            copy[i] = s[i];
        }
    }
    return copy;
}

bool _islowercase(char *s)
{
    bool found_a_letter = look_for_letters(s);
    if (!found_a_letter)
    {
        // No Letters Found
        found_no_letters("_islowercase()");
    }

    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (!isalpha(s[i]))
            {
                continue;
            }

            else if (!islower(s[i]))
            {
                return false;
            }
        }
        return true;
    }
}

bool _isuppercase(char *s)
{
    bool found_a_letter = look_for_letters(s);
    if (!found_a_letter)
    {
        // No Letters Found
        found_no_letters("_isuppercase()");
    }

    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (!isalpha(s[i]))
            {
                continue;
            }

            else if (!isupper(s[i]))
            {
                return false;
            }
        }
        return true;
    }
}

char *_case(char *s)
{
    bool found_a_letter = look_for_letters(s);
    if (!found_a_letter)
    {
        // No Letters Found
        found_no_letters("_case()");
        return "None";
    }

    bool is_lower = _islowercase(s);
    bool is_upper = _isuppercase(s);

    if (is_lower)
    {
        return "low";
    }

    else if (is_upper)
    {
        return "upp";
    }

    else
    {
        return "both";
    }
}

bool look_for_letters(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isalpha(s[i]))
        {
            continue;
        }
        // If we've found at least one letter
        return true;
    }
    return false;
}

void found_no_letters(char *function)
{
    printf("%s says {Couldn't find any letters}\n", function);
}
