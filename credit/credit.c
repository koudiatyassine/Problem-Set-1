#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for credit card number
    long long cc_number;
    do
    {
        cc_number = get_long("Number: ");
    }
    while (cc_number <= 0);

    // Count digits in cc_number
    int count = 0;
    long long digits = cc_number;
    while (digits > 0)
    {
        digits /= 10;
        count++;
    }

    // Validate card length and starting digits
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Arrays to store card digits
    int card_digits[count];
    int index = count - 1;
    digits = cc_number;
    while (digits > 0)
    {
        card_digits[index] = digits % 10;
        digits /= 10;
        index--;
    }

    // Apply Luhn's algorithm
    int sum = 0;
    for (int i = count - 2; i >= 0; i -= 2)
    {
        int digit = card_digits[i] * 2;
        sum += (digit % 10) + (digit / 10);
    }
    for (int i = count - 1; i >= 0; i -= 2)
    {
        sum += card_digits[i];
    }

    // Check validity
    if (sum % 10 == 0)
    {
        // Determine card type
        if ((count == 13 || count == 16) && card_digits[count - 1] == 4)
        {
            printf("VISA\n");
        }
        else if (count == 15 && card_digits[count - 1] == 3 && (card_digits[count - 2] == 4 || card_digits[count - 2] == 7))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && card_digits[count - 1] == 5 && card_digits[count - 2] >= 1 && card_digits[count - 2] <= 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
