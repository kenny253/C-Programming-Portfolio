#include <stdio.h>

// A global variable can be accessed by any function.
int luckynumber;

// Function prototype: This function doesn't take any parameters because it uses
// the global variable.
void printluckynumber(void);

int main(void)
{
    printf("Enter a number: ");
    scanf("%d", &luckynumber);

    // Call the function; it will use the value stored in the global variable.
    printluckynumber();

    return 0;
}

// Function definition: Accesses the global 'luckynumber' to print its value.
void printluckynumber(void)
{
    printf("The number you entered was %d\n", luckynumber);
}
