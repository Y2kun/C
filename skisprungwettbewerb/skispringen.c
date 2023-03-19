#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPRUNGWEITE_MIN 80
#define SPRUNGWEITE_MAX 148

float sprung();
int haltungspunkte();
float gesamtpunkte(float, int);
void ergebnisse(float, int, float);

int main() {
    srand(time(NULL));
    int springer = 0;
    int maxSpringer = 0;
    float maxPunkt = 0, durch = 0;
    printf("--- Skisprungprogramm ---\n\n");
    printf("Anzahl der Springer: ");
    scanf("%i", &springer);

    for(int i = 1; springer >= i; i++) {
        int hp = haltungspunkte();
        float weite = sprung(), gesamt = gesamtpunkte(weite, hp);
        printf("Springer Nr.%i\n", i);
        printf("Weite: %.2f\n", weite);
        printf("Haltungspunkte: %i\n", hp);
        printf("Gesamtpunkte: %.2f\n", gesamt);
        printf("\n");
        if(gesamt > maxPunkt) {
            maxPunkt = gesamt;
            maxSpringer = i;
        }
        durch += weite;
    }
    ergebnisse(maxPunkt, maxSpringer, durch/springer);
    return 0;
}

float sprung() {
    float sprung = rand() % (SPRUNGWEITE_MAX * 100 - SPRUNGWEITE_MIN * 100) + SPRUNGWEITE_MIN * 100;
    return sprung / 100;
}

int haltungspunkte() {
    int zz, maxs = 0, mins = 20, hp = 0;
    const int max = 20, min = 15;
    for(int i = 0; i < 5; i++) {
        zz = rand() % (max - min) + min;
        if (zz > maxs) {maxs = zz;}
        if (zz < mins) {mins = zz;}
        hp += zz;
    }
    hp = hp - maxs - mins;
    return hp;
}

float gesamtpunkte(float weite, int hp) {
    float wp, gp;
    wp =  (60.0 + (weite - 120.0) * 1.8);
    gp = wp + hp;
    return gp;
}

void ergebnisse(float maxPunkt, int maxSpringer, float durch) {
    printf("Die maximale punktzahl von %.2f erreichte Springer Nr.%i\n", maxPunkt, maxSpringer);
    printf("Die durchschnittliche Sprungweite betraegt: %.2f", durch);
}

