#include <stdio.h>

int getInput();
void minimumCoins(int);

int main() {
    minimumCoins(getInput());
    return 0;
}

int getInput() {
    float input = 0;
    printf("Please input the amount of euros you want in copper coins\n");
    scanf("%f", &input);
    input = (int)(input*100);
    return input;
}

void minimumCoins(int input) {
    printf("Amount of Five Cent %i\nAmount of Two Cent %i\nAmount of One Cent %i\n", input/5, input%5/2, input%2);
}