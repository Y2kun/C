#include <stdio.h>
#include <string.h>

#define LENGTH 2048

//does not work

void write(char[LENGTH],char[LENGTH],char[LENGTH],char[LENGTH]);
void gender();

int main() {
    char name[LENGTH] = {'\0'};
    char age[LENGTH] = {'\0'};
    char salery[LENGTH] = {'\0'};
    char sex[LENGTH] = {'\0'};

    while(1) {
        printf("Name:");
        fgets(name,LENGTH,stdin);
        name[strcspn(name, "\n")] = 0;
        name[strcspn(name, ",")] = 0;
        if(name[0] == 'x') {break;}

        printf("Age:");
        fgets(age,LENGTH,stdin);
        age[strcspn(age, "\n")] = 0;
        age[strcspn(age, ",")] = 0;

        printf("Salery:");
        fgets(salery,LENGTH,stdin);
        salery[strcspn(salery, "\n")] = 0;
        salery[strcspn(salery, ",")] = 0;

        printf("Sex:");
        fgets(sex,LENGTH,stdin);
        sex[strcspn(sex, "\n")] = 0;
        sex[strcspn(sex, ",")] = 0;

        write(name,age,salery,sex);
    }
    gender();

    return 0;
}

void write(char name[LENGTH],char age[LENGTH],char salery[LENGTH],char sex[LENGTH]) {
    FILE *fptr;

    fptr = fopen("sub/persons.csv","a");

    fprintf(fptr, " %s, %s, %s, %s,\n",name, age, salery, sex);

    fclose(fptr);
}

void gender() {
    FILE *fptr;
    fptr = fopen("sub/persons.csv","r");
    char array[LENGTH] = {'\0'};
    char cache[LENGTH] = {'\0'};
    int counter = 0;

    while (fgets(cache, LENGTH, fptr) != NULL) {
        strcat(array, cache);
    }

    for(int i = 0; i < LENGTH; i++) {
        if(array[i] == '\n') {
            if(array[i-0] == 'w' || array[i-0] == 'W') {
                counter++;
            }
        }
    }

    printf("The amount of women in the file is:%i\n", counter);
    fclose(fptr);
}