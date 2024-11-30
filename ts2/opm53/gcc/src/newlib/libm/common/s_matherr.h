// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBM_COMMON_S_MATHERR_H
#define GCC_SRC_NEWLIB_LIBM_COMMON_S_MATHERR_H

struct exception {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

int matherr(exception *x);

#endif // GCC_SRC_NEWLIB_LIBM_COMMON_S_MATHERR_H
