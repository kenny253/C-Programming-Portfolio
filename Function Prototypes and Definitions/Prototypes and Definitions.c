#include <stdio.h>

/* Function Prototypes */
int remainderFinder(int, int);      // Finds remainder of a / b
int findLarger(int, int);           // Returns the larger of two numbers
void atmmenu(void);                 // Displays ATM menu

/* Main Function */
int main(void)
{
    printf("Remainder of 10 %% 3 is: %d\n", remainderFinder(10, 3));
    printf("Larger number between 10 and 5 is: %d\n", findLarger(10, 5));
    atmmenu();

    return 0;
}

/* Function Definitions */

// 1. Remainder Function
int remainderFinder(int a, int b)
{
    return a % b;
}

// 2. Find Larger Function
int findLarger(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// 3. ATM Menu Function
void atmmenu(void)
{
    printf("Welcome to the ATM!\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw\n");
    printf("3. Deposit\n");
    printf("4. Quit\n");
}
