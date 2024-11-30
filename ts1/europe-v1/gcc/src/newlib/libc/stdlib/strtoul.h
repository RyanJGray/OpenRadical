// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOUL_H
#define GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOUL_H

long unsigned int _strtoul_r(_reent *rptr, char *nptr, char **endptr, int base);
long unsigned int strtoul(char *s, char **ptr, int base);

#endif // GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOUL_H
