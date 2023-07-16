// STATUS: NOT STARTED

#include "k_sin.h"

static double half = 0.5;
static double S1 = -0.16666666666666632;
static double S2 = 0.0083333333333224895;
static double S3 = -0.00019841269829857949;
static double S4 = 2.7557313707070068e-06;
static double S5 = -2.5050760253406863e-08;
static double S6 = 1.5896909952115501e-10;

double __kernel_sin(double x, double y, int iy) {
	double z;
	double r;
	double v;
	__int32_t ix;
	ieee_double_shape_type gh_u;
}
