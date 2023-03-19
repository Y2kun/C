#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player1();
int player2();

int main() {
    srand(time(NULL));
    int p1 = 0, p2 = 0;

    while (p1 < 25 && p2 < 25) {
        p1 += player1();
        p2 += player2();
    }
    if (p1 > p2) {printf("Player 1 WINS!!!");}
    if (p1 < p2) {printf("Player 2 WINS!!!");}

    return 0;
}

int player1() {
    int score = 0, rng = rand() % 6 + 1;
    printf("Player 1, it is your turn\n");
    while (rng != 6) {
        rng = rand() % 6 + 1;
        score += rng;
        printf("%i ", rng);
    }
    printf("\n");
    return score;
}

int player2() {
    int score = 0, rng = 0;
    printf("Player 2, it is your turn\n");
    while (rng != 6) {
        rng = rand() % 6 + 1;
        score += rng;
        printf("%i ", rng);
    }
    printf("\n");
    return score;
}