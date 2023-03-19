#include <stdio.h>

int main() {
    int i = 0;
    printf("A Coffee costs exactly 1 Euro\nPlease insert 1 Euro\n");
    scanf("%i",&i);
    switch(i) {
        case 0: printf("Thank you for nothing"); break;
        case 1: printf("Thank you for the money here is your coffee"); break;
        default: printf("Thank for your grand donation"); break;
    }
    return 0;
}
