#include <stdio.h>
#include <stdlib.h>

// Function prototype for ReadData.
void ReadData(void);

int main(void) {
    // File pointer for writing to the file
    FILE *pWrite;
    // Character arrays to store the name and hobby
    char name[20];
    char hobby[20];

    // Read and display the current file contents before appending new data
    printf("\nCurrent file contents:\n");
    ReadData();

    // Prompt the user to enter new information
    printf("\nEnter new name and hobby leaving a space between each entry: ");
    // Use scanf to read the name and hobby from the user
    scanf("%s%s", name, hobby);

    // Open the data file "hobby.dat" in "append" mode ('a').
    // This mode adds new data to the end of the file without erasing existing contents.
    pWrite = fopen("hobby.dat", "a");

    // Check if the file was successfully opened.
    // If pWrite is NULL, it means the file couldn't be opened.
    if (pWrite == NULL) {
        printf("\nFile could not be opened\n");
        // Exit the program with a non-zero status to indicate an error.
        exit(1);
    } else {
        // Write the new name and hobby to the file with a tab and newline
        // for better formatting.
        fprintf(pWrite, "%s\t%s\n", name, hobby);
        // Close the file to ensure the data is saved.
        fclose(pWrite);

        // Read and display the file again to show the newly added data
        // and confirm the append was successful.
        ReadData();
    }

    return 0;
}

// Function to read and display the data from the file
void ReadData(void) {
    // File pointer for reading from the file
    FILE *pRead;
    char hobby[20];
    char name[20];

    // Open the file "hobby.dat" in "read" mode ('r').
    pRead = fopen("hobby.dat", "r");

    // Check if the file was successfully opened.
    if (pRead == NULL) {
        printf("\nFile could not be opened!\n");
    } else {
        printf("\nInformation contained in data file hobby.dat are:\n");
        printf("Name\tHobby\n");

        // Loop using fscanf to read data from the file.
        // The loop continues as long as it successfully reads 2 items.
        while (fscanf(pRead, "%s%s", name, hobby) == 2) {
            // Print the data that was just read, formatted with tabs.
            printf("%s\t%s\n", name, hobby);
        }

        // Close the file to release resources.
        fclose(pRead);
    }
}
//If the file hobby.dat does not exist the the program creates the file and appends the
//info entered by the user to the end of file when ever the program is run and new information is entered
