#include <stdio.h>

void transpose();
int a[10][10], b[10][10], m, n;

int main()
{
    int i, j;
    printf("\nEnter number of rows & columns: ");
    scanf("%d%d", &m, &n);

    printf("\nEnter elements of 2-D array:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\n\n2-D array before transposing:\n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("\t%d", a[i][j]);
        printf("\n\n");
    }

    transpose();

    printf("\n\n2-D array after transposing:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("\t%d", b[i][j]);
        printf("\n\n");
    }

    return 0;
}

void transpose()
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            b[j][i] = a[i][j];
}
