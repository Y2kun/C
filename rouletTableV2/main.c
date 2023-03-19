#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int green = 0, black = 0, red = 0, count = 0;
    printf("Please input the amount of times you want the green field\n");
    scanf("%i", &count);
    while (green < count) {
        int rng = rand() % 36;
        if (rng == 0) {green++;}
        if (rng >= 1 && rng <= 17) {black++;}
        if (rng >= 18 && rng <= 35) {red++;}
    }
    printf("The Amount of green: %i\n", green);
    printf("The Amount of black: %i\n", black);
    printf("The Amount of red  : %i\n", red);
    return 0;
}
