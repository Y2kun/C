#include <stdio.h>
#include <malloc.h>

#define LENGTH 32

int main() {
    FILE *file;
    char fileName[LENGTH] = {'\0'};
    char *text = (char *) malloc(sizeof(char));
    int i = 0;
    printf("----Textwriter----\n");

    printf("Please input the directory of the file:");
    fgets(fileName , LENGTH, stdin);
    file = fopen(fileName, "w");

    while(text[i] != '\n') {
        text[i] = getc(stdin);
        i++;
        realloc(text, (i + 1) * (sizeof(char)));
    }

    free(text);
    fclose(file);
    return 0;
}
