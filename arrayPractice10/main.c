#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAX 10

int max(int[]);
int index(int[], int);

int main() {
    srand(time(NULL));
    int array[MAX] = {};

    for(int i = 0; i < MAX; i++) {
        array[i] = rand() % 100 + 1;
    }

    int maximum = max(array);

    for(int i = 0; i < MAX; i++) {
        printf("%i\n", array[i]);
    }

    printf("Max number: %i\n", maximum);
    printf("Index number: %i", index(array, maximum)+1);
    return 0;
}

int max(int num[]) {
    int max = 0;
    for(int i = 0; i < MAX; i++) {
        if(max < num[i]) {max = num[i];}
    }
    return max;
}

int index(int num[], int max) {
    for(int i = 0; i < MAX; i++) {
        if(num[i] == max) {return i;}
    }
}