#include <stdio.h>

void my_tupper(char * s) {
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = 'A' +  (s[0] - 'a');
    }
    int i = 1;
    while (s[i]) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'a' + (s[i] - 'A');
        }
        i++;
    }
}

int main(int argc, char * argv []) {
    if (argc == 1) {
        printf("Dag allemaal!\n");
    } else {
        int i;
        for (i = 1; i < argc; i++) {
            my_tupper(argv[i]);
            printf("Dag %s!\n", argv[i]);
        }
    }
}
