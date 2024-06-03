// STATUS: NOT STARTED

#include "dp-bit.h"

// warning: multiple differing types with the same name (#266, type name not equal)
typedef UDItype fractype;
// warning: multiple differing types with the same name (#266, type name not equal)
typedef USItype halffractype;
// warning: multiple differing types with the same name (#266, type name not equal)
typedef DFtype FLO_type;
// warning: multiple differing types with the same name (#266, type name not equal)
typedef DItype intfrac;

// warning: multiple differing types with the same name (#266, size not equal)
typedef struct {
	fp_class_type class;
	unsigned int sign;
	int normal_exp;
	union {
		fractype ll;
		halffractype l[2];
	} fraction;
} fp_number_type;

// warning: multiple differing types with the same name (#266, size not equal)
typedef union {
	FLO_type value;
	fractype value_raw;
	halffractype words[2];
	struct {
		fractype fraction;
		unsigned int exp : 11;
		unsigned int sign : 1;
	} bits;
} FLO_union_type;

FLO_type __pack_d(fp_number_type *src) {}

void __unpack_d(FLO_union_type *src, fp_number_type *dst) {}

static fp_number_type* _fpadd_parts(fp_number_type *a, fp_number_type *b, fp_number_type *tmp) {}

FLO_type dpadd(FLO_type arg_a, FLO_type arg_b) {}

FLO_type dpsub(FLO_type arg_a, FLO_type arg_b) {}

FLO_type dpmul(FLO_type arg_a, FLO_type arg_b) {}

FLO_type dpdiv(FLO_type arg_a, FLO_type arg_b) {}

int __fpcmp_parts_d(fp_number_type *a, fp_number_type *b) {}

SItype dpcmp(FLO_type arg_a, FLO_type arg_b) {}

FLO_type litodp(SItype arg_a) {}

SItype dptoli(FLO_type arg_a) {}

USItype dptoul(FLO_type arg_a) {}

FLO_type __negdf2(FLO_type arg_a) {}

DFtype __make_dp(fp_class_type class, unsigned int sign, int exp, UDItype frac) {}

SFtype dptofp(DFtype arg_a) {}
