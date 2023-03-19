#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 4
#define MAXTEMPT 12

// WORK IN PROGRESS

int main() {
    srand(time(NULL));
    int initKey[LENGTH] = {};
    char key[LENGTH+1] = {};
    for(int i = 0; i < LENGTH; i++) {
        initKey[i] = rand() % 6;
    }

    //Assigning Letters
    for(int i = 0; i <= LENGTH; i++) {
        switch (initKey[i]) {
            case 0: key[i] = 'A'; break;
            case 1: key[i] = 'B'; break;
            case 2: key[i] = 'C'; break;
            case 3: key[i] = 'D'; break;
            case 4: key[i] = 'E'; break;
            case 5: key[i] = 'F'; break;
        }
    }
    key[LENGTH+1] = '\0';

    printf("MASTERMIND\n\n");
    printf("I have already selected %i Letters, Its your turn\n", LENGTH);
    printf("All possible Letters are the following:  A B C D E F");

    for(int l = 0; l < MAXTEMPT; l++) {
        int correct = 0, similar = 0;
        char input[LENGTH+1] = {};

        //Input
        printf("\nPlease input your decision (e.g. ABCD ):");
        scanf("%s", input);

        //Comparisons
        for(int i = 0; i < LENGTH; i++) {
            if(input[i] == key[i]) {correct++;}
            else {
                for(int z = 0; z < LENGTH; z++) {
                    if(input[i] == key[z]) {similar++;}
                }
            }
        }

        //WINNING
        if(correct == LENGTH) {printf("You Have guessed the right combination!!!  =)\n");return 0;}
        //Information
        printf("Correct count is: %i\n", correct);
        printf("Similar count is: %i\n", similar);
    }
    //LOSING
    printf("You lost, how unfortunate :|, please play again");
    printf("\nThe key is: %s\n", key);
    return 0;
}
