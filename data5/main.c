#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 256

void write(char[LENGTH],char[LENGTH],char[LENGTH],char[LENGTH]);

int main() {
    char name[LENGTH] = {'\0'};
    char age[LENGTH] = {'\0'};
    char salery[LENGTH] = {'\0'};
    char sex[LENGTH] = {'\0'};

    while(1) {
        printf("Name:");
        fgets(name,LENGTH,stdin);
        name[strcspn(name, "\n")] = 0;
        if(name[0] == 'x') {exit(0);}

        printf("Age:");
        fgets(age,LENGTH,stdin);
        age[strcspn(age, "\n")] = 0;

        printf("Salery:");
        fgets(salery,LENGTH,stdin);
        salery[strcspn(salery, "\n")] = 0;

        printf("Sex:");
        fgets(sex,LENGTH,stdin);
        sex[strcspn(sex, "\n")] = 0;

        write(name,age,salery,sex);
    }

    return 0;
}
void write(char name[LENGTH],char age[LENGTH],char salery[LENGTH],char sex[LENGTH]){
    FILE *fptr;
    char buffer[LENGTH] = {'\0'};

    fptr = fopen("sub/persons.csv","r+");

    fscanf(fptr, buffer);
    strcat(buffer, name);
    strcat(buffer, ",");
    strcat(buffer, age);
    strcat(buffer, ",");
    strcat(buffer, salery);
    strcat(buffer, ",");
    strcat(buffer, sex);
    strcat(buffer, "\n");
    fprintf(fptr, buffer);

    fclose(fptr);
}