#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rolls 300000

int main(){
    srand(time(NULL));
    int i = 1, rng = 0;
    int nums[6] = {};
    while(i <= rolls) {
        rng = rand() % 6 + 1;
        switch(rng) {
            case 1: nums[0]++; break;
            case 2: nums[1]++; break;
            case 3: nums[2]++; break;
            case 4: nums[3]++; break;
            case 5: nums[4]++; break;
            case 6: nums[5]++; break;
        }
        i++;
    }
    printf("You rolled the dice %i times\n",i-1);
    printf("You got %i ones\n"
           "You got %i twos\n"
           "You got %i threes\n"
           "You got %i fours\n"
           "You got %i ones\n"
           "You got %i ones\n",nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
    return 0;
}
