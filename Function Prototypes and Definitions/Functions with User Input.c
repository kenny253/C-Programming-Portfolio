#include <stdio.h>

// Function prototype
int addtwoNumbers(int, int);

int main(void)
{
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Call the function with the numbers entered by the user.
    int result = addtwoNumbers(num1, num2);
    printf("The numbers are %d\n", result);

    return 0;
}

// Function definition
int addtwoNumbers(int operand1, int operand2)
{
    return operand1 + operand2;
}
