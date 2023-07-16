// STATUS: NOT STARTED

#include "e_pow.h"

static double bp[0] = {
};

static double dp_h[0] = {
};

static double dp_l[0] = {
};

static double zero = 0;
static double one = 1;
static double two = 2;
static double two53 = 9007199254740992;
static double huge = 1.0000000000000001e+300;
static double tiny = 1e-300;
static double L1 = 0.59999999999999465;
static double L2 = 0.42857142857855018;
static double L3 = 0.33333332981837743;
static double L4 = 0.27272812380853401;
static double L5 = 0.23066074577556175;
static double L6 = 0.20697501780033842;
static double P1 = 0.16666666666666602;
static double P2 = -0.0027777777777015593;
static double P3 = 6.6137563214379344e-05;
static double P4 = -1.6533902205465252e-06;
static double P5 = 4.1381367970572385e-08;
static double lg2 = 0.69314718055994529;
static double lg2_h = 0.69314718246459961;
static double lg2_l = -1.904654299957768e-09;
static double ovt = 8.0085662595372941e-17;
static double cp = 0.96179669392597555;
static double cp_h = 0.96179670095443726;
static double cp_l = -7.0284616509527583e-09;
static double ivln2 = 1.4426950408889634;
static double ivln2_h = 1.4426950216293335;
static double ivln2_l = 1.9259629911266175e-08;

double __ieee754_pow(double x, double y) {
	double z;
	double ax;
	double z_h;
	double z_l;
	double p_h;
	double p_l;
	double y1;
	double t1;
	double t2;
	double r;
	double s;
	double t;
	double u;
	double v;
	double w;
	__int32_t i;
	__int32_t j;
	__int32_t k;
	__int32_t yisint;
	__int32_t n;
	__int32_t hx;
	__int32_t hy;
	__int32_t ix;
	__int32_t iy;
	ieee_double_shape_type ew_u;
	ieee_double_shape_type ew_u;
	double s2;
	double s_h;
	double s_l;
	double t_h;
	double t_l;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type sh_u;
	ieee_double_shape_type sl_u;
	ieee_double_shape_type sl_u;
	ieee_double_shape_type ew_u;
	ieee_double_shape_type gh_u;
	ieee_double_shape_type sh_u;
}
