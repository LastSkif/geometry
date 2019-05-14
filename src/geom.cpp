#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppl.h"

const double PI = 3.14159265;
const int N = 50;
const int n = 3;

int main() {
	int i = 0, p = 0, k = 0, it[n][9], er = 0, n1 = 0;
	char A[] = "circle(", B[] = "triangle(", s[80], s1[80] = {0},
	     emp[] = "\0", exit[] = "exit";

	while (n1 != n) {
		printf("%d. ", n1 + 1);
		scanf("%s", s);
		if (strcmp(exit, s) == 0) break;
		if (strncmp(A, s, 7) == 0) {
			it[n1][8] = 1;
			er = 1;
			i = 7;
			p = 0;
			k = 7;
			while (p < 2) {
				if (s[i] == ')') {
					it[n1][8] = 4;
					p = 10;
					continue;
				}
				if (s[i] == ',') {
					it[n1][p] = atoi(s1);
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
				if (p == 10) {
					p = 0;
					continue;
				}
				if (s[i] == ')') {
					it[n1][2] = atof(s1);
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
		}

		if (strncmp(B, s, 9) == 0) {
			it[n1][8] = 2;
			er = 1;
			i = 9;
			p = 0;
			k = 9;
			while (p < 7) {
				if (s[i] == ')') {
					it[n1][8] = 4;
					p = 10;
					continue;
				}
				if (s[i] == ',') {
					it[n1][p] = atoi(s1);
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
				if (p == 10) {
					p = 0;
					continue;
				}
				if (s[i] == ')') {
					it[n1][p] = atoi(s1);
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
		}
		if (er == 0) {
			it[n1][8] = 3;
		}
		er = 0;
		n1++;
	}

	perpl(it);

	return 0;
}
