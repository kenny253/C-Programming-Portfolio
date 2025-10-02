#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // File pointers for writing to and reading from the file
    FILE *pWrite;
    FILE *pRead;

    // Character arrays and a float to hold student data
    char fName[20];
    char lName[20];
    char id[15];
    float gpa;

    // --- Writing Student Data to the File ---
    // Open the file "students.dat" in "write" mode ('w').
    // This will create the file if it doesn't exist or erase its contents if it does.
    pWrite = fopen("students.dat", "w");

    // Check if the file was successfully opened.
    if (pWrite == NULL) {
       goto ErrorHandler;
    } else {
        printf("\nEnter student first name, last name, id, and gpa.\n\n");
        printf("Enter Data separated by spaces: ");
        // Use scanf to read input from the user.
        scanf("%s %s %s %f", fName, lName, id, &gpa);

        // Use fprintf to write the formatted data to the file.
        // The file pointer is the first argument.
        fprintf(pWrite, "%s\t%s\t%s\t%.2f\n", fName, lName, id, gpa);
        // Close the file to ensure all data is saved.
        fclose(pWrite);
    }

    // --- Reading Student Data from the File ---
    // Open the same file in "read" mode ('r').
    pRead = fopen("students.dat", "r");

    // Check if the file was successfully opened for reading.
    if (pRead == NULL) {
        goto ErrorHandler;
    } else {
        printf("\nData in the students.dat file are:\n");
        printf("First name\tLast Name\tID\tGPA\n");

        // Loop using fscanf to read data from the file.
        // The loop continues as long as fscanf successfully reads 4 items.
        while (fscanf(pRead, "%s %s %s %f", fName, lName, id, &gpa) == 4) {
            // Print the data that was just read from the file.
            printf("%s\t\t%s\t\t%s\t%.2f\n", fName, lName, id, gpa);
        }
        // Close the file to release its resources.
        fclose(pRead);
    }
    exit(EXIT_SUCCESS);
    ErrorHandler:
        perror("The following error occured");
        exit(EXIT_FAILURE);
    return 0;
}
