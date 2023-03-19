#include <stdio.h>

#define MAX 255

int length(char[]);

int main() {
    char text[MAX] = {};
    printf("Please Input a text\n");
    gets(text);
    printf("The length is:%i",length(text));
    return 0;
}

int length(char text[]) {
    int counter = 0;
    for(int i = 0; i <= MAX; i++) {
        if(text[i] != '\0') {counter++;};
    }
    return counter;
}