#include <stdio.h>

char * shift_left(char row [], int size) {
    int i;
    char temp;
    for (i = 0; i < size - 1; i++) {
        temp = row[i];
        row[i] = row[i + 1];
        row [i + 1] = temp;
    }
    return row;
}

void print_row(char row [], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%c ", row[i]);
    }
    printf("\n");
}

int main() {
    char row [] = {'a', 'b', 'c', 'd', 'e'};
    int size = sizeof(row) / sizeof(char);
    int i;
    printf("Original: ");
    print_row(row, size);
    for (i = 0; i < 3; i++) {
        shift_left(row, size);
        print_row(row, size);
    }
    return 0;
}
