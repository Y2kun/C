#include <stdio.h>
#include <math.h>

int main() {
    float r = 0;
    printf("Define the radius of the circle\n");
    scanf("%f",&r);
    printf("The area of the circle is %f\n",(r*r*M_PI));
    printf("The circumferance of the circle is %f\n",(2*r*M_PI));
    return 0;
}
