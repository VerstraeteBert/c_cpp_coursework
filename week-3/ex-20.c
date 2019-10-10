/**
 * Initieel: passed by value, binnen wissel geen referentie meer naar ints meegegeven in parameters;
 * Waardes x en y zijn niet gewisseled na call van wissel
 */
void wissel(int * a, int * b){
    int hulp;
    printf(" Bij start van de wisselprocedure hebben we a=%d en b=%d.\n",*a,*b);
    hulp = *a;
    *a = *b;
    *b = hulp;
    printf(" Op het einde van de wisselprocedure hebben we a=%d en b=%d.\n",*a,*b);
}

int main(){
    int x, y;
    x = 5;
    y = 10;
    printf("Eerst hebben we x=%d en y=%d.\n",x,y);
    wissel(&x,&y);
    printf("Na de wissel hebben we x=%d en y=%d.\n",x,y);
    return 0;
}