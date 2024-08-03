#include <cs50.h>
#include <stdio.h>

// Function to print a single row of the pyramid
void print_p(int i, int height)
{
    // Calculate the number of spaces and hashes needed for this row
    int hc = i + 1; // number of hashes on the center
    int sc = height - (i + 1); // number of spaces

    // Print the spaces
    for (int j = 0; j < sc; j++)
    {
        // Put a space on the screen
        putc(' ', stdout);
    }

    // Print the hashes
    for (int j = 0; j < hc; j++)
    {
        // Put a hash on the screen
        putc('#', stdout);
    }

    // Print a space and another space
    putc(' ', stdout);
    putc(' ', stdout);

    // Print the remaining hashes
    for (int j = 0; j < hc; j++)
    {
        // Put a hash on the screen
        putc('#', stdout);
    }
}

// Main function to run the program
int main(void)
{
    // Get the height of the pyramid from the user
    int height;

    do
    {
        // Keep asking for input until a valid height is entered (between 1 and 8)
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Loop through each row of the pyramid, printing it using the print_p function
    for (int i = 0; i < height; i++)
    {
        // Print the current row
        print_p(i, height);
        printf("\n");
    }
}
