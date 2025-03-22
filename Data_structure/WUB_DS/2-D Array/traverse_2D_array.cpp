#include <stdio.h>

int a[50][50], m, n;

int main()
{
    int i, j;
    printf("\nEnter number of rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("\nEnter elements of 2-D array:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n\n2-D array traversing:\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
