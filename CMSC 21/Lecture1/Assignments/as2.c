
#include <stdio.h>
#include <string.h>

// FUNCTION TO REVERSE STRING 
void string_reverse(char *inp)
{
    int i, j, len, temp;  // i to iterate from the start of string, j to iterate from the end of the string, 

    len = strlen(inp);  

    j = len - 1; // index of the end of the string
    for(i = 0; i < j; i++)
    {
        temp = inp[i];  // temp equal to the first character of inp
        inp[i] = inp[j]; // inp[i] = the last character of inp
        inp[j] = temp; // inp[j] = first character of inp
        j--;
    }

}


int main(void)
{
    char number[4];
    printf("Enter a 3-digit number here: ");
    fgets(number, 4, stdin);

    printf("You entered: %s\n", number);
    string_reverse(number);
    printf("Reverse: %s", number);

    return 0;
}