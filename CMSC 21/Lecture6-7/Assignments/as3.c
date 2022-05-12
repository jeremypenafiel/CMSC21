#include <stdio.h>

#define ROW 8
#define COLUMN 8

int main(void){

    //PRINTING OF MATRIX
    char nodes [][4] = {"A", "B", "[C]", "[D]", " E", "F", "G", "H"}; // initialize list of all points
    int road_networks[ROW][COLUMN] ={{1, 1, 0, 0, 0, 1, 0, 0},  // initialize matrix
                                     {1, 1, 1, 0, 0, 0, 0, 0},
                                     {0, 1, 1, 0, 1, 1, 0, 0},
                                     {0, 0, 0, 1, 1, 0, 0, 0},
                                     {0, 0, 0, 1, 1, 0, 0, 0},
                                     {1, 0, 1, 0, 0, 1, 0, 0},
                                     {1, 0, 0, 1, 0, 0, 1, 0},
                                     {0, 0, 0, 0, 0, 1, 0, 1}};
    // PRINTS THE TOPMOST ROW
    printf("%7c", ' ');
    for(int i = 0; i < ROW; i++){

        printf("%-7s", nodes[i]);

    }
    
    printf("\n");

    // PRINTS SUCCEEDING ROWS
    for(int i = 0; i < ROW; i++){

        printf("%-7s", nodes[i]);

        for (int j = 0; j < ROW; j++){

            printf("%-7d", road_networks[i][j]);

        }
        printf("\n");
    }

    //WHILE LOOP FOR INPUT
    int node_location;
    while (1)
    {

        printf("\nWhich point are you located?\n\n");
        printf("\t(0) A\n");
        printf("\t(1) B\n");
        printf("\t(2) C\n");
        printf("\t(3) D\n");
        printf("\t(4) E\n");
        printf("\t(5) F\n");
        printf("\t(6) G\n");
        printf("\t(7) H\n");
        printf("Please input your location: ");

        scanf("%d", &node_location);
        if (node_location < 0 || node_location > ROW-1){

            printf("\nInvalid input!\n");

        }else{

            printf("At point: %s\n", nodes[node_location]);
            break;

        }
    }

    // Find shortest path

    int visited[ROW] = {node_location}; // initialize array of visited nodes with the first element being the starting node
    int motherNodeDistance[ROW] = {0}; // initialize array of distances from the index of the parent node

    int visitedArraySize = 1, visitedQueue = 0, stop = 0;

    while(!stop){ // runs while charging station is not reached
        
        for(int i = 0; i < COLUMN; i++){ // for loop will iterate through the row of current node, checking which nodes it can go to

            int skip = 0;
        
            if (road_networks[node_location][i] == 1){ // checks if current node in iteration can be traveled to

                for (int j = 0; j < visitedArraySize; j++){
                    
                    if (i == visited[j]){ // checks if current node is in visited array

                        skip = 1;  

                    }else if( i == 2 || i == 3){ // checks if we are visiting the charging station

                        stop = 1;   
                    }
                    
                    break;
                }
                if (skip){ // skips current iteration in first for loop

                    continue;
                }
                visited[visitedArraySize] = i; // adds the adjacent nodes to the visited array
                motherNodeDistance[visitedArraySize] = visitedArraySize - visitedQueue; /* visitedArraySize - visitedQueue is 
                                                                                            the distance from the current node's index, 
                                                                                            added to visited array, to its parent node's index*/
                visitedArraySize++;
            }
        }

        visitedQueue++;
        
        if (visitedQueue >= visitedArraySize){ // checks if there are no more unvisited places that are adjacent to latest node

            printf("\nIt's impossible to go to your destination.\n");
            break;

        }
        node_location = visited[visitedQueue];

        if(stop){ // stop is 1 if we have already visited the charging station

            break;

        }
    }

    int index = visitedArraySize-1, arrayIndex = ROW - 1; 
    int path[ROW]={0}; // initialize array for the shortest path

    // adds nodes in shortest path to array
    while (visited[index] != visited[0]){

        path[arrayIndex] = visited[index]; /* latest element in path = latest element in visited array 
                                                so that when the path array is read from left to right, the nodes are in order */
        arrayIndex--;
        index -= motherNodeDistance[index];

    }
    // Printing of points in path
    for (int i = 0; i < ROW; i++){
        if (path[i] != 0){

            printf("Now at point: %s\n", nodes[path[i]]);

        }if (path[i] == 2|| path[i]==3){

            printf("Point: %s arrived to charging station", nodes[path[i]]);
        }
    }
  
    return 0;
}