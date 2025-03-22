#include <stdio.h>

int main()
{
    int array[100], n, i, j, element1, element2;
    int found1 = 0, found2 = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter two elements to delete: ");
    scanf("%d %d", &element1, &element2);

    int original_size = n;

    for (i = 0; i < n; i++)
    {
        if (array[i] == element1)
            found1 = 1;
        if (array[i] == element2)
            found2 = 1;

        if (array[i] == element1 || array[i] == element2)
        {
            for (j = i; j < n - 1; j++)
            {
                array[j] = array[j + 1];
            }
            n--;
            i--;
        }
    }

    if (!found1)
    {
        printf("This element (%d) cannot be deleted as it does not exist.\n", element1);
    }
    if (!found2)
    {
        printf("This element (%d) cannot be deleted as it does not exist.\n", element2);
    }

    if (original_size == n)
    {
        printf("No elements were deleted.\n");
    }
    else
    {
        printf("Updated array: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
