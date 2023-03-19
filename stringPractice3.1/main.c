#include <stdio.h>
#define SIZE 255

int input(char Arr[], int*);
int newlen(char Arr[]);
void gross(char Arr[], int);
void isPalindrome(char Arr[], int);
void onlyLet(char Arr[], char Arr2[], int);

int main() {
    char array[SIZE] = {'\0'};
    char arrayfilterd[SIZE] = {'\0'};
    int length = 0;

    input(array, &length);
    printf("Your name %s is %i letters long\n", array, length);

    gross(array, length);
    onlyLet(array, arrayfilterd, length);
    length = newlen(array);
    isPalindrome(arrayfilterd, length);

    return 0;
}

int input(char Array[], int *ptr) {
    int counter = 0, i = 0;

    printf("Please Input your name\n");

    while(i < SIZE - 1  && Array[i-1] != '\n') {
        scanf("%c", &Array[i]);
        i++;
    }

    Array[i-1] = '\0';
    i = 0;

    while(Array[i] != '\0') {
        if(Array[i] != ' ')
            counter++;
        i++;
        *ptr = *ptr + 1;
    }

    return counter;
}

void gross(char Array[], int length) {
    for(int i = 0; i <= length; i++) {
        if((int)Array[i] > 96 && (int)Array[i] < 173) {
            Array[i] = (char)Array[i] - 32;
        }
    }
}

int newlen(char Array[]) {
    int counter = 0, i = 0;

    while(Array[i] != '\0') {
        if(Array[i] != ' ')
            counter++;
        i++;
    }

    return counter;
}

void isPalindrome(char Array[], int length)
{
    char status = 0;

    for(int i = 0; i < length / 2 && status != 1; i++) {
        if(Array[i] != Array[length - 1 - i]) {
            status = 1;
        }
    }

    printf("It is ");
    if(status == 1) {
        printf("not a Palindrom");
    } else {
        printf("a Palindrom");
    }
}

void onlyLet(char Array[], char ArrFilterd[], int length) {
    int j = 0;

    for(int i = 0; i <= length; i++) {
        if((int)Array[i] >= 65 && (int)Array[i] <= 90 || (int)Array[i] >= 97 && (int)Array[i] <= 122) {
            ArrFilterd[j] = Array[i];
            j++;
        }
    }
}