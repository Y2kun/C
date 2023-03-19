#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Days 31

void maxi(int*, int*, int, int);
void mini(int*, int*, int, int);

int main() {
    srand(time(NULL));
    float average = 0;
    int maxDay = 0, minDay = 0;
    int max = 0, min = 1000;

    printf("RAIN AMOUNT\n\n");

    for(int i = 0; i < Days; i++) {
        int rain = rand() % 1000;
        maxi(&max, &maxDay, rain, i);
        mini(&min, &minDay, rain, i);
        average += rain;
    }
    printf("The highest amount of rain was: %i (Day %i)\n", max, maxDay);
    printf("The lowest amount of rain was: %i (Day %i)\n", min, minDay);
    printf("The Average Rain is: %f", average/Days);
    return 0;
}

void maxi(int *max, int *maxDay, int rain, int day) {
    if(*max < rain) {
        *max = rain;
        *maxDay = day;
    }
}

void mini(int *min, int *minDay, int rain, int day) {
    if(*min > rain) {
        *min = rain;
        *minDay = day;
    }
}
