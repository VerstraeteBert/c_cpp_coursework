#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int waarde, aantal_delers;
    int * delers;
} Deeltal;

void schrijf_ints(const int *, int);
void schrijf_deeltal(const Deeltal *);
int aantal_delers_van(int);
int * delers_van(int);
void lees_deeltal(Deeltal *);
void lees_deeltallen(Deeltal *, size_t);
void schrijf_deeltallen(const Deeltal *, size_t);
void free_deeltallen(Deeltal *, size_t);

int main(void) {
    Deeltal * p_deeltallen = (Deeltal *) malloc(sizeof(Deeltal) * 4);
    lees_deeltallen(p_deeltallen, 4);
    schrijf_deeltallen(p_deeltallen, 4);
    free_deeltallen(p_deeltallen, 4);
    free(p_deeltallen);
}

void schrijf_ints(const int * p_ints, int aant) {
    size_t i;
    printf("%d", p_ints[0]);
    for (i = 1; i < aant; i++) {
        printf("-%d", p_ints[i]);
    }
}

void schrijf_deeltal(const Deeltal * p_dt) {
    printf("%d  ", p_dt->waarde);
    schrijf_ints(p_dt->delers, p_dt->aantal_delers);
    printf("\n");
}

int aantal_delers_van(int x) {
    int i; int num_delers = 0;
    for (i = 1; i <= (x / 2); i++) {
        if (x % i == 0) {
            num_delers++;
        }
    }
    return num_delers;
}

int * delers_van(int x) {
    int num_delers = aantal_delers_van(x);
    int * delers = (int *) malloc(num_delers * sizeof(int));
    int idx_deler = 0; int j;
    for (j = 1; j <= x / 2; j++) {
        if (x % j == 0) {
            delers[idx_deler] = j;
            idx_deler++;
        }
    }
    return delers;
}

void lees_deeltal(Deeltal * deeltal) {
    int waarde;
    printf("Geef een strikt positieve waarde in voor het deeltal: \n");
    while (scanf("%d", &waarde) == 0 || waarde < 0) {
        printf("FOUT: geef een strikt positieve waarde in voor het deeltal: \n");
        fflush(stdin);
    }
    deeltal->waarde = waarde;
    deeltal->delers = delers_van(waarde);
    deeltal->aantal_delers = aantal_delers_van(waarde);
}

void lees_deeltallen(Deeltal * deeltallen, size_t aantal) {
    size_t i;
    for (i = 0; i < aantal; i++) {
        lees_deeltal(&deeltallen[i]);
    }
}

void schrijf_deeltallen(const Deeltal * p_deeltallen, size_t aant) {
    size_t i;
    for (i = 0; i < aant; i++) {
        schrijf_deeltal(&p_deeltallen[i]);
    }
}

void free_deeltallen(Deeltal * p_deeltallen, size_t aant) {
    size_t i;
    for (i = 0; i < aant; i++) {
        free(p_deeltallen[i].delers);
    }
}
