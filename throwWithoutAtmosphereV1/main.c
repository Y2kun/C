#include <stdio.h>
#include <math.h>

int main(){
    const float g = 9.81;
    float v = 0, a = 0, t = 0;
    printf("Please Input the speed, throwing degree then the time\n");
    scanf("%f %f %f", &v, &a, &t);
    float r = a*M_PI/180, ms = v/3.6;
    float h = ms*t*sin(r)-(t*t*g/2);
    float d1 = ms*t*cos(r);
    float d2 = ms*(2*(sin(r)*ms)/g*cos(r));
    if (h >= 0 && d1 >= 76) {printf("The ball flies for %.3fs and is %f meter from you\nHOMERUN!!!", t, d1);}
        else if (h <= 0 && d2 >= 76) {printf("The ball is on the ground, flew for %.3fs and is %f meter from you\nHOMERUN!!!", t, d2);}
        else if (h >= 0) {printf("The ball flies for %.3fs and is %f meter from you\n", t, d1);}
        else if (h <= 0) {printf("The ball is on the ground, flew for %.3fs and is %f meter from you\n", t, d2);}
        else {printf("Incorrect input!!!");}
    return 0;
}
