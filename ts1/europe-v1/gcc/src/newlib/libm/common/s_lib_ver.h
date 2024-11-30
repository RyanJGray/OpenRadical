// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBM_COMMON_S_LIB_VER_H
#define GCC_SRC_NEWLIB_LIBM_COMMON_S_LIB_VER_H

typedef enum {
	__fdlibm_ieee = -1,
	__fdlibm_svid = 0,
	__fdlibm_xopen = 1,
	__fdlibm_posix = 2
} __fdlibm_version;

extern __fdlibm_version __fdlib_version;


#endif // GCC_SRC_NEWLIB_LIBM_COMMON_S_LIB_VER_H
