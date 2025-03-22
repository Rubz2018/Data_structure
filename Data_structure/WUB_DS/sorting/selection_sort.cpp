#include <stdio.h>
#include <stdlib.h>
int main()
{
    int data[100], i, n, steps, t;
    printf("How many number you want insert in array:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the number of data[%d]:", i);
        scanf("%d", &data[i]);
    }

    for (steps = 0; steps < n; steps++)
        for (i = steps + 1; i < n; i++)
        {
            if (data[steps] > data[i])
            {
                t = data[steps];
                data[steps] = data[i];
                data[i] = t;
            }
        }
    printf("In ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", data[i]);
    return 0;
}
