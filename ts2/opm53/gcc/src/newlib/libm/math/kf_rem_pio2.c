// STATUS: NOT STARTED

#include "kf_rem_pio2.h"

static int init_jk[0] = {
};

static float PIo2[0] = {
};

static float zero = 0.f;
static float one = 1.f;
static float two8 = 256.f;
static float twon8 = 0.00390625f;

int __kernel_rem_pio2f(float *x, float *y, int e0, int nx, int prec, __int32_t *ipio2) {
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
	float z;
	float fw;
	float f[20];
	float fq[20];
	float q[20];
}
