#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x,y;
} punt;

double euclid_afst(const punt * p1, const punt * p2);
double manhattan_afst(const punt * p1, const punt * p2);
double schaak_afst(const punt * p1, const punt * p2);

double bepaal_max_afst(const punt punten [], size_t aant, double(*afst)(const punt *, const punt *));

int main(void) {
    int aant_punten;
    printf("Hoeveel punten?\n");
    while (scanf("%d", &aant_punten) != 1) {
        fflush(stdin);
    }
    scanf("%d",&aant_punten);
    punt * punten = (punt *) malloc(aant_punten * sizeof(punt));
    int i;
    double x, y;
    char komma;
    for (i = 0; i < aant_punten; i++) {
        while (scanf("%lf %c %lf", &x, &komma, &y) != 3 || komma != ',') {
            fflush(stdin);
        }
        punten[i].x = x;
        punten[i].y = y;
    }
    double max_eucl = bepaal_max_afst(
                punten,
                aant_punten,
                euclid_afst
            );
    double max_manh = bepaal_max_afst(
            punten,
            aant_punten,
            manhattan_afst
            );
    double max_cheb = bepaal_max_afst(
            punten,
            aant_punten,
            schaak_afst
            );
    printf("Max euclid: %.1lf\n", max_eucl);
    printf("Max manh: %.1lf\n", max_manh);
    printf("Max cheb: %.1lf\n", max_cheb);
    free(punten);
    return 0;
}

double bepaal_max_afst(const punt punten [], size_t aant, double(*afst)(const punt *, const punt *)) {
    if (aant <= 1) return -1;
    size_t i;
    double max = afst(&punten[0], &punten[2]);
    for (i = 1; i < aant - 1; i++) {
        double huidige_afst = afst(&punten[i], &punten[i+1]);
        if (max < huidige_afst) {
            max = huidige_afst;
        }
    }
    return max;
}

double euclid_afst(const punt * p1, const punt * p2) {
    return sqrt(pow(p1->x - p2->y, 2) + pow(p1->y - p2->y, 2));
}

double manhattan_afst(const punt * p1, const punt * p2) {
    return fabs(p1->x - p2->x) + fabs(p1->y - p2->y);
}

double schaak_afst(const punt * p1, const punt * p2) {
    double abs_x = fabs(p1->x - p2->x);
    double abs_y = fabs(p1->y - p2->y);
    return abs_x > abs_y ? abs_x : abs_y;
}
