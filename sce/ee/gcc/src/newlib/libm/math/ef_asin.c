// STATUS: NOT STARTED

#include "ef_asin.h"

static float one = 1.f;
static float huge = 1e+30.f;
static float pio2_hi = 1.57079625f;
static float pio2_lo = 7.54978942e-08f;
static float pio4_hi = 0.785398185f;
static float pS0 = 0.166666672f;
static float pS1 = -0.325565815f;
static float pS2 = 0.201212525f;
static float pS3 = -0.0400555357f;
static float pS4 = 0.000791535f;
static float pS5 = 3.47933092e-05f;
static float qS1 = -2.40339494f;
static float qS2 = 2.02094579f;
static float qS3 = -0.688284f;
static float qS4 = 0.077038154f;

float __ieee754_asinf(float x) {
	float t;
	float w;
	float p;
	float q;
	float c;
	float r;
	float s;
	__int32_t hx;
	__int32_t ix;
	__int32_t iw;
}
