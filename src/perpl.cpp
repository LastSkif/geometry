#include "ppl.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double PI = 3.14159265;
const int n = 3;

void per(int x[n][9])
{
    int i, j, j1, r, t1, t2, t3, t4, t5, t6;
    float p, pl, s1, s2, s3, pr;

    for (i = 0; i < n; i++) {
        printf("\n%d.\n", i + 1);

        if (x[i][8] == 2) {
            s1 = sqrt(
                    pow((x[i][0] - x[i][2]), 2) + pow((x[i][1] - x[i][3]), 2));
            s2 = sqrt(
                    pow((x[i][2] - x[i][4]), 2) + pow((x[i][3] - x[i][5]), 2));
            s3 = sqrt(
                    pow((x[i][4] - x[i][6]), 2) + pow((x[i][5] - x[i][7]), 2));
            pr = s1 + s2 + s3;
            p = pr / 2;
            pl = p * (p - s1) * (p - s2) * (p - s3);
            if (pr == 0 or pl == 0) {
                printf("Invalid triangle \n");
                continue;
            }
        }

        if (x[i][8] == 4) {
            printf("Invalid input format \n");
            continue;
        }

        if (x[i][8] == 1)
            perpl(x[i][2]);
        if (x[i][8] == 2)
            perpl(x[i]);
        if (x[i][8] == 3) {
            printf("There is no such as figure\n");
            continue;
        }
        printf("peresechenia: \n");

        for (j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (x[i][8] == 1) {
                if (x[j][8] == 1) {
                    r
                            = sqrt(pow((x[i][0] - x[j][0]), 2)
                                   + pow((x[i][1] - x[j][1]), 2));
                    if (r < (x[i][2] + x[j][2])) {
                        printf("%d. Circle\n", j + 1);
                        continue;
                    }
                }
                if (x[j][8] == 2) {
                    t1
                            = sqrt(pow((x[i][0] - x[j][0]), 2)
                                   + pow((x[i][1] - x[j][1]), 2));
                    t2
                            = sqrt(pow((x[i][0] - x[j][2]), 2)
                                   + pow((x[i][1] - x[j][3]), 2));
                    t3
                            = sqrt(pow((x[i][0] - x[j][4]), 2)
                                   + pow((x[i][1] - x[j][5]), 2));
                    if (t1 < x[i][2] or t2 < x[i][2] or t3 < x[i][2]) {
                        printf("%d. Triangle\n", j + 1);
                        continue;
                    }
                }
            }

            if (x[i][8] == 2) {
                if (x[j][8] == 1) {
                    t1
                            = sqrt(pow((x[j][0] - x[i][0]), 2)
                                   + pow((x[j][1] - x[i][1]), 2));
                    t2
                            = sqrt(pow((x[j][0] - x[i][2]), 2)
                                   + pow((x[j][1] - x[i][3]), 2));
                    t3
                            = sqrt(pow((x[j][0] - x[i][4]), 2)
                                   + pow((x[j][1] - x[i][5]), 2));
                    if (t1 < x[i][2] or t2 < x[i][2] or t3 < x[i][2]) {
                        printf("%d. Circle\n", j + 1);
                        continue;
                    }
                }
                if (x[j][8] == 2) {
                    for (j1 = 0; j1 <= 4; j1++) {
                        t1 = x[j][0] + x[j][2];
                        t2 = x[j][4] + x[j][2];
                        t3 = x[j][0] + x[j][4];
                        t4 = x[j][1] + x[j][3];
                        t5 = x[j][3] + x[j][5];
                        t6 = x[j][5] + x[j][1];
                        if ((t1 + t4) / 2 <= x[i][j1 + 1] + x[i][j1])
                            if ((t1 + t4) / 2 >= x[i][j1 + 2] + x[i][j1 + 3]) {
                                printf("%d. Triangle\n", j + 1);
                                j1 = 10;
                                continue;
                            }
                        printf("(%d+%d)/2 = %d - %d\n",
                               t1,
                               t4,
                               x[i][j1 + 1] + x[i][j1],
                               x[i][j1 + 2] + x[i][j1 + 3]);
                        if ((t2 + t5) / 2 <= x[i][j1 + 1] + x[i][j1])
                            if ((t2 + t5) / 2 >= x[i][j1 + 2] + x[i][j1 + 3]) {
                                printf("%d. Triangle\n", j + 1);
                                j1 = 10;
                                continue;
                            }
                        printf("(%d+%d)/2 = %d - %d\n",
                               t1,
                               t4,
                               x[i][j1 + 1] + x[i][j1],
                               x[i][j1 + 2] + x[i][j1 + 3]);
                        if ((t3 + t6) / 2 <= x[i][j1 + 1] + x[i][j1])
                            if ((t3 + t6) / 2 >= x[i][j1 + 2] + x[i][j1 + 3]) {
                                printf("%d. Triangle\n", j + 1);
                                j1 = 10;
                                continue;
                            }
                        printf("(%d+%d)/2 = %d - %d\n",
                               t1,
                               t4,
                               x[i][j1 + 1] + x[i][j1],
                               x[i][j1 + 2] + x[i][j1 + 3]);
                    }
                }
            }
        }
    }
}

void perpl(int r)
{
    int pl, pr;
    pl = PI * r * r;
    pr = PI * 2 * r;
    printf(" ploshad - %d \n perimetr - %d\n", pl, pr);
}

void perpl(int* x)
{
    float p, pl, s1, s2, s3, pr;
    s1 = sqrt(pow((x[0] - x[2]), 2) + pow((x[1] - x[3]), 2));
    s2 = sqrt(pow((x[2] - x[4]), 2) + pow((x[3] - x[5]), 2));
    s3 = sqrt(pow((x[4] - x[6]), 2) + pow((x[5] - x[7]), 2));
    pr = s1 + s2 + s3;
    p = pr / 2;
    pl = p * (p - s1) * (p - s2) * (p - s3);
    printf(" ploshad - %f \n perimetr - %f\n", pl, pr);
}
