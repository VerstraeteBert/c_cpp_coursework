#include <stdio.h>
int main(){
    int t[6] = {0, 10, 20, 30, 40, 50};
    int* pt[3]; // array van pointers
    int i;
    for(i=0; i<3; i++){
        pt[i] = &t[2*i];
        // pt[&p[0], &p[2], &p[4]]
    }
    pt[1]++;
    // pt[&p[0], &p[3], &p[4]]
    pt[2] = pt[1];
    // pt[&p[0], &p[3], &p[3]]
    *pt[1] += 1;
    // pt[&p[0], &p[3], &p[3]]
    // t[6] = {0, 10, 20, 31, 40, 50};
    *pt[2] *= 2;
    // pt[&p[0], &p[3], &p[3]]
    // t[6] = {0, 10, 20, 62, 40, 50};
    int ** ppt = &pt[0];
    // **ppt = &pt[0]
    // pt[&p[0], &p[3], &p[3]]
    // t[6] = {0, 10, 20, 62, 40, 50};
    (*ppt)++;
    // ppt = &pt[0]
    // pt[&p[1], &p[3], &p[3]]
    // t[6] = {0, 10, 20, 62, 40, 50};
    **ppt += 1;
    // ppt = &pt[0]
    // pt[&p[1], &p[3], &p[3]]
    // t[6] = {0, 11, 20, 62, 40, 50};
    for(i=0; i<6; i++){
        printf("%d ",t[i]);
    }
    // 0, 11, 20, 62, 40, 50
    printf("\n");
    for(i=0; i<3; i++){
        printf("%d ",*pt[i]);
    }
    // &p[1],&p[3],&p[3]
    printf("\n");
    return 0;
    /**
     * bijvraag
     * sizeof(pointer) / sizeof(point[0])
    **/
}
