#include <stdio.h>
int main()
{
    int array[100], n, i, location = 0;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for (i = 1; i < n; i++)
        if (array[i] > array[location])
            location = i;
    printf("Maximum element is present at location %d and its value is %d.\n",
           location + 1, array[location]);
    return 0;
}