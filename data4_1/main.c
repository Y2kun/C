#include <stdio.h>
#include <string.h>

#define LENGTH 255

int main() {
    char name[LENGTH] = {"\0"};
    char buffer[LENGTH] = {"\0"};
    char *pos;
    int price;
    FILE *html, *person;

    printf("Please Input the name of the person for the Bounty:");
    fgets(name, LENGTH, stdin);
    printf("Please Input the size of the bounty:");
    scanf("%i", price);
    //strip
    name[strcspn(name, "\n")] = 0;

    //open files
    html = fopen("index.html", "r");
    person = fopen(strcat(name, ".html"), "w");

    //changing files
    fgets(buffer, LENGTH, html);
    pos = strstr(buffer, "<h3>Billy the Kid</h3>");
    fprintf(strcat(name, ".html") ,strcat("</h3>", strcat(name, "</h3>")), pos);
    //close files
    fclose(html);
    fclose(person);
    return 0;
}