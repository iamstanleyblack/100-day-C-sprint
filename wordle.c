#include <stdio.h>
#include <string.h>

int main() {
    // The welcome message print to the screen
    printf("Welcome to Wordle!\n");

    // Store the secret word in an array of characters
    char secret_word[] = "candy";

    // Create an array to hold the 5 result letters (G, Y, or B)
    char results[5];

    // Create an array to track available letters (size 6 for the hidden end character)
    char remaining_letters[6];

    // Copy the secret word into our remaining_letters tracker
    strcpy(remaining_letters, secret_word);

    // Prompt the user to type their guess
    printf("Enter your guess: ");

    // Create an array to store the 5-letter guess from the user
    char the_guess[6];

    // Read exactly 5 characters from the keyboard into the_guess array
    scanf("%5s", the_guess);

    // PASS 1: Loop through each of the 5 letters to find exact matches (Greens)
    for (int i = 0; i < 5; i++) {
        // Check if the guessed letter perfectly matches the secret word letter in the same spot
        if (the_guess[i] == secret_word[i]) {
            // Mark this spot in our results array as a Green ('G')
            results[i] = 'G';
            // Replace the matched letter with an asterisk so it cannot be reused
            remaining_letters[i] = '*';
        } else {
            // If it is not a perfect match yet, put a blank space as a placeholder
            results[i] = ' ';
        }
    }

    // PASS 2: Loop through the 5 letters again to find partial matches (Yellows) and misses (Blacks)
    for (int i = 0; i < 5; i++) {
        // If we already marked this exact spot as 'G' in the first pass, skip to the next letter
        if (results[i] == 'G') {
            continue;
        }

        // Create a tracker to remember if we find a Yellow match (0 means no, 1 means yes)
        int found = 0;

        // Look through our remaining_letters pool to see if the guessed letter exists anywhere
        for (int j = 0; j < 5; j++) {
            // Check if the current guessed letter matches a letter in the pool
            if (the_guess[i] == remaining_letters[j]) {
                // We found a match! Mark the result as Yellow ('Y')
                results[i] = 'Y';
                // Remove it from the pool by replacing it with an asterisk
                remaining_letters[j] = '*';
                // Update our tracker so we know we found it
                found = 1;
                // Stop searching the pool for this specific letter since we already found a match
                break;
            }
        }

        // If we checked the whole pool and our tracker still says 0 (not found)
        if (found == 0) {
            // Mark the result as a Black ('B')
            results[i] = 'B';
        }
    }

    // Print the final result prefix
    printf("Result: ");

    // Loop through our finished results array one last time
    for (int i = 0; i < 5; i++) {
        // Print each result letter followed by a space
        printf("%c ", results[i]);
    }

    // Print a new line at the very end to keep the terminal clean
    printf("\n");

    // End the program successfully
    return 0;
}
