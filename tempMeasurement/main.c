#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_MAX 50
#define TEMP_MIN -20

float maxtemp(float, float);
void warning(float, int*);
float mitteltemp(float, int);
void abweichung(float, float, float*);

int main() {
    srand(time(NULL));
    const int t_num = 100;
    float temp = 0, max_temp = TEMP_MIN, sum_temp = 0, aver = 0, dif = 0;
    int warn = 0;

    printf("Safety Dog\n");

    for(int i = 1; i <= t_num; i++) {
        temp = (rand() % ((TEMP_MAX - TEMP_MIN) * 10) - TEMP_MIN * 10 * (-1) ) / 10.0;
        sum_temp += temp;
        max_temp = maxtemp(temp, max_temp);
        printf("Nr.%i Temperature: %.2fC\n",i , temp);
        warning(temp, &warn);
    }

    aver = mitteltemp(sum_temp, t_num);
    printf("Average Temperature %.2fC\n", aver);
    abweichung(aver, max_temp, &dif);
    printf("Difference of the maximum to the average: %.2f\n", dif);
    printf("Number of warnings: %i", warn);
    return 0;
}

float maxtemp(float t, float m) {
    if(t > m) {m = t;}
    return m;
}

void warning(float t, int* a) {
    const int WMIN = -5, WMAX = 35;
    if(t > WMAX || t < WMIN) {printf("\tWANING! CRITICAL TEMPERATURE!\n"); (*a)++;}
}

float mitteltemp(float sum, int num) {
    float out = sum / num;
    return out;
}

void abweichung(float aver, float max, float* dif ) {
    *dif = max - aver;
}