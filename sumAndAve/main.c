#include <stdio.h>
int main() {
    int num [4] = {};
    int sum = 0;
    //read the terminal
    for (int i = 0; i < 4; i++) scanf("%i",&num[i]);
    //calculations
    for (int i = 0; i < 4; i++) sum += num[i];

    float ave = sum/4;
    //output
    printf("%i\n",sum);
    //average
    printf("%15.15f",ave);
    return 0;
}
