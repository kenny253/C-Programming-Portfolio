#include <stdio.h>

// Function prototype: Declares the function before it's used.
// It tells the compiler about the function's return type and name.
void printreportheader(void);

int main(void)
{
    // Call the function to print the header
    printreportheader();

    return 0;
}

// Function definition: Contains the actual code for the function.
// It prints a simple header with four columns.
void printreportheader(void)
{
    printf("\nColumn1\tColumn2\tColumn3\tColumn4\n");
}
