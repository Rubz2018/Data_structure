#include <stdio.h>
int main()
{
    int x = 10;                             // Declare an integer variable
    int *p = &x;                            // Declare a pointer and store the address of x
    printf("Value of x: %d\n", x);          // Prints 10
    printf("Address of x: %p\n", &x);       // Prints the address of x
    printf("Pointer p: %p\n", p);           // Prints the address stored in pointer p (same as &x)
    printf("Value pointed by p: %d\n", *p); // Dereferencing the pointer gives the value of x (10)
    return 0;
}