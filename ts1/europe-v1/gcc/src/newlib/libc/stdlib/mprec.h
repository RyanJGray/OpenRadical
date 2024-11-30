// STATUS: NOT STARTED

#ifndef GCC_SRC_NEWLIB_LIBC_STDLIB_MPREC_H
#define GCC_SRC_NEWLIB_LIBC_STDLIB_MPREC_H

// warning: multiple differing types with the same name (type name not equal)
typedef __uint32_t ULong;
extern double __mprec_tens[0];
extern double __mprec_bigtens[0];
extern double __mprec_tinytens[0];

_Bigint* _Balloc(_reent *ptr, int k);
void _Bfree(_reent *ptr, _Bigint *v);
_Bigint* _multadd(_reent *ptr, _Bigint *b, int m, int a);
_Bigint* _s2b(_reent *ptr, char *s, int nd0, int nd, ULong y9);
int _hi0bits(ULong x);
int _lo0bits(ULong *y);
_Bigint* _i2b(_reent *ptr, int i);
_Bigint* _multiply(_reent *ptr, _Bigint *a, _Bigint *b);
_Bigint* _pow5mult(_reent *ptr, _Bigint *b, int k);
_Bigint* _lshift(_reent *ptr, _Bigint *b, int k);
int __mcmp(_Bigint *a, _Bigint *b);
_Bigint* __mdiff(_reent *ptr, _Bigint *a, _Bigint *b);
double _ulp(double _x);
double _b2d(_Bigint *a, int *e);
_Bigint* _d2b(_reent *ptr, double _d, int *e, int *bits);
double _ratio(_Bigint *a, _Bigint *b);
double _mprec_log10(int dig);

#endif // GCC_SRC_NEWLIB_LIBC_STDLIB_MPREC_H
