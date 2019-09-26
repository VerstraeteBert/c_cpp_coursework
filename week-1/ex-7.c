#include <stdio.h>

const int MAX_AMOUNT = 5;

int main() {
    int acc = 0;
    int i, num;
    for (i = 0; i < MAX_AMOUNT; i++) {
        if (scanf("%d", &num) == 0 || num < 0) {
            printf("Invalid input: must be a positive whole number\n");
            break;
        }
        acc += num;
        while (getchar() != '\n') {}
    }
    printf("%d Positive number(s) given\n", i);
    printf("Sum of the positive number(s) is: %d", acc);
    return(0);
}