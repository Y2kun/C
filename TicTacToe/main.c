#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 3
#define HIGHT 3

//Incomplete

void draw(char array[WIDTH] [HIGHT]);

int main() {
    srand(time(NULL));
    char board[WIDTH] [HIGHT] = {'\0'};
    int data[WIDTH] [HIGHT] = {};
    int x = 0, y = 0, count = 0, turn = 0, vic = 0;

    printf("TIC TAC TOE: THE GAME\n\n");

    draw(board);

    //Mainloop
    while(count < WIDTH * HIGHT && vic == 0) {
        //Player 1
        while(turn == 0) {
            if(x <= 0 || y <= 0 || x >= WIDTH || y >= HIGHT || turn == 0) {
                printf("Please place your X, the x-, then the y-position:");
                scanf("%i %i", &x, &y);
                x--; y--;
                if(board[x] [y] == 'X' || board[x] [y] == 'O') { printf("No!\n");}
                else {
                    board [x] [y] = 'X';
                    turn = 1;
                    count++;
                }
                draw(board);
            }
        }


        //Player 2
        while(turn == 1) {
            if(x <= 0 || y <= 0 || x >= WIDTH || y >= HIGHT || turn == 1) {
                int rngW = rand() % WIDTH, rngH = rand() % HIGHT;

                if(board[rngW] [rngH] == 'X' || board[rngW] [rngH] == 'O') { printf("No!\n");}
                else {
                    board [rngW] [rngH] = 'O';
                    turn = 0;
                    count++;
                }
                draw(board);
            }
        }
    }

    if(count == WIDTH * HIGHT) { printf("It is a draw");}
    if(vic == 1) { printf("You won!");}
    if(vic == 2) { printf("You lost :(");}
    return 0;
}

void draw(char board[WIDTH] [HIGHT]) {
    for(int i = 0; i < WIDTH; i++) {printf(" %i", i+1);}
    printf("\n");
    for(int i = 0; i < HIGHT; i++) {
        printf("%i", i+1);
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i] [j]);
        }
        printf("\n");
    }
}