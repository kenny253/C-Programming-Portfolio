#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declare and initialize string pointers.
    char *str1 = "Analyzing strings with the strstr() function";
    char *str2 = "ing";
    char *str3 = "xyz";

    // Print the strings for clarity.
    printf("\nstr1 = \"%s\"\n", str1);
    printf("str2 = \"%s\"\n", str2);
    printf("str3 = \"%s\"\n", str3);

    // Use strstr() to search for str2 in str1.
    // The function returns a pointer to the first occurrence of str2 if found, otherwise it returns NULL.
    if (strstr(str1, str2) != NULL) {
        printf("\nstr2 was found in str1\n");
    } else {
        printf("\nstr2 was not found in str1\n");
    }

    // Use strstr() to search for str3 in str1.
    if (strstr(str1, str3) != NULL) {
        printf("str3 was found in str1\n");
    } else {
        printf("str3 was not found in str1\n");
    }

    /*
     * As u can see from the preceding program, the strstr() function takes two strings as arguments.
     * The strstr() function looks for the first occurrence of the second argument in the
     * first argument. If the string in the second argument is found in the string in the first argument,
     * the strstr() function returns a pointer to the string in the first argument. Otherwise
     * NULL is returned.
     */

    return 0;
}
