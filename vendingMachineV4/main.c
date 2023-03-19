#include <stdio.h>

int output(int);
void init();

int main() {
    int i = 0, end;
    //initial output
    init();
    //THE LOOP
    do {
        scanf("%i", &i);
        end = output(i);
    } while (end);
    //happens when everything ends
    return 0;
}

void init() {
    printf("Water = 1 Euro\n"
           "Coffee = 2 Euro\n"
           "Beer = 3 Euro\n"
           "Please insert your Money\n");
}

int output(int in) {
    int loop = 0;
    //lot of questions and outputs
    if (in >= 1 && in <= 3) { printf("Thank you, here is your "); }
    if (in == 1) { printf("water"); }
    else if (in == 2) { printf("coffee"); }
    else if (in == 3) { printf("beer"); }
    else {
        printf("Please try again\n");
        loop = 1;
    }
    return loop;
}