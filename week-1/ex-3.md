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
- Both print statements are coupled to a iteration value, while they shouldn't be.
- Small performance impact, the if-statements need to be evaluated during each loop.