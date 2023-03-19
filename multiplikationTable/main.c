#include <stdio.h>

int main() {
    int length = 0;
    printf("Please input the length of the table\n");
    scanf("%i", &length);
    for (int i = 1; i <= length; i++) {
        for (int e = 1; e <= length; e++) {
            printf("%i \t* %i\t =\t%i\t\n", e, i, e*i);
        }
    }
    return 0;
}
