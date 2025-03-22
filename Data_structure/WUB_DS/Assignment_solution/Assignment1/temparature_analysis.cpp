#include <stdio.h>

int main()
{
    int temps[7], i, sum = 0, hottest, coldest, hot_days = 0;

    printf("Enter the temperatures for 7 days:\n");
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &temps[i]);
    }

    hottest = coldest = temps[0];
    for (i = 1; i < 7; i++)
    {
        sum += temps[i];
        if (temps[i] > hottest)
        {
            hottest = temps[i];
        }
        if (temps[i] < coldest)
        {
            coldest = temps[i];
        }
        if (temps[i] > 30)
        {
            hot_days++;
        }
    }

    float average = (float)sum / 7;

    printf("\nHottest temperature: %d\n", hottest);
    printf("Coldest temperature: %d\n", coldest);
    printf("Average temperature: %.2f\n", average);
    printf("Number of days above 30°C: %d\n", hot_days);

    return 0;
}