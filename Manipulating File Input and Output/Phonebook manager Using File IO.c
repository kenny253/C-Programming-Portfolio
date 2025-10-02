#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold contact data
typedef struct {
    char fName[20];
    char lName[20];
    char number[20];
} Contact;

// Function prototypes
void printPhoneBook(void);
void modifyContact(void);
void deleteContact(void);

int main(void) {
    Contact newContact;
    int response;
    FILE *pFile;

    // Loop until user chooses Exit
    do {
        // Display menu
        printf("\n\tPHONE BOOK\n\n");
        printf("1. Add a new phone book entry\n");
        printf("2. Print phone book\n");
        printf("3. Modify an entry\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d", &response);
        getchar(); // clear newline left in buffer

        switch (response) {
            case 1:
                // --- Add a new contact ---
                printf("\nEnter first name: ");
                scanf("%s", newContact.fName);
                printf("Enter last name: ");
                scanf("%s", newContact.lName);
                printf("Enter phone number: ");
                scanf("%s", newContact.number);

                // Open file for appending
                pFile = fopen("phone_book.dat", "a");
                if (pFile != NULL) {
                    fprintf(pFile, "%s %s %s\n",
                            newContact.fName,
                            newContact.lName,
                            newContact.number);
                    fclose(pFile);
                    printf("\nContact added successfully.\n");
                } else {
                    perror("Error opening file");
                }
                break;

            case 2:
                // --- Print contacts ---
                printPhoneBook();
                break;

            case 3:
                // --- Modify contact ---
                modifyContact();
                break;

            case 4:
                // --- Delete contact ---
                deleteContact();
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid selection. Please try again.\n");
                break;
        }

    } while (response != 5);

    return EXIT_SUCCESS;
}

/* ---------------------------
   Function: printPhoneBook()
   Reads and displays all contacts
----------------------------*/
void printPhoneBook(void) {
    FILE *pFile = fopen("phone_book.dat", "r");
    Contact contact;

    if (pFile == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n\tPHONE BOOK ENTRIES\n");
    printf("First Name\tLast Name\tPhone Number\n");

    while (fscanf(pFile, "%s %s %s",
                  contact.fName,
                  contact.lName,
                  contact.number) == 3) {
        printf("%s\t\t%s\t\t%s\n",
               contact.fName,
               contact.lName,
               contact.number);
    }

    fclose(pFile);
}

/* ---------------------------
   Function: modifyContact()
   Finds a contact by first name
   and allows editing
----------------------------*/
void modifyContact(void) {
    FILE *pFile = fopen("phone_book.dat", "r");
    Contact contacts[100]; // store contacts in memory
    int count = 0;

    if (pFile == NULL) {
        perror("Error opening file");
        return;
    }

    // Load all contacts
    while (fscanf(pFile, "%s %s %s",
                  contacts[count].fName,
                  contacts[count].lName,
                  contacts[count].number) == 3) {
        count++;
    }
    fclose(pFile);

    char searchName[20];
    printf("\nEnter the first name of the contact to modify: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].fName, searchName) == 0) {
            printf("\nEnter new first name: ");
            scanf("%s", contacts[i].fName);
            printf("Enter new last name: ");
            scanf("%s", contacts[i].lName);
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact not found.\n");
        return;
    }

    // Rewrite all contacts
    pFile = fopen("phone_book.dat", "w");
    for (int i = 0; i < count; i++) {
        fprintf(pFile, "%s %s %s\n",
                contacts[i].fName,
                contacts[i].lName,
                contacts[i].number);
    }
    fclose(pFile);
    printf("\nContact modified successfully.\n");
}

/* ---------------------------
   Function: deleteContact()
   Removes a contact by first name
----------------------------*/
void deleteContact(void) {
    FILE *pFile = fopen("phone_book.dat", "r");
    Contact contacts[100];
    int count = 0;

    if (pFile == NULL) {
        perror("Error opening file");
        return;
    }

    while (fscanf(pFile, "%s %s %s",
                  contacts[count].fName,
                  contacts[count].lName,
                  contacts[count].number) == 3) {
        count++;
    }
    fclose(pFile);

    char searchName[20];
    printf("\nEnter the first name of the contact to delete: ");
    scanf("%s", searchName);

    pFile = fopen("phone_book.dat", "w"); // overwrite file
    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].fName, searchName) != 0) {
            fprintf(pFile, "%s %s %s\n",
                    contacts[i].fName,
                    contacts[i].lName,
                    contacts[i].number);
        } else {
            deleted = 1;
        }
    }
    fclose(pFile);

    if (deleted)
        printf("\nContact deleted successfully.\n");
    else
        printf("\nContact not found.\n");
}
