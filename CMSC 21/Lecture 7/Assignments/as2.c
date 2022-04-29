#include <stdio.h>

#define N_MOVIES 4
#define N_REVIEWERS ((int)(sizeof(ratings) / sizeof(ratings[0])))

int main(){

    double sum_per_reviewer, ave_per_reviewer;
    
    double ratings[][N_MOVIES] = {
        {4, 6, 2, 5},
        {7, 9, 4, 9},
        {6, 9, 3, 7}
    };

    printtf("N reviewers: %d\n", N_REVIEWERS);

    for (int reviewer = 0; reviewer < N_REVIEWERS; reviewer++){
        printf("Reviewer%d : ", reviewer+1);
        sum_per_reviewer = 0;

        for (int movie = 0; movie < N_MOVIES; movie++){
            printf("%.0f ", ratings[reviewer][movie]);
            sum_per_reviewer += ratings[reviewer][movie];
        }

        ave_per_reviewer = sum_per_reviewer / N_MOVIES;
        printf("--- Average %.1f", ave_per_reviewer);
        printf("\n");
    }
    return 0;
}