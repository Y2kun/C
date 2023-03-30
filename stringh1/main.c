#include <stdio.h>
#include <string.h>

#define length 80

int main() {
    char text[length] = {"Hier kommt die Maus:"};
    char array1[length] = {""};
    char array2[length] = {""};
    printf("Please input an text with the maximum length of %i\n", length);
    fgets(array1, length, stdin);
    array1[strcspn(array1, "\n")] = 0;
    strcat(text, array1);

    printf("Please input an second text with the maximum length of %i\n", length);
    fgets(array2, length, stdin);
    array2[strcspn(array2, "\n")] = 0;
    strcat(text, array2);

    printf("Your sentence:%s", text);
    return 0;
}
