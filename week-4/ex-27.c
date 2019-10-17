#include <stdio.h>

void verzetNaarEersteHoofdletter(const char ** s) {
    while (**s != '\0') {
        if (**s >= 'A' && **s <= 'Z') {
            return;
        }
        (*s)++;
    }
}

const char * pointerNaarEersteKleineLetter(const char * s) {
    const char * p = s;
    while (*p != '\0') {
        if (*p >= 'a' && *s <= 'z') {
            return p;
        }
        p++;
    }
    return p;
}

void schrijf(const char * left, const char * right) {
    while(left != right) {
       printf("%c", *left++);
    }
    printf("\n");
}

int main(){
    char zus1[50] = "sneeuwWITje";
    char zus2[50] = "rozeROOD";
    const char* begin;
    const char* eind;
    begin = zus1;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin,eind); /* schrijft ’WIT’ uit */
    begin = zus2;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin,eind); /* schrijft ’ROOD’ uit */
    return 0;
}
