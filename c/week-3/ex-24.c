#include <stdio.h>

void pivot(char * start, char * end, char * pivot) {
    char * l = pivot - 1;
    char * r = pivot + 1;
    while (l >= start && r <= end) {
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l--;
        r++;
    }
}

void write(const char * c1, const char * c2) {
    while (c1 != c2) {
        printf("%c", *c1);
        c1++;
    }
}

int main() {
    char text[] = {'b','d','?','z','g','o','e','z','e','b',
    ' ','d','i','g','!','h','o','s','v'};
    pivot(text + 7,text + 12,text + 9);
    write(text + 4,text + 15);
}
