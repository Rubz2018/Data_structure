#include <stdio.h>

int main()
{
    int temperatures[] = {25, 28, 30, 32, 35, 30, 28};
    int size = sizeof(temperatures) / sizeof(temperatures[0]);
    int anomalyTemp = 35;

    for (int i = 0; i < size; i++)
    {
        if (temperatures[i] == anomalyTemp)
        {
            printf("Anomaly found at index %d.\n", i);
            return 0;
        }
    }

    printf("Anomaly not found.\n");
    return 1;
}