#include <code.h>
#include <stdbool.h>
#include <stdio.h>

void merge_sort(int array[], int size);

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

void merge_sort(int array[], int size)
{
    int length = arlen(array, size);
    if (length <= 1)
    {
        return;
    }
    // Get the length of the left and right half
    int l_length = length / 2;
    int r_length = length - l_length;

    // Create arrays to store the two halves of the list
    int left_half[l_length], right_half[r_length];

    // Make the left half
    for (int l = 0; l < l_length; l++)
    {
        left_half[l] = array[l];
    }

    // Make the right half
    for (int r = 0; r < r_length; r++)
    {
        right_half[r] = array[(l_length + r)];
    }
    merge_sort(left_half, sizeof(left_half));
    merge_sort(right_half, sizeof(right_half));

    // SORT AND MERGE.
    int left = 0, right = 0;
    bool skip = false;
    for (int index = 0; index < length; index++)
    {
        if (skip)
        {
            skip = false;
            continue;
        }

        // If the elements in the left half have finished.
        if (left == l_length && right < r_length)
        {
            array[index] = right_half[right];
            right++;
        }

        // If the elements in the right half have finished
        else if (left < l_length && right == r_length)
        {
            array[index] = left_half[left];
            left++;
        }

        // ELSE
        // if both halves still have elements
        else if (left < l_length && right < r_length)
        {
            if (left_half[left] < right_half[right])
            {
                array[index] = left_half[left];
                left++;
            }

            else if (left_half[left] > right_half[right])
            {
                array[index] = right_half[right];
                right++;
            }

            // If the two elements are equal
            else
            {
                array[index] = left_half[left];
                array[index + 1] = right_half[right];
                left++, right++;
                skip = true;
            }
        }
    }
}
