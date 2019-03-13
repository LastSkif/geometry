#include <cstring>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[100], b[100], emp[] = "\0";
    int i;
    while (1) {
        scanf("%s", a);

        if (strstr(a, "exit"))
            break;
        if (strstr(a, "circle")) {
            printf("%s\n", a);
            //            for(i = 0; i < 100; i++) {
            //              if (a[i] == '(') {
            //                strncat(b, emp, 2);
            //
            //                  break;
            //            }
            //          b[i] = a[i];
            //    }

        } else
            printf("unknown shape %s \n", a);

        for (i = 0; i < 100; i++) {
            if (a[i] == '(') {
                strncat(b, emp, 2);

                break;
            }
            b[i] = a[i];
        }
        // printf("%s \n", b);
        // strcpy(b, emp);
    }
    return 0;
}
