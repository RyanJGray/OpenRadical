// STATUS: NOT STARTED

#include "vfprintf.h"

static int __sprint(FILE *fp, __suio *uio) {}

static int __sbprintf(FILE *fp, char *fmt, va_list ap) {
	int ret;
	FILE fake;
	unsigned char buf[1024];
}

int vfiprintf(FILE *fp, char *fmt0, va_list ap) {}

int _vfiprintf_r(_reent *data, FILE *fp, char *fmt0, va_list ap) {
	char *fmt;
	int ch;
	int n;
	int m;
	char *cp;
	__siov *iovp;
	int flags;
	int ret;
	int width;
	int prec;
	char sign;
	wchar_t wc;
	u_long _uquad;
	enum {
		OCT = 0,
		DEC = 1,
		HEX = 2
	} base;
	int dprec;
	int realsz;
	int size;
	char *xdigs;
	__suio uio;
	__siov iov[8];
	char buf[40];
	char ox[2];
	int state;
	static char blanks[16] = {
		/* [0] = */ 32,
		/* [1] = */ 32,
		/* [2] = */ 32,
		/* [3] = */ 32,
		/* [4] = */ 32,
		/* [5] = */ 32,
		/* [6] = */ 32,
		/* [7] = */ 32,
		/* [8] = */ 32,
		/* [9] = */ 32,
		/* [10] = */ 32,
		/* [11] = */ 32,
		/* [12] = */ 32,
		/* [13] = */ 32,
		/* [14] = */ 32,
		/* [15] = */ 32
	};
	static char zeroes[16] = {
		/* [0] = */ 48,
		/* [1] = */ 48,
		/* [2] = */ 48,
		/* [3] = */ 48,
		/* [4] = */ 48,
		/* [5] = */ 48,
		/* [6] = */ 48,
		/* [7] = */ 48,
		/* [8] = */ 48,
		/* [9] = */ 48,
		/* [10] = */ 48,
		/* [11] = */ 48,
		/* [12] = */ 48,
		/* [13] = */ 48,
		/* [14] = */ 48,
		/* [15] = */ 48
	};
	char *p;
}

static int __sprint(FILE *fp, __suio *uio) {}

static int __sbprintf(FILE *fp, char *fmt, va_list ap) {
	int ret;
	FILE fake;
	unsigned char buf[1024];
}

int vfprintf(FILE *fp, char *fmt0, va_list ap) {}

int _vfprintf_r(_reent *data, FILE *fp, char *fmt0, va_list ap) {
	char *fmt;
	int ch;
	int n;
	int m;
	char *cp;
	__siov *iovp;
	int flags;
	int ret;
	int width;
	int prec;
	char sign;
	wchar_t wc;
	char *decimal_point;
	char softsign;
	double _double;
	int expt;
	int expsize;
	int ndig;
	char expstr[7];
	u_long _uquad;
	enum {
		OCT = 0,
		DEC = 1,
		HEX = 2
	} base;
	int dprec;
	int realsz;
	int size;
	char *xdigs;
	__suio uio;
	__siov iov[8];
	char buf[348];
	char ox[2];
	int state;
	static char blanks[16] = {
		/* [0] = */ 32,
		/* [1] = */ 32,
		/* [2] = */ 32,
		/* [3] = */ 32,
		/* [4] = */ 32,
		/* [5] = */ 32,
		/* [6] = */ 32,
		/* [7] = */ 32,
		/* [8] = */ 32,
		/* [9] = */ 32,
		/* [10] = */ 32,
		/* [11] = */ 32,
		/* [12] = */ 32,
		/* [13] = */ 32,
		/* [14] = */ 32,
		/* [15] = */ 32
	};
	static char zeroes[16] = {
		/* [0] = */ 48,
		/* [1] = */ 48,
		/* [2] = */ 48,
		/* [3] = */ 48,
		/* [4] = */ 48,
		/* [5] = */ 48,
		/* [6] = */ 48,
		/* [7] = */ 48,
		/* [8] = */ 48,
		/* [9] = */ 48,
		/* [10] = */ 48,
		/* [11] = */ 48,
		/* [12] = */ 48,
		/* [13] = */ 48,
		/* [14] = */ 48,
		/* [15] = */ 48
	};
	char *p;
}

static char* cvt(_reent *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length) {
	int mode;
	int dsgn;
	char *digits;
	char *bp;
	char *rve;
	double_union tmp;
}

static int exponent(char *p0, int exp, int fmtch) {
	char *p;
	char *t;
	char expbuf[308];
}
