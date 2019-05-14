#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppl.h"

const double PI = 3.14159265;

int per(int* x) {
	int pr1, r;
	float s1, s2, s3, pr;
	if (x[8] == 1) {
		r = x[2];
		// pl = PI * r * r;
		pr1 = PI * 2 * r;
		pr = pr1;
	}

	if (x[8] == 2) {
		s1 = sqrt(pow((x[0] - x[2]), 2) + pow((x[1] - x[3]), 2));
		s2 = sqrt(pow((x[2] - x[4]), 2) + pow((x[3] - x[5]), 2));
		s3 = sqrt(pow((x[4] - x[6]), 2) + pow((x[5] - x[7]), 2));
		pr = s1 + s2 + s3;
		// p = pr / 2;
		// pl = p * (p - s1) * (p - s2) * (p - s3);}
		pr = int(pr);
	}
	return pr;
}

