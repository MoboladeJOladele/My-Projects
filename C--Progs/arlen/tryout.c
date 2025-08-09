#include<stdio.h>

#include "arlen.c"

int main(void)
{
    char *string = "hello, world!";
    char *string_set[] = {"yes", "no", "maybe"};
    int num[] = {12, 13, 26, 0, 1, 1};

    printf("Length of string: %i\n", arlen(string, sizeof(string)));
    printf("Length of string set: %i\n", arlen(string_set, sizeof(string_set)));
    printf("Length of number array: %i\n", arlen(num, sizeof(num)));

    // Length of an element in the string set
    printf("\nLength of Element: %i\n", arlen(string_set[2], sizeof(string_set[2])));
}