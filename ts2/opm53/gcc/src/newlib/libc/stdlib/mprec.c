// STATUS: NOT STARTED

#include "mprec.h"

double __mprec_tens[0] = {
};

double __mprec_bigtens[0] = {
};

double __mprec_tinytens[0] = {
};

_Bigint* _Balloc(_reent *ptr, int k) {
	int x;
	_Bigint *rv;
}

void _Bfree(_reent *ptr, _Bigint *v) {}

_Bigint* _multadd(_reent *ptr, _Bigint *b, int m, int a) {
	int i;
	int wds;
	ULong *x;
	ULong y;
	ULong xi;
	ULong z;
	_Bigint *b1;
}

_Bigint* _s2b(_reent *ptr, char *s, int nd0, int nd, ULong y9) {
	_Bigint *b;
	int i;
	int k;
	__int32_t y;
}

int _hi0bits(ULong x) {
	int k;
}

int _lo0bits(ULong *y) {
	int k;
	ULong x;
}

_Bigint* _i2b(_reent *ptr, int i) {
	_Bigint *b;
}

_Bigint* _multiply(_reent *ptr, _Bigint *a, _Bigint *b) {
	_Bigint *c;
	int k;
	int wc;
	ULong carry;
	ULong y;
	ULong z;
	ULong *x;
	ULong *xa;
	ULong *xae;
	ULong *xb;
	ULong *xbe;
	ULong *xc;
	ULong *xc0;
	ULong z2;
}

_Bigint* _pow5mult(_reent *ptr, _Bigint *b, int k) {
	_Bigint *b1;
	_Bigint *p5;
	_Bigint *p51;
	int i;
	static int p05[3] = {
		/* [0] = */ 5,
		/* [1] = */ 25,
		/* [2] = */ 125
	};
}

_Bigint* _lshift(_reent *ptr, _Bigint *b, int k) {
	int i;
	int k1;
	int n;
	int n1;
	_Bigint *b1;
	ULong *x;
	ULong *x1;
	ULong *xe;
	ULong z;
}

int __mcmp(_Bigint *a, _Bigint *b) {
	ULong *xa;
	ULong *xa0;
	ULong *xb;
	ULong *xb0;
	int i;
	int j;
}

_Bigint* __mdiff(_reent *ptr, _Bigint *a, _Bigint *b) {
	_Bigint *c;
	int i;
	int wa;
	int wb;
	__int32_t borrow;
	__int32_t y;
	ULong *xa;
	ULong *xae;
	ULong *xb;
	ULong *xbe;
	ULong *xc;
	__int32_t z;
}

double _ulp(double _x) {
	double_union a;
	__int32_t L;
}

double _b2d(_Bigint *a, int *e) {
	ULong *xa;
	ULong *xa0;
	ULong w;
	ULong y;
	ULong z;
	int k;
	double_union d;
}

_Bigint* _d2b(_reent *ptr, double _d, int *e, int *bits) {
	double_union d;
	_Bigint *b;
	int de;
	int i;
	int k;
	ULong *x;
	ULong y;
	ULong z;
}

double _ratio(_Bigint *a, _Bigint *b) {
	double_union da;
	double_union db;
	int k;
	int ka;
	int kb;
}

double _mprec_log10(int dig) {
	double v;
}
