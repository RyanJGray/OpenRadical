// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOD_H
#define GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOD_H

double _strtod_r(_reent *ptr, char *s00, char **se);
double strtod(char *s00, char **se);
float strtodf(char *s00, char **se);

#endif // GCC_SRC_NEWLIB_LIBC_STDLIB_STRTOD_H
