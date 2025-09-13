#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook {
    char name[50];
    char phone[20];
} Book;

int main(void) {
    Book *contacts = NULL;
    int size = 0;        // number of contacts
    int option;

    // Reserve the first block of memory
    contacts = calloc(1, sizeof(Book));
    if (contacts == NULL) {
        printf("Out of Memory!\n");
        return 1;
    }

    printf("\tTHE PHONEBOOK PROGRAM\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a new contact\n");
        printf("2. Modify an existing contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // clear newline from buffer

        switch (option) {
        case 1: {
            // Expand memory for a new contact
            size++;
            contacts = realloc(contacts, size * sizeof(Book));
            if (contacts == NULL) {
                printf("Out of Memory!\n");
                return 1;
            }

            printf("Enter name: ");
            fgets(contacts[size - 1].name, 50, stdin);
            contacts[size - 1].name[strcspn(contacts[size - 1].name, "\n")] = '\0';

            printf("Enter phone number: ");
            fgets(contacts[size - 1].phone, 20, stdin);
            contacts[size - 1].phone[strcspn(contacts[size - 1].phone, "\n")] = '\0';

            printf("Contact added successfully!\n");
            break;
        }
        case 2: {
            if (size == 0) {
                printf("No contacts to modify.\n");
                break;
            }
            int index;
            printf("Enter contact number to modify (1 - %d): ", size);
            scanf("%d", &index);
            getchar();

            if (index < 1 || index > size) {
                printf("Invalid contact number.\n");
                break;
            }

            printf("Enter new name: ");
            fgets(contacts[index - 1].name, 50, stdin);
            contacts[index - 1].name[strcspn(contacts[index - 1].name, "\n")] = '\0';

            printf("Enter new phone number: ");
            fgets(contacts[index - 1].phone, 20, stdin);
            contacts[index - 1].phone[strcspn(contacts[index - 1].phone, "\n")] = '\0';

            printf("Contact modified successfully!\n");
            break;
        }
        case 3: {
            if (size == 0) {
                printf("No contacts available.\n");
                break;
            }
            printf("\nYour Contacts:\n");
            for (int i = 0; i < size; i++) {
                printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
            }
            break;
        }
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (option != 4);

    free(contacts);
    return 0;
}
