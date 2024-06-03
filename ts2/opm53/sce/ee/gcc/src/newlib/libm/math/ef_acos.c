// STATUS: NOT STARTED

#include "ef_acos.h"

static float one = 1.f;
static float pi = 3.1415925f;
static float pio2_hi = 1.57079625f;
static float pio2_lo = 7.54978942e-08f;
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

float __ieee754_acosf(float x) {
	float z;
	float p;
	float q;
	float r;
	float w;
	float s;
	float c;
	float df;
	__int32_t hx;
	__int32_t ix;
	__int32_t idf;
}
