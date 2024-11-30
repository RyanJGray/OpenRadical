// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_REENT_LSEEKR_H
#define GCC_SRC_NEWLIB_LIBC_REENT_LSEEKR_H

typedef long int _off_t;
typedef long int off_t;
_off_t _lseek_r(_reent *ptr, int fd, off_t pos, int whence);

#endif // GCC_SRC_NEWLIB_LIBC_REENT_LSEEKR_H
