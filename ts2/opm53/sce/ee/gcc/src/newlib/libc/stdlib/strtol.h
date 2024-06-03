// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOL_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOL_H

long int _strtol_r(_reent *rptr, char *nptr, char **endptr, int base);
long int strtol(char *s, char **ptr, int base);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOL_H
