// STATUS: NOT STARTED

#include "k_rem_pio2.h"

static int init_jk[0] = {
};

static double PIo2[0] = {
};

static double zero = 0;
static double one = 1;
static double two24 = 16777216;
static double twon24 = 5.9604644775390625e-08;

int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, __int32_t *ipio2) {
	__int32_t jz;
	__int32_t jx;
	__int32_t jv;
	__int32_t jp;
	__int32_t carry;
	__int32_t n;
	__int32_t iq[20];
	__int32_t i;
	__int32_t j;
	__int32_t k;
	__int32_t m;
	__int32_t q0;
	__int32_t ih;
	double z;
	double fw;
	double f[20];
	double fq[20];
	double q[20];
}
