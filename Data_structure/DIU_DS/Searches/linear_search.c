#include <stdio.h>

int main()
{
    int c, n, search, array[100];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("Enter value to find\n");
    scanf("%d", &search);

    // Performing Linear Search
    for (c = 0; c < n; c++)
    {
        if (array[c] == search)
        {
            printf("%d found at location %d.\n", search, c + 1);
            return 0; // Exit after finding the element
        }
    }

    printf("Not found! %d isn't present in the list.\n", search);
    return 0;
}
