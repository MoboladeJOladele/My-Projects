#include <cs50.h>
#include <stdio.h>

int merge_sort(int list[], int length);

int main(void)
{
    int numbers[] = {4, 6, 2, 8, 9, 1, 3, 5, 0, 7};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    merge_sort(numbers, length);

    for (int i = 0; i < length; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");
    return 0;
}

int merge_sort(int list[], int length)
{
    if (length > 1)
    {
        // Get the length of the left and right halfs
        int len_left = length / 2;
        int len_right = length - len_left;

        // Create arrays to store the two halves of the list
        int left_half[len_left], right_half[len_right];

        // Make the left half
        for (int l = 0; l < len_left; l++)
        {
            left_half[l] = list[l];
        }

        // Make the right half
        for (int r = 0; r < len_right; r++)
        {
            right_half[r] = list[(len_left + r)];
        }
        merge_sort(left_half, len_left);
        merge_sort(right_half, len_right);

        // SORT AND MERGE.
        int l = 0, r = 0;

        for (int next = 0; next < length; next++)
        {
            // If the elements in the left half have finished.
            if (l == len_left && r < len_right)
            {
                int rem = len_right - r;

                // If the digits left in the right half are more than one
                if (rem > 1)
                {
                    if (right_half[r] < right_half[r + 1])
                    {
                        list[next] = right_half[r];
                        r++;
                    }

                    else if (right_half[r] > right_half[r + 1])
                    {
                        list[next] = right_half[r + 1];
                        r++;
                    }

                    // IF
                    // the two elements are equal
                    else
                    {
                        list[next] = right_half[r];
                        list[next + 1] = right_half[r + 1];
                        next++, r += 2;
                    }
                }

                // THEN,
                // capture the last digit.
                else
                {
                    list[next] = right_half[r];
                }
            }


            // ELSE
            // if the elements in the right half have finished
            else if(l < len_left && r == len_right)
            {
                int rem = len_left - l;

                // If there remains more than one digit in the left half
                if (rem > 1)
                {
                    if (left_half[l] < left_half[l + 1])
                    {
                        list[next] = left_half[l];
                        l++;
                    }

                    else if (left_half[l] > left_half[l + 1])
                    {
                        list[next] = left_half[l + 1];
                        l++;
                    }

                    // IF
                    // the two elements are equal
                    else
                    {
                        list[next] = left_half[l];
                        list[next + 1] = left_half[l + 1];
                        next++, l += 2;
                    }
                }

                // THEN,
                // capture the last digit.
                else
                {
                    list[next] = left_half[l];
                }
            }

            // ELSE
            // if both halves still have elements
            else
            {
                if (left_half[l] < right_half[r])
                {
                    list[next] = left_half[l];
                    l++;
                }

                else if (left_half[l] > right_half[r])
                {
                    list[next] = right_half[r];
                    r++;
                }

                // IF
                // the two elements are equal
                else
                {
                    list[next] = left_half[l];
                    list[next + 1] = right_half[r];
                    next++, l++, r++;
                }
            }
        }

        return 0;
    }

    return 12;
}
