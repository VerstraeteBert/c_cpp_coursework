#include <stdio.h>

void schrijf(const char * begin, const char * eind) {
    while (begin != eind) {
        printf("%c", *begin);
        begin++;
    }
    printf("\n");
}

const char * pointerNaarEersteKleineLetter(const char * ptr) {
    while (*ptr != '\0' && !(*ptr >= 'a' && *ptr <= 'z')) {
        ptr++;
    }
    return ptr;
}

void verzetNaarEersteHoofdletter(const char ** ptr) {
    while (**ptr != '\0' && !(**ptr >= 'A' && **ptr <= 'Z')) {
        (*ptr)++;
    }
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
