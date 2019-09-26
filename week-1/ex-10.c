#include <stdio.h>

unsigned long long int calc_faculty(int x) {
    unsigned long long int result = x;
    while (x != 1) {
        result *= --x;
    }
    return result;
}

unsigned long long int calc_faculty_rec(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return calc_faculty_rec(x - 1) * x;
    }
}

int main() {
    printf("%llu\n", calc_faculty(4));
    printf("%llu", calc_faculty_rec(4));
    return(0);
}