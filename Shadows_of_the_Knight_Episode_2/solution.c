#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE  0
#define FALSE 1
#define MAXSIZE   1000
#define MOVEMENTS  100

struct point {
    int x;
    int y;
};


double distance(struct point p0, struct point p1)
{
    return sqrt( ((p0.x - p1.x)*(p0.x - p1.x)) + ((p0.y - p1.y)*(p0.y-p1.y)) ); 
}

struct point centroid(int mat[][MAXSIZE], int Xmin, int Xmax, int Ymin, int Ymax)
{
    int i,j;
    struct point p;
    int X = 0;
    int Y = 0;
    int T = 0;
    for ( j = Ymin; j <= Ymax; j++ )
        for ( i = Xmin; i <= Xmax; i++ )
            if (mat[j][i] == TRUE)
            {
                X += i;
                Y += j;
                T++;
            }
    p.x = (int)(round(X / (double)T));
    p.y = (int)(round(Y / (double)T));
    return p;
}

void init_movements(struct point *p, int len)
{
    int i;
    for ( i = 0; i <= len-1; i++ )
        p[i].x = 0;
        p[i].y = 0;
}

void add_movement(struct point *p, struct point p0, int i, int len)
{
    if ( i >= len )
        return;
    p[i].x = p0.x;
    p[i].y = p0.y;
}

int check_movement(struct point *p, struct point p0, int len)
{
    int i;
    for (i=0; i <= len-1; i++)
        if (p[i].x == p0.x && p[i].y == p0.y)
            return 1;
    return 0;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    struct point mov[MOVEMENTS];
    int M[MAXSIZE][MAXSIZE] = {0};
    int Xmin;
    int Ymin;
    int Xmax;
    int Ymax;
    int i,j;
    struct point p0;
    struct point p1;
    struct point tmp;
    
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    int nmov = 0;
    scanf("%d%d", &X0, &Y0);

    init_movements(mov, MOVEMENTS);

    Xmin = 0;
    Ymin = 0;
    Xmax = W-1;
    Ymax = H-1;

    p0.x = X0;
    p0.y = Y0;
    p1.x = X0;
    p1.y = Y0;
    // game loop
    add_movement(mov,p0, nmov++, MOVEMENTS);
    
    while (1) {
        char bombDir[11]; // Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
        scanf("%s", bombDir);
        if (!strcmp(bombDir,"WARMER"))
        {
            for ( j = Ymin; j <= Ymax; j++ )
                for ( i = Xmin; i <= Xmax; i++ )
                {
                    tmp.x = i;
                    tmp.y = j;
                    if ( (M[j][i] == TRUE) && distance(p1,tmp) >= distance(p0,tmp) )
                        M[j][i] = FALSE;
                }
        }
        else if (!strcmp(bombDir,"COLDER"))
        {
            for ( j = Ymin; j <= Ymax; j++ )
                for ( i = Xmin; i <= Xmax; i++ )
                {
                    tmp.x = i;
                    tmp.y = j;
                    if ( (M[j][i] == TRUE) && distance(p1,tmp) <= distance(p0,tmp) )
                        M[j][i] = FALSE;
                }
        }
        else if (!strcmp(bombDir,"SAME"))
        {
            for ( j = Ymin; j <= Ymax; j++ )
                for ( i = Xmin; i <= Xmax; i++ )
                {
                    tmp.x = i;
                    tmp.y = j;
                    if ( (M[j][i] == TRUE) && distance(p1,tmp) != distance(p0,tmp) )
                        M[j][i] = FALSE;    
                }
                
        }
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        p0.x = p1.x;
        p0.y = p1.y;
        p1 =  centroid(M,Xmin,Xmax,Ymin,Ymax);
        if (check_movement(mov,p1,nmov))
            fprintf(stderr,"Pu--to");
        add_movement(mov,p1, nmov++, MOVEMENTS);    
        printf("%d %d\n", p1.x,p1.y);
    }

    return 0;
}
