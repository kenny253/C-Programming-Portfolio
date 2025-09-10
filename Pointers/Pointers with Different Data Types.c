#include <stdio.h>

int main(void)
{
    // Declare pointers for different data types
    int *iPtr = NULL;
    char *cPtr = NULL;
    float *fFloat = NULL;

    // Declare and initialize non-pointer variables
    int iNumber = 5;
    float fNumber = 10;
    char cCharacter = 'J';

    // Assign the addresses of non-pointer variables to their respective pointers
    iPtr = &iNumber;
    cPtr = &cCharacter;
    fFloat = &fNumber;

    // Print the values of the non-pointer variables
    printf("The value of int iNumber is %d\n", iNumber);
    printf("The value of float fNumber is %f\n", fNumber);
    printf("The value of char cCharacter is %c\n", cCharacter);
    printf("\n");

    // Print the values pointed to by the pointers
    printf("The value of Pointer iPtr is %d\n", *iPtr);
    printf("The value of Pointer cPtr is %c\n", *cPtr);
    printf("The value of Pointer fFloat is %f\n", *fFloat);
    printf("\n");

    // Print the memory addresses of the non-pointer variables
    printf("The address of non-pointer value iNumber is %p\n", (void *)&iNumber);
    printf("The address of non-pointer value fNumber is %p\n", (void *)&fNumber);
    printf("The address of non-pointer value cCharacter is %p\n", (void *)&cCharacter);
    printf("\n");

    // Print the memory addresses stored in the pointers
    printf("The address of pointer value iPtr is %p\n", (void *)iPtr);
    printf("The address of pointer value cPtr is %p\n", (void *)cPtr);
    printf("The address of pointer value fFloat is %p\n", (void *)fFloat);

    return 0;
}
