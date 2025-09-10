// Simple Phonebook
// This program demonstrates the use of structs, arrays of structs,
// with functions to create a basic phonebook. It allows the user
// to add names and then prints all the names entered.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to hold a single phonebook entry.
// This one holds a character array for the name.
typedef struct {
    char name[50];
} book;

// Function prototypes to declare the functions before they are used.
void addnumber(book *entries, int *count);
void printbook(const book *entries, int count);

int main(void)
{
    // Create a fixed-size array of 5 'book' structs to hold phonebook entries.
    book phonebook[5];
    int count = 0; // Tracks the number of entries added to the phonebook.

    printf("PHONE BOOK\n");

    // Call the addnumber function to add entries.
    // We pass the phonebook array and a pointer to the count so the function can modify them.
    addnumber(phonebook, &count);

    // Call the printbook function to display all the entries.
    // We pass the phonebook array and the current count.
    printbook(phonebook, count);

    return 0;
}

// Function to add new entries to the phonebook.
// It takes a pointer to the array and a pointer to the entry count.
void addnumber(book *enter, int *count)
{
    int resp = 0;

    // Loop to allow the user to add multiple entries, up to the limit of 5.
    while (resp != 2 && *count < 5) {
        printf("\nPress 1 to enter a new friend's name or 2 to cancel: ");

        // Read the user's response.
        if (scanf("%d", &resp) != 1) {
            // Handle invalid input (e.g., a letter instead of a number)
            while (getchar() != '\n'); // Clear the input buffer
            continue; // Go to the next loop iteration
        }

        // Clear the input buffer after reading the number.
        while (getchar() != '\n');

        if (resp == 1) {
            printf("Enter a friend's name: ");

            // Use fgets() for safe input to prevent buffer overflow.
            // fgets() reads the entire line, including the newline character.
            fgets(enter[*count].name, 50, stdin);

            // Remove the newline character that fgets() adds at the end.
            enter[*count].name[strcspn(enter[*count].name, "\n")] = '\0';

            // Increment the entry count.
            (*count)++;
        }
    }
}

// Function to print all the entries in the phonebook.
// It takes a constant pointer to the array (meaning it cannot be modified)
// and the current entry count.
void printbook(const book *print, int count)
{
    int x;

    printf("\nYour Phone-book entries are:\n");

    // Loop through the entries and print each name.
    for (x = 0; x < count; x++) {
        printf("%s\n", print[x].name);
    }
}
