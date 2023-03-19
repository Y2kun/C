#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

void Search(int array[]) {
    int uneven[NUM] = {}, l = 0;

    for(int i = 0; i < NUM; i++) {
        if((array[i] % 2) == 1) {
            uneven[l] = array[i];
            l++;
        }
    }

    for (int i = 0; i < l; i++) {
        printf("%i\t", uneven[i]);
    }
}

int main() {
    srand(time(NULL));
    int array[NUM] = {};

    for(int i = 0; i <= NUM; i++) {
        array[i] = rand() % NUM;
    }

    Search(array);

    return 0;
}
