#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float f = 0, c = 0;
    int up = 0, lo = 0, i = 0;
    srand(time(NULL));
    printf("Please input the upper and lower chances\n");
    scanf("%i %i", &up, &lo);
    printf("fahrenheit\tcelsius\n");

    while(i <= 20) {
        f = rand() % up + lo;
        c = (f-32)*5/9;
        printf("%.0f\t\t%.3f\n",f, c);
        i++;
    }
    return 0;
}
