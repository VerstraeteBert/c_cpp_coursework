#include <stdio.h>

/**
 * 1.  Kan je de lengte van de array opvragen via de pointer p?
 * Nee, niet direct. Het zal de grootte van de pointer zelf teruggeven.
 * Dit kan wel indirect gedaan worden, over de volledige gerefereerde character array te loopen en ondertussen het aantal elementen bij te houden
 * (tot aan de stop '\0' bij char arrays)
 */

void write_n(const char * string, int num_to_print) {
    int i;
    for (i = 0; i < num_to_print; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void write(const char * c1, const char * c2) {
    while (c1 != c2) {
        printf("%c", *c1);
        c1++;
    }
    printf("\n");
}

void print_sizes_of() {
    /**
     * Pointers always 8 bytes mem
     */
    int * int_pt;
    char * char_pt;
    double * double_pt;
    printf("Size of int pt: %lu \n", sizeof(int_pt));
    printf("Size of char pt: %lu \n", sizeof(char_pt));
    printf("Size of double pt: %lu \n", sizeof(double_pt));
}

int main(){
    print_sizes_of();
    char letters [] = {'p','o','r','g','o','e','d','o','i','e','o','k',
    'i',':','a','-','t','('};
    const char *p = letters;
    write_n(letters+3,4);
    write(p+10,p+12);
}