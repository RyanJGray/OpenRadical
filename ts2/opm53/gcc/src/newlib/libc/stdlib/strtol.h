// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOL_H
#define GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOL_H

long int _strtol_r(_reent *rptr, char *nptr, char **endptr, int base);
long int strtol(char *s, char **ptr, int base);

#endif // GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOL_H
