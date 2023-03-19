#include <stdio.h>
#include <stdlib.h>

int main() {
    int in = 1, sum = 0, min = 100000, max = 0, num = 0;
    while(in != 0) {
        printf("Tell me the price of the produkt: ");
        scanf("%i", &in);
        if (in == 0) {
        } else {x
            num++;
            printf("Produkt %i: %i\n", num, in);
            if (min > in) {min = in;}
            if (max < in) {max = in;}
            sum = sum + in;
        }
    }
    printf("\nAmount of Products: %i\nCheapest Product: %i\nMost Expensive Product: %i\nCost for Everything: %i",num, min, max, sum);
    return 0;
}
