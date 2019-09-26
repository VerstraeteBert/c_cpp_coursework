#include <stdio.h>
#include <stdlib.h>

void pow_pos(int x, int ceil) {
    if (x <= 0) {
        exit(1);
    }
    int result = x;
    while (1) {
        printf("%d ", result);
        result *= x;
        if (result >= ceil) {
            break;
        }
    }
}

int main(){
    pow_pos(10, 10000);
    return(0);
}



