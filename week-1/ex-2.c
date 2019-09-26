#include <stdio.h>

/*
 * octal
 *  96(10) => 140(8)
 *  96 / 8 = 12R0
 *  12 / 8 =  1R4
 *  1  / 8 =  0R1
 *  Reverse the remainders => 140
 *  To put in right order  => { 1 * 10^2, 1 * 10^1, 1 * 10^0 }
 */
void print_decimal_to_octal(int decimal_num) {
    int octal_num = 0; int pos_pow = 1;

    while (decimal_num != 0) {
        octal_num += (decimal_num % 8) * pos_pow;
        decimal_num /= 8;
        pos_pow *= 10;
    }
    printf("%d", octal_num);
}

/*
 * Similar to octal
 * Cannot used integer to store the result, must use a char array to accommodate alphabetical values
 * ASCII values are used:
 *      '0' = 48 -- '9' == 58
 *      'A' = 65 -- 'F' == 70
 * Printed in reverse order (inserted bottom up)
 */
void print_decimal_to_hex(int decimal_num) {
    char hex_num[10];
    int remainder = 0; int len = 0;
    do {
        remainder = decimal_num % 16;
        if (remainder < 10) {
            hex_num[len++] = remainder + 48; // ASCII 48 == '0'; 9 + 48 == ASCII '9'
        } else {
            hex_num[len++] = remainder + 55; // ASCII 65 == 'A'; 10 + 55 == ASCII 'A'
        }
        decimal_num /= 16;
    } while (decimal_num != 0);

    int i;
    for (i = len - 1; i >= 0; i--) {
        printf("%c", hex_num[i]);
    }
}

int main() {
    const int ceil = 64;
    int i;

    for (i = 0; i <= ceil; i++) {
        // Printf (boring)
        printf("%4d%4o%4X\n", i, i, i);

        // Own conversions
//        printf("%d\t", i);
//        print_decimal_to_octal(i);
//        printf("\t");
//        print_decimal_to_hex(i);
//        printf("\n");
    }
    return 0;
}
