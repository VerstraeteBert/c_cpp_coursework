```
int i;
for(i=10; i>0; i--){
    if(i==10) {
        printf("Hello world!\n");
    }
    printf("%d ",i);
    if(i==1) {
        printf("\nSTART");
    }
}
```
The print statements of "Hello, World!" and "START" should be placed outside of the loop.
Being inside of the loop, there's a small performance impact, in which the if-statements need to be evaluated during each loop.