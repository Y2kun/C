#include <stdio.h>
#include <math.h>

int main(){
    //some initial definitions
    const float g = 9.81;
    float v = 0, a = 0, t = 0, h = 0.00001, d = 0;
    //a lot of printing
    printf("**************************************************************************************************************\n");
    printf("************************************************Baseballsim*V2************************************************\n");
    printf("**************************************************************************************************************\n\n");
    //reading user input
    printf("Please Input the speed and throwing degree\n");
    scanf("%f %f", &v, &a);
    //some initial calculations for the radian and the meter per second metric
    float r = a*M_PI/180, ms = v/3.6;
    printf("        t          h         d\n");
    //a while loop
    while (h >= 0 && t <= 10) {
        //output so the user can get information
        printf("%10.1f%10.2f%10.2f\n", t, h, d);
        //really important calculations for the time, height and distance of the ball
        t = t + 0.1;
        h = ms*t*sin(r)-(t*t*g/2);
        d = ms*t*cos(r);
    }
    return 0;
}
