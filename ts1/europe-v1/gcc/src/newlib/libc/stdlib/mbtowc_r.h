// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_STDLIB_MBTOWC_R_H
#define GCC_SRC_NEWLIB_LIBC_STDLIB_MBTOWC_R_H

typedef int wchar_t;
int _mbtowc_r(_reent *r, wchar_t *pwc, char *s, size_t n, int *state);

#endif // GCC_SRC_NEWLIB_LIBC_STDLIB_MBTOWC_R_H
