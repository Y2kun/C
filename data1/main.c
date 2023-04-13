#include <stdio.h>

#define LENGTH 100

int main() {
    FILE *fptr = NULL;
    char array[LENGTH] = {'\0'};
    printf("Please Input an text that is not longer than %i characters\n", LENGTH);
    fgets(array, LENGTH, stdin);
    fptr = fopen("out.txt", "w");
    fprintf(fptr, array);
    fclose(fptr);
    return 0;
}
