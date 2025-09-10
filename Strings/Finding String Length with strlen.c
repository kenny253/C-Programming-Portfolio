#include <stdio.h>
#include <string.h> // Required for strlen()

int main(void)
{
    // STRLEN() - It is used to check for the length or number of characters of the string.
    char *str1 = "Vine";
    char str2[] = "Michael";

    printf("The length of string 1 is %zu\n", strlen(str1));
    printf("The length of string 2 is %zu\n", strlen(str2));

    return 0;
}
