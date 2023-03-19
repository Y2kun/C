#include <stdio.h>

int main() {
    char name[30] = {'\0'};
    printf("Please Input your name:");
    scanf("%s", name);
    printf("This is your name, correct?\n%s", name);
    return 0;
}
