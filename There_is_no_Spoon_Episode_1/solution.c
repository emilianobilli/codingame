#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
 
int check_horizontal (char **v, int y, int xmin,int xmax)
{
    int i;
    for ( i = xmin; i <= xmax; i ++ )
        if (v[y][i] == '0')
            return i;
    return -1;        
}

int check_vertical(char **v, int x, int ymin,int ymax)
{
    int i;
    for ( i = ymin; i <= ymax; i++)
        if (v[i][x] == '0')
            return i;
    return -1;
}    
 
int main()
{
    char **mat;
    int width; // the number of cells on the X axis
    int rx,ry;
    int bx,by;

    scanf("%d", &width);
    int height; // the number of cells on the Y axis
    scanf("%d", &height); fgetc(stdin);
    
    mat = (char **) calloc(height, sizeof(char **));
    
    for (int i = 0; i < height; i++) {
        mat[i] = calloc(32,sizeof(char));
        fgets(mat[i], 32, stdin); // width characters, each either 0 or .
    }

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++ )
            if (mat[j][i] == '0') 
            {
                rx = check_horizontal(mat,j,i+1,width-1);
                if (rx != -1)
                    ry = j;
                else
                    ry = -1;
                
                by = check_vertical(mat,i, j+1, height-1);
                if (by != -1)
                    bx = i;
                else
                    bx = -1;
                    
                printf ("%d %d %d %d %d %d\n", i, j, rx, ry, bx, by); 
            }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // Three coordinates: a node, its right neighbor, its bottom neighbor
/*    printf("0 0 1 0 0 1\n"); */

    return 0;
}
