#include <stdio.h>

int numWords(char *fptr);

int main() {
    FILE *fptr = NULL;
    fptr = fopen("input.txt", "r");
    printf("The number of words in the file is: %i", numWords(fptr));
    fclose(fptr);
    return 0;
}

int numWords(char *fptr) {
    char chr;
    int count = 1;
    while ((chr = fgetc(fptr)) != EOF) {
        if (chr == ' ' || chr == '\t' || chr == '\n' || chr == '\0')
            count++;
    }
    return count;
}