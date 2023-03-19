#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    //First practice
    /*
    int array[5] = {7, 14, 27, 3, 16}, result = 0;

    for(int i = 0; i < 5; i++) {
        result += array[i];
    }
    printf("The result is: %i", result);

    return 0;
     */

    //Second practice
    /*
    int array[7] = {};

    for(int i = 0; i < 7; i++) {
        scanf("%i", &array[i]);
    }
    for(int i = 0; i < 7; i++) {
        printf("%i ", array[i]);
    }
    */

    //Third practice
    /*
    int array[50] = {}, input = 1;

    for(int i = 0; i < 50; i++) {
        array[i] = rand() % 100 + 1;
    }

    for(int i = 0; i < 50; i++) {
        printf("%i ", array[i]);
    }

    while(input != 0) {
        printf("\nInput Index:");
        scanf("%i", &input);
        printf("%i", array[input-1]);
    }
    */


    //Fourth practice
    /*
    #define MAX 80
    int array[MAX] = {}, num = 0;

    do{
        printf("Please input a number %i:", num+1);
        scanf("%i", &array[num]);
        num++;
    }while(array[num-1] >= 1 && num < MAX);

    for(int i = 0; i < num; i++) {
        printf("%i ", array[i]);
    }

    printf("\nNumber of Numbers: %i", num);
    */

    //Fiveth practice
    /*
    #define SIZE 10
    int array[SIZE] = {};

    for(int i = 1; i < SIZE; i++) {
        printf("Input:");
        scanf("%i", &array[i]);

        for(int z = 0; z < SIZE; z++) {
            if(array[i] == array[z] && i != z) {array[i] = 0;}
        }
    }

    for(int i = 0; i < SIZE; i++) {
        printf("Nr.%i == %i\n", i+1, array[i]);
    }
    */

    //Sixth practice
    /*
    #define SIZE 1000
    int array[SIZE] = {}, count[SIZE] = {}, max = 0, min = SIZE, sum = 0, maxcount = 0;
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;

        count[array[i]] += 1;

        if(array[i] < min) {min = array[i];}
        if(array[i] > max) {max = array[i];}
        sum += array[i];
    }

    for(int i = 0; i < SIZE; i++) {
        if(count[i] > maxcount) {maxcount = count[i];}
    }

    printf("The smallest Number is:%i\n", min);
    printf("The largest Number is:%i\n", max);
    printf("The average Number is: %i\n", sum / SIZE);
    printf("The Sum is:%i\n", sum);
    printf("The most common number was:%i\n", maxcount);
     */

    //Seventh practice
    /*
    #define SIZE 9

    int ind1, ind2, temp;
    int array[SIZE] = {};

    printf("Please input 9 numbers that are between 1 and 9:");
    for(int i = 0; i < SIZE; i++) {
        scanf("%i", &array[i]);
    }

    for(int i = 0; i <= SIZE; i++) {
        ind1 = rand() % SIZE;
        ind2 = rand() % SIZE;
        temp = array[ind1];
        array[ind1] = array[ind2];
        array[ind2] = temp;
    }

    for(int i = 0; i < SIZE; i++) {
        printf("Nr.%i: %i\n", i+1 ,array[i]);
    }
    return 0;
     */


}
