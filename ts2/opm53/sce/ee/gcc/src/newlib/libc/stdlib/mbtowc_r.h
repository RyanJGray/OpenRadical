// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_MBTOWC_R_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_MBTOWC_R_H

typedef int wchar_t;
int _mbtowc_r(_reent *r, wchar_t *pwc, char *s, size_t n, int *state);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_MBTOWC_R_H
