#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1024

int main() {
    char name[LENGTH] = {"\0"};
    char buffer[LENGTH] = {"\0"};
    char bounty[LENGTH] = {"\0"};
    FILE *html, *person;

    printf("Please Input the name of the person for the Bounty:");
    fgets(name, LENGTH, stdin);
    printf("Please Input the size of the bounty:");
    scanf("%s", bounty);
    //strip
    name[strcspn(name, "\n")] = 0;
    bounty[strcspn(bounty, "\n")] = 0;

    //changing files
    strcat(buffer, "<html>\n"
            "<head>\n"
            "    <link rel=\"stylesheet\" href=\"style.css\">\n"
            "</head>\n"
            "<body>\n"
            "    <br><br>\n"
            "    <hr>\n"
            "    <h1>Wanted</h1>\n"
            "    <h2>Dead or Alive</h2>\n"
            "    <br>\n"
            "    <h3>");
    strcat(buffer, name);
    strcat(buffer, "</h3>\n"
                   "    <br>\n"
                   "    <h2>Reward</h2>");
    strcat(buffer, bounty);
    strcat(buffer, "</h2>\n"
                   "</body>\n"
                   "</html>");

    person = fopen(strcat(name, ".html"), "w");
    fprintf(person, buffer);
    fclose(person);
    return 0;
}