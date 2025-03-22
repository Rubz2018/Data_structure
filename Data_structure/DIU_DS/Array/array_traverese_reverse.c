#include <stdio.h>

int main()
{
    int a[10], n, i, temp;

    printf("Enter a number less than 11 : ");
    scanf("%d", &n);
    if (n > 10)
        return 0;

    printf("Enter %d elements for the array : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Inserted elements of the array : \n");
    for (i = 0; i < n; i++)
    {
        printf("Element[%d] = %d\n", i, a[i]);
    }

    // Reverse the array
    for (i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    printf("Reversed elements of the array : \n");
    for (i = 0; i < n; i++)
    {
        printf("Element[%d] = %d\n", i, a[i]);
    }

    return 0;
}