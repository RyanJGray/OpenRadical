// STATUS: NOT STARTED

#include "k_cos.h"

static double one = 1;
static double C1 = 0.041666666666666602;
static double C2 = -0.001388888888887411;
static double C3 = 2.4801587289476729e-05;
static double C4 = -2.7557314351390663e-07;
static double C5 = 2.0875723212981748e-09;
static double C6 = -1.1359647557788195e-11;

double __kernel_cos(double x, double y) {
	double z;
	double r;
	double qx;
	__int32_t ix;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type iw_u;
}
