#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_SIZE = 5;

char * lees();

int main(void) {
    char * ingelezen = lees();
    printf("%s", ingelezen);
    free(ingelezen);
}

char * lees() {
    char temp[MAX_SIZE + 1];
    fgets(temp, MAX_SIZE + 1, stdin);
    fflush(stdin);
    int len = strlen(temp);
    if (temp[len - 1] == '\n') {
        temp[len - 1] = '\0';
        len--;
    }
    char * res = (char *) malloc((len + 1) * sizeof(char));
    strcpy(res, temp);
    return res;
}
