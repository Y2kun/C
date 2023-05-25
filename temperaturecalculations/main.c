#include <stdio.h>
#include <malloc.h>

void CalcStat(int*, int, int);

//does not work
int main() {
    FILE *file;
    file = fopen("./sub/temp.txt", "r");
    int *list = (int *) malloc(sizeof(int));
    int length = 0, num = 0;

    //Self explanitory
    if(file == NULL) {
        printf("Error: File not Found");
        return 404;
    }

    while (fscanf(file, "%i\n", &num) != EOF) {
        list[length] = num;
        length++;
        realloc(list, (length + 1) * (sizeof(int)));
    }
    fclose(file);

    for(int i = 0; i <= 3; i++) {
        CalcStat(list, length, i);
    }

    free(list);
    return 0;
}

void CalcStat(int* list, int num, int mode) {
    FILE *file;
    file = fopen("/sub/temp.txt", "a");
    float allTemp = 0;
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i <= num; i++) {
        allTemp += list[i];
        if(list[i] <= min) {min = list[i];}
        if(list[i] >= max) {max = list[i];}
    }
    if(mode == 0) {fprintf(file, "-------------------\n");}
    else if(mode == 1) {fprintf(file, "Average: %f °C\n", allTemp/num);}
    else if(mode == 2) {fprintf(file, "Minimum: %i °C\n", min);}
    else if(mode == 3) {fprintf(file, "Maximum: %i °C\n", max);}
}
