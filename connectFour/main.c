#include <stdio.h>

#define HEIGHT 6
#define WIDTH 7
#define WINLENGHT 4
#define NOBODY '\0'
#define P1 'x'
#define P2 'o'

//Could be better, but works with a few flaws

int getMove(char board[HEIGHT][WIDTH], char player);
void draw(char board[HEIGHT][WIDTH]);
int gravity(char board[HEIGHT][WIDTH], int);
int winCheck(char board[HEIGHT][WIDTH]);

int main() {
    char board[HEIGHT][WIDTH] = {'\0'};
    int y = 0, x = 0, count = 0;

    printf("CONNECT FOUR: THE GAME\n\n");
    draw(board);

    //Mainloop
    while (count < HEIGHT * WIDTH) {
        //Player 1
        x = getMove(board, P1);
        y = gravity(board, x);
        if (y != -1) {board[y][x] = P1;}
        if (winCheck(board) != -1) {
            draw(board);
            printf("Player %c WINS!!!\n", P1);
            return 0;
        }
        draw(board);

        //Player 2
        x = getMove(board, P2);
        y = gravity(board, x);
        if (y != -1) {board[y][x] = P2;}
        if (winCheck(board) != -1) {
            draw(board);
            printf("Player %c WINS!!!\n", P2);
            return 0;
        }
        draw(board);

        count++;
    }
    printf("It is a draw!!!");
}

int getMove(char board[HEIGHT][WIDTH], char player) {
    int x = -1;
    printf("Place %c at,(1-%i) :", player, WIDTH);

    while (x < 0 || x > WIDTH && board[HEIGHT - 1][x] != '\0') {
        scanf("%i", &x);
    }
    return x - 1;
}

void draw(char board[HEIGHT][WIDTH]) {
    printf(" ");
    for(int i = 0; i < WIDTH; i++) {
        printf(" %i", i+1);
    }
    printf("\n");

    for(int i = HEIGHT-1; i >= 0; i--) {
        printf("%i ", i+1);
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int gravity(char board[HEIGHT][WIDTH], int x) {
    for(int y = HEIGHT-1; y >= 0; y--) {
        if(board[y][x] == NOBODY) {return y;}
    }
    return -1;
}

int winCheck(char board[HEIGHT][WIDTH]) {
    // Did anybody win horizontally?
    for (int x = 0; x < WIDTH-4; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int res = board[x][y] + board[x][y+1] + board[x][y+2] + board[x][y+3];
            if (res == P1*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x][y+i] = P1-32;}
                return P1;
            }
            if (res == P2*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x][y+1] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win vertically?
    for (int x = 0; x < WIDTH-4; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int res = board[x][y] + board[x+1][y] + board[x+2][y] + board[+3][y];
            if (res == P1*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x+i][y] = P1-32;}
                return P1;
            }
            if (res == P2*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x+i][y] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win diagonally? (top left-bottom right)
    for (int x = 0; x < WIDTH-4; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int res = board[x][y] + board[x+1][y+1] + board[x+2][y+2] + board[x+3][y+3];
            if (res == P1*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x+i][y+i] = P1-32;}
                return P1;
            }
            if (res == P2*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x+i][y+i] = P2-32;}
                return P2;
            }
        }
    }
    // Did anybody win diagonally? (top right-bottom left)
    for (int x = 0; x < WIDTH-4; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int res = board[x][y] + board[x-1][y+1] + board[x-2][y+2] + board[-3][y+3];
            if (res == P1*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x-i][y+i] = P1-32;}
                return P1;
            }
            if (res == P2*4) {
                for(int i = 0; i < WINLENGHT; i++) {board[x-i][y+i] = P2-32;}
                return P2;
            }
        }
    }
    return -1;
}