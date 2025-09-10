#include <stdio.h>

// Function prototypes
int addTwoNumbers(int, int);
int subtractTwoNumbers(int, int);

int main(void)
{
    int num1 = 10, num2 = 5;

    // Call both functions and print the results
    int sum = addTwoNumbers(num1, num2);
    int difference = subtractTwoNumbers(num1, num2);

    printf("The sum is: %d\n", sum);
    printf("The difference is: %d\n", difference);

    return 0;
}

// Function definition for addition
int addTwoNumbers(int num1, int num2)
{
    return num1 + num2;
}

// Function definition for subtraction
int subtractTwoNumbers(int num1, int num2)
{
    return num1 - num2;
}
