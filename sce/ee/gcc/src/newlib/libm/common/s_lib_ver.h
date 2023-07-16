// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBM_COMMON_S_LIB_VER_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBM_COMMON_S_LIB_VER_H

enum __fdlibm_version {
	__fdlibm_ieee = -1,
	__fdlibm_svid = 0,
	__fdlibm_xopen = 1,
	__fdlibm_posix = 2
};

extern __fdlibm_version __fdlib_version;


#endif // SCE_EE_GCC_SRC_NEWLIB_LIBM_COMMON_S_LIB_VER_H
