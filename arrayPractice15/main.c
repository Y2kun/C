#include <stdio.h>

//RPC-In C

int main() {
    float input[2] = {};
    char op = ' ';
    printf("Please Input your calculation:");
    scanf("%f %f %c", &input[0], &input[1], &op);

    switch(op) {
        case '+': printf("The addition is:%.2f", input[0] + input[1]); break;
        case '-': printf("The subtraction is:%.2f", input[0] - input[1]); break;
        case '*': printf("The multiplication is:%.2f", input[0] * input[1]); break;
        case '/': printf("The division is:%.2f", input[0] / input[1]); break;
    }
    return 0;
}