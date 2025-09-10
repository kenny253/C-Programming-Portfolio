#include <stdio.h>

// Function prototype to build function prototypes to accept arrays
int namelength(char[]);

int main(void)
{
    // Part 1: Pointers with Arrays
    int array[5] = {1, 2, 3, 4, 5};
    int *iPtr = array;

    printf("The address of pointer %p\n", (void *)iPtr);
    printf("The address of the first array value %p\n", (void *)&array[0]);
    printf("Pointer points to %d\n", *iPtr);
    printf("First array index contains value %d\n\n", array[0]);

    // Part 2: Arrays as Function Arguments
    char name[50] = {'\0'};

    printf("\nEnter your first name: ");
    scanf("%s", name);
    printf("Your first name is %d characters long\n", namelength(name));

    return 0;
}

// Function to calculate string length
int namelength(char name[])
{
    int x = 0;
    while (name[x] != '\0')
        x++;
    return x;
}
