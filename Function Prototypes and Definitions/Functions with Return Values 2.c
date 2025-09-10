#include <stdio.h>

// Function prototype: Declares the function before main().
int addtwonumbers(int, int);

int main(void)
{
    // Call the function with two numbers and store the returned value.
    int result = addtwonumbers(4, 7);
    printf("%d is the result of the calculation\n", result);

    return 0;
}

// Function definition: Takes two integer arguments and returns their sum.
int addtwonumbers(int operand1, int operand2)
{
    return operand1 + operand2;
}
