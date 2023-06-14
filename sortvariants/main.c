#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100000

int main() {
    srand(time(NULL));
    int array[LENGTH] = {};
    int b, j, temp;
    size_t start, end;

    for (int i = 0; i < LENGTH; ++i) {
        //array[i] = 1;
        array[i] = rand() % 10000;
    }

    start = clock();
    //Bubble sort
    /*
    for (int i = 0; i < LENGTH - 1; i++) {
        for (int j = 0; j < LENGTH - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    */


    //Insertion Sort
    ///*
    for (b = 1; b < LENGTH; b++) {
        temp = array[b];
        j = b - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
    //*/
    end = clock();
    printf("%.3f\n", (float) (end-start)/CLOCKS_PER_SEC);
    /*
    for (int i = 0; i < LENGTH; i++) {
        printf("%i ", array[i]);
    }
     */
    return 0;
}
