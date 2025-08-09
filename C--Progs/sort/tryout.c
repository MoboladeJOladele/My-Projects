#include <stdio.h>

#include "sort.c"

int main(void)
{
    char letters[] = {'g', 'f', 'b', 'c', 'e', 'd', 'a'};
    char* strings[] = {"Jasmine", "jasmine", "JAMES", "Oli", "Adam"};

    sort(letters, "ascending", sizeof(letters));
    for (int i = 0, n = arlen(letters, sizeof(letters)); i < n; i++)
    {
        printf("'%c'", letters[i]);
        if (i < (n -1))
        {
            printf(", ");
        }
    }
    printf("\n");

    sort(strings, "ascending", sizeof(strings));
    for (int j = 0, n = arlen(strings,  sizeof(strings)); j < n; j++)
    {
        printf("%s", strings[j]);
        if (j < (n -1))
        {
            printf(", ");
        }
    }
    printf("\n");
}
