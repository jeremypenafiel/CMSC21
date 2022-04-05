#include <stdio.h>

int main(void){

    int i = 10;
    while (i<10)
    {
        printf("i is %d\n", i);
        i++;
    }
    i=10;
    for (; i< 10;){
        printf("i is %d\n", i);
        i++;
    }
    i=10;
    do
    {
        printf("i is %d\n", i);
        i++;
    } while (i <10);
    
    
}