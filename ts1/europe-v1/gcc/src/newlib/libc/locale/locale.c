// STATUS: NOT STARTED

#include "locale.h"

int __mb_cur_max = 1;

static lconv lconv = {
	/* .decimal_point = */ 0x3c5110,
	/* .thousands_sep = */ 0x3c5108,
	/* .grouping = */ 0x3c5108,
	/* .int_curr_symbol = */ 0x3c5108,
	/* .currency_symbol = */ 0x3c5108,
	/* .mon_decimal_point = */ 0x3c5108,
	/* .mon_thousands_sep = */ 0x3c5108,
	/* .mon_grouping = */ 0x3c5108,
	/* .positive_sign = */ 0x3c5108,
	/* .negative_sign = */ 0x3c5108,
	/* .int_frac_digits = */ 127,
	/* .frac_digits = */ 127,
	/* .p_cs_precedes = */ 127,
	/* .p_sep_by_space = */ 127,
	/* .n_cs_precedes = */ 127,
	/* .n_sep_by_space = */ 127,
	/* .p_sign_posn = */ 127,
	/* .n_sign_posn = */ 127
};

char* _setlocale_r(_reent *p, int category, char *locale) {
	static char lc_ctype[8] = {
		/* [0] = */ 67,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 0,
		/* [6] = */ 0,
		/* [7] = */ 0
	};
	static char last_lc_ctype[8] = {
		/* [0] = */ 67,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 0,
		/* [6] = */ 0,
		/* [7] = */ 0
	};
}

lconv* _localeconv_r(_reent *data) {}

char* setlocale(int category, char *locale) {}

lconv* localeconv() {}
