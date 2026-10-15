#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Required for "bool", "true", and "false"
#include <stdlib.h>  // Required for rand() and srand()
#include <time.h>    // Required for time() to seed the random generator

// Function to generate the computer's choice
int generate_computer_choice() {
    // rand() % 3 generates a number: 0, 1, or 2
    // Adding 1 shifts it to: 1 (Rock), 2 (Paper), or 3 (Scissors)
    return (rand() % 3) + 1;
}

int main() {
    // Seeding the random number generator once at the start of main
    srand(time(NULL));

    bool choice = true;
    char answer[10] = "yes"; // Initialized so the loop starts
    int user_move;

    while (choice) {
        // 1. Ask the user if they want to play or continue
        printf("Do you want to play? (yes/no): ");
        scanf("%9s", answer);

        if (strcmp(answer, "no") == 0) {
            printf("You said no. Goodbye!\n");
            choice = false; // Exits the loop
        } 
        else {
            // 2. Present game choices
            printf("\nPick one answer from the choices below:\n");
            printf("1. Rock\n2. Paper\n3. Scissors\n");
            printf("Enter number (1-3): ");
            scanf("%d", &user_move);

            // 3. Generate computer choice
            int comp_move = generate_computer_choice();

            // Print what the computer chose
            if (comp_move == 1) printf("Computer chose: Rock\n");
            else if (comp_move == 2) printf("Computer chose: Paper\n");
            else if (comp_move == 3) printf("Computer chose: Scissors\n");
            
            printf("-------------------------------\n");
            // You can add your win/loss logic right here!
        }
    }

    return 0;
}
