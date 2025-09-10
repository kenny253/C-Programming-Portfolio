#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes for encryption and decryption.
void encrypt(char [], int);
void decrypt(char [], int);

int main(void)
{
    char mystring[21] = {0};
    int iSelection = 0;
    int iRand;

    // Seed the random number generator using the current time.
    srand(time(NULL));
    // Generate an initial random key between 1 and 4.
    iRand = (rand() % 4) + 1;

    while (iSelection != 4) {
        printf("\n1\tEncrypt clear text\n");
        printf("2\tDecrypt cypher text\n");
        printf("3\tGenerate a new key\n");
        printf("4\tQuit\n");
        printf("Select a cryptography option: ");
        scanf("%d", &iSelection);

        switch(iSelection) {
            case 1:
                printf("\nEnter one word as a clear text to encrypt: ");
                scanf("%s", mystring); // Note: This can cause a buffer overflow with long input.
                encrypt(mystring, iRand);
                break;
            case 2:
                printf("\nEnter a cypher text to decrypt: ");
                scanf("%s", mystring); // Note: This can cause a buffer overflow with long input.
                decrypt(mystring, iRand);
                break;
            case 3:
                // Generate a new random key.
                iRand = (rand() % 4) + 1;
                printf("\nNew key generated\n");
                break;
        }
    }
    return 0;
}

// Function to encrypt a message using a Caesar cipher.
void encrypt(char sMessage[], int random)
{
    int x = 0;
    // Encrypt by shifting each character's ASCII value.
    while (sMessage[x]) {
        sMessage[x] += random;
        x++;
    }

    x = 0;
    printf("\nThe encrypted message is: \n");
    // Print the encrypted message.
    while (sMessage[x]) {
        printf("%c", sMessage[x]);
        x++;
    }
}

// Function to decrypt a message.
void decrypt(char sMessage[], int random)
{
    int x = 0;
    // Decrypt by reversing the ASCII shift.
    while (sMessage[x]) {
        sMessage[x] -= random;
        x++;
    }

    x = 0;
    printf("\nThe Decrypted message is: ");
    // Print the decrypted message.
    while (sMessage[x]) {
        printf("%c", sMessage[x]);
        x++;
    }
}
