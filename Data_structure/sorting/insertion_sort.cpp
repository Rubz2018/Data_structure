#include <stdio.h>

int main()
{
    int n, array[100], i, t, j;
    printf("How many numbers you want to insert in the array:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the number for array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    // Insertion sort implementation
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            t = array[j];
            array[j] = array[j - 1];
            array[j - 1] = t;
            j--;
        }
    }

    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
