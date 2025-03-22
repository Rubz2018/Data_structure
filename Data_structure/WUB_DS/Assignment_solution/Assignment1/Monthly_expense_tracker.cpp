#include <stdio.h>

int main()
{
    int expenses[30], n, i, sum = 0, threshold;

    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    printf("Enter the expenses:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &expenses[i]);
    }

    printf("Enter the expense threshold: ");
    scanf("%d", &threshold);

    for (i = 0; i < n; i++)
    {
        sum += expenses[i];
        if (expenses[i] > threshold)
        {
            printf("Expense %d exceeds the threshold.\n", i + 1);
        }
        else
        {
            printf("Expense %d is within the threshold.\n", i + 1);
        }
    }

    float average = (float)sum / n;

    printf("\nTotal expenses: %d\n", sum);
    printf("Average expense: %.2f\n", average);

    return 0;
}