#include <stdio.h>

int input(void);
float calc(int, int);

int main() {
    int in1, in2;

    while (in1 != -1 && in2 != -1) {
        printf("Please input two numbers\n");
        in1 = input();
        in2 = input();
        fflush(stdin);
        if (in1 != -1 && in2 != -1) {
            printf("%.6f\n", calc(in1, in2));
        }
    }
    return 0;
}

int input() {
    int num = 0;
    scanf("%i", &num);
    return num;
}

float calc(int a, int b) {
    float out = 0;
    if (a == b) { out = 0; }
    else if (a > b) { out = a * 2.5 - b * 1.5; }
    else if (a < b) { out = a * 0.5 - b / 0.5; }
    return out;
}