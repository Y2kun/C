#include <stdio.h>
#include <string.h>

#define LENGTH 100

//does not function prperly should copy all types of files

int main() {
    char origin[LENGTH] = {"\0"};
    char copy[LENGTH] = {"\0"};
    FILE *ori, *cop ;

    printf("Please Input the file to copy from:");
    fgets(origin, LENGTH, stdin);
    printf("Please Input the file to copy to:");
    fgets(copy, LENGTH, stdin);
    //strip
    origin[strcspn(origin, "\n")] = 0;
    copy[strcspn(copy, "\n")] = 0;

    ori = fopen(origin, "rb");
    cop = fopen(copy, "wb");
    fgets(origin, LENGTH, ori);
    fprintf(cop, "%s", origin);
    fclose(ori);
    fclose(cop);
    return 0;
}