#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int generate_random_number(){
    return (rand() % 3) + 1;
    // This geneerates a number between 1 to 3, then adds 1
}

int main(){
    bool choice = true;
    char answer[10] = "yes";
    int user_make_move;

    printf("We are going to play a rock paper scissors game.\n");
    printf("Do you want to play the game? (yes/no) \n");
    scanf("%9s", answer);

    if(strcmp(answer, "no") == 0){
        printf("You chose "no"");
        break;
    }else {
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

