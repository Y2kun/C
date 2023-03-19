#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(float*, float*, float*);
float trapezoidArea(float, float, float);
float triangleArea(float, float, float);

int main() {
    float a = 1, b = 1, c = 1;
    char in = "";
    printf("The Trapezoid/Triangle Area Calculator\n\n");
    printf("Please Type (t) if you want to calculate the Trapezoid\nType (d) if you want to calculate the triangle\n");
    scanf("%c", &in);
    if(in == 't') {
        for(int check = 0; check == 0;) {
            input(&a, &b, &c);
            if(a <= 0 || b <= 0 || c <= 0) {check = 1;
            } else {
                printf("The Area of the trapezoid is: %.2f\n", trapezoidArea(a, b ,c));
            }
        }
    } else if(in == 'd') {
        for(int check = 0; check == 0;) {
            input(&a, &b, &c);
            if(a <= 0 || b <= 0 || c <= 0) {check = 1;
            } else {
                printf("The Area of the triangle is: %.2f\n", triangleArea(a, b ,c));
            }
        }
    } else {
        printf("Error");
    }
    return 0;
}

void input(float *aout, float *bout, float *cout) {
    float a = 0, b = 0, c = 0;
    printf("Please Input a:");
    scanf("%f", &a);
    printf("Please Input b:");
    scanf("%f", &b);
    printf("Please Input h:");
    scanf("%f", &c);
    *aout = a;
    *bout = b;
    *cout = c;

}

float trapezoidArea(float a, float b, float h) {
    return ((a+b)*h)/2.0;
}

float triangleArea(float a, float b, float c) {
    return a+b+c; //this formula is not correct
}
