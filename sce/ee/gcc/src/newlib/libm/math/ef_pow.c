// STATUS: NOT STARTED

#include "ef_pow.h"

static float bp[0] = {
};

static float dp_h[0] = {
};

static float dp_l[0] = {
};

static float zero = 0.f;
static float one = 1.f;
static float two = 2.f;
static float two24 = 16777216.f;
static float huge = 1e+30.f;
static float tiny = 1e-30.f;
static float L1 = 0.6f;
static float L2 = 0.428571433f;
static float L3 = 0.333333343f;
static float L4 = 0.272728115f;
static float L5 = 0.230660751f;
static float L6 = 0.206975013f;
static float P1 = 0.166666672f;
static float P2 = -0.00277777785f;
static float P3 = 6.61375598e-05f;
static float P4 = -1.6533902e-06f;
static float P5 = 4.13813694e-08f;
static float lg2 = 0.693147182f;
static float lg2_h = 0.693145752f;
static float lg2_l = 1.42860654e-06f;
static float ovt = 4.29956657e-08f;
static float cp = 0.961796701f;
static float cp_h = 0.961792f;
static float cp_l = 4.70173836e-06f;
static float ivln2 = 1.44269502f;
static float ivln2_h = 1.44268799f;
static float ivln2_l = 7.05260754e-06f;

float __ieee754_powf(float x, float y) {
	float z;
	float ax;
	float z_h;
	float z_l;
	float p_h;
	float p_l;
	float y1;
	float t1;
	float t2;
	float r;
	float s;
	float t;
	float u;
	float v;
	float w;
	__int32_t i;
	__int32_t j;
	__int32_t k;
	__int32_t yisint;
	__int32_t n;
	__int32_t hx;
	__int32_t hy;
	__int32_t ix;
	__int32_t iy;
	__int32_t is;
	float s2;
	float s_h;
	float s_l;
	float t_h;
	float t_l;
}
