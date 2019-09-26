```
#include <stdio.h>
int main(){
    int macht = 1;
    int i;
    for(i=0; i<20; i++){
        printf("%d ",macht);
        macht *= 2;
        if(macht > 10000){
            break;
        }
    }
    return 0;
}
```
It is not known how many iterations are necessary before hitting the limit.
This means that a  for-loop is not suitable in this case; a while loop suits this suitation better.
