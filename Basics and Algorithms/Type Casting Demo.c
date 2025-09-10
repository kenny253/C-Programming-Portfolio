/*
 * TYPE CASTING
 *
 * Type casting enables C programmers to force one variable of a certain type
 * to be another type, an important consideration especially when dealing with
 * integer division. For all its power, type casting is simple to use. As
 * demonstrated next, just surround a data type name with parentheses followed
 * by the data or variable for which you want to type cast.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 10;
    int y = 20;

    printf("\nWithout typecast\n");
    // This will perform integer division, resulting in 0, even with a float format specifier.
    printf("The value of 10 / 20 is %.2f\n", x / y);

    printf("\nWith typecast\n");
    // By casting the integers to floats, a floating-point division is performed.
    printf("The value of 10 / 20 is %.2f\n", (float)x / (float)y);

    // Type casting is not limited to numbers; you can type cast characters to numbers and vice versa.

    int number = 86;
    char letter = 'M';

    printf("\n86 type-casted to char is: %c\n", (char)number);
    printf("\n'M' type-casted to int is: %d\n", (int)letter);

    // When you type cast letters to numbers and vice versa, you get their ASCII values.
    return 0;
}
