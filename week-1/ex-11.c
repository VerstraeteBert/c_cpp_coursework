#include <stdio.h>

int ggd(a, b) {
    if (a == 0 || b == 0) {
        return a != 0 ? a : b;
    }
    return ggd(b, a % b);
}

int main() {
    printf("%d", ggd(99, 84));
}
