#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void output(int a[MAX]);
int cmpfunc (const void * a, const void * b) {return ( *(int*)a - *(int*)b );}

int main() {
    int a[MAX] = {9, 5, 10, 6, 2, 53, 6, 2, 1, 3};

    output(a);
    printf("\n");
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    //quicksort
    qsort(a, MAX, sizeof(int), cmpfunc);
    output(a);
    return 0;
}

void output(int a[MAX]) {
    for(int i = 0; i < MAX; i++) {
        printf("%i ", a[i]);
    }
}