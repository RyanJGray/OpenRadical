// STATUS: NOT STARTED

#include "ef_atan2.h"

static float tiny = 1e-30.f;
static float zero = 0.f;
static float pi_o_4 = 0.785398185f;
static float pi_o_2 = 1.57079637f;
static float pi = 3.1415925f;
static float pi_lo = 1.50995788e-07f;

float __ieee754_atan2f(float y, float x) {
	float z;
	__int32_t k;
	__int32_t m;
	__int32_t hx;
	__int32_t hy;
	__int32_t ix;
	__int32_t iy;
	__uint32_t zh;
}
