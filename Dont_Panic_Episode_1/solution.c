#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

char mat[15][200] = {0}; 

int find_elevator(char *f, int size)
{
    int i;
    for (i=0; i<=size-1; i++)
        if (f[i] == 'E' || f[i] == 'F')
            return i;
}
 
int main()
{
    int x;
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    scanf("%d%d%d%d%d%d%d%d", &nbFloors, &width, &nbRounds, &exitFloor, &exitPos, &nbTotalClones, &nbAdditionalElevators, &nbElevators);
    mat[exitFloor][exitPos] = 'F';
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        scanf("%d%d", &elevatorFloor, &elevatorPos);
        mat[elevatorFloor][elevatorPos] = 'E';
    }

    
    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        char direction[11]; // direction of the leading clone: LEFT or RIGHT
        scanf("%d%d%s", &cloneFloor, &clonePos, direction);
        x = find_elevator(mat[cloneFloor], width);
        if ( (x < clonePos && !strcmp(direction, "RIGHT")) ||
             (x > clonePos && !strcmp(direction,"LEFT")))
            printf("BLOCK\n");
        else
            printf("WAIT\n");
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
    }

    return 0;
}
