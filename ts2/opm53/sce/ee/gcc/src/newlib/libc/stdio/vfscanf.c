// STATUS: NOT STARTED

#include "vfscanf.h"

int __svfscanf(FILE *fp, char *fmt0, va_list ap) {
	char *fmt;
	int c;
	size_t width;
	char *p;
	int n;
	int flags;
	char *p0;
	int nassigned;
	int nread;
	int base;
	wchar_t wc;
	long unsigned int (*ccfn)(/* parameters unknown */);
	char ccltab[256];
	char buf[350];
	char *lptr;
	short int *sp;
	int *ip;
	float *flp;
	long double *ldp;
	double *dp;
	long int *lp;
	static short int basefix[17] = {
		/* [0] = */ 10,
		/* [1] = */ 1,
		/* [2] = */ 2,
		/* [3] = */ 3,
		/* [4] = */ 4,
		/* [5] = */ 5,
		/* [6] = */ 6,
		/* [7] = */ 7,
		/* [8] = */ 8,
		/* [9] = */ 9,
		/* [10] = */ 10,
		/* [11] = */ 11,
		/* [12] = */ 12,
		/* [13] = */ 13,
		/* [14] = */ 14,
		/* [15] = */ 15,
		/* [16] = */ 16
	};
	size_t sum;
	size_t r;
	long unsigned int res;
	double res;
}

char* __sccl(char *tab, char *fmt) {
	int c;
	int n;
	int v;
}
