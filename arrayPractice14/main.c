#include <stdio.h>

#define MAX 30

int countChar(char[]);

int main() {
    char name[MAX] = {'\0'};
    printf("Please Input your name:");
    scanf("%s", name);
    printf("This is your name, correct?\n%s\n", name);
    printf("The number of <a> is:%i\n", countChar(name));

    printf("The reverse is:");
    for(int i = MAX; i >= 0; i--) {
        if(name[i] != '\0') {printf("%c", name[i]);}
    }
    printf("\nThe Number(s):");
    for(int i = 0; i < MAX; i++) {
        switch(name[i]) {
            case '0': printf("0"); break;
            case '1': printf("1"); break;
            case '2': printf("2"); break;
            case '3': printf("3"); break;
            case '4': printf("4"); break;
            case '5': printf("5"); break;
            case '6': printf("6"); break;
            case '7': printf("7"); break;
            case '8': printf("8"); break;
            case '9': printf("9"); break;
        }
    }
    return 0;
}

int countChar(char name[]) {
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        if(name[i] == 'a') {count++;}
    }
    return count;
}