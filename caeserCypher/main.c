#include <stdio.h>

#define LENGTH 80

int cleanup(char code[LENGTH]);
void toupper(char code[LENGTH], int);
void encrypt(char code[LENGTH], int, int);

int main() {
    char code[LENGTH] = {'\0'};
    int shift = 0, length;
    printf("Please input the text to encrypt: ");
    fgets(code, LENGTH, stdin);
    printf("Please input the amount of shift: ");
    scanf("%i", &shift);
    length = cleanup(code);
    toupper(code, length);
    encrypt(code, shift, length);
    printf("The encrypted text is: %s", code);
    return 0;
}

int cleanup(char code[LENGTH]) {
    for(int i = 0; i < LENGTH; i++) {
        if(code[i] == ' ') {code[i] = code[i+1]; code[i+1] = ' ';}
        if(code[i] == '\0') {return i;}
    }
}

void toupper(char code[LENGTH], int length) {
    for(int i = 0; i < length - 1; i++) {
        if(code[i] >= 97 && code[i] <= 122) {code[i] = code[i] - 32;}
    }
}

void encrypt(char code[LENGTH], int shift, int length) {
    for(int i = 0; i < length - 1; i++) {
        code[i] = (code[i] - 65 + shift) % 26 + 65;
    }
}