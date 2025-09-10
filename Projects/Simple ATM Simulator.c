#include <stdio.h>

int main(void)
{
    // Declare variables for the ATM simulation.
    int response;
    float balance = 500.00;
    float deposit;
    float withdraw;

    printf("\n--- ATM Menu ---\n");
    printf("Your current balance is: $%.2f\n", balance);
    printf("1. Deposit money\n");
    printf("2. Withdraw money\n");
    printf("What do you want to do today? ");
    scanf("%d", &response);

    // Check if the user wants to deposit money.
    if (response == 1)
    {
        printf("How much do you want to deposit? ");
        scanf("%f", &deposit);
        balance += deposit; // Add the deposit amount to the balance.
        printf("Your new balance is: $%.2f\n", balance);
    }

    // Check if the user wants to withdraw money.
    else if (response == 2)
    {
        printf("How much do you want to withdraw? ");
        scanf("%f", &withdraw);

        // Check if there are sufficient funds before withdrawing.
        if (withdraw > balance)
        {
            printf("You do not have sufficient funds.\n");
        }
        else
        {
            balance -= withdraw; // Subtract the withdrawal amount from the balance.
            printf("Your new balance is: $%.2f\n", balance);
        }
    }
    else
    {
        printf("Invalid choice. Please select 1 or 2.\n");
    }

    // --- Profit Calculator (Profit Wiz) ---
    // This section calculates profit based on user input.
    float fRevenue, fCost;

    printf("\n\n--- Profit Wiz ---\n");
    printf("How much revenue did you make this year?\n ");
    scanf("%f", &fRevenue);
    printf("How much did you spend running the business this year?\n ");
    scanf("%f", &fCost);
    printf("You made a profit of $%.2f this year.\n", fRevenue - fCost);

    return 0;
}
