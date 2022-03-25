
#include <stdio.h>
#include <string.h>

int main(void){

    int number, tensDigit, onesDigit, answer;
    int valid  = 0;

    // DO-WHILE LOOP TO ACCEPT AND VALIDATE INPUT
    do
    {
        printf("\nEnter two-digit number: ");
        valid = scanf("%d", &number);

        if(number < 10 || number > 99 || !valid){ // runs if number is not  a two-digit number or a non-numeric character was entered
            valid = 0;
            printf("\n\n###### ERROR ######\n\nEnter a positive two-digit number!\n\n###################\n\n");
        }
        if (!valid){
            while((number =  getchar()) != '\n' && number != EOF); // clears the input stream
        }
    } while (!valid);
    
    tensDigit = number / 10;
    onesDigit =  number % 10;

    printf("Number entered in words: ");

    // PRINTING OF NUMBER IN WORDS
    if(tensDigit >= 2){ // if number is greater than 19

        switch (tensDigit)
    {
            case 9:
                printf("Ninety");
                break;
            case 8:
                printf("Eighty");
                break;
            case 7:
                printf("Seventy");
                break;
            case 6:
                printf("Sixty");
                break;
            case 5:
                printf("Fifty");
                break;
            case 4:
                printf("Forty");
                break;
            case 3:
                printf("Thirty");
                break;
            case 2:
                printf("Twenty");
                break;
    }
        switch (onesDigit)
        {
            case 9:
                printf("-nine");
                break;
            case 8:
                printf("-eight");
                break;
            case 7:
                printf("-seven");
                break;
            case 6:
                printf("-six");
                break;
            case 5:
                printf("-five");
                break;
            case 4:
                printf("-four");
                break;
            case 3:
                printf("-three");
                break;
            case 2:
                printf("-two");
                break;
            case 1:
                printf("-one");
                break;
        }
    }
    switch (number)
    {

    case 19:
        printf("Nineteen");
        break;
    case 18:
        printf("Eighteen");
        break;
    case 17:
        printf("Seventeen");
        break;
    case 16:
        printf("Sixteen");
        break;
    case 15:
        printf("Fifteen");
        break;
    case 14:
        printf("Fourteen");
        break;
    case 13:
        printf("Thirteen");
        break;
    case 12:
        printf("Twelve");
        break;
    case 11:
        printf("Eleven");
        break;
    case 10:
        printf("Ten");
        break;
    }
    
    // USER CHOICE TO ENTER ANOTHER NUMBER
    printf("\n\nDo you want to enter another number?\nEnter 1 for Yes and 2 for No: ");
    scanf("%d", &answer);
    if (answer == 1){
        main();
    }else{
        printf("Program exited.");
    }
    
    return 0;
}