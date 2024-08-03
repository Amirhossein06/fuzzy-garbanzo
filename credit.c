#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Get the card number from the user.
    string card_number;
    do
    {
        card_number = get_string("Number: ");
    }
    // Keep asking for input until a valid card number is entered.
    while (card_number == NULL || strlen(card_number) == 0);

    // Initialize variables to store the sum of the digits and the count of digits.
    int sum = 0;
    int digit_count = 0;

    // Loop through the card number from right to left (i.e., from last digit to first).
    for (int i = strlen(card_number) - 1; i >= 0; i--)
    {
        // Convert the current digit to an integer.
        int digit = card_number[i] - '0';

        // Check if this is an odd-position digit (i.e., the first, third, fifth, etc.).
        if (digit_count % 2 == 1)
        {
            // Double the value of the digit.
            digit *= 2;

            // If the doubled value is greater than 9, add 1 to it.
            if (digit > 9)
            {
                digit = digit % 10 + 1;
            }
        }

        // Add the current digit to the sum.
        sum += digit;
        // Increment the digit count.
        digit_count++;
    }

    // Check if the sum of the digits is divisible by 10.
    if (sum % 10 == 0)
    {
        // Check which bank the card belongs to based on its length and first few digits.
        if ((strlen(card_number) == 15) &&
            (strncmp(card_number, "34", 2) == 0 || strncmp(card_number, "37", 2) == 0))
        {
            printf("amex\n");
        }
        else if ((strlen(card_number) == 16) &&
                 (strncmp(card_number, "51", 2) == 0 || strncmp(card_number, "52", 2) == 0 ||
                  strncmp(card_number, "53", 2) == 0 || strncmp(card_number, "54", 2) == 0 ||
                  strncmp(card_number, "55", 2) == 0))
        {
            printf("mastercard\n");
        }
        else if ((strlen(card_number) == 13 || strlen(card_number) == 16) &&
                 strncmp(card_number, "4", 1) == 0)
        {
            printf("visa\n");
        }
        else
        {
            printf("invalid\n");
        }
    }
    else
    {
        printf("invalid\n");
    }

    return 0;
}
