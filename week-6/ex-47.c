#include <stdio.h>

typedef unsigned int uint;

uint get_bit_i(uint x, int i) {
    return 1 & (x >> i);
}

void write_bits(uint x, int length) {
    for (int i = length - 1; i >= 0; i--) {
        printf("%d", get_bit_i(x, i));
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

uint one_bit(int i) {
    return (1 << i);
}

uint num_set_bits(uint x) {
    int acc = 0;
    while (x) {
        acc += (x & 1);
        x >>= 1;
    }
    return acc;
}

uint set_ith_bit(uint x, int i) {
    return x | (1 << i);
}

uint unset_ith_bit(uint x, int i) {
    return x & ~(1 << i);
}

uint switch_ith_bit(uint x, int i) {
    return x ^ (1 << i);
}

int is_equal(uint x, uint y) {
    return x ^ y;
}

/**
 * n & (n-1) == 0
 *
 *  0100 (n) (macht van 2)
 * &0011 (n-1)
 *  0000 => true
 *
 *  0110 (n) (geen macht van 2)
 * &0101 (n-1)
 *  0100 => false
 *
 * deze test evalueert dat een getal een macht van 2 is
 */

uint product (uint a, uint b) {
    int res = 0;
    while (a != 0) {
        if ((a & 1) == 1) {
            res += b;
        }
        a >>= 1;
        b <<= 1;
    }
    return res;
}

int main () {
    printf("%d\n", get_bit_i(7, 0));
    write_bits(6, 8);
    write_bits(one_bit(4), 32);

    printf("Num set bits: %d\n", num_set_bits(7));

    printf("Set_ith_bit:\n");
    write_bits(set_ith_bit(5, 0), 32);
    printf("%d", product(16, 8));
    return 0;
}
