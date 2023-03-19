#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 45

//Work not gona progress

int shuffle(int[]);

int main() {
    srand(time(NULL));
    int array[NUM] = {};

    for(int i = 0; i < NUM; i++) {
        array[i] = i+1;
    }

    for(int i = 0; i < NUM; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
    shuffle(array);

    for(int i = 0; i < NUM; i++) {
        printf("%i ", array[i]);
    }

    return 0;
}

int shuffle(int num[]) {
    for (int i = 0; i < NUM; i++){
        int swap_index = rand() % NUM;
        int temp = num[i];
        num[i] = num[swap_index];
        num[swap_index] = temp;
    }
}