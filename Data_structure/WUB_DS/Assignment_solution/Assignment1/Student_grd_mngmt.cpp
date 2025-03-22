#include <stdio.h>

int main()
{
    int grades[100], n, i, sum = 0, highest, lowest;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the grades of %d students:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &grades[i]);
    }

    highest = lowest = grades[0];
    for (i = 1; i < n; i++)
    {
        sum += grades[i];
        if (grades[i] > highest)
        {
            highest = grades[i];
        }
        if (grades[i] < lowest)
        {
            lowest = grades[i];
        }
    }

    float average = (float)sum / n;

    printf("\nHighest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);
    printf("Average grade: %.2f\n", average);

    return 0;
}