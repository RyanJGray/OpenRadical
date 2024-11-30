// STATUS: NOT STARTED

#include "e_sqrt.h"

static double one = 1;
static double tiny = 1e-300;

double __ieee754_sqrt(double x) {
	double z;
	__int32_t sign;
	__uint32_t r;
	__uint32_t t1;
	__uint32_t s1;
	__uint32_t ix1;
	__uint32_t q1;
	__int32_t ix0;
	__int32_t s0;
	__int32_t q;
	__int32_t m;
	__int32_t t;
	__int32_t i;
	ieee_double_shape_type ew_u;
	ieee_double_shape_type iw_u;
}
