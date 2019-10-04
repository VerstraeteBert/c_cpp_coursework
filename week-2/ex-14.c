#include <stdio.h>

char * shift_left(char row [], size_t size) {
    size_t i; char temp;
    for (i = 0; i < size - 1; i++) {
        temp = row[i];
        row[i] = row[i + 1];
        row [i + 1] = temp;
    }
    return row;
}

void print_row(const char row [], size_t size) {
    size_t i;
    for(i = 0; i < size; i++) {
        printf("%c ", row[i]);
    }
    printf("\n");
}

int main() {
    char row [] = {'a', 'b', 'c', 'd', 'e'};
    size_t size = sizeof(row) / sizeof(row[0]); int i;
    printf("Original: ");
    print_row(row, size);
    for (i = 0; i < 3; i++) {
        shift_left(row, size);
        print_row(row, size);
    }
    return 0;
}
