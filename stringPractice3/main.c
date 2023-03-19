#include <stdio.h>

#define MAX 255

int length(char[]);
void capital(char[]);
int isPalidrome(char[]);

int main() {
    char text[MAX] = {};
    int len = 0;
    printf("Please Input a text\n");
    gets(text);
    printf("The length is:%i\n", length(text));
    capital(text);
    printf("The text in capital letters is:%s\n",text);
    if(isPalidrome(text) == 0) { printf("This is not a Palindrome:%s", text);}
    else {printf("This is a Palindrome");}
    return 0;
}

int length(char text[]) {
    int counter = 0;
    for(int i = 0; i <= MAX; i++) {
        if(text[i] != '\0') {counter++;};
    }
    return counter;
}

void capital(char text[]) {
    for(int i = 0; i < MAX; i++) {
        switch(text[i]) {
            case 'a': text[i] = 'A'; break;
            case 'b': text[i] = 'B'; break;
            case 'c': text[i] = 'C'; break;
            case 'd': text[i] = 'D'; break;
            case 'e': text[i] = 'E'; break;
            case 'f': text[i] = 'F'; break;
            case 'g': text[i] = 'G'; break;
            case 'h': text[i] = 'H'; break;
            case 'i': text[i] = 'I'; break;
            case 'j': text[i] = 'J'; break;
            case 'k': text[i] = 'K'; break;
            case 'l': text[i] = 'L'; break;
            case 'm': text[i] = 'M'; break;
            case 'n': text[i] = 'N'; break;
            case 'o': text[i] = 'O'; break;
            case 'p': text[i] = 'P'; break;
            case 'q': text[i] = 'Q'; break;
            case 'r': text[i] = 'R'; break;
            case 's': text[i] = 'S'; break;
            case 't': text[i] = 'T'; break;
            case 'u': text[i] = 'U'; break;
            case 'v': text[i] = 'V'; break;
            case 'w': text[i] = 'W'; break;
            case 'x': text[i] = 'X'; break;
            case 'y': text[i] = 'Y'; break;
            case 'z': text[i] = 'Z'; break;
        }
    }
}

int isPalidrome(char text[]) {
    int len = 0, factor = 0;
    for(int i = 0; i < MAX; i++) {
        switch(text[i]) {
            case ' ': text[i] = text[i++]; break;
            case '.': text[i] = text[i++]; break;
            case ',': text[i] = text[i++]; break;
        }
    }
    len = length(text);
    char correct[len+1] = {};
    if(len % 2 == 0) {factor = len/2;}
    else {factor = len/2 + 1;}

    for(int i = len; i >= 0; i--) {
        correct[i] = text[len-i];
    }

}