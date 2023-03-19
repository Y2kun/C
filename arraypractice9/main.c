#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int evenOrUneven(int array[] , int mode) {
    int even = 0, uneven = 0;

    for(int i = 0; i <= MAX; i++) {
        if((array[i] % 2) == 0) {even++;}
        if((array[i] % 2) == 1) {uneven++;}
    }
    if (mode == 0) {printf("The number of even Numbers is: %i", even);}
    else {printf("The number of uneven Numbers is: %i", uneven);}
}

int main() {
    srand(time(NULL));
    int array[MAX] ={}, mode = 0;

    printf("Please input\n 0 if you want even\n 1 if you want uneven\n");
    scanf("%i", &mode);

    for(int i = 0; i <= MAX; i++) {
        array[i] = rand() % MAX;
    }

    evenOrUneven(array, mode);
    return 0;
}

