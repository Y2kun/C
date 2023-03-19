#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int balance = 0, betamount = 10, num1 = 0, num2 = 0, num3 = 0, i = 0;

    printf("Please input your money: ");
    scanf("%i", &balance);
    printf("Please input your amount of money you want to bet: ");
    scanf("%i", &betamount);
    while(balance >= betamount) {
        num1 = rand() % 9;
        num2 = rand() % 9;
        num3 = rand() % 9;

        if (num1 == num2 && num1 == num3) {
            balance = balance + betamount*100;
            printf("You got all three the same, you get:%i\n", betamount*100);
        }else if (num1 == num2 || num2 == num3 || num2 == num3){
            balance = balance + betamount*10;
            printf("You got two the same, you get:%i\n", betamount*10);
        }else {
            balance = balance - betamount;
            printf("You got less than two the same, you loose:%i\n", betamount);
        }
        printf("\nPlease input your amount of money you want to bet next round: ");
        scanf("%i", &betamount);
        i++;
    }
    printf("You have not enough money to play\n");
    printf("You played for %i rounds",i);
    return 0;
}
