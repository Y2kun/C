#include <stdio.h>
#include <math.h>

void input(float*, float*, float*);
void street(float, float*, float*, float*, float*);

int main() {
    float start, end, step;
    float react, bad, normal, good;
    input(&start, &end, &step);
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|V\t||Reaction path\t||Stopping distance(good)\t||Stopping distance(normal)\t||Stopping distance(bad)|\n");
    for(float i = start ;i < end; i += step) {
        street(i, &react, &bad, &normal, &good);
        printf("|%.2f\t||%.2f\t\t||%.2f\t\t\t\t||%.2f\t\t\t\t||%.2f\t\t\t|\n", i, react, good, normal, bad);
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    return 0;
}

void input(float *in1, float *in2, float *in3) {
    float start, end, step;
    printf("Please input the start distance\nthe end distance\nthe steps\n");
    scanf("%f",&start);
    scanf("%f",&end);
    scanf("%f",&step);
    *in1 = start;
    *in2 = end;
    *in3 = step;
}

void street(float speed, float *react, float *bad, float *normal, float *good) {
    *react = 3 * speed / 10;
    *bad = pow(speed/10.0, 2.0);
    *normal = pow(speed/10.0, 2.0) * 0.75;
    *good = pow(speed/10.0, 2.0)/2.0;
}