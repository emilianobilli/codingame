#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int max;
    int min;
    int value;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        fprintf(stderr,"%d\n", v);
        if ( i == 0 ) 
        {
            max = v;
            min = v;
            value = 0;
        }
        else {
            if ( v < min ) 
            {
                min = v;
                if ( min-max < value )
                    value = min-max;
            }
            if ( v > max )
            {
                max = v;
                min = v;
            }
        }
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n",value);

    return 0;
}
