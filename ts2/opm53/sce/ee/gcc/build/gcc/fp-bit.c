// STATUS: NOT STARTED

#include "fp-bit.h"

// warning: multiple differing types with the same name (#267, type name not equal)
typedef USItype fractype;
// warning: multiple differing types with the same name (#267, type name not equal)
typedef UHItype halffractype;
// warning: multiple differing types with the same name (#267, type name not equal)
typedef SFtype FLO_type;
// warning: multiple differing types with the same name (#267, type name not equal)
typedef SItype intfrac;

// warning: multiple differing types with the same name (#267, size not equal)
typedef struct {
	fp_class_type class;
	unsigned int sign;
	int normal_exp;
	union {
		fractype ll;
		halffractype l[2];
	} fraction;
} fp_number_type;

// warning: multiple differing types with the same name (#267, size not equal)
typedef union {
	FLO_type value;
	fractype value_raw;
	struct {
		fractype fraction;
		unsigned int exp : 8;
		unsigned int sign : 1;
	} bits;
} FLO_union_type;

FLO_type __pack_f(fp_number_type *src) {}

void __unpack_f(FLO_union_type *src, fp_number_type *dst) {}

static fp_number_type* _fpadd_parts(fp_number_type *a, fp_number_type *b, fp_number_type *tmp) {}

FLO_type fpadd(FLO_type arg_a, FLO_type arg_b) {}

FLO_type fpsub(FLO_type arg_a, FLO_type arg_b) {}

FLO_type fpmul(FLO_type arg_a, FLO_type arg_b) {}

FLO_type fpdiv(FLO_type arg_a, FLO_type arg_b) {}

int __fpcmp_parts_f(fp_number_type *a, fp_number_type *b) {}

SItype fpcmp(FLO_type arg_a, FLO_type arg_b) {}

FLO_type sitofp(SItype arg_a) {}

SItype fptosi(FLO_type arg_a) {}

USItype fptoui(FLO_type arg_a) {}

FLO_type __negsf2(FLO_type arg_a) {}

SFtype __make_fp(fp_class_type class, unsigned int sign, int exp, USItype frac) {}

DFtype fptodp(SFtype arg_a) {}
