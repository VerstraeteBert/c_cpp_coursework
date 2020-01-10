#include <stdio.h>
#include <string.h>

int is_palindroom_perm(const char *);
int maak_bit_map(const char *);
int max_een_bit(int);

int main() {
    char * woord_1 = "hanlonk";
    printf("%s is een palindroom perm: %d\n", woord_1, is_palindroom_perm(woord_1));
    char * woord_2 = "maadamadmim";
    printf("%s is een palindroom perm: %d\n", woord_2, is_palindroom_perm(woord_2));
}

// palindroom perm -> elke char moet een even aantal keer voorkomen zoals abba, bbaa, baba
// met uitzondering van één character : poopoop -> oopoopp
int is_palindroom_perm(const char * woord) {
    int bitmap = maak_bit_map(woord);
    return bitmap == 0 || max_een_bit(bitmap);
}

int maak_bit_map(const char * woord) {
    size_t i; int mask; int bitmap = 0;
    for (i = 0; i < strlen(woord); i++) {
        mask = 1 << (woord[i] - 'a');
        if ((bitmap & mask) == 0) {
            bitmap |= mask;
        } else {
            bitmap &= ~mask;
        }
    }
    return bitmap;
}

int max_een_bit(int bitmap) {
    return (bitmap & (bitmap - 1)) == 0;
}
