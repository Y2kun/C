#include <stdio.h>
#include <malloc.h>
#include <string.h>

void printHeader(char[], int*);

int main() {
    char filename[32] = {'\0'};
    char path[32] = "sub/";
    float *num = (float*) malloc(sizeof(float));
    int *nr = (int*) malloc(sizeof(int));
    char *valid = (char*) malloc(sizeof(char));
    char header[256] = {'\0'};
    char ch;
    int i = 0, j;
    int index = 0;

    FILE *in = NULL;

    printf("Please Input the name of the File: ");
    scanf("%s", filename);
    strcat(path, filename);

    in = fopen(path, "r");

    if(in == NULL) {
        printf("\nError 404: File not found!\n");
        return 404;
    }
    else {
        // reading header
        while((ch = fgetc(in)) != '\n') {
            header[i] = ch;
            i++;
        }
        i = 0;

        // reading leftover numbers
        while(fscanf(in, "%d\t%f\t%c", &nr[i], &num[i], &valid[i]) != EOF) {
            i++;

            *num = (float*) malloc(sizeof(float));
            *nr = (int*) malloc(sizeof(int));
            *valid = (char*) malloc(sizeof(char));
        }
    }
    fclose(in);

    //Outputting the file
    printHeader(header, &index);
    for(j = 0; j < i; j++) {
        printf("\t%d", nr[j]);
    }
    printf("\n");

    printHeader(header, &index);
    for(j = 0; j < i; j++) {
        printf("\t%.1f", num[j]);
    }
    printf("\n");

    printHeader(header, &index);
    for(j = 0; j < i; j++) {
        printf("\t%c", valid[j]);
    }
    printf("\n");

    free(nr);
    free(num);
    free(valid);

    return 0;
}

void printHeader(char h[], int *index) {
    while(h[*index] != '\t' && h[*index] != '\0') {
        printf("%c", h[*index]);
        (*index)++;
    }
    (*index)++;
}