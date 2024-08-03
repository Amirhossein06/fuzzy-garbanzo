#include <cs50.h>
#include <stdio.h>

// Define the death rate and birth rate
#define DEATH_RATE 4
#define BORN_RATE 3

// Main function to run the program
int main(void)
{
    // Get the starting size of the llama population from the user
    int start_size;
    do
    {
        // Keep asking for input until a valid starting size is entered (at least 9)
        start_size = get_int("start size: ");
    }
    while (start_size < 9);

    // Get the ending size of the llama population from the user
    int end_size;
    do
    {
        // Keep asking for input until a valid ending size is entered (greater than or equal to starting size)
        end_size = get_int("end size: ");
    }
    while (end_size < start_size);

    // Initialize variables to keep track of years and llama population
    int years = 0;
    int current_size = start_size;

    // Loop through each year until the population reaches the desired size
    while (current_size < end_size)
    {
        // Calculate the number of llamas born in this year
        int llama_born = current_size / BORN_RATE;

        // Calculate the number of llamas that died in this year
        int llama_passed = current_size / DEATH_RATE;

        // Update the current size of the llama population
        current_size = current_size + llama_born - llama_passed;

        // Increment the number of years
        years++;
    }

    // Print the number of years it took to reach the desired population size
    printf("Years: %d\n", years);

    return 0;
}
