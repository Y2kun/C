#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BMARBELS 10
#define PLAYER0 0
#define PLAYER1 1

int main() {
    srand(time(NULL));
    int rng = 0, p0marble = BMARBELS, p1marble = BMARBELS, p0bet = 0, in = 0, turn = 0;
    turn = rand() % 2;

    while (p0marble > 0 && p1marble > 0) {
        if (turn == PLAYER0) {
            rng = rand() % p1marble + 1;
            printf("It is your turn\n");
            printf("You have %i marble(s)\n", p0marble);
            printf("Please input the amount of marbles you want to bet: ");
            if (!scanf("%i", & p0bet)) {
                printf("Input is not valid, please only input full numbers\n");
                return 1;
            }
            if (p0bet > p0marble) {
                printf("Input too high\n");
                continue;
            } else if (p0bet < 1) {
                printf("Input too low\n");
                continue;
            } else {
                printf("Please input 0 if the opponents number is even\n");
                printf("Please input 1 if the opponents number is odd\n");
                scanf("%i", & in );

                if (rng % 2 == rng % p0bet) {
                    p0marble = p0marble + p0bet;
                    p1marble = p1marble - p0bet;
                    printf("You won %i marble(s)\n", p0bet);
                } else {
                    p0marble = p0marble - p0bet;
                    p1marble = p1marble + p0bet;
                    printf("You lost %i marble(s)\n", p0bet);
                }
            }
            turn = PLAYER1;
        } else if (turn == PLAYER1) {
            printf("It is the opponents turn\n");
            printf("It has %i marble(s)\n", p1marble);

            if (p1marble <= 0) {
                printf("Opponent has no marbles left");
            } else {
                printf("Please input the amount of marbles you want to bet: ");
                if (!scanf("%i", & p0bet)) {
                    printf("Input is not valid, please only input full numbers\n");
                    return 1;
                }

                if (p0bet > p0marble || p0bet > p1marble) {
                    printf("Input to high\n");
                    return 1;
                } else if (p0bet < 1) {
                    printf("Input to low\n");
                    return 1;
                } else {
                    if (rng % 2 == rng % p0bet) {
                        p0marble = p0marble - p0bet;
                        p1marble = p1marble + p0bet;
                        printf("You lost %i marble(s)\n", p0bet);
                    } else {
                        p0marble = p0marble + p0bet;
                        p1marble = p1marble - p0bet;
                        printf("You won %i marble(s)\n", p0bet);
                    }
                }
            }
            turn = PLAYER0;
        }
    }

    if (p0marble >= p1marble) {
        printf("\nYou won (*^o^*)\n");
    } else {
        printf("\nYou lost (>_<)\n");
    }
    return 0;
}
