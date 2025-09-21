#include <stdio.h>
#include <stdlib.h>

//THIS PROGRAM WORKS BY READING PAIR OF STRINGS SEPERATED BY A SPACE
int main(void) {
    char name[50];
    char hobby[50];
    FILE *pRead;

    pRead = fopen("hobby.dat", "r");   // open file for reading

    if (pRead == NULL) {
        printf("File cannot be opened!\n");
        exit(1);  // quit program if file not found
    } else {
        printf("\nName\tHobby\n\n");
    }

    // read pairs of strings until fscanf fails
    while (fscanf(pRead, "%49s %49s", name, hobby) == 2) {
        printf("%s\t%s\n", name, hobby);
    }

    fclose(pRead); // always close files
    return 0;
}
/*To successfully run this program and not get the error message u first have to create a file on
ur computer called hobby.dat so the program can read the information in this file */
