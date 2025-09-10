#include <stdio.h>
#include <stdlib.h> // Required for atof() and atoi()

int main(void)
{
    // CONVERTING A STRING TO FLOAT AND INTEGER
    char *str1 = "120.55";
    char *str2 = "55";

    float x;
    int y;

    printf("The value of str1 is %s\n", str1);
    printf("String 2 is \"%s\"\n", str2);
    printf("\n");

    x = atof(str1); // atof() is used to convert a string to a float
    y = atoi(str2); // atoi() is used to convert a string to an int

    printf("The value of str1 converted to float is %.2f\n", x);
    printf("The value of str2 converted to int is %d\n", y);

    return 0;
}
