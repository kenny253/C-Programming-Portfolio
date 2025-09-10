#include <stdio.h>
#include <string.h>
#include <ctype.h> // Required for tolower() and toupper()

// CONVERTING FROM LOWER CASE TO UPPER CASE AND VICE VERSA
// Function prototypes
void convertL(char *);
void convertU(char *);

int main(void)
{
    char name1[] = "Michael";
    char name2[] = "Vine";

    convertL(name1);
    convertU(name2);

    return 0;
}

// Function to convert a string to lowercase.
void convertL(char *str)
{
    int x;

    for (x = 0; x < strlen(str); x++) {
        str[x] = tolower(str[x]);
    }
    printf("First name converted to lower case is %s\n", str);
}

// Function to convert a string to uppercase.
void convertU(char *str)
{
    int x;

    for (x = 0; x < strlen(str); x++) {
        str[x] = toupper(str[x]);
    }
    printf("last name converted to upper case is %s\n", str);
}
