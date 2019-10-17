#include <stdio.h>

void my_tupper(char * s) {
    if (s[0] >= 97 && s[0] <= 122) {
        s[0] -= 32;
    }
    int i;
    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
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
