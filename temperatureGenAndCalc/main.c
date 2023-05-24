#include <stdio.h>
#include <malloc.h>

float CalcStat(int*, int, int);

int main() {
    FILE *file;
    file = fopen("/sub/temp.txt", "r+");
    int* list = (int*) malloc(sizeof(int));
    int num = 0, mode = 0;

    printf("What mode should be used?(1-average, 2-min, 3-max):");
    scanf("%i", mode);

    while (fscanf(file, "%f\n", list) != EOF) {
        num++;
        realloc(list, num * (sizeof(int)+1));
    }

    printf("%.2f", CalcStat(list, num, mode));

    free(list);
    fclose(file);
    return 0;
}

float CalcStat(int* list, int num, int mode) {
    float allTemp = 0;
    return 0;
}
