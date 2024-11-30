// STATUS: NOT STARTED

#include "s_scalbn.h"

static double two54 = 18014398509481984;
static double twom54 = 5.5511151231257827e-17;
static double huge = 1.0000000000000001e+300;
static double tiny = 1e-300;

double scalbn(double x, int n) {
	__int32_t k;
	__int32_t hx;
	ieee_double_shape_type ew_u;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type sh_u;
	ieee_double_shape_type sh_u;
}
