#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VARLENGTH 40
#define TIMELENGTH 24
#define MAXLENGTH 70

void readFile(char header[VARLENGTH], int val[TIMELENGTH]);
void writeFile(char header[VARLENGTH], int val[TIMELENGTH], char *comment);

int main() {
    char header[VARLENGTH] = {'\0'};
    char *comment = (char*) malloc(sizeof(char) + 1);
    int val[TIMELENGTH] = {};
    char c = '\0';
    int lastwrap = 0, wraploc = 0, i = 0;

    printf("Vehicle-Counter-Formatter\n\n");
    readFile(header, val);

    printf("Please write your comment:\n");
    //reading the comment
    while(c != '\n') {
        c = getc(stdin);
        comment[i] = c;
        i++;
        comment = realloc(comment, ((i + 1) * (sizeof(char))));
    }


    //making the spaces of the comment
    comment[i] = '\0';
    for (int f = 0; comment[f] != '\0'; f++, wraploc++) {
        if (wraploc >= MAXLENGTH) {
            for (int k = i; k > 0; k--) {
                if (k - lastwrap <= MAXLENGTH && comment[k] == ' ') {
                    comment[k] = '\n';
                    lastwrap = k + 1;
                    break;
                }
            }
            wraploc = 0;
        }
    }

    writeFile(header, val, comment);
    free(comment);
    return 0;
}

void readFile(char header[VARLENGTH], int val[TIMELENGTH]) {
    FILE *in;
    const char INFILE[17] = "./data/input.txt";
    in = fopen(INFILE, "r");
    char headerPart[11] = {'\0'};
    if(in == NULL) {
        printf("The Directory %s could not be opened", INFILE);
        exit(EXIT_FAILURE);
    }

    fgets(header, VARLENGTH, in);
    fgets(headerPart, 11, in);
    strcat(header, headerPart);
    for(int i = 0; i <= TIMELENGTH; i++) {
        fscanf(in, "%i\n", &val[i]);
    }

    printf("File successfully read\n");
    fclose(in);
}

void writeFile(char header[VARLENGTH], int val[TIMELENGTH], char *comment) {
    FILE *out;
    const char OUTFILE[18] =  "./data/output.txt";
    out = fopen(OUTFILE, "w");
    if(out == NULL) {
        printf("The Directory %s could not be opened", OUTFILE);
        exit(EXIT_FAILURE);
    }

    fprintf(out, "%s\n\nTime\tVehicle\n", header);
    for(int i = 0; i < TIMELENGTH; i++) {
        if(i+1 <= 9) {fprintf(out ,"0");}
        fprintf(out ,"%i:00\t%i\n", i+1, val[i]);
    }

    fprintf(out ,"\n%s", comment);

    printf("File successfully created\n");
    fclose(out);
}
