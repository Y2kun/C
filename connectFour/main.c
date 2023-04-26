#include <stdio.h>
#include <stdlib.h>

#define WIDTH 7
#define HEIGHT 6
#define WINLENGTH 4
#define NOBODY ' '
#define P1 'x'
#define P2 'o'

//It`s alive!!!

void active(char board[WIDTH][HEIGHT], char);
int getMove(char board[WIDTH][HEIGHT], char);
void draw(char board[WIDTH][HEIGHT]);
int gravity(char board[WIDTH][HEIGHT], int);
int winCheck(char board[WIDTH][HEIGHT]);

int main() {
    char board[WIDTH][HEIGHT] = {};
    printf("CONNECT FOUR: THE GAME\n\n");

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            board[x][y] = NOBODY;
        }
    }

    draw(board);

    //Main
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        active(board, P1); //Player 1
        active(board, P2); //Player 2
    }
    printf("It's a draw!!!");
    return 0;
}

void active(char board[WIDTH][HEIGHT], char p) {
    int x = getMove(board, p);
    int y = gravity(board, x);
    if (x != -1) {board[x][y] = p;}
    if (winCheck(board) == p) {
        draw(board);
        printf("Player %c WINS!!!\n", p);
        exit(0);
    }
    draw(board);
}

int getMove(char board[WIDTH][HEIGHT], char p) {
    int y = -1;
    printf("Place %c at,(1-%i) :", p - 32, WIDTH);

    while (y < 0 || y > WIDTH && board[WIDTH - 1][y] != NOBODY) {
        scanf("%i", &y);
    }
    return y - 1;
}

void draw(char board[WIDTH][HEIGHT]) {
    int k = HEIGHT - 1;
    //drawing the first two lines
    printf("#################\n##|");
    for(int i = 0; i < WIDTH; i++) {
        printf("%i|", i + 1);
    }
    printf("\n");

    //drawing the rest of the board
    for(int y = 0; y < HEIGHT; y++) {
        printf("#%i|", k + 1);

        for(int x = 0; x < WIDTH; x++) {
            printf("%c|", board[x][y]);
        }
        printf("\n");
        k--;
    }
}

int gravity(char board[WIDTH][HEIGHT], int x) {
    //self explanatory
    for(int y = HEIGHT - 1; y >= 0; y--) {
        if(board[x][y] == NOBODY) {return y;}
    }
    return -1;
}

int winCheck(char board[WIDTH][HEIGHT]) {
    // Did anybody win vertically?
    for (int x = 0; x < WIDTH - WINLENGTH + 1; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int res = board[x][y] + board[x+1][y] + board[x+2][y] + board[x+3][y];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x+i][y] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x+i][y] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win horizontally?
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT - WINLENGTH + 1; y++) {
            int res = board[x][y] + board[x][y+1] + board[x][y+2] + board[x][y+3];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x][y+i] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x][y+i] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win diagonally? (top left-bottom right)
    for (int x = 0; x < WIDTH + WINLENGTH - 1; x++) {
        for (int y = 0; y < HEIGHT - WINLENGTH + 1; y++) {
            int res = board[x][y] + board[x+1][y-1] + board[x+2][y-2] + board[x+3][y-3];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x+i][y-i] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x+i][y-i] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win diagonally? (top right-bottom left)
    for (int x = 0; x < WIDTH - WINLENGTH + 1; x++) {
        for (int y = 0; y < HEIGHT - WINLENGTH + 1; y++) {
            int res = board[x][y] + board[x+1][y+1] + board[x+2][y+2] + board[x+3][y+3];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x+i][y+i] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[x+i][y+i] = P2-32;}
                return P2;
            }
        }
    }
    return 0;
}