#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NAMELENGTH 32

int main() {
    FILE *file;
    char c = '\0';
    char fileName[NAMELENGTH] = {'\0'};
    char *text = (char *) malloc(sizeof(char));
    int i = 0;
    int newSize;

    printf("------Text_writer------\n");
    printf("Please input the directory of the file:");
    fgets(fileName, NAMELENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = 0;
    file = fopen(fileName, "w+");
    if(file == NULL) {return 1;}

    printf("Please input what you want the file to contain:\n");
    while(c != '\n') {
        c = getc(stdin);
        text[i] = c;
        i++;
        newSize = (i + 1) * (sizeof(char));
        text = realloc(text, newSize);
        if (text == NULL) {
            printf("Extending text length failed!");
            return 1;
        }
    }

    text[i] = '\0';
    fprintf(file, "%s", text);
    free(text);
    fclose(file);
    return 0;
}
