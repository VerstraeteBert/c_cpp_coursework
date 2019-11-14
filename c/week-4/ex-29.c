#include <stdio.h>

void schrijf_arr(const void *, const size_t, const int, const char, void(*)(const void *));
void write_string(const char **);
void write_double(const double *);
void write_int(const int *);

int main() {
    char * namen[] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
    int leeftijden[] = {21,30,18,14,22,19};
    double scores[] = {0.5,1.6,8.2,-2.4};

    schrijf_arr(leeftijden,
            sizeof(leeftijden) / sizeof(leeftijden[0]),
            sizeof(leeftijden[0]),
            '%',
                (void (*)(const void *)) write_int);
    schrijf_arr(scores,
                sizeof(scores) / sizeof(scores[0]),
                sizeof(scores[0]),
                ' ',
                 (void (*)(const void *)) write_double);
    schrijf_arr(namen,
                sizeof(namen) / sizeof(namen[0]),
                sizeof(namen[0]),
                '%',
                (void (*)(const void *)) write_string);
}

void schrijf_arr(const void * ptr, const size_t size, const int data_width,
        const char seperator, void (*write_func)(const void *)) {

    const char * arr = (char *) ptr;
    size_t i;
    write_func(arr);
    for(i = 1; i < size; i++) {
        printf("%c", seperator);
        write_func(arr + i * data_width);
    }
    printf("\n");
}

void write_string(const char ** p_str) {
    printf("%s", *p_str);
}

void write_double(const double * p_double) {
    printf("%.1f", *p_double);
}

void write_int(const int * p_int) {
    printf("%d", *p_int);
}
