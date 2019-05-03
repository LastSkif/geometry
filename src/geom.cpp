#include <cstring>
#include <stdio.h>
#include <stdlib.h>

const float pi=3,14;
int n;

int main()
{
    int i = 0, p = 0, k = 0, fg[2], fh[8];
    double r;
    char A[] = "circle(", B[] = "triangle(", s[80], s1[80] = {0}, emp[] = "\0",
         exit[] = "exit";

    while (1) {
        scanf("%s", s);
        if (strcmp(exit, s) == 0)
            break;
        if (strncmp(A, s, 7) == 0) {
            i = 7;
            p = 0;
            k = 7;
            while (p < 2) {
                if (s[i] == ',') {
                    fg[p] = atoi(s1);
                    strcpy(s1, emp);

                    p++;
                    k++;
                } else {
                    strncat(s1, s + k, 1);
                    k++;
                }
                i++;
            }
            while (p != 0) {
                if (s[i] == ')') {
                    r = atof(s1);
                    strcpy(s1, emp);
                    k = 7;
                    p = 0;
                    i = 6;
                } else {
                    strncat(s1, s + k, 1);
                    k++;
                }
                i++;
            }
            pip(r);
        }

        if (strncmp(B, s, 9) == 0) {
            i = 9;
            p = 0;
            k = 9;
            while (p < 7) {
                if (s[i] == ',') {
                   fh[p] = atoi(s1);
                    strcpy(s1, emp);
                    p++;
                    k++;
                } else {
                    strncat(s1, s + k, 1);
                    k++;
                }
                i++;
            }
            while (p != 0) {
                if (s[i] == ')') {
                    fh[p] = atoi(s1);
                    strcpy(s1, emp);
                    k = 7;
                    p = 0;
                    i = 6;
                } else {
                    strncat(s1, s + k, 1);
                    k++;
                }
                i++;
            }
            pip(fh);
        }
    }
    printf(" %d", fg[0]);

    return 0;
}
