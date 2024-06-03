// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOD_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOD_H

double _strtod_r(_reent *ptr, char *s00, char **se);
double strtod(char *s00, char **se);
float strtodf(char *s00, char **se);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOD_H
