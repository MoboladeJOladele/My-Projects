#include <stdio.h>

#include "merge_sort.c"


int main(void)
{
    int numbers[] = {4, 5, 2, 9, 9, 1, 3, 5, 0};
    merge_sort(numbers, sizeof(numbers));

    int length = arlen(numbers, sizeof(numbers));
    for (int i = 0; i < length; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");
    return 0;
}
