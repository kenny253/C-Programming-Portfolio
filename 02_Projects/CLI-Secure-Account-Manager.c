/*
 * PROJECT TITLE: Banking Program (CLI)
 * DESCRIPTION: A simple command-line interface banking application that allows
 * users to create an account, log in, and manage a balance.
 * User passwords are encrypted using a Caesar Cipher for security demonstration.
 *
 * FILE PERSISTENCE LOGIC: This version achieves persistence for a single user
 * by reading the user's name and encrypted password when logging in, and then
 * completely overwriting the Bank.dat file with the new balance after every
 * transaction (UpdateAcc).
 * -----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Used for the Sleep() function
#include <string.h>  // Used for string manipulation (strcmp, strlen, etc.)
#include <ctype.h>   // Used for islower(), isupper() for encryption

// --- PREPROCESSOR MACROS ---

// MACRO: Standardized error checking. If 'condition' is true (i.e., failed),
// the program immediately jumps to the local ErrorHandler label.
#define CHECK_ERROR(condition) \
if (condition){\
    goto ErrorHandler;\
}

// CONSTANT: The fixed key used for the Caesar Cipher shift.
#define KEY 3
// CONSTANT: The size of the alphabet, necessary for the modulo operation.
#define ALPHABET_SIZE 26


// --- FUNCTION PROTOTYPES ---

// Function to apply the Caesar Cipher for encryption. Takes the string pointer and the key.
char *PasswordEncryption(char *password, int key);
// Function to handle new account creation (writing credentials to file).
void CreateID(void);
// Function to handle user login and authentication and load the balance.
void ConfirmID(void);
// Function to read the current credentials and balance from the file, update the balance, and write all data back.
void UpdateAcc(float);
// Function to change the password incase the user forgets his password
void ChangePassword(void);


// --- GLOBAL STATE ---

// Flag to track user login status (0 = Not logged in, 1 = Logged in).
int Found = 0;
// Global variable to hold the account balance. This value is kept updated in memory.
float AccBalance = 100.00;


// -----------------------------------------------------------------------------
// MAIN PROGRAM LOOP
// -----------------------------------------------------------------------------
int main()
{
    int select = 0;
    float DepositAmt;
    float WithdrawAmt;

    do {
        // Clear screen (optional, for cleaner display)
        system("cls");

        puts("\t\t--- THE BANK PROGRAM ---\n");

        if (Found == 1){
            printf("Current Balance: $%.2f | Status: %s\n\n",
                AccBalance, Found == 1 ? "Logged In" : "Logged Out");
        }

        puts("1.\tCreate a bank account.");
        puts("2.\tLogin into your account.");
        puts("3.\tReset Password.");
        puts("4.\tCheck Balance.");
        puts("5.\tDeposit funds.");
        puts("6.\tWithdraw funds.");
        puts("7.\tQuit.");

        printf("Enter a choice: ");

        // Use scanf to read the integer choice
        if (scanf("%d", &select) != 1) {
            // Handle non-integer input to prevent crashes
            puts("\nInvalid input. Please enter a number.");
            while (getchar() != '\n'); // Clear buffer
            continue; // Skip the rest of the loop and restart
        }

        // Clear the input buffer after scanf, essential for proper fgets usage later
        while (getchar() != '\n');


        switch(select){
        case 1:
            // Reset Found flag before creation attempt, in case a previous attempt failed
            Found = 0;
            CreateID();
            if (Found == 1) { // Only display success messages if creation was successful
                puts("\nAccount Creation in Progress.....\n");
                Sleep(3000); // Pauses program for 3 seconds
                puts("Account Creation Complete\n");
                printf("$%.2f has been awarded into your account\n\n", AccBalance);
            }
            break;

        case 2:
            ConfirmID();
            break;

        case 3:
            ChangePassword();
            break;

        case 4:
            // Prevent access if not logged in
            if (Found != 1) {
                puts("Dear customer, you need to either log in or create an account to access this session.");
                break;
            }

            puts("\nBalance check in progress, please wait....");
            Sleep(3000); // Pauses program for 3 seconds 
            printf("Your Account Balance is: $%.2f\n\n", AccBalance);
            break;

        case 5:
            // Prevent access if not logged in
            if (Found != 1) {
                puts("Dear customer, you need to either log in or create an account to access this session.");
                break;
            }

            printf("\nEnter deposit amount: $");
            if (scanf("%f", &DepositAmt) != 1) {
                puts("\nInvalid deposit amount.");
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n'); // Clear buffer

            if (DepositAmt <= 0) {
                puts("\nDeposit amount must be positive.");
                break;
            }

            AccBalance += DepositAmt;
            UpdateAcc(AccBalance); // Update file with new balance
            puts("\nDear customer, funds have been successfully deposited into account.");
            printf("Current Balance: $%.2f\n\n", AccBalance);
            break;

        case 6:
            // Prevent access if not logged in
            if (Found != 1) {
                puts("Dear customer, you need to either log in or create an account to access this session.");
                break;
            }

            printf("\nEnter amount to withdraw: $");
            if (scanf("%f", &WithdrawAmt) != 1) {
                puts("\nInvalid withdrawal amount.");
                while (getchar() != '\n'); // Clear buffer
                break;
            }
            while (getchar() != '\n'); // Clear buffer

            if (WithdrawAmt <= 0) {
                puts("\nWithdrawal amount must be positive.");
                break;
            } else if (WithdrawAmt > AccBalance){
                printf("\nInsufficient funds\n\n");
            }else{
                AccBalance -= WithdrawAmt;
                UpdateAcc(AccBalance); // Update file with new balance
                printf("Transaction successful. Your current balance is $%.2f\n\n", AccBalance);
            }
            break;

        case 7:
            puts("\nProgram exited successfully....");
            puts("THANK YOU");
            break;

        default:
            puts("\nOption incorrect. Please refer back to the menu!");
            break;
        }

        // Pause to allow user to read output before the menu redraws
        if (select != 7) { // Pause on all options except Quit
            printf("\nPress ENTER to continue...");
            getchar();
        }

    } while (select != 7); // Quit loop on option 7

    return 0;
    // Error handling block for main()
ErrorHandler:
    perror("A fatal error occurred in main");
    exit(EXIT_FAILURE);
    return 0; // Only reachable on error
}


// -----------------------------------------------------------------------------
// FUNCTION DEFINITION: CreateID
// -----------------------------------------------------------------------------
/**
 * Prompts user for a name and password, encrypts the password, and saves both
 * to 'Bank.dat'. Uses calloc for dynamic memory allocation.
 */
void CreateID(void)
{
    FILE *Write = NULL;
    // Allocate memory for user input strings (80 chars each)
    char *UserName = calloc(80, sizeof(char));
    char *UserPassword = calloc(80, sizeof(char));
    int x = 0;

    // Error Check: Ensure memory was allocated successfully (FATAL ERROR)
    CHECK_ERROR(UserName == NULL);
    CHECK_ERROR(UserPassword == NULL);

    printf("\nEnter Name: ");
    // fgets reads the input for user name and save it into UserName
    fgets(UserName, 80, stdin);
    // Remove newline character added by fgets
    UserName[strcspn(UserName, "\n")] = '\0';

    // Loop through the string and convert each character in name to uppercase.
    for (x = 0; x < strlen(UserName); x++) {
        UserName[x] = toupper(UserName[x]);
    }

    printf("\nEnter Password: ");
    // fgets reads the input for user password and save it into UserPassword
    fgets(UserPassword, 80, stdin);
    // Remove newline character added by fgets
    UserPassword[strcspn(UserPassword, "\n")] = '\0';

    // ENCRYPTION STEP: Encrypt the password before writing to the file
    PasswordEncryption(UserPassword, KEY);

    // Reset global state for the new account and set login flag
    AccBalance = 100.00; // Ensure the initial balance is 100.00
    Found = 1; // Assume login success until file write fails.

    // Open the file in write mode ("w"). This will overwrite any existing file.
    Write = fopen("Bank.dat", "w");

    // Handle file open error locally without exiting the program.
    if (Write == NULL) {
        puts("\nERROR: Could not open Bank.dat for writing. Account not saved.");
        Found = 0; // Reset login flag since account wasn't saved
        goto Cleanup; // Jump to cleanup block
    }

    // Write credentials and initial balance to the file (3 lines total)
    fprintf(Write, "%s\n%s\n%.2f\n", UserName, UserPassword, AccBalance);

Cleanup: // Block for freeing memory and closing file pointer before returning
    // Clean up
    if (Write) fclose(Write);
    free(UserName);
    free(UserPassword);

    return; // Return to main() loop

    // Error handling block for CreateID() - ONLY for fatal memory allocation failure
ErrorHandler:
    // If an error occurred (only memory allocation failure), attempt to free memory before exiting
    if (UserName) free(UserName);
    if (UserPassword) free(UserPassword);
    perror("Error during account creation (Fatal Memory Error)");
    exit(EXIT_FAILURE);
}


// -----------------------------------------------------------------------------
// FUNCTION DEFINITION: ConfirmID
// -----------------------------------------------------------------------------
/**
 * Prompts user for login details, encrypts the entered password, and compares
 * it against the stored, encrypted credentials in 'Bank.dat'. On success,
 * it sets the global 'Found' flag and loads the saved balance into 'AccBalance'.
 */
void ConfirmID(void)
{
    char EnteredName[100];
    char EnteredPassword[100];
    char StoredNameLine[100];
    char StoredPasswordLine[100];
    float StoredBalance; // Variable to hold the balance read from the file
    int x = 0;
    FILE *Read = NULL;

    // Reset Found flag before login attempt
    Found = 0;

    printf("\nEnter Name: ");
    fgets(EnteredName, sizeof(EnteredName), stdin);
    EnteredName[strcspn(EnteredName, "\n")] = '\0';

    // Loop through the string and convert each character to uppercase.
    // to streamline login
    for (x = 0; x < strlen(EnteredName); x++) {
        EnteredName[x] = toupper(EnteredName[x]);
    }

    printf("\nEnter Password: ");
    fgets(EnteredPassword, sizeof(EnteredPassword), stdin);
    EnteredPassword[strcspn(EnteredPassword, "\n")] = '\0';

    // Open file in read mode ("r")
    Read = fopen("Bank.dat", "r");

    if (Read == NULL) {
        puts("\nERROR: Could not open Bank.dat. Account likely not created yet.");
        return; // Return immediately on non-fatal file open error
    }

    // ENCRYPTION STEP: Encrypt the password the user just typed for comparison
    PasswordEncryption(EnteredPassword, KEY);

    // Read Name and Password line-by-line using fgets to handle spaces and newlines correctly
    // 1. Read Name line
    if (fgets(StoredNameLine, sizeof(StoredNameLine), Read) == NULL) { goto CheckAndContinue; }
    StoredNameLine[strcspn(StoredNameLine, "\n")] = '\0';

    // 2. Read Encrypted Password line
    if (fgets(StoredPasswordLine, sizeof(StoredPasswordLine), Read) == NULL) { goto CheckAndContinue; }
    StoredPasswordLine[strcspn(StoredPasswordLine, "\n")] = '\0';

    // 3. Read the balance
    if (fscanf(Read, "%f", &StoredBalance) != 1) { goto CheckAndContinue; }


    // strcmp returns 0 for equality. (0 == 0) is true.
    // The names must match AND the encrypted passwords must match.
    if (strcmp(StoredNameLine, EnteredName) == 0 && strcmp(StoredPasswordLine, EnteredPassword) == 0){
        printf("\nLogin Successful... WELCOME %s\n\n", EnteredName);
        Found = 1; // Set global flag to success
        AccBalance = StoredBalance; // Update the global balance with the saved value
    }

CheckAndContinue:
    if (Read) fclose(Read); // Ensure file is closed after reading attempt

    if (Found != 1) {
        puts("\nCredentials incorrect or account data is missing/corrupt. Please try again!\n");
    }

    return;

    // The CHECK_ERROR macro is removed here as file open failure is handled non-fatally.
    // If a fatal error occurs (e.g., if a CHECK_ERROR was re-added), it would jump here.
ErrorHandler:
    if (Read) fclose(Read);
    perror("Error during login authentication (Fatal)");
    exit(EXIT_FAILURE);
}


// -----------------------------------------------------------------------------
// FUNCTION DEFINITION: PasswordEncryption
// -----------------------------------------------------------------------------
/**
 * Encrypts the password string *in place* using the Caesar Cipher (Shift by KEY).
 * It only affects alphabetic characters, leaving numbers and symbols alone.
 * password The string to be encrypted/decrypted.
 * key The shift amount (defined by the KEY constant).
 * return A pointer to the modified password string.
 */
char *PasswordEncryption(char *password, int key) {

    int counter = 0;

    // Loop through every character until the end of the string ('\0')
    while (password[counter] != '\0') {
        char store = password[counter]; // Store current char for readability

        // --- Handle Uppercase Letters (A-Z) ---
        if (isupper(store)) {
            // Formula: (Index - Base + Key) % 26 + Base
            password[counter] = ((store - 'A' + key) % ALPHABET_SIZE) + 'A';
        }
        // --- Handle Lowercase Letters (a-z) ---
        else if (islower(store)) {
            // Formula: (Index - Base + Key) % 26 + Base
            password[counter] = ((store - 'a' + key) % ALPHABET_SIZE) + 'a';
        }
        // Non-alphabetic characters (numbers, symbols) are ignored and remain unchanged.

        counter++;
    }

    return password;
}


// -----------------------------------------------------------------------------
// FUNCTION DEFINITION: UpdateAcc
// -----------------------------------------------------------------------------
/**
 * Handles account persistence for a single user.
 * 1. Reads the existing Name and Encrypted Password from Bank.dat.
 * 2. Uses the newAccBalance provided (the updated global balance).
 * 3. Re-opens the file in 'w' (write/overwrite) mode.
 * 4. Writes the old Name, old Password, and the new Balance back.
 * 5. newAccBalance The updated balance value to be saved to the file.
 */
void UpdateAcc(float newAccBalance)
{
    // Use fixed arrays to safely store data read from the file
    char StoredName[100];
    char StoredPassword[100];
    float StoredBal; // Holds the balance read from file, then overwritten by newAccBalance

    FILE *Read = NULL;
    FILE *Write = NULL; // Define Write here for ErrorHandler safety

    // --- STEP 1: READ EXISTING DATA ---
    Read = fopen("Bank.dat", "r");
    CHECK_ERROR(Read == NULL);

    // Read Name and Password line-by-line using fgets to handle spaces correctly.
    // 1. Read Name line
    if (fgets(StoredName, sizeof(StoredName), Read) == NULL) { goto ReadError; }
    StoredName[strcspn(StoredName, "\n")] = '\0';

    // 2. Read Encrypted Password line
    if (fgets(StoredPassword, sizeof(StoredPassword), Read) == NULL) { goto ReadError; }
    StoredPassword[strcspn(StoredPassword, "\n")] = '\0';

    // 3. Read the balance (Not strictly needed for logic, but ensures we read the whole file)
    if (fscanf(Read, "%f", &StoredBal) != 1) { goto ReadError; }

    // Close the file stream after reading
    fclose(Read);
    Read = NULL; // Set to NULL since it's closed

    // --- STEP 2: OVERWRITE FILE ---
    // Open in "w" (write/overwrite) mode to ensure only the updated data remains
    Write = fopen("Bank.dat", "w");
    CHECK_ERROR(Write == NULL);

    // Write the old Name, old Password, and the NEW Balance back to the file
    fprintf(Write, "%s\n%s\n%.2f\n", StoredName, StoredPassword, newAccBalance);

    // Close the file stream after writing
    fclose(Write);

    // Successful return
    return;

ReadError: // Custom label for read error if data format is wrong or incomplete
    if (Read) fclose(Read); // Close Read if it was opened
    perror("Error reading existing account data format.");
    return; // Return instead of exiting for a non-fatal data format error.


// Error handling block for UpdateAcc()
ErrorHandler:
    if (Write) fclose(Write);
    if (Read)  fclose(Read);
    // Note: The error message is generic as the error could occur in read or write phase
    perror("Error during file update process");
    exit(EXIT_FAILURE);
}

// -----------------------------------------------------------------------------
// FUNCTION DEFINITION: ChangePassword
// -----------------------------------------------------------------------------
/**
 * Prompts the user for the account name, verifies it, then prompts for and
 * encrypts a new password. It reads the existing data and overwrites the file
 * with the new encrypted password, preserving the name and balance.
 */
void ChangePassword(void)
{
    FILE *Read = NULL;
    FILE *Write = NULL;
    char EnteredName[100];
    char NewPassword[100];
    char StoredName[100];
    char StoredPassword[100];
    float StoredBalance;
    int x = 0;

    printf("\nResetting password, please wait....\n");
    Sleep(3000);

    printf("Enter account name: ");
    fgets(EnteredName, sizeof(EnteredName), stdin);
    EnteredName[strcspn(EnteredName, "\n")] = '\0';

    // Convert Entered Name to capital letters
    for (x = 0; x < strlen(EnteredName); x++){
        EnteredName[x] = toupper(EnteredName[x]);
    }

    // --- STEP 1: READ EXISTING DATA ---
    Read = fopen("Bank.dat", "r");

    if (Read == NULL) {
        puts("\nERROR: Could not open Bank.dat. Account likely not created yet.");
        return;
    }

    // Read all three fields (Name, Encrypted Password, Balance)
    if (fgets(StoredName, sizeof(StoredName), Read) == NULL) { goto ReadError; }
    StoredName[strcspn(StoredName, "\n")] = '\0';

    if (fgets(StoredPassword, sizeof(StoredPassword), Read) == NULL) { goto ReadError; }
    StoredPassword[strcspn(StoredPassword, "\n")] = '\0';

    if (fscanf(Read, "%f", &StoredBalance) != 1) { goto ReadError; }

    fclose(Read);
    Read = NULL;

    // --- STEP 2: VERIFY AND GET NEW PASSWORD ---
    // Check if the entered name matches the stored name
    if (strcmp(EnteredName, StoredName) == 0){
        printf("\nAccount found. Enter new password: ");
        fgets(NewPassword, sizeof(NewPassword), stdin);
        NewPassword[strcspn(NewPassword, "\n")] = '\0';

        // Password encryption step - on the new password
        PasswordEncryption(NewPassword, KEY);

        // --- STEP 3: OVERWRITE FILE WITH NEW PASSWORD ---
        Write = fopen("Bank.dat", "w");
        CHECK_ERROR(Write == NULL);

        // Write the stored name, the NEW encrypted password, and the stored balance
        fprintf(Write, "%s\n%s\n%.2f\n", StoredName, NewPassword, StoredBalance);

        fclose(Write);
        Write = NULL;

        // Since the password changed, we must also update the global AccBalance and Found state
        // if the user was currently logged in, to force a re-login.
        if (Found == 1) {
            Found = 0;
            puts("\nPassword successfully changed. Please log in again with your new password.");
        } else {
            puts("\nPassword successfully changed.");
        }

    } else {
        puts("\nError: Account name not found.");
    }

    return;

ReadError: // Custom label for read error if data format is wrong or incomplete
    if (Read) fclose(Read); // Close Read if it was opened
    puts("Error: Account data file is corrupted or incomplete.");
    return;

    // Error handling block for ChangePassword() - handles only the fopen failure from CHECK_ERROR
ErrorHandler:
    if (Write) fclose(Write);
    if (Read) fclose(Read);
    perror("Error during password change (Fatal)");
    exit(EXIT_FAILURE);
}