#include <stdio.h>

int main() {
    int line = 0, i = 0;
    printf("Please input the amount of lines: ");
    scanf("%i", &line);
    for (line; line != 0; line--) {
        printf("Line %i: ", line);
        for (i = 0; i < line; i++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
