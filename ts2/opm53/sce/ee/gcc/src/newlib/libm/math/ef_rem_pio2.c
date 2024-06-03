// STATUS: NOT STARTED

#include "ef_rem_pio2.h"

static __int32_t two_over_pi[0] = {
};

static __int32_t npio2_hw[0] = {
};

static float zero = 0.f;
static float half = 0.5f;
static float two8 = 256.f;
static float invpio2 = 0.636619806f;
static float pio2_1 = 1.57078552f;
static float pio2_1t = 1.08043341e-05f;
static float pio2_2 = 1.08042732e-05f;
static float pio2_2t = 6.0771e-11f;
static float pio2_3 = 6.07709438e-11f;
static float pio2_3t = 6.12323426e-17f;

__int32_t __ieee754_rem_pio2f(float x, float *y) {
	float z;
	float w;
	float t;
	float r;
	float fn;
	float tx[3];
	__int32_t i;
	__int32_t j;
	__int32_t n;
	__int32_t ix;
	__int32_t hx;
	int e0;
	int nx;
	__uint32_t high;
}
