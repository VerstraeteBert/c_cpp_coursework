#include <stdio.h>

    /**
     * Characters of a string need to be swapped symettrically around a pivot, given a start and end point.
     *
     * Example
     *  a b c d e f g h
     *  pivot = c (idx 2)
     *  start = a (idx 0)
     *  end = h (idx 7)
     *  => e d c b a f g h
     */
void pivot(const char * start, const char * end, char * pivot) {
    /**
     *The difference between the closest point (end / start)
     * and the pivot is the amount of numbers that can be swapped
     */
    long diff_idx;
    diff_idx = (end - pivot) < (pivot - start) ? (end - pivot) : (pivot - start);

    /**
     * If N elements need to be swapped,
     * start next to the pivot on both sides and swap numbers,
     * moving outwards until N swaps have been completed
     */
    char * left = pivot - 1; char * right = pivot + 1;
    long i; char temp;
    for (i = 0; i < diff_idx; i++) {
        temp = *right;
        *right = *left;
        *left = temp;
        left--; right++;
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
