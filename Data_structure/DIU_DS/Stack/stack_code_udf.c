#include <stdio.h>

int add(int x, int y)
{
    int c;
    c = x + y;
    return c;
}

int summation()
{
    int a = 4, b = 7;
    return a + b;
}

void sum1(void)
{
    int a = 10, b = 20;

    printf("f-3 Sum is : %d\n", a + b);
}

void addition(int x, int y)
{
    int c;
    c = x + y;
    printf(" f-4 sum = %d\n", c);
}

int main()
{
    int a = 40, b = 70;
    int sum;
    sum = add(a, b);
    printf("f-1 SUM= %d\n", sum);

    int y = summation();
    printf("f-2 sum = %d\n", y);

    sum1();

    addition(40, 60);

    return 0;
}