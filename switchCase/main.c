#include <stdio.h>

int main() {
    while (1) {
        int num = 0;
        char let = ' ';
        printf("Please input a number\n");
        scanf("%i", &num);

        switch(num) {
            case 1: printf("ONE!"); break;
            case 2: printf("TWO!"); break;
            case 3: printf("THREE!"); break;
            default: printf("Something else"); break;
        }
        fflush(stdin); //fixes the keyboard
        printf("\n\nPlease input Y or N\n");
        scanf("%c", &let);

        switch(let) {
            case 'Y': case 'y': printf("YES!\n"); break;
            case 'N': case 'n': printf("NO!\n"); break;
            default: printf("What do you mean\n"); break;
        }
    }
    return 0;
}
