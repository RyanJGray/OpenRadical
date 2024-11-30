// STATUS: NOT STARTED

#ifndef GCC_BUILD_GCC_FP_BIT_H
#define GCC_BUILD_GCC_FP_BIT_H

typedef unsigned int USItype;
typedef float SFtype;
typedef short unsigned int UHItype;
FLO_type __pack_f(fp_number_type *src);
void __unpack_f(FLO_union_type *src, fp_number_type *dst);
FLO_type fpadd(FLO_type arg_a, FLO_type arg_b);
FLO_type fpsub(FLO_type arg_a, FLO_type arg_b);
FLO_type fpmul(FLO_type arg_a, FLO_type arg_b);
FLO_type fpdiv(FLO_type arg_a, FLO_type arg_b);
int __fpcmp_parts_f(fp_number_type *a, fp_number_type *b);
SItype fpcmp(FLO_type arg_a, FLO_type arg_b);
FLO_type sitofp(SItype arg_a);
SItype fptosi(FLO_type arg_a);
USItype fptoui(FLO_type arg_a);
FLO_type __negsf2(FLO_type arg_a);
SFtype __make_fp(fp_class_type class, unsigned int sign, int exp, USItype frac);
DFtype fptodp(SFtype arg_a);

#endif // GCC_BUILD_GCC_FP_BIT_H
