#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppl.h"

const double PI = 3.14159265;
const int n = 3;

void perpl(int x[n][9]) {
	int i, j, j1, r, t1, t2, t3, t4, t5, t6;
	float p, pl, s1, s2, s3, pr;
	int pl1, pr1;

	for (i = 0; i < n; i++) {
		printf("\n%d.\n", i + 1);

		if (x[i][8] == 2) {
			s1 = sqrt(pow((x[i][0] - x[i][2]), 2) +
				  pow((x[i][1] - x[i][3]), 2));
			s2 = sqrt(pow((x[i][2] - x[i][4]), 2) +
				  pow((x[i][3] - x[i][5]), 2));
			s3 = sqrt(pow((x[i][4] - x[i][6]), 2) +
				  pow((x[i][5] - x[i][7]), 2));
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

		if (x[i][8] == 3) {
			printf("There is no such as figure\n");
			continue;
		}

		pr1 = per(x[i]);
		pl1 = plo(x[i]);

		printf("Perimetr - %d\n", pr1);
		printf("Ploshad - %d\n", pl1);
		printf("Peresechenia: \n");

		for (j = 0; j < n; j++) {
			if (i == j) continue;

			if (x[i][8] == 1) {
				if (x[j][8] == 1) {
					r = sqrt(pow((x[i][0] - x[j][0]), 2) +
						 pow((x[i][1] - x[j][1]), 2));
					if (r < (x[i][2] + x[j][2])) {
						printf("%d. Circle\n", j + 1);
						continue;
					}
				}
				if (x[j][8] == 2) {
					t1 = sqrt(pow((x[i][0] - x[j][0]), 2) +
						  pow((x[i][1] - x[j][1]), 2));
					t2 = sqrt(pow((x[i][0] - x[j][2]), 2) +
						  pow((x[i][1] - x[j][3]), 2));
					t3 = sqrt(pow((x[i][0] - x[j][4]), 2) +
						  pow((x[i][1] - x[j][5]), 2));
					if (t1 < x[i][2] or t2 < x[i][2] or
					    t3 < x[i][2]) {
						printf("%d. Triangle\n", j + 1);
						continue;
					}
				}
			}

			if (x[i][8] == 2) {
				if (x[j][8] == 1) {
					t1 = sqrt(pow((x[j][0] - x[i][0]), 2) +
						  pow((x[j][1] - x[i][1]), 2));
					t2 = sqrt(pow((x[j][0] - x[i][2]), 2) +
						  pow((x[j][1] - x[i][3]), 2));
					t3 = sqrt(pow((x[j][0] - x[i][4]), 2) +
						  pow((x[j][1] - x[i][5]), 2));
					if (t1 < x[i][2] or t2 < x[i][2] or
					    t3 < x[i][2]) {
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
						if ((t1 + t4) / 2 <=
						    x[i][j1 + 1] + x[i][j1])
							if ((t1 + t4) / 2 >=
							    x[i][j1 + 2] +
								x[i][j1 + 3]) {
								printf(
								    "%d. "
								    "Triangle"
								    "\n",
								    j + 1);
								j1 = 10;
								continue;
							}

						if ((t2 + t5) / 2 <=
						    x[i][j1 + 1] + x[i][j1])
							if ((t2 + t5) / 2 >=
							    x[i][j1 + 2] +
								x[i][j1 + 3]) {
								printf(
								    "%d. "
								    "Triangle"
								    "\n",
								    j + 1);
								j1 = 10;
								continue;
							}

						if ((t3 + t6) / 2 <=
						    x[i][j1 + 1] + x[i][j1])
							if ((t3 + t6) / 2 >=
							    x[i][j1 + 2] +
								x[i][j1 + 3]) {
								printf(
								    "%d. "
								    "Triangle"
								    "\n",
								    j + 1);
								j1 = 10;
								continue;
							}
					}
				}
			}
		}
	}
}
