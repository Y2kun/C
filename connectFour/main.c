#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 6
#define WIDTH 7
#define WINLENGTH 4
#define NOBODY '\0'
#define P1 'x'
#define P2 'o'

//It`s alive!!!

void active(char board[HEIGHT][WIDTH], char);
int getMove(char board[HEIGHT][WIDTH], char);
void draw(char board[HEIGHT][WIDTH]);
int gravity(char board[HEIGHT][WIDTH], int);
int winCheck(char board[HEIGHT][WIDTH]);

int main() {
    char board[HEIGHT][WIDTH] = {NOBODY};
    printf("CONNECT FOUR: THE GAME\n\n");
    draw(board);

    //Main
    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        active(board, P1); //Player 1
        active(board, P2); //Player 2
    }
    printf("It's a draw!!!");
    return 0;
}

void active(char board[HEIGHT][WIDTH], char p) {
    int x = getMove(board, p);
    int y = gravity(board, x);
    if (y != -1) {board[y][x] = p;}
    if (winCheck(board) == p) {
        draw(board);
        printf("Player %c WINS!!!\n", p);
        exit(0);
    }
    draw(board);
}

int getMove(char board[HEIGHT][WIDTH], char p) {
    int x = -1;
    printf("Place %c at,(1-%i) :", p - 32, WIDTH);

    while (x < 0 || x > WIDTH && board[HEIGHT - 1][x] != NOBODY) {
        scanf("%i", &x);
    }
    return x - 1;
}

void draw(char board[HEIGHT][WIDTH]) {
    int k = HEIGHT - 1;
    printf("#################\n##|");
    for(int i = 0; i < WIDTH; i++) {
        printf("%i|", i + 1);
    }
    printf("\n");

    for(int y = 0; y < HEIGHT; y++) {
        printf("#%i|", k + 1);

        for(int x = 0; x < WIDTH; x++) {
            printf("%c|", board[y][x]);
        }
        printf("\n");
        k--;
    }
}

int gravity(char board[HEIGHT][WIDTH], int x) {
    for(int y = HEIGHT - 1; y >= 0; y--) {
        if(board[y][x] == NOBODY) {return y;}
    }
    return -1;
}

int winCheck(char board[HEIGHT][WIDTH]) {
    // Did anybody win vertically?
    for (int y = 0; y < HEIGHT - WINLENGTH + 1; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int res = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+3][x];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y+i][x] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y+i][x] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win horizontally?
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH - WINLENGTH + 1; x++) {
            int res = board[y][x] + board[y][x+1] + board[y][x+2] + board[y][x+3];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y][x+i] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y][x+i] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win diagonally? (top left-bottom right)
    for (int y = 0; y < HEIGHT + WINLENGTH - 1; y++) {
        for (int x = 0; x < WIDTH - WINLENGTH + 1; x++) {
            int res = board[y][x] + board[y+1][x-1] + board[y+2][x-2] + board[y+3][x-3];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y+i][x-i] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y+i][x-i] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win diagonally? (top right-bottom left)
    for (int y = 0; y < HEIGHT - WINLENGTH + 1; y++) {
        for (int x = 0; x < WIDTH - WINLENGTH + 1; x++) {
            int res = board[y][x] + board[y+1][x+1] + board[y+2][x+2] + board[y+3][x+3];
            if (res == P1 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y+i][x+i] = P1-32;}
                return P1;
            }
            if (res == P2 * WINLENGTH) {
                for(int i = 0; i < WINLENGTH; i++) {board[y+i][x+i] = P2-32;}
                return P2;
            }
        }
    }
    return 0;
}