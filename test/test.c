#include <stdio.h>
#include <ranlib.h>
#include <time.h>


int main(void) {
    srand(time(NULL));
    printf("%d", rand() % 50);
    printf("%d\n", sizeof(unsigned int));
    printf("%d\n", sizeof(int));
    return 0;
}
