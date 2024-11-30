// STATUS: NOT STARTED

#include "e_atan2.h"

static double tiny = 1e-300;
static double zero = 0;
static double pi_o_4 = 0.78539816339744828;
static double pi_o_2 = 1.5707963267948966;
static double pi = 3.1415926535897931;
static double pi_lo = 1.2246467991473532e-16;

double __ieee754_atan2(double y, double x) {
	double z;
	__int32_t k;
	__int32_t m;
	__int32_t hx;
	__int32_t hy;
	__int32_t ix;
	__int32_t iy;
	ieee_double_shape_type ew_u;
	ieee_double_shape_type ew_u;
	__uint32_t zh;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type sh_u;
}
