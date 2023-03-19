#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int rng = rand() % 100 + 1;
    int i = 0, input = 0;
    printf("This is an Numberguessing game\nWe give you a number between 100 and 1 and you have to figure it out\n");
    while(input != rng) {
        scanf("%i", &input);
        if (input < rng) {
                printf("The number is bigger\n");
                i++;}
        else if (input > rng) {
                printf("The number is smaller\n");
                i++;}
    }
    printf("You guessed the number congatulations\n");
    printf("You needed %i atempts", i);
    return 0;
}
