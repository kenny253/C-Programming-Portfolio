#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each contact
typedef struct {
    char name[50];
    char phone[20];
} Contact;

void loadContacts(Contact **contacts, int *size);
void saveContacts(Contact *contacts, int size);
void addContact(Contact **contacts, int *size);
void viewContacts(Contact *contacts, int size);
void modifyContact(Contact *contacts, int size);
void deleteContact(Contact **contacts, int *size);
void searchContact(Contact *contacts, int size);

int main(void) {
    Contact *contacts = NULL;
    int size = 0;
    int option;

    // Load contacts from file (if any exist)
    loadContacts(&contacts, &size);

    do {
        printf("\n\t📞 DYNAMIC PHONEBOOK MANAGER\n");
        printf("1. Add a new contact\n");
        printf("2. View all contacts\n");
        printf("3. Modify a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Search for a contact\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // clear newline

        switch (option) {
            case 1: addContact(&contacts, &size); break;
            case 2: viewContacts(contacts, size); break;
            case 3: modifyContact(contacts, size); break;
            case 4: deleteContact(&contacts, &size); break;
            case 5: searchContact(contacts, size); break;
            case 6:
                printf("\nSaving contacts and exiting...\n");
                saveContacts(contacts, size);
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }
    } while (option != 6);

    free(contacts); // free memory before closing
    return 0;
}

// ---------------------------------------------
// Load contacts from file into memory
// ---------------------------------------------
void loadContacts(Contact **contacts, int *size) {
    FILE *fp = fopen("contacts.dat", "r");
    if (fp == NULL) return; // no file yet, just skip

    Contact temp;
    while (fscanf(fp, "%49[^|]|%19[^\n]\n", temp.name, temp.phone) == 2) {
        *contacts = realloc(*contacts, (*size + 1) * sizeof(Contact));
        (*contacts)[*size] = temp;
        (*size)++;
    }
    fclose(fp);
}

// ---------------------------------------------
// Save all contacts to file
// ---------------------------------------------
void saveContacts(Contact *contacts, int size) {
    FILE *fp = fopen("contacts.dat", "w");
    if (fp == NULL) {
        printf("Error saving contacts.\n");
        return;
    }
    for (int i = 0; i < size; i++)
        fprintf(fp, "%s|%s\n", contacts[i].name, contacts[i].phone);
    fclose(fp);
}

// ---------------------------------------------
// Add a new contact to the list
// ---------------------------------------------
void addContact(Contact **contacts, int *size) {
    Contact newContact;
    printf("\nEnter name: ");
    fgets(newContact.name, 50, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';
    printf("Enter phone number: ");
    fgets(newContact.phone, 20, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    *contacts = realloc(*contacts, (*size + 1) * sizeof(Contact));
    (*contacts)[*size] = newContact;
    (*size)++;

    printf("Contact added successfully!\n");
}

// ---------------------------------------------
// View all contacts
// ---------------------------------------------
void viewContacts(Contact *contacts, int size) {
    if (size == 0) {
        printf("\nNo contacts to display.\n");
        return;
    }
    printf("\nYour Contacts:\n");
    for (int i = 0; i < size; i++)
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
}

// ---------------------------------------------
// Modify an existing contact
// ---------------------------------------------
void modifyContact(Contact *contacts, int size) {
    if (size == 0) {
        printf("\nNo contacts to modify.\n");
        return;
    }
    int index;
    printf("\nEnter contact number to modify (1 - %d): ", size);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > size) {
        printf("Invalid contact number.\n");
        return;
    }

    printf("Enter new name: ");
    fgets(contacts[index - 1].name, 50, stdin);
    contacts[index - 1].name[strcspn(contacts[index - 1].name, "\n")] = '\0';
    printf("Enter new phone number: ");
    fgets(contacts[index - 1].phone, 20, stdin);
    contacts[index - 1].phone[strcspn(contacts[index - 1].phone, "\n")] = '\0';

    printf("Contact modified successfully!\n");
}

// ---------------------------------------------
// Delete a contact
// ---------------------------------------------
void deleteContact(Contact **contacts, int *size) {
    if (*size == 0) {
        printf("\nNo contacts to delete.\n");
        return;
    }
    int index;
    printf("\nEnter contact number to delete (1 - %d): ", *size);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *size) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = index - 1; i < *size - 1; i++)
        (*contacts)[i] = (*contacts)[i + 1];

    (*size)--;
    *contacts = realloc(*contacts, (*size) * sizeof(Contact));
    printf("Contact deleted successfully!\n");
}

// ---------------------------------------------
// Search for a contact by name
// ---------------------------------------------
void searchContact(Contact *contacts, int size) {
    if (size == 0) {
        printf("\nNo contacts to search.\n");
        return;
    }
    char search[50];
    printf("\nEnter name to search: ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcasecmp(contacts[i].name, search) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("No contact found with that name.\n");
}
