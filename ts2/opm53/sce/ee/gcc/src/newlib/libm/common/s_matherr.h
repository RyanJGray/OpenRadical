// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBM_COMMON_S_MATHERR_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBM_COMMON_S_MATHERR_H

struct exception {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

int matherr(exception *x);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBM_COMMON_S_MATHERR_H
