#include <stdio.h>

#define ARRAY_SIZE 10

int arr[ARRAY_SIZE] = {12, 54, 2, 1, 33, 10, 14, 233, 13, 99};

int main()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    printf("[");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (i == ARRAY_SIZE - 1)
        {
            printf("%i", arr[i]);
            continue;
        }
        printf("%i, ", arr[i]);
    }
    printf("]");
}