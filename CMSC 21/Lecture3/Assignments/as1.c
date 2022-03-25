#include <stdio.h>
#include <string.h>



int main(void)
{   
    int teenager; int age =  13;
    teenager =  (age >= 13 && 19 >= age)? 1: 0;
    printf("%d", teenager);
    return 0;
}