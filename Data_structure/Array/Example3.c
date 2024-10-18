#include <stdio.h>

int main()
{
    int arr[10] = {12, 4, 56, 23, 89, 2, 34, 67, 90, 11}, max, i;

    max = arr[0];
    for (i = 1; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Maximum number in the array is: %d\n", max);

    return 0;
}
