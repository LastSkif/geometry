#include "ppl.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double PI = 3.14159265;
const int N = 50;
const int n = 3;

int main()
{
    int i = 0, p = 0, k = 0, it[n][9], er=0, n1=0;
    char A[] = "circle(", B[] = "triangle(", s1[80], s2[80] = {0}, emp[] = "\0",
         exit[] = "exit";

    while (n1!=n) {
    	printf("%d. ",n1+1);
        scanf("%s", s1);
        if (strcmp(exit, s1) == 0)
            break;
        if (strncmp(A, s1, 7) == 0) {
        	it[n1][8]=1;
        	er=1;
            i = 7;
            p = 0;
            k = 7;
            while (p < 2) {
		if (s1[i] == ')'){
		it[n1][8]=4;
		p=10;
		continue;		
		}
                if (s1[i] == ',') {
                    it[n1][p] = atoi(s2);
                    strcpy(s2, emp);

                    p++;
                    k++;
                } else {
                    strncat(s2, s1 + k, 1);
                    k++;
                }
                i++;
            }
            while (p != 0) {
		if (p == 10){
		p=0;
		continue;		
		}
                if (s1[i] == ')') {
                    it[n1][2] = atof(s2);
                    strcpy(s2, emp);
                    k = 7;
                    p = 0;
                    i = 6;
                } else {
                    strncat(s2, s1 + k, 1);
                    k++;
                }
                i++;
            }
        }

        if (strncmp(B, s1, 9) == 0) {
        	it[n1][8]=2;
			er=1;
            i = 9;
            p = 0;
            k = 9;
            while (p < 7) {
		if (s1[i] == ')'){
			it[n1][8]=4;
			p=10;
			continue;		
		}
                if (s1[i] == ',') {
                    it[n1][p] = atoi(s2);
                    strcpy(s2, emp);
                    p++;
                    k++;
                } else {
                    strncat(s2, s1 + k, 1);
                    k++;
                }
                i++;
            }
            while (p != 0) {
		if (p == 10){
		p=0;
		continue;		
		}
                if (s1[i] == ')') {
                    it[n1][p] = atoi(s2);
                    strcpy(s2, emp);
                    k = 7;
                    p = 0;
                    i = 6;
                } else {
                    strncat(s2, s1 + k, 1);
                    k++;
                }
                i++;
            }
        }
	if(er==0){
        	it[n1][8]=3;
		}
	er=0;
        n1++;
        
    }
	per(it);

    return 0;
}
