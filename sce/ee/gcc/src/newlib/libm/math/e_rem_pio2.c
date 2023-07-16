// STATUS: NOT STARTED

#include "e_rem_pio2.h"

static __int32_t two_over_pi[0] = {
};

static __int32_t npio2_hw[0] = {
};

static double zero = 0;
static double half = 0.5;
static double two24 = 16777216;
static double invpio2 = 0.63661977236758138;
static double pio2_1 = 1.5707963267341256;
static double pio2_1t = 6.0771005065061922e-11;
static double pio2_2 = 6.077100506303966e-11;
static double pio2_2t = 2.0222662487959506e-21;
static double pio2_3 = 2.0222662487111665e-21;
static double pio2_3t = 8.4784276603688996e-32;

__int32_t __ieee754_rem_pio2(double x, double *y) {
	double z;
	double w;
	double t;
	double r;
	double fn;
	double tx[3];
	__int32_t i;
	__int32_t j;
	__int32_t n;
	__int32_t ix;
	__int32_t hx;
	int e0;
	int nx;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type gl_u;
	ieee_double_shape_type sl_u;
	ieee_double_shape_type sh_u;
}
