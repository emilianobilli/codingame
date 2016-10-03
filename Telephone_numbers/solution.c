#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
struct iDroid {
    struct iDroid *n[10];   
};

struct iDroid *new(void)
{
    return calloc(1, sizeof(struct iDroid));
}
 
int main()
{
    int N, n, x=0;
    struct iDroid *base = new();
    struct iDroid *current = NULL;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char telephone[21];
        scanf("%s", telephone);
        
        current = base;         
        for (char *s = &telephone[0]; *s; s++)
        {
            n = *s - '0';
            if (current->n[n])
                current = current->n[n];
            else {
                current->n[n] = new();
                current = current->n[n];
                x++;
            }
        }
        
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    

    // The number of elements (referencing a number) stored in the structure.
    printf("%d\n",x);

    return 0;
}
