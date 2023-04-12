#include <stdio.h>
#include <string.h>

#define LENGTH 80

void encrypt(char code[LENGTH], int, int);
void decrypt(char code[LENGTH], int, int);

int main() {
    char code[LENGTH] = {'\0'};
    int shift = 0, length;
    char opt = ' ';
    printf("Please input the text to process: ");
    fgets(code, LENGTH, stdin);
    length = strlen(code) - 2;
    printf("Please input the amount of shift: ");
    scanf("%i", &shift);
    printf("Please input if you want to encrypt or decrypt (E, D):");
    fflush(stdin);
    scanf("%c", &opt);
    if(opt == 'E' || opt == 'e') {encrypt(code, shift, length);}
    else if(opt == 'D' || opt == 'E') {decrypt(code, shift, length);}
    return 0;
}

void encrypt(char code[LENGTH], int shift, int length) {
    for(int i = 0; i < LENGTH; i++) {
        if(code[i+1] == '\0') {break;}
        if(code[i] == ' ') {code[i] = code[i+1]; code[i+1] = ' ';}
    }
    for(int i = 0; i < length; i++) {
        if(code[i] >= 97 && code[i] <= 122) {code[i] = code[i] - 32;}
    }
    for(int i = 0; i < length; i++) {
        code[i] = (code[i] - 65 + shift) % 26 + 65;
    }
    printf("The encrypted text is: %s", code);
}

void decrypt(char code[LENGTH], int shift, int length) {
    for(int i = 0; i < length; i++) {
        code[i] = (code[i] - shift - 26) % 26 + 65;
    }
    printf("The decrypted text is: %s", code);
}