#include <stdio.h>

// Function prototypes to pass read-only arguments.
void printArgument(const int *);
void printArray(const int []);

int main(void)
{
    // Part 1: Passing a read-only integer
    int iNumber = 5;
    printArgument(&iNumber);

    // Part 2: Passing a read-only array
    int iNumbers[3] = {2, 4, 5};
    printArray(iNumbers);

    return 0;
}

// Function that takes a read-only pointer argument.
void printArgument(const int *num)
{
    printf("\nRead-only argument is %d\n", *num);
}

// Function that takes a read-only array argument.
void printArray(const int iNumber[])
{
    printf("\nRead-only array numbers are:\n");
    for (int x = 0; x < 3; x++) {
        printf("%d\n", iNumber[x]);
    }
}
