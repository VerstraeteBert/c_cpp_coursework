#include <stdio.h>

const int MAX_AMOUNT = 5;

int main() {
    int acc = 0;
    int num;
    int i = 0;
    while (i < MAX_AMOUNT && scanf("%d", &num) != 0 && num >= 0) {
        acc += num;
        i++;
    }
    printf("%d Positive number(s) given\n", i);
    printf("Sum of the positive number(s) is: %d", acc);
    return(0);
}
