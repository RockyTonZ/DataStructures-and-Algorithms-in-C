#include <stdio.h>

#define ARRAY_SIZE 10
int arr[ARRAY_SIZE] = {12, 54, 2, 1, 33, 10, 14, 233, 13, 99};
int main(void)
{
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Print the sorted array
    printf("[");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (i == ARRAY_SIZE - 1)
        {
            printf("%i", arr[i]);
        }
        else
        {
            printf("%i, ", arr[i]);
        }
    }
    printf("]\n");

    return 0;
}