#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE  0
#define FALSE 1
#define MAXSIZE   10000 
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
    unsigned long int X = 0;
    unsigned long int Y = 0;
    unsigned long int T = 0;
    for ( j = Ymin; j <= Ymax; j++ )
        for ( i = Xmin; i <= Xmax; i++ )
            if (mat[j][i] == TRUE)
            {
                X += (unsigned long int)i;
                Y += (unsigned long int)j;
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

struct point alternative_centroid(struct point C, struct point *p, int len,int mat[][MAXSIZE], int Xmax, int Ymax)
{
    struct point nC;
    int x, y;
    x = C.x;
    y = C.y;
    
    if ( x+1 <= Xmax && mat[y][x+1] == TRUE)
    {
        nC.x = x+1;
        nC.y = y;
        if (!check_movement(p,nC,len))
            return nC;
    }
    if ( y+1 <= Ymax && mat[y+1][x] == TRUE)
    {
        nC.x = x;
        nC.y = y+1;
        if (!check_movement(p,nC,len))
            return nC;
    }
    if ( x-1 >= 0 && mat[y][x-1] == TRUE)
    {
        nC.x = x-1;
        nC.y = y;
        if (!check_movement(p,nC,len))
            return nC;
    }
    if ( y-1 >= 0 && mat[y-1][x] == TRUE)
    {
        nC.x = x;
        nC.y = y-1;
        if (!check_movement(p,nC,len))
            return nC;
    }
    if ( x+1 <= Xmax && y-1 >= 0 && mat[y-1][x+1] == TRUE)
    {
        nC.x = x+1;
        nC.y = y-1;
        if (!check_movement(p,nC,len))
            return nC;
    }
    if ( x-1 >= 0 && y+1 <= Ymax && mat[y+1][x-1] == TRUE )
    {
        nC.x = x-1;
        nC.y = y+1;
        if (!check_movement(p,nC,len))
            return nC;
    }
    if ( x+1 <= Xmax && y+1 <= Ymax && mat[y+1][x+1] == TRUE)
    {
        nC.x = x+1;
        nC.y = y+1;
        if (!check_movement(p,nC,len))
            return nC;    
    }    
    if ( x-1 >= 0 && y-1 >=0 && mat[y-1][x-1] == TRUE )
    {
        nC.x = x-1;
        nC.y = y-1;
        if (!check_movement(p,nC,len))
            return nC;
    }
}

int M[MAXSIZE][MAXSIZE] = {{0}};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    struct point mov[MOVEMENTS];
    int Xmin;
    int Ymin;
    int Xmax;
    int Ymax;
    int i,j, k;
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
        if ((Xmax+1-Xmin) * (Ymax+1-Ymin) <= (1000*1000))
        {
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
            p1 = alternative_centroid(p1,mov,nmov,M,Xmax,Ymax);
        add_movement(mov,p1, nmov++, MOVEMENTS);
        }
        else
        {
            if (!strcmp(bombDir, "WARMER"))
            {
                if (p1.x > p0.x)
                    Xmin = p0.x + ( p1.x - p0.x );
                else if (p1.x < p0.x)
                    Xmax = p0.x - ( p0.x - p1.x );
                if (p1.y > p0.y)
                    Ymin = p0.y + (p1.y - p0.y);
                else if (p1.y < p0.y)
                    Ymax = p0.y - ( p0.y - p1.y );
            }
            if (!strcmp(bombDir, "COLDER"))
            {
                if (p1.x > p0.x)
                    Xmax = p0.x - ( p0.x - p1.x );
                else if (p1.x < p0.x)
                    Xmin = p0.x + ( p1.x - p0.x );

                if (p1.y > p0.y)
                    Ymax = p0.y - ( p0.y - p1.y );
                else if (p1.y < p0.y)
                    Ymin = p0.y + (p1.y - p0.y);
            }
            p0.x = p1.x;
            p0.y = p1.y;
            p1.x = (Xmax-Xmin)/2;
            p1.y = (Ymax-Ymin)/2;
            add_movement(mov,p1,nmov++, MOVEMENTS);
            fprintf(stderr,"%d,%d,%d,%d", Xmin,Xmax,Ymin,Ymax);
        }
        printf("%d %d\n", p1.x,p1.y);
    }

    return 0;
}
