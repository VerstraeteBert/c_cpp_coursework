// 25 - 26 - 29 - 30 - 27 - 28 - 31 - 32
#include <stdio.h>
#define AANTAL 5

int som(int a, int b) {
    return a+b;
}

int product(int a, int b) {
    return a*b;
}

int verschil(int a, int b) {
    return a-b;
}

void schrijf(const int * t, int aantal) {
    int i;
    for(i=0; i<aantal; i++){
        printf("%i ",t[i]);
    }
    printf("\n");
}

void vul_array(const int * src_1, const int * src_2, int * dest, size_t len, int(*)(int, int));

int main(){
    int a[AANTAL];
    int b[AANTAL];
    int c[AANTAL];
    int i;

    for(i=0; i<AANTAL; i++){
        a[i] = 10*i;
        b[i] = i;
    }
    vul_array(a,b,c,AANTAL,som);
    schrijf(c,AANTAL);
    vul_array(a,b,c,AANTAL,product);
    schrijf(c,AANTAL);
    vul_array(a,b,c,AANTAL,verschil);
    schrijf(c,AANTAL);
    return 0;
}

void vul_array(const int * src_1, const int * src_2, int * dest, size_t len, int(*cb)(int, int)) {
    size_t i;
    for (i = 0; i < len; i++) {
        dest[i] = cb(src_1[i], src_2[i]);
    }
}
