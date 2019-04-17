#include <cstring>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct cir {
        char a[100];
        int n;
        int k;
    } circle[4];
    emp[] = "\0";
    int i, j = 0;
    while (j < 4) {
        scanf("%s %d %d", circle.a, circle.n, circle.k);

        if (strstr(circle.a, "exit"))
            break;
        if (strstr(circle.a, "circle")) {
            printf("%s\n", a);

        } else
            printf("unknown shape %s \n", a);

        for (i = 0; i < 100; i++) {
            if (a[i] == '(') {
                strncat(b, emp, 2);

                break;
            }
            b[i] = a[i];
        }

        j++;
    }
    return 0;
}
