#include <stdio.h>
#include <string.h>

#define length 80

int main() {
    char array[length] = {};
    char search[length] = {};
    printf("Input an string:");
    fgets(array, length, stdin);
    printf("Input an string to search for in the first string:");
    fgets(search, length, stdin);
    search[strcspn(search, "\n")] = 0;
    if(strstr(array, search)) { printf("%s is in the string", search);}
    return 0;
}
