#include <stdio.h>

#define ASIZE 80

int main() {
    char in[ASIZE] = {'\0'};
    char text[ASIZE] = {'\0'};
    char c = '\0';
    int i = 0;
    FILE* fptr = NULL;
    printf("Filehandling\n\n"
           "Please input a text with a maximum of %i characters\n", ASIZE);

    //Reading from the Terminal (stdin)
    //scanf("%s", text);
    //gets(text);
    //fgets(text, ASIZE, stdin);
    while ((c = getc(stdin)) != '\n' && i < ASIZE-1) {
        text[i] = c;
        i++;
    }
    text[i] = '\0';

    //Writing a File
    fptr = fopen("text.txt", "w");
    if (fptr == NULL) {
        printf("The File is not Avaiable");
        return 0;
    }

    //fputs(text, fptr);
    //fprintf(fptr, "Some Text: %s", text);

    i = 0;
    while(text[i] != '\0') {
        fputc(text[i], fptr);
        i++;
    }

    rewind(fptr);
    fgets(in, ASIZE, fptr);

    fclose(fptr);
    return 0;
}