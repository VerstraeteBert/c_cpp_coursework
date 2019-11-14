#include <stdio.h>

void my_tupper (char * str) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] += ('A' - 'a');
    }
    int i;
    for (i = 1; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

int main() {
    char s [80];
    fgets(s, 80, stdin);
    my_tupper(s);
    printf("%s\n", s);

    char s2[16] =  "snEeuwwITJE<3!!";
    my_tupper(s2);
    printf("%s\n", s2);
    return 0;
}
