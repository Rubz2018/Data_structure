#include <stdio.h>
#include <time.h>

int main()
{
    char arr[] = {'C', 'B', 'G', 'A', 'F', 'H', 'D', 'L', 'E', 'K', 'N', 'P', 'Q', 'R', 'T', 'U', 'V', 'W'};
    int n = sizeof(arr) / sizeof(arr[0]);
    char target;
    clock_t start, end;
    double cpu_time_used;

    // Display the original array
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");

    // Input character to search
    printf("Enter the character to search: ");
    scanf(" %c", &target);

    // Start timing the linear search
    start = clock();

    // Linear search implementation
    int found = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found = i;
            break;
        }
    }

    // End timing the linear search
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found != -1)
        printf("Character '%c' found at index %d\n", target, found);
    else
        printf("Character '%c' not found in the array\n", target);

    printf("Time taken for linear search: %f seconds\n", cpu_time_used);

    return 0;
}
