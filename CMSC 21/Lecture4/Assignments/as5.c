#include <stdio.h>
#include <stdlib.h>

int dayValidation(int min, int max){
    
    while(1){
        int input;
        printf("\nInput:");
        scanf("%d", &input); 

        if(input < min || input > max){
            printf("\n\nInvalid input!\n\nEnter a number between %d and %d.\n\n", min, max);
        }else{
            return input;
        }
    }
}

int main(void){
    int days, startingDay;
    printf("Enter number of days in a month");
    days =  dayValidation(28, 31);


    printf("Enter the starting day of the week (1=Sun, 7=Sat)");
    startingDay = dayValidation(1, 7);

    // loop for spacing the starting day
    int j = 1;
    while (j  < startingDay){
            printf("   ");
            j++;
        }
    
    for (int i = 1; i <= days; i++)
    {   
        printf("%2d ", i);
        
        if(i%7 == (8-startingDay)%7){
            printf("\n");
        }
    }

    return 0;
    
}