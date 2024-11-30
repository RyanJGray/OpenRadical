// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_REENT_SBRKR_H
#define GCC_SRC_NEWLIB_LIBC_REENT_SBRKR_H

extern int errno;

void* _sbrk_r(_reent *ptr, size_t incr);

#endif // GCC_SRC_NEWLIB_LIBC_REENT_SBRKR_H
