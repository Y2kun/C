#include <stdio.h>
#include <string.h>

#define length 80

int main() {
    char array1[length] = {""};
    char array2[length] = {""};
    printf("Please Input an string:");
    fgets(array1, length, stdin);
    strcpy(array2, array1);
    printf("%s", array2);
    return 0;
}
