#include <stdio.h>

int main()
{
    int a[10], i;

    // Prompt user for input
    printf("Enter 10 integers:\n");

    // Input array elements
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    // Output array elements
    printf("The entered integers are:\n");
    for (i = 0; i < 10; i++)
        printf("  %d\n", a[i]);

    // printf("\n"); // Add a newline for better formatting
    return 0;
}
