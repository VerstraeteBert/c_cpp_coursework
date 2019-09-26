#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int calc_faculty(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return calc_faculty(x - 1) * x;
    }
}

void print_byte_sizes() {
    /**
    * Real:
    *  float = 4B
    *  double = 8B
    *  long double = 16B
    */
    printf("Reeel: ");
    float f;
    double d;
    long double ld;
    printf("%lu ", sizeof(f));
    printf("%lu ", sizeof(d));
    printf("%lu ", sizeof(ld));

    /**
     *  Whole:
     *  int = 4B
     *  unsigned long long int = 8B
     *  signed long long = 8B
     *  long long int = 8B
     */
    int integer;
    signed long long sll;
    long long int lli;
    printf("\nGeheel: ");
    printf("%lu ", sizeof(integer));
    printf("%lu ", sizeof(sll));
    printf("%lu ", sizeof(lli));

    /**
     * Real data types might have more space but are just an approximation of the actual value;
     * The largest positive whole number can be stored in unsigned long long int
     * -> unsigned signifies that the most significant bit is used as a data bit
     */
}

int get_int_from_stdin(int min, int max) {
    int num;
    printf("Faculty Calculator: input a whole number between 2 and 30\n");
    if (scanf("%d", &num) == 0 || num < min || num > max) {
        printf("Invalid input: %d\n", num);
        while (getchar() != '\n') {}
        num = get_int_from_stdin(min, max);
    }
    return num;
}

int main() {
    print_byte_sizes();

    /**
     * Prints faculties of 2 -> 30
     */
//    int i;
//    for (i = 2; i <= 30; i++) {
//        printf("Origineel: %d\tFaculteit: %.0Lf\n", i, calc_faculty(i));
//    }

    /**
     * Random number gen ( 2 <= x <= 20 )
     */
//    srand(time(NULL));
//    int r = rand() % 19 + 2;
//    printf("Origineel: %d\tFaculteit: %.0Lf", r, calc_faculty(r));
//    return(0);

    /**
    * Input desired number ( 2 -> 30 ) to calculate faculty
    */
    const int MIN = 2;
    const int MAX = 30;
    int num;
    num = get_int_from_stdin(MIN, MAX);
    printf("The faculty of %d is %.0llu", num, calc_faculty(num));

    return(0);
}
