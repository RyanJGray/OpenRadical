// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_VFPRINTF_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_VFPRINTF_H

typedef char *__gnuc_va_list;
typedef __sFILE FILE;
typedef __gnuc_va_list va_list;
int vfiprintf(FILE *fp, char *fmt0, va_list ap);
int _vfiprintf_r(_reent *data, FILE *fp, char *fmt0, va_list ap);
int vfprintf(FILE *fp, char *fmt0, va_list ap);
int _vfprintf_r(_reent *data, FILE *fp, char *fmt0, va_list ap);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_VFPRINTF_H