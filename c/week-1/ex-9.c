#include <stdio.h>

int number_sum(int number) {
    int acc = 0;
    while (number != 0) {
        acc += number % 10;
        number /= 10;
    }
    return acc;
}

int number_sum_rec_helper(int number, int acc) {
    if (number == 0) return acc;
    acc += number % 10;
    number /= 10;
    return number_sum_rec_helper(number, acc);
}

int number_sum_rec(int number) {
    return number_sum_rec_helper(number, 0);
}

int main() {
    printf("%d\n", number_sum(897));
    printf("%d\n", number_sum_rec(897));
}
