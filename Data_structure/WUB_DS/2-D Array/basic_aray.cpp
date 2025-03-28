#include <stdio.h>
int main()
{
    // array declaration and initialization
    int my_array[5][3] = {
        {1, 2, 3},    // row 0
        {4, 5, 6},    // row 1
        {7, 8, 9},    // row 2
        {10, 11, 12}, // row 3
        {13, 14, 15}  // row 4
    };
    // accessing and printing the elements
    for (int i = 0; i < 5; i++)
    {
        // variable i traverses the rows
        for (int j = 0; j < 3; j++)
        {
            // variable j traverses the columns
            printf("my_array [%d][%d] = %d\n", i, j, my_array[i][j]);
        }
    }
    return 0;
}