#include <stdio.h>

void pivot(const char * start, const char * end, char * pivot) {
    /**
     * The difference between the closest point (end / start)
     * and the pivot is the amount of numbers that can be swapped
     */
    long diff_idx;
    diff_idx = (end - pivot) < (pivot - start) ? (end - pivot) : (pivot - start);

    /**
     * In essence, we need to swap elements around the pivot
     * if pivot idx is 3 then 2 and 4 need to be swapped.
     *
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
