#include <stdio.h>

void schrijf_int(const int * get) {
    printf("%d", *get);
}

void schrijf_cstring(const char * const * str) {
    printf("%s", *str);
}

void schrijf_double(const double * db) {
    printf("%.1f", *db);
}


void schrijf_array(const void *, size_t, size_t, char, void(*)(const void*));

int main(void) {
    char * namen [] = {"Evi", "Jaro", "Timen", "Youri",  "Ashaf", "Jennifer"};
    int leeftijden [] = {21, 30, 18, 14, 22, 19};
    double scores [] = {0.5, 1.6, 8.2, -2.4};

    schrijf_array(
            leeftijden,
            sizeof(leeftijden) / sizeof(leeftijden[0]),
            sizeof(leeftijden[0]),
            ',',
            (void(*)(const void*)) schrijf_int
            );

    schrijf_array(
            scores,
            sizeof(scores) / sizeof(scores[0]),
            sizeof(scores[0]),
            '$',
            (void(*)(const void*)) schrijf_double
    );

    schrijf_array(
            namen,
            sizeof(namen) / sizeof(namen[0]),
            sizeof(namen[0]),
            '$',
            (void(*)(const void*)) schrijf_cstring
    );

    return 0;
}

void schrijf_array(const void * t, size_t aantal, size_t grootte, char tussenteken, void(*schrijf)(const void*)) {
    const char * arr = (const char *) t;
    size_t i;
    schrijf(arr);
    for (i = 1; i < aantal; i++) {
        printf("%c", tussenteken);
        schrijf(arr + (grootte * i));
    }
    puts("\n");
}
