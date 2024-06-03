// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_STDIO_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_STDIO_H

typedef long int _fpos_t;
typedef _fpos_t fpos_t;
int __sread(void *cookie, char *buf, int n);
int __swrite(void *cookie, char *buf, int n);
fpos_t __sseek(void *cookie, fpos_t offset, int whence);
int __sclose(void *cookie);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_STDIO_H
