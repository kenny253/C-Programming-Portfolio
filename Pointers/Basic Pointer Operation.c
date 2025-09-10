#include <stdio.h>

int main(void)
{
    // Part 1: Basic Pointer Assignment
    int iAge = 30;
    int *ptrAge = NULL;

    // Assigning the address of a variable to a pointer
    ptrAge = &iAge;

    // Assigning a non-pointer value using indirection
    int x = *ptrAge;

    // Modifying the original value via the pointer
    *ptrAge = 7;

    printf("\n*ptrAge = %p\n", (void *)ptrAge);
    printf("&iAge = %p\n", (void *)&iAge);
    printf("The value of x is now %d\n\n", x);

    // Part 2: Pointers and Indirection
    int y = 5;
    int *iPtr = NULL;

    printf("Pointer *iPtr points to %p\n", (void *)iPtr);

    // Assign memory address of integer y to pointer
    iPtr = &y;
    printf("Pointer now points to %p\n", (void *)iPtr);

    // Assign the value of y to x via pointer indirection
    x = *iPtr;
    printf("The value of x is now %d\n", x);

    // Change the value of y to 15 via the pointer
    *iPtr = 15;
    printf("The value of y is now %d\n", y);

    printf("y, x, and iptr occupy memory spaces %p, %p, %p\n", &y, &x, iPtr);

    return 0;
}
