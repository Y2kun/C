#include <stdio.h>

#define MAXF 300

int main() {
    int f = 0;
    float c = 0;
    printf("fahrenheit\tcelsius\n");

    while(f <= MAXF) {
        c = (f-32)*5/9;
        printf("%d\t\t%.3f\n",f, c);
        f = f+20;
    }
    return 0;
}
