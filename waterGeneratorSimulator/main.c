#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((time(NULL)));
    int tests = 0, i = 0, end = 0;
    float max = 0.0, min = 20.0, sum = 0.0;
    printf("Please input the amount of tests: ");
    scanf("%i", &tests);
    printf("Starting simulation with %i tests\n",tests);
    while(tests > i && end == 0) {
        float x = rand() % 100/5.0;
        if (x > max) {max = x;}
        if(x < min) {min = x;}
        sum = sum + x;

        if (x > 1.5 && x < 18.5) {
            printf("Waterheight %.2f m in green area, Normal activity\n", x);
        } else if (x < 1.5) {
            printf("Minimal waterheight of below 1.5 m has been reached (%.2f m), Turbine will be deactivated\n", x);
            end++;
        } else if (x > 18.5) {
            printf("Maximal waterheight of above 18.5 m has been reached (%.2f m), Turbine will be activated\n", x);
            end++;
        }
        i++;
    }
    printf("Max height was: %.2f m\n",max);
    printf("Min height was: %.2f m\n",min);
    printf("Simulation has finished\n");
    printf("Total average waterheight was: %.2f m", sum/i);
    return 0;
}
