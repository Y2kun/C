#include <stdio.h>

int main() {
    float input = 0;

    printf("Please input a Number ");
    scanf("%f",&input);

    if (input >= 0) {printf("Your input is Positiv");}
    else {printf("Your input is Negativ");}
    return 0;
}
