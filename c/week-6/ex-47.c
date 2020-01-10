#include <assert.h>
#include <stdio.h>

typedef unsigned int uint;

uint bit_i (uint x, int i) {
    return (x >> i) & 1;
}

void schrijf (uint i, int lengte) {
    int j;
    for (j = lengte - 1; j >= 0; j--) {
        printf("%u", bit_i(i, j));
        if (j % 4 == 0 && j != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

uint eenbit(int i) {
    return 1 << i;
}

uint aantal_eenbits(uint i) {
    uint count = 0;
    while (i) {
        count += (i & 1);
        i >>= 1;
    }
    return count;
}

uint bit_i_aangezet(uint x, int i) {
    return (x | (1 << i));
}

uint bit_i_uitgezet(uint x, int i) {
    return x & ~(eenbit(i));
}

uint bit_i_gewisseld(uint x, int i) {
    return (x ^ eenbit(i));
}

int zijn_gelijk(uint x, uint y) {
    return x ^ y;
}

int is_even(uint x) {
    return !(x & 1);
}

///** 10
// * n & (n-1) == 0
// *
// *  0100 (n) (macht van 2)
// * &0011 (n-1)
// *  0000 => true
// *
// *  0110 (n) (geen macht van 2)
// * &0101 (n-1)
// *  0100 => false
// *
// * deze test evalueert dat een getal een macht van 2 is
// */
//

int product(int a, int b) {
    int sum = 0;
    while (b) {
        if (b & 1) {
            sum += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return sum;
}


int main(void) {
    assert(bit_i(4, 2) == 1);
    assert(bit_i(10, 3) == 1);
    assert(bit_i(4, 1) == 0);

    schrijf(eenbit(4), 8);
    schrijf(eenbit(0), 8);

    assert(aantal_eenbits(8) == 1);
    assert(aantal_eenbits(1) == 1);
    assert(aantal_eenbits(0) == 0);
    assert(aantal_eenbits(93) == 5);

    assert(bit_i_aangezet(4, 0) == 5);
    assert(bit_i_aangezet(0, 0) == 1);
    assert(bit_i_aangezet(8, 3) == 8);

    assert(is_even(2) == 1);
    assert(is_even(1) == 0);

    assert(product(4, 2) == 8);
    assert(product(1, 0) == 0);
    assert(product(5, 1) == 5);
    assert(product(40, 20) == 800);

    schrijf(513, 10);
}
