#include <stdio.h>

int main(void)
{
    // A pointer to a string literal
    char *mystring = "Mike";
    int x;

    // The value of the pointer is the memory address of the first character.
    // The asterisk `*` here dereferences the pointer to get the value,
    // which is the first character.
    printf("The pointer variable's value is %c\n", *mystring);

    // Printing the string pointed to by the pointer.
    printf("The pointer variable points to: %s\n", mystring);
    printf("The memory location for each character are: \n\n");

    // Access and print the address of each character in hexadecimal format.
    for (x = 0; x < 5; x++) {
        // The pointer `mystring` is an array of characters, so we can
        // use array notation `mystring[x]` to get to each character.
        // `&mystring[x]` gets the address of that character.
        printf("%p\n", &mystring[x]);
    }

    return 0;
}
