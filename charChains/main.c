#include <stdio.h>
#include <stdlib.h>

#define NSIZE 30

int input(char[]);

int main() {
    char name[NSIZE] = {'\0'};
    int length = input(name);

    printf("Hello, %s your name has %i characters", name, length);

    return 0;
}

int input(char n[]) {
    int i = 0, j = 0;

    printf("Please Input your Name: ");
    scanf("%s", n);

    for(n[i] != '\0';;) {
        if(n[i] !=  ' ') {j++;}
        i++;
    }
    return j;
}
