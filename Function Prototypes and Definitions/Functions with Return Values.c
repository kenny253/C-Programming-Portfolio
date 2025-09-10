#include <stdio.h>

// Function prototype: This function will return an integer.
int getsecondnum(void);

int main(void)
{
    int num1;
    printf("Enter number: ");
    scanf("%d", &num1);
    printf("You entered %d and %d numbers\n", num1, getsecondnum());

    return 0;
}

// Function definition: Gets a number from the user and returns it.
int getsecondnum(void)
{
    int num;
    printf("Enter a second number: ");
    scanf("%d", &num);
    return num;
}
