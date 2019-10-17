#include <stdio.h>

void schrijf_int(const int * t) {
    printf("%d", *t);
}

void schrijf_double(const double * t) {
    printf("%lf", *t);
}

void schrijf_string(const char** t) {
    printf("%s", *t);
}

void schrijf_array(const void * t, size_t aantal, int grootte, char tussenteken, void(*schrijf)(const void*)) {
    size_t i;
    // chars zijn 1 byte, pointer met verwijzingen naar data gesplit per byte
    const char * s = (char *) t;
    for (i = 0; i < aantal; i++) {
        schrijf(s + i * grootte);
        if (i != aantal - 1) {
            printf("%c", tussenteken);
        }
    }
    printf("\n");
}

int main() {
    char * namen[] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
    printf("%lu\n", sizeof(namen) / sizeof(namen[0]));
    printf("%lu\n", sizeof(char *));
    int leeftijden[] = {21,30,18,14,22,19};
    double scores[] = {0.5,1.6,8.2,-2.4};
    schrijf_array(leeftijden, sizeof(leeftijden) / sizeof(leeftijden[0]), sizeof(int), ',', (void(*) (const void*)) &schrijf_int);
    schrijf_array(scores, sizeof(scores) / sizeof(scores[0]), sizeof(double), ';', (void(*) (const void*)) &schrijf_double);
    schrijf_array(namen, sizeof(namen) / sizeof(namen[0]), sizeof(char *), ':', (void(*) (const void*)) &schrijf_string);
}
