#include <stdio.h>

void segment(int);
void trunk(int);

int main() {
    int parts = 0;
    printf("Please Input the number of segments for the for the tree\n");
    scanf("%i", &parts);
    segment(parts);
    trunk(parts);
    return 0;
}

void segment(int parts)
{
    int i,j;
    for(i=1; i<=parts; i++)
    {
        for(j=1;j<=parts-i; j++)
        {
            printf(" ");
        }
        for(j=1; j<=2*i-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void trunk(int parts) {
    int i,j;
    for(i=1; i<=parts; i++)
    {
        for(j=1; j<=parts-2; j++)
        {
            printf(" ");
        }
        printf("|-|\n");
    }
}