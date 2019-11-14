#include <stdio.h>

void print_even_indices(char array[], size_t size) {
    size_t i;
    for (i = 0; i < size; i += 2) {
        printf("%c", array[i]);
    }
}

int main() {
    char letters[] =  {'p','o','r','e','o','i','f','o','i','e','c','i',
    'i',':','a','-','t','('};
    print_even_indices(letters, sizeof(letters) / sizeof(letters[0]));
    return(0);
}
