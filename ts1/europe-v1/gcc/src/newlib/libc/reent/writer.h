// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_REENT_WRITER_H
#define GCC_SRC_NEWLIB_LIBC_REENT_WRITER_H

typedef long int _ssize_t;
_ssize_t _write_r(_reent *ptr, int fd, void *buf, size_t cnt);

#endif // GCC_SRC_NEWLIB_LIBC_REENT_WRITER_H
