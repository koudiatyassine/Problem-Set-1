#include <stdio.h>
#include <cs50.h> // For using the cs50 library for input validation

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8); // Ensure height is between 1 and 8 inclusive

    // Loop to print each row of the pyramid
    for (int row = 1; row <= height; row++)
    {
        // Print spaces for left pyramid
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }
        // Print hashes for left pyramid
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // New line between left and right pyramids
        printf("  ");

        // Print hashes for right pyramid
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}
