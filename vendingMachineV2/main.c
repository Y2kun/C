#include <stdio.h>

int main() {
    int i = 0;
    printf("A Water = 1 Euro\n");
    printf("A Coffee = 2 Euro\n");
    printf("A Beer = 3 Euro\n");
    printf("Please insert Money\n");
    scanf("%i",&i);
    switch(i) {
        case 0: printf("Thank you for nothing"); break;
        case 1: printf("Thank you for the money here is your water"); break;
        case 2: printf("Thank you for the money here is your coffee"); break;
        case 3: printf("Thank you for the money here is your beer"); break;
        default: printf("Thank for your grand donation"); break;
    }
    return 0;
}
