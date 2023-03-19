#include <stdio.h>

#define HEIGHT 6
#define WIDTH 7
#define NOBODY '\0'
#define P1 'x'
#define P2 'o'

//Incomplete

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
        winCheck(board) == 0;
        x = getMove(board, P1);
        y = gravity(board, x);
        board[y][x] = P1;
        if (winCheck(board) != -1) printf("Player %c WINS!!!\n", P1);
        draw(board);

        x = getMove(board, P2);
        y = gravity(board, x);
        board[y][x] = P2;
        if (winCheck(board) != -1) printf("Player %c WINS!!!\n", P2);
        draw(board);
    }
}
/*

        //Player 1
        printf("Player 1 place your x at,(1-%i) :", WIDTH);
        scanf("%i", &y);
        while (y < 0 || y > WIDTH) {
            scanf("%i", &y);
        }

        y--;
        x = gravity(board, y);
        if(board [x][y] == '\0') {
            board [x][y] = 'x';
            count++;
        }
        draw(board);

        //Player 2
        printf("Player 2 place your o at,(1-%i) :", WIDTH);
        scanf("%i", &y);
        while (y > WIDTH) {
            scanf("%i", &y);
        }

        y--;
        x = gravity(board, y);
        if(board [x][y] == '\0') {
            board [x][y] = 'o';
            count++;
        }
        draw(board);
    }
    if(count == HEIGHT * WIDTH) {printf("It is a DRAW\n"); return 0;}
    printf("Player %i WINS!!!\n", winCheck(board));
    draw(board);
    return 0;
}
 */

int getMove(char board[HEIGHT][WIDTH], char player) {
    int x = -1;

    while (1) {
        if(scanf("%d", &x) != -1) {
            while(getchar != "\n") {

            }
        }
    }

    printf("Place %c at,(1-%i) :", player, WIDTH);
    while (x < 0 || x > WIDTH || board[HEIGHT - 1][x - 1] != '\0') {
        scanf("%d", &x);
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
        if(board[y][x] == NOBODY) {
            return y;
        }
    }

    return -1;
}

int winCheck(char board[HEIGHT][WIDTH]) {
    // Did anybody win horizontally?
    for (int x = 0; x < WIDTH-4; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int res = board[x][y] + board[x][y+1] + board[x][y+2] + board[x][y+3];
            if (res == P1*4) return P1;
            if (res == P2*4) return P2;
        }
    }

    return -1;
}

/*
int winCheck(char board[HEIGHT][WIDTH]) {
    char pl[2] = {'x', 'o'};
    char capitalPL[2] = {'X', 'O'};
    int win = 0;

    for(win = 1; win <= 2; win++) {
        //Horizontal check
        for(int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < 4; j++) {
                if(board [i][j] == pl[win] && board [i][j+1] == pl[win] && board [i][j+2] == pl[win] && board [i][j+3] == pl[win]) {
                    board [i][j] = capitalPL[win];
                    board [i][j+1] = capitalPL[win];
                    board [i][j+2] = capitalPL[win];
                    board [i][j+3] = capitalPL[win];
                    return win;
                }
            }
        }
        //Vertical check
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < WIDTH; j++) {
                if(board [i][j] == pl[win] && board [i+1][j] == pl[win] && board [i+2][j] == pl[win] && board [i+3][j] == pl[win]) {
                    board [i][j] = capitalPL[win];
                    board [i+1][j] = capitalPL[win];
                    board [i+2][j] = capitalPL[win];
                    board [i+3][j] = capitalPL[win];
                    return win;
                }
            }
        }
        //Diagonal check (up left-down right)
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 4; j++) {
                if(board [i][j] == pl[win] && board [i+1][j+1] == pl[win] && board [i+2][j+2] == pl[win] && board [i+3][j+3] == pl[win]) {
                    board [i][j] = capitalPL[win];
                    board [i+1][j+1] = capitalPL[win];
                    board [i+2][j+2] = capitalPL[win];
                    board [i+3][j+3] = capitalPL[win];
                    return win;
                }
            }
        }
        //Diagonal check (down left-up right)
        for(int i = 3; i < HEIGHT; i++) {
            for(int j = 0; j < 4; j++) {
                if(board [i][j] == pl[win] && board [i-1][j+1] == pl[win] && board [i-2][j+2] == pl[win] && board [i-3][j+3] == pl[win]) {
                    board [i][j] = capitalPL[win];
                    board [i-1][j+1] = capitalPL[win];
                    board [i-2][j+2] = capitalPL[win];
                    board [i-3][j+3] = capitalPL[win];
                    return win;
                }
            }
        }
    }
    return win;
}
 */