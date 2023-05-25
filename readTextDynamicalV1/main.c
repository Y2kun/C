#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NAMELENGTH 32

int main() {
    FILE *file;
    char fileName[NAMELENGTH] = {'\0'};
    char *text = (char *) malloc(sizeof(char));
    int i = 0;
    printf("------Textwriter------\n");

    printf("Please input the directory of the file:");
    fgets(fileName, NAMELENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = 0;
    file = fopen(fileName, "w");

    while(fscanf(stdin, "%c", &text[i]) != '\n') {
        //text[i] = getc(stdin);
        i++;
        realloc(text, (i + 1) * (sizeof(char)));
    }

    fprintf(fileName, "%s", text);

    free(text);
    fclose(file);
    return 0;
}
