#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Please only use these operators: + - * /\n");
    while (1) {
        float n1 = 0.0, n2 = 0.0;
        char op = 0;
        printf("Please input your calculation: \n");
        int sres = scanf("%f %c %f", &n1, &op, &n2);

        if (sres != 3) {
            printf("Input invalid, must be of format %%f <OP> %%f\n");
            continue;
        };

        switch(op) {
            case '+': printf("= %.3f\n\n", n1 + n2); break;
            case '-': printf("= %.3f\n\n", n1 - n2); break;
            case '*': printf("= %.3f\n\n", n1 * n2); break;
            case '/': safediv(n1, n2); break;
        }
    }
    return 0;
}

void safediv(float a, float b) {
  if (b == 0) {
        printf("Can't divide by zero\n\n");
        return;
  }
   printf("= %.3f\n\n", a / b);
}
