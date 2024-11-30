// STATUS: NOT STARTED

#include "stdio.h"

struct flock {
	short int l_type;
	short int l_whence;
	long int l_start;
	long int l_len;
	short int l_pid;
	short int l_xxx;
};

struct eflock {
	short int l_type;
	short int l_whence;
	long int l_start;
	long int l_len;
	short int l_pid;
	short int l_xxx;
	long int l_rpid;
	long int l_rsys;
};

int __sread(void *cookie, char *buf, int n) {
	int ret;
}

int __swrite(void *cookie, char *buf, int n) {}

fpos_t __sseek(void *cookie, fpos_t offset, int whence) {
	off_t ret;
}

int __sclose(void *cookie) {}
