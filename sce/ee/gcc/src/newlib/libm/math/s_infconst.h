// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBM_MATH_S_INFCONST_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBM_MATH_S_INFCONST_H

typedef unsigned int __uint32_t;

union __dmath {
	__uint32_t i[2];
	double d;
};

extern __dmath __infinity;


#endif // SCE_EE_GCC_SRC_NEWLIB_LIBM_MATH_S_INFCONST_H
