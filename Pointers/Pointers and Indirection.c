#include <stdio.h>

// Function prototype: takes a pointer to an integer
void Intvalue(int *ptr);

int main(void)
{
    int Data = 0;
    int Choose;
    int *PtrData = NULL;
    PtrData = &Data;

    printf("\n\tTHIS PROGRAM ALLOWS A USER TO PRINT AND ASSIGN INFO TO POINTERS VIA INDIRECTION\n");

    do {
        printf("\n\t\tMENU\n");
        printf("1\tEnter new Integer value\n");
        printf("2\tPrint Pointer Address\n");
        printf("3\tPrint Integer Address\n");
        printf("4\tPrint Integer Value\n");
        printf("5\tQuit\n");
        printf("Choose a Selection from 1-5: ");
        scanf("%d", &Choose);
        printf("\n");

        switch(Choose) {
            case 1:
                // Calls a function to modify the integer value through its pointer.
                Intvalue(PtrData);
                break;
            case 2:
                // Prints the memory address stored in the pointer.
                printf("The memory address of the pointer PtrData is %p\n", (void *)PtrData);
                break;
            case 3:
                // Prints the actual memory address of the integer variable.
                printf("The memory address of the integer Data is %p\n", (void *)&Data);
                break;
            case 4:
                // Prints the value of the integer variable.
                printf("The value of integer Data is %d\n", Data);
                break;
            case 5:
                printf("Program Exited.\n");
                return 0;
            default:
                printf("You entered the wrong option. Refer to the menu and enter a proper option.\n");
                break;
        }
    } while (Choose != 5);

    return 0;
}

// This function takes a pointer and uses indirection to modify the value it points to.
void Intvalue(int *ptr)
{
    printf("Enter a new integer value: ");
    scanf("%d", ptr); // Using the pointer to modify the original variable via indirection
    printf("Integer value successfully entered.\n");
}
