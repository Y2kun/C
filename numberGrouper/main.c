#include <stdio.h>
#include <stdlib.h>

#define MAXNAME 255
#define MAX 10000

//unfinished

int sorter(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

char inputName(char fileName[MAXNAME]);
float sort(float input[MAX], float od[MAX/2], float rfu[MAX/2], int length);

int main() {
    char fileName[MAXNAME] = {'\n'};
    float input[MAX] = {};
    float od[MAX/2] = {};
    float rfu[MAX/2] = {};
    float val = 0;
    int length = 0;

    FILE *rfuFile, *odFile, *fileInput;
    inputName(fileName);
    rfuFile = fopen("./output/rfu.txt" ,"w");
    odFile = fopen("./output/od.txt", "w");
    fileInput = fopen(fileName, "w");

    while (fscanf(fileInput, "%f", &val) == 1 && length < MAX) {
        input[length] = val;
        length++;
    }

    sort(input, od, rfu, length);

    return 0;
}

char inputName(char fileName[MAXNAME]) {
    printf("Please Input the File name: ");
    fgets(fileName, MAXNAME, stdin);
}

float sort(float input[MAX], float od[MAX/2], float rfu[MAX/2], int length) {
    qsort(input, MAX, sizeof(int), sorter);
    for (int i = 0; i < length; i++) {
        printf("%.2f ", input[i]);
    }
}