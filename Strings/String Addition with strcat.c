#include <stdio.h>
#include <string.h>

int main(void)
{
//GLUING CONTENTS OF ONE STRING TO ANOTHER
char str1[11] = "Coding in ";
char *str2 = "C language";

printf("Strings glued together contains: %s", strcat(str1, str2));
/*the second string argument (str2) is glued to the first
string argument (str1). After gluing the two strings, the strcat() function returns
the value in str1. Note that I had to include an extra space at the end of str1 “Coding
in”, because the strcat() function does not add a space between the two merged strings.*/
}
