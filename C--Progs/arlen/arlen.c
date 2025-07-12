#include <stdio.h>
#include <string.h>

// Int functions stacked alphabetically
int char_len(char* array, int size);
int double_len(double* array, int size);
int float_len(float* array, int size);
int int_len(int* array, int size);
int long_len(long* array, int size);
int string_len(char** array, int size);


#define arlen(array, size) _Generic((array), \
        char*:   char_len,    \
        char**:  string_len,  \
        int*:    int_len,     \
        long*:   long_len,    \
        float*:  float_len,   \
        double*: double_len   \
)(array, size)

int main(void)
{
    // Create an array of intgers
    int numbers[] = {7, 6, 8, 18, 23};

    // Create a string (an array of chars)
    char name[] = {"Joseph"};

    // Create an array of strings (char *)
    char *org[] = {"Github", "Youtube", "Google", "Meta"};

    // Return the size of the first array
    printf("Int: %i\n", arlen(numbers, sizeof(numbers)));

    // Return the size of the second array
    printf("Char: %i\n", arlen(name, sizeof(name)));

    // Return the size of the third array
    printf("String: %i\n", arlen(org, sizeof(org)));

    // Return the size of an element (or sub-array) within the parent array
    printf("El: %lu\n", strlen(org[2]));
}

int char_len(char* array, int size)
{
    int len = size / sizeof(array[0]);
    return len;
}

int int_len(int* array, int size)
{
    int len = size / sizeof(array[0]);
    return len;
}

int long_len(long* array, int size)
{
    int len = size / sizeof(array[0]);
    return len;
}

int float_len(float* array, int size)
{
    int len = size / sizeof(array[0]);
    return len;
}

int double_len(double* array, int size)
{
    int len = size / sizeof(array[0]);
    return len;
}

int string_len(char** array, int size)
{
    int len = size / sizeof(array[0]);
    return len;
}
