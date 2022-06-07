#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 typedef struct
    {
        struct point{
            float x;
            float y;
        }point1, point2;
        float *midpoint;
        float slope;
        float distance;
    }line;

// function prototypes
void input(line* p);
void solve(line* p);
float solveSlope(line *p);
float *solveMidpoint(line *p);
float solveDistance(line *p);
void getSlopeInterceptForm(line *p);


int main(void){
    system("cls");
    line line; // declare struct line variable
    
    input(&line); // gets input
    solve(&line); // solves slope, midpoint, distance

    printf("Point 1: (%g, %g)", line.point1.x, line.point1.y);
    printf("\nPoint 2: (%g, %g)", line.point2.x, line.point2.y);

    printf("\n\nSlope: %g", line.slope);
    printf("\nMidpoint: (%g, %g)", line.midpoint[0], line.midpoint[1]);
    printf("\nDistance between 2 points is %g units.", line.distance);
    
    getSlopeInterceptForm(&line); // prints slope-intercept form

    return 0 ;
}


// function definitions 
void input(line* p){

    printf("Enter x and y for point 1: ");
    scanf("%f %f", &p->point1.x, &p->point1.y);
    printf("Enter x and y for point 2: ");
    scanf("%f %f", &p->point2.x, &p->point2.y);

}

float solveSlope(line *p){
    float slope;
    float y1 = p->point1.y, y2 = p->point2.y, x1 = p->point1.x, x2 = p->point2.x;

    slope = (y2 - y1)/(x2 - x1);  /*m = y2-y1/x2-x1 */
    return slope;
}

float *solveMidpoint(line *p){
    float x, y; static float r[2];
    x = (p->point1.x + p->point2.x)/2;  // (x1+x2)/2
    y = (p->point1.y + p->point2.y)/2;  // (y1+y2)/2
    r[0] = x; r[1] = y;

    return r;
}

float solveDistance(line *p){
    float x, y, distance;
    float y1 = p->point1.y, y2 = p->point2.y, x1 = p->point1.x, x2 = p->point2.x;

    x = (x1 - x2) * (x1 - x2); // squaring the difference of x1 and and x2
    y = (y1 - y2) * (y1 - y2); // squaring the difference of y1 and and y2
    
    distance = sqrt(x+y);
    return distance;
}

void getSlopeInterceptForm(line *p){
    float m  = p->slope, x = p->point1.x, y = p->point1.y, b;
    b = (m * (-x)) + (y); /* y - y1 = m(x- x1)    // point-slope form
                             y = mx - mx1 + y 
                             y = m(0) - mx1 + y           **b is y-intercept (y-intercept is value when x=0) 
                             y = -mx1 + y        
                                          
                             */
    printf("\ny = %gx + %g", m, b);
}

void solve(line *p){
    p->slope = solveSlope(p);
    p->midpoint =  solveMidpoint(p);
    p->distance =  solveDistance(p);
}
