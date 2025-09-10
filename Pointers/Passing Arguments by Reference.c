#include <stdio.h>

// Function prototype: takes a pointer to an integer
void demoPassByReference(int *);

int main(void)
{
    int x = 0;

    printf("\nEnter number: ");
    scanf("%d", &x);

    demoPassByReference(&x);

    printf("\nx is currently %d\n", x);

    return 0;
}

// Function that modifies the value of a variable using a pointer.
void demoPassByReference(int *ptrx)
{
    *ptrx += 5;
    printf("The value of x is now %d\n", *ptrx);
}
