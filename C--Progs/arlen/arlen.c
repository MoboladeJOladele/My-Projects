#include <stdio.h>

#define arlen_others(type, name) \
    int name(type array, int size) { \
        return size / sizeof(array[0]); \
    }

// Other arlen functions
arlen_others(int*, arlen_ints)
arlen_others(long*, arlen_longs)
arlen_others(float*, arlen_floats)
arlen_others(double*, arlen_doubles)
arlen_others(char**, arlen_string_set)

// String (char*) arlen function
int arlen_string(char* s, int size) {
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

// _Generic Function Selector
#define arlen(array, size) _Generic((array), \
    int*: arlen_ints, \
    long*: arlen_longs, \
    float*: arlen_floats, \
    double*: arlen_doubles, \
    char*: arlen_string, \
    char**: arlen_string_set \
)(array, size)

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
