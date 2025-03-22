#include <stdio.h>

int main()
{
    char arr[] = {'g', 'a', 't', 'b', 'z', 'm', 'p'};
    int n = sizeof(arr) / sizeof(arr[0]);
    char target;

    // Sorting the array using Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");

    // Input character to search
    printf("Enter the character to search: ");
    scanf(" %c", &target);

    // Binary search implementation
    int left = 0, right = n - 1, mid, found = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            found = mid;
            break;
        }

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (found != -1)
        printf("Character '%c' found at index %d\n", target, found);
    else
        printf("Character '%c' not found in the array\n", target);

    return 0;
}
