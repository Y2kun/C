#include <stdio.h>

int main() {
    float net = 0.0, salesTax = 0.0;
    printf("Please Input the net you want to convert\nThen Input the sales tax in the same line\n");
    scanf("%f %f", &net, &salesTax);
    printf("The Gross equals %.2f", (net+((net/100)*salesTax)));
    return 0;
}
