#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int count = 0;
    while(count <= 100000) {
        int rng = rand() % 100000 + 10000;
        printf("%i ",rng);
        count = count+1;
    }
    return 0;
}
