#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi = 3, 14
int main()
{
    struct circle {
        int x;
        int y;
        int r;
    } cir;
    float S;
    int k;
    while (1) {
        scanf("%d %d %d", &cir.x, &cir.y, cir.r);
        S = pi * cir.r;
        printf("%f ", S);
        printf("End?");
        if (kbhit())
            k = getch;
        if (k = 27)
            break;
    }

    return 0;
}
