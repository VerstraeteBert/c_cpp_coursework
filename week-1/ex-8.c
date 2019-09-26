#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double MIN_RAD = -3;
const double MAX_RAD = 3.2;
const int DECIMALS = 3;

unsigned long long int calc_faculty(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return calc_faculty(x - 1) * x;
    }
}

double calc_sin(double rad) {
    int i;
    double res = 0;
    for (i = 0; i < 10; i++) {
        double curr = (1 / (double) calc_faculty(2 * i + 1) * pow(rad, 2 * i + 1));
        if (i % 2 == 0) {
            res += curr;
        } else {
            res -= curr;
        }
    }
    return res;
}

double randfrom(double min, double max, int decimals) {
    srand(time(NULL));
    double range = (max - min);
    double div = RAND_MAX / range;
    double random_value = min + (rand() / div);
    int decimal_power= (int) pow(10, decimals);
    return (round(random_value * decimal_power) / decimal_power);
}

int main() {
    double rad = randfrom(MIN_RAD, MAX_RAD, DECIMALS);
    printf("%f\n", rad);
    printf("%f\n", calc_sin(rad));
    printf("%f", sin(rad));
}