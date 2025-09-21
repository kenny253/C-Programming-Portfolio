#include <stdio.h>
#include <stdlib.h>  // for exit()

int main(void) {
    FILE *pRead;
    char name[50];

    pRead = fopen("names.dat", "r");//"r" means the file names.dat is opened in read only format
    if (pRead == NULL) {
        printf("\nFile cannot be opened\n");
        exit(1); // quit program if file not found
    } else {
        printf("\nContents of names.dat\n\n");
    }

    // read first word from the file
    while (fscanf(pRead, "%49s", name) == 1) {//means: keep looping only while you actually read a word ie whenever a word is read the loop returns a 1
    //In case u want to read a name with a white space u used the fgets function as follows
    //while(fgets(name, sizeof name, pRead) != NULL){
   // name[strcspn(name, "\n")] = '\0';

        printf("%s\n", name);
    }

    fclose(pRead); // close the file
    return 0;
}
/*To successfully run this program and not get the error message u first have to create a file on
ur computer called name.dat so the program can read the information in this file */
