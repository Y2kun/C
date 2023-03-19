#include <stdio.h>

//The Conversions
#define euro 1.0
#define dollar 1.21
#define swiss 1.08
#define lira 9.01

// The functions
void start();
int select(int);
float convertor(int);
float calc(int, int, float);
void out(int, int, float, float);

int main() {
    //Some definitions
    float in = 0;
    int sel1 = 0, sel2 = 0;
    while (1) {
        //Getting the input
        start();
        printf("Please input the first input\n");
        scanf("%i", &sel1);
        sel1 = select(sel1);
        if (sel1 == 0) {return 1;}
        printf("Please input the second input\n");
        scanf("%i", &sel2);
        sel2 = select(sel2);
        if (sel2 == 0) {return 1;}
        printf("Please input the amount you want to convert\n");
        scanf("%f", &in);
        if (in == 0) {return 1;}
        //End of getting the input
        //The output
        if (sel1 == sel2) {printf("You silly, why would you do that?\n\n");}
        else {out(sel1, sel2, in, calc(sel1, sel2, in));}
    }
}

void start() {
    //Some info
    printf("Please input the following for getting a result.\nThe first one is the the currency you want to convert from, the second one is the currency you want to convert to\n");
    printf("0 to End\n1 for Euro\n2 for Dollar\n3 for Swiss francs\n4 for Turkish Lira\n");
}

int select(int in) {
    int sel;
    switch(in) {
        case 0: printf("Exiting..."); sel = 0; break;
        case 1: printf("Selected Currency: Euro\n"); sel = 1; break;
        case 2: printf("Selected Currency: Dollar\n"); sel = 2; break;
        case 3: printf("Selected Currency: Swiss francs\n"); sel = 3; break;
        case 4: printf("Selected Currency: Turkish Lira\n"); sel = 4; break;
        default: printf("Please try again"); sel = 0; break;
    }
    return sel;
}

float convertor(int input) {
    //The converter
    float factor;
    switch(input) {
        case 1: factor = euro; break;
        case 2: factor = dollar; break;
        case 3: factor = swiss; break;
        case 4: factor = lira; break;
    }
    return factor;
}

float calc(int sel1, int sel2, float money) {
    // The calculator
    float val = convertor(sel1), goal = convertor(sel2);
    float moneyFrom = money / val;
    float moneyTo = moneyFrom * goal;
    return moneyTo;
}

void out(int sel1, int sel2, float init, float end) {
    //First part of output
    printf("The initial currency was ");
    switch(sel1) {
        case 1: printf("Euro\n"); break;
        case 2: printf("Dollar\n"); break;
        case 3: printf("Swiss francs\n"); break;
        case 4: printf("Turkish Lira\n"); break;
    }
    printf("And the amount for calculating was %.2f\n", init);
    //The second part for the output
    printf("The goal currency was ");
    switch(sel2) {
        case 1: printf("Euro\n"); break;
        case 2: printf("Dollar\n"); break;
        case 3: printf("Swiss francs\n"); break;
        case 4: printf("Turkish Lira\n"); break;
    }
    //The result
    printf("And the goal amount was %.2f\n\n", end);
}