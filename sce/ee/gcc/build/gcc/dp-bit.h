// STATUS: NOT STARTED

#ifndef SCE_EE_GCC_BUILD_GCC_DP_BIT_H
#define SCE_EE_GCC_BUILD_GCC_DP_BIT_H

typedef int SItype;
typedef double DFtype;

typedef enum {
	CLASS_SNAN = 0,
	CLASS_QNAN = 1,
	CLASS_ZERO = 2,
	CLASS_NUMBER = 3,
	CLASS_INFINITY = 4
} fp_class_type;

FLO_type __pack_d(fp_number_type *src);
void __unpack_d(FLO_union_type *src, fp_number_type *dst);
FLO_type dpadd(FLO_type arg_a, FLO_type arg_b);
FLO_type dpsub(FLO_type arg_a, FLO_type arg_b);
FLO_type dpmul(FLO_type arg_a, FLO_type arg_b);
FLO_type dpdiv(FLO_type arg_a, FLO_type arg_b);
int __fpcmp_parts_d(fp_number_type *a, fp_number_type *b);
SItype dpcmp(FLO_type arg_a, FLO_type arg_b);
FLO_type litodp(SItype arg_a);
SItype dptoli(FLO_type arg_a);
USItype dptoul(FLO_type arg_a);
FLO_type __negdf2(FLO_type arg_a);
DFtype __make_dp(fp_class_type class, unsigned int sign, int exp, UDItype frac);
SFtype dptofp(DFtype arg_a);

#endif // SCE_EE_GCC_BUILD_GCC_DP_BIT_H
