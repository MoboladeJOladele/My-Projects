#include <stdio.h>
#include "strings.c"

int main(void)
{
    char *string1 = "John";
    char *string2 = "john";

    if (strcmp(_case(string1), "low") != 0)
    {
        printf("[%s] isn't lowercase\n", string1);
    }

    if (strcmp(_case(string1), "upp") != 0)
    {
        printf("[%s] isn't uppercase\n", string1);
    }

    if (strcmp(_case(string1), "both") == 0)
    {
        printf("[%s] has both lowercase and uppercase letters\n\n", string1);
    }

    if (strcmp(_case(string2), "low") == 0)
    {
        printf("[%s] isn't uppercase\n", string2);
        printf("It's lowercase\n");
    }
}
