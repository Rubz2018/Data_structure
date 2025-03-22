#include <stdio.h>

int main()

{

    int array[100], search, i, n, newindex;

    printf("Enter number of elements in array\n");

    scanf("%d", &n);

    printf("Enter %d integer(s)\n", n);

    for (i = 0; i < n; i++)

        scanf("%d", &array[i]);

    printf("Enter a number to search\n");

    scanf("%d", &search);

    for (i = 0; i < n; i++)

    {

        if (array[i] == search) /* If required element is found */

        {

            newindex = i;

            for (i = newindex; i < n - 1; i++)

                a[i] = a[i + 1];

            break;
        }
    }

    printf("i = %d", i);

    if (i == n)

        printf("%d is n't present in the array.\n", search);

    else
    {

        printf("After Deletion elements of the array are : ");

        for (i = 0; i < n - 1; i++)

            printf("%d ", a[i]);
    }

    return 0;
}