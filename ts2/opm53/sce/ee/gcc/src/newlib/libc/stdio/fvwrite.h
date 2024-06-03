// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_FVWRITE_H
#define SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_FVWRITE_H

struct __siov {
	void *iov_base;
	size_t iov_len;
};

struct __suio {
	__siov *uio_iov;
	int uio_iovcnt;
	int uio_resid;
};

int __sfvwrite(FILE *fp, __suio *uio);

#endif // SCE_EE_GCC_SRC_NEWLIB_LIBC_STDIO_FVWRITE_H
