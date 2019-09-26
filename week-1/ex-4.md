```
#include <stdio.h>
int main(){
    int macht = 1;
    while(macht < 10000){
        macht *= 2;
        printf("%d ",macht);
    }
    return 0;
}
```

Requirement that results are < 10000.  
-> in this code, this is only checked before the multiplication. 