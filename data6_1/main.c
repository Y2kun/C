#include <stdio.h>
#include <string.h>

#define LENGTH 512

int main() {
    FILE *in;
    char filename[32] = {'\0'};
    char path[64] = {"sub/"};
    char array[LENGTH] = {'\0'};

    printf("What is the file called that you want to format: ");
    scanf("%s", filename);
    strcat(path, filename);
    in = fopen(path,"r");

    fgets(array, LENGTH, in);

    printf("%s", array);
    fclose(in);
    return 0;
}
