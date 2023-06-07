#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 32
#define MAX_LINE_LENGTH 80
#define BLOCK_SIZE 10

//does not work correctly but almost

int main() {
    char sub[5] = {"sub/"};
    char txt[5] = {".txt"};
    char filename[MAX_FILENAME_LENGTH + 1];
    char text[BLOCK_SIZE + 1];
    int length = 0;
    int consecutive_newlines = 0;
    int allChars = 0;
    int allWords = 0;

    printf("Please Input the Filename (max. %d Zeichen): ", MAX_FILENAME_LENGTH);
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    strcat(sub , filename);
    strcat(sub , txt);
    FILE *file = fopen(sub, "w");

    if (file == NULL) {
        printf("Error: File not Found\n");
        return 404;
    }

    printf("Please Input the Text (max. 2 Enters to End):\n");

    while (consecutive_newlines < 2) {
        fgets(text, sizeof(text), stdin);
        int text_length = strcspn(text, "\n");
        text[text_length] = '\0';

        if (text_length == 0) {
            consecutive_newlines++;
        } else {
            allChars += text_length;
            consecutive_newlines = 0;

            for (int i = 0; i < text_length; i++) {
                char c = text[i];

                fputc(c, file);
                length++;

                if (length == MAX_LINE_LENGTH) {
                    fputc('\n', file);
                    length = 0;
                }

                if (c == ' ') {
                    allWords++;
                }
            }
        }

        if (length != 0) {
            fputc('\n', file);
            length = 0;
        }
    }

    fprintf(file, "\nNumber of Characters: %d\n", allChars);
    fprintf(file, "Number of Words: %d\n", allWords);

    fclose(file);

    printf("The text was succesfully saved.\n");

    return 0;
}