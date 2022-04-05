#include <stdio.h>


int main(void){

    int n;
    printf("\nEnter n:");
    scanf("%d", &n);
    
    printf("\n\nTABLE OF POWERS OF TWO\n\n");
    printf(" n    2 to the n\n");
    printf("--- ------------\n");

    for (int i = 0; i <= n; i++){
        int answer = 1;
        
        for(int j = i; j > 0; j--){
            answer *= 2;     
        }
        if (i == 0){
            answer = 1;
        }
        printf("%-6d%d\n", i, answer);
    }
    return 0;
}
