// STATUS: NOT STARTED

#include "impure.h"

static _reent impure_data = {
	/* ._errno = */ 0,
	/* ._stdin = */ 0x423984,
	/* ._stdout = */ 0x4239dc,
	/* ._stderr = */ 0x423a34,
	/* ._inc = */ 0,
	/* ._emergency = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 0,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 0,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 0,
		/* [14] = */ 0,
		/* [15] = */ 0,
		/* [16] = */ 0,
		/* [17] = */ 0,
		/* [18] = */ 0,
		/* [19] = */ 0,
		/* [20] = */ 0,
		/* [21] = */ 0,
		/* [22] = */ 0,
		/* [23] = */ 0,
		/* [24] = */ 0
	},
	/* ._current_category = */ 0,
	/* ._current_locale = */ 0x458388,
	/* .__sdidinit = */ 0,
	/* .__cleanup = */ NULL,
	/* ._result = */ NULL,
	/* ._result_k = */ 0,
	/* ._p5s = */ NULL,
	/* ._freelist = */ NULL,
	/* ._cvtlen = */ 0,
	/* ._cvtbuf = */ NULL,
	/* ._new = */ {
		/* ._reent = */ {
			/* ._rand_next = */ 1,
			/* ._strtok_last = */ NULL,
			/* ._asctime_buf = */ {
				/* [0] = */ 0,
				/* [1] = */ 0,
				/* [2] = */ 0,
				/* [3] = */ 0,
				/* [4] = */ 0,
				/* [5] = */ 0,
				/* [6] = */ 0,
				/* [7] = */ 0,
				/* [8] = */ 0,
				/* [9] = */ 0,
				/* [10] = */ 0,
				/* [11] = */ 0,
				/* [12] = */ 0,
				/* [13] = */ 0,
				/* [14] = */ 0,
				/* [15] = */ 0,
				/* [16] = */ 0,
				/* [17] = */ 0,
				/* [18] = */ 0,
				/* [19] = */ 0,
				/* [20] = */ 0,
				/* [21] = */ 0,
				/* [22] = */ 0,
				/* [23] = */ 0,
				/* [24] = */ 0,
				/* [25] = */ 0
			},
			/* ._localtime_buf = */ {
				/* .tm_sec = */ 0,
				/* .tm_min = */ 0,
				/* .tm_hour = */ 0,
				/* .tm_mday = */ 0,
				/* .tm_mon = */ 0,
				/* .tm_year = */ 0,
				/* .tm_wday = */ 0,
				/* .tm_yday = */ 0,
				/* .tm_isdst = */ 0
			},
			/* ._gamma_signgam = */ 0
		},
		/* ._unused = */ {
			/* ._nextf = */ {
				/* [0] = */ 0x1,
				/* [1] = */ NULL,
				/* [2] = */ NULL,
				/* [3] = */ NULL,
				/* [4] = */ NULL,
				/* [5] = */ NULL,
				/* [6] = */ NULL,
				/* [7] = */ NULL,
				/* [8] = */ NULL,
				/* [9] = */ NULL,
				/* [10] = */ NULL,
				/* [11] = */ NULL,
				/* [12] = */ NULL,
				/* [13] = */ NULL,
				/* [14] = */ NULL,
				/* [15] = */ NULL,
				/* [16] = */ NULL,
				/* [17] = */ NULL,
				/* [18] = */ NULL,
				/* [19] = */ NULL,
				/* [20] = */ NULL,
				/* [21] = */ NULL,
				/* [22] = */ NULL,
				/* [23] = */ NULL,
				/* [24] = */ NULL,
				/* [25] = */ NULL,
				/* [26] = */ NULL,
				/* [27] = */ NULL,
				/* [28] = */ NULL,
				/* [29] = */ NULL
			},
			/* ._nmalloc = */ {
				/* [0] = */ 0,
				/* [1] = */ 0,
				/* [2] = */ 0,
				/* [3] = */ 0,
				/* [4] = */ 0,
				/* [5] = */ 0,
				/* [6] = */ 0,
				/* [7] = */ 0,
				/* [8] = */ 0,
				/* [9] = */ 0,
				/* [10] = */ 0,
				/* [11] = */ 0,
				/* [12] = */ 0,
				/* [13] = */ 0,
				/* [14] = */ 0,
				/* [15] = */ 0,
				/* [16] = */ 0,
				/* [17] = */ 0,
				/* [18] = */ 0,
				/* [19] = */ 0,
				/* [20] = */ 0,
				/* [21] = */ 0,
				/* [22] = */ 0,
				/* [23] = */ 0,
				/* [24] = */ 0,
				/* [25] = */ 0,
				/* [26] = */ 0,
				/* [27] = */ 0,
				/* [28] = */ 0,
				/* [29] = */ 0
			}
		}
	},
	/* ._atexit = */ NULL,
	/* ._atexit0 = */ {
		/* ._next = */ NULL,
		/* ._ind = */ 0,
		/* ._fns = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL,
			/* [2] = */ NULL,
			/* [3] = */ NULL,
			/* [4] = */ NULL,
			/* [5] = */ NULL,
			/* [6] = */ NULL,
			/* [7] = */ NULL,
			/* [8] = */ NULL,
			/* [9] = */ NULL,
			/* [10] = */ NULL,
			/* [11] = */ NULL,
			/* [12] = */ NULL,
			/* [13] = */ NULL,
			/* [14] = */ NULL,
			/* [15] = */ NULL,
			/* [16] = */ NULL,
			/* [17] = */ NULL,
			/* [18] = */ NULL,
			/* [19] = */ NULL,
			/* [20] = */ NULL,
			/* [21] = */ NULL,
			/* [22] = */ NULL,
			/* [23] = */ NULL,
			/* [24] = */ NULL,
			/* [25] = */ NULL,
			/* [26] = */ NULL,
			/* [27] = */ NULL,
			/* [28] = */ NULL,
			/* [29] = */ NULL,
			/* [30] = */ NULL,
			/* [31] = */ NULL
		}
	},
	/* ._sig_func = */ NULL,
	/* .__sglue = */ {
		/* ._next = */ NULL,
		/* ._niobs = */ 0,
		/* ._iobs = */ NULL
	},
	/* .__sf = */ {
		/* [0] = */ {
			/* ._p = */ NULL,
			/* ._r = */ 0,
			/* ._w = */ 0,
			/* ._flags = */ 0,
			/* ._file = */ 0,
			/* ._bf = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._lbfsize = */ 0,
			/* ._cookie = */ NULL,
			/* ._read = */ NULL,
			/* ._write = */ NULL,
			/* ._seek = */ NULL,
			/* ._close = */ NULL,
			/* ._ub = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._up = */ NULL,
			/* ._ur = */ 0,
			/* ._ubuf = */ {
				/* [0] = */ 0,
				/* [1] = */ 0,
				/* [2] = */ 0
			},
			/* ._nbuf = */ {
				/* [0] = */ 0
			},
			/* ._lb = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._blksize = */ 0,
			/* ._offset = */ 0,
			/* ._data = */ NULL
		},
		/* [1] = */ {
			/* ._p = */ NULL,
			/* ._r = */ 0,
			/* ._w = */ 0,
			/* ._flags = */ 0,
			/* ._file = */ 0,
			/* ._bf = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._lbfsize = */ 0,
			/* ._cookie = */ NULL,
			/* ._read = */ NULL,
			/* ._write = */ NULL,
			/* ._seek = */ NULL,
			/* ._close = */ NULL,
			/* ._ub = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._up = */ NULL,
			/* ._ur = */ 0,
			/* ._ubuf = */ {
				/* [0] = */ 0,
				/* [1] = */ 0,
				/* [2] = */ 0
			},
			/* ._nbuf = */ {
				/* [0] = */ 0
			},
			/* ._lb = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._blksize = */ 0,
			/* ._offset = */ 0,
			/* ._data = */ NULL
		},
		/* [2] = */ {
			/* ._p = */ NULL,
			/* ._r = */ 0,
			/* ._w = */ 0,
			/* ._flags = */ 0,
			/* ._file = */ 0,
			/* ._bf = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._lbfsize = */ 0,
			/* ._cookie = */ NULL,
			/* ._read = */ NULL,
			/* ._write = */ NULL,
			/* ._seek = */ NULL,
			/* ._close = */ NULL,
			/* ._ub = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._up = */ NULL,
			/* ._ur = */ 0,
			/* ._ubuf = */ {
				/* [0] = */ 0,
				/* [1] = */ 0,
				/* [2] = */ 0
			},
			/* ._nbuf = */ {
				/* [0] = */ 0
			},
			/* ._lb = */ {
				/* ._base = */ NULL,
				/* ._size = */ 0
			},
			/* ._blksize = */ 0,
			/* ._offset = */ 0,
			/* ._data = */ NULL
		}
	}
};

_reent *_impure_ptr = &impure_data;