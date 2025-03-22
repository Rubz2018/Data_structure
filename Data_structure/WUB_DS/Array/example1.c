#include <stdio.h>

int main()
{
    int temps[7], i;
    float sum = 0, avg;

    // Input temperatures for 7 days
    printf("Enter temperatures for 7 days:\n");
    for (i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%d", &temps[i]);
        sum += temps[i];
    }

    // Calculate average
    avg = sum / 7;
    printf("Average temperature of the week: %.2f\n", avg);

    return 0;
}
