#include <stdio.h>
#include <stdlib.h>

void add();
int a[10][10], b[10][10], c[10][10], m, n, x, y;

int main()
{
    int i, j;

    printf("\nEnter number of rows & columns of array A: ");
    scanf("%d%d", &m, &n);

    printf("\nEnter elements of array A:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter number of rows & columns of array B: ");
    scanf("%d%d", &x, &y);

    if (m != x || n != y)
    {
        printf("Error: Matrices must have the same dimensions to be added.\n");
        return 1;
    }

    printf("\nEnter elements of array B:\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n\nArray A:\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }

    printf("Array B:\n\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("\t%d", b[i][j]);
        }
        printf("\n\n");
    }

    add();

    printf("Resultant Array after Addition (Array C):\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", c[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}

void add()
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
