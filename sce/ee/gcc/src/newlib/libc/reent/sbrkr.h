// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_REENT_SBRKR_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_REENT_SBRKR_H

extern int errno;

void* _sbrk_r(_reent *ptr, size_t incr);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_REENT_SBRKR_H
