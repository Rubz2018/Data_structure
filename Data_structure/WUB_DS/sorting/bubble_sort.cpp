#include <stdio.h>
int main()
{
    int data[100], i, n, step, temp;
    printf("How many number you want insert in array:\n");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        printf("\nEnter the number of data[%d]:", i);
        scanf("%d", &data[i]);
    }

    for (step = 0; step < n - 1; step++)
        for (i = 0; i < n - step - 1; i++)
        {
            if (data[i] > data[i + 1])
            {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
    printf("In ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", data[i]);
    return 0;
}
