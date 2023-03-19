#include <stdio.h>

int main() {
    int i = 0, torf = 1;
    printf("A Water = 1 Euro\n");
    printf("A Coffee = 2 Euro\n");
    printf("A Beer = 3 Euro\n");
    printf("Please insert Money\n");
    scanf("%i",&i);
    while (torf) {
        switch(i) {
            case 1: printf("Thank you for the money here is your water"); torf = 0; break;
            case 2: printf("Thank you for the money here is your coffee"); torf = 0; break;
            case 3: printf("Thank you for the money here is your beer"); torf = 0; break;
            default: printf("Please try again\n"); torf = 1; break;
        }
        if (torf) {scanf("%i",&i);}
    }
    return 0;
}
