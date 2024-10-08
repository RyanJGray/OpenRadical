// STATUS: NOT STARTED

#include "em.h"

u32 vifdata_notexture[0] = {
};

texbuffer *thistexbuf = texbuf;

texsize_t tsizes[31] = {
	/* [0] = */ {
		/* .width = */ 16,
		/* .height = */ 16,
		/* .mask = */ 0,
		/* .numfit = */ 32,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 2,
			/* [3] = */ 3,
			/* [4] = */ 4,
			/* [5] = */ 5,
			/* [6] = */ 6,
			/* [7] = */ 7,
			/* [8] = */ 8,
			/* [9] = */ 9,
			/* [10] = */ 10,
			/* [11] = */ 11,
			/* [12] = */ 12,
			/* [13] = */ 13,
			/* [14] = */ 14,
			/* [15] = */ 15,
			/* [16] = */ 16,
			/* [17] = */ 17,
			/* [18] = */ 18,
			/* [19] = */ 19,
			/* [20] = */ 20,
			/* [21] = */ 21,
			/* [22] = */ 22,
			/* [23] = */ 23,
			/* [24] = */ 24,
			/* [25] = */ 25,
			/* [26] = */ 26,
			/* [27] = */ 27,
			/* [28] = */ 28,
			/* [29] = */ 29,
			/* [30] = */ 30,
			/* [31] = */ 31
		},
		/* .extents = */ 1
	},
	/* [1] = */ {
		/* .width = */ 16,
		/* .height = */ 32,
		/* .mask = */ 0,
		/* .numfit = */ 16,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 4,
			/* [3] = */ 5,
			/* [4] = */ 8,
			/* [5] = */ 9,
			/* [6] = */ 12,
			/* [7] = */ 13,
			/* [8] = */ 16,
			/* [9] = */ 17,
			/* [10] = */ 20,
			/* [11] = */ 21,
			/* [12] = */ 24,
			/* [13] = */ 25,
			/* [14] = */ 28,
			/* [15] = */ 29,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [2] = */ {
		/* .width = */ 16,
		/* .height = */ 64,
		/* .mask = */ 0,
		/* .numfit = */ 8,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 4,
			/* [3] = */ 5,
			/* [4] = */ 16,
			/* [5] = */ 17,
			/* [6] = */ 20,
			/* [7] = */ 21,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [3] = */ {
		/* .width = */ 16,
		/* .height = */ 128,
		/* .mask = */ 0,
		/* .numfit = */ 8,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 1,
			/* [2] = */ 4,
			/* [3] = */ 5,
			/* [4] = */ 16,
			/* [5] = */ 17,
			/* [6] = */ 20,
			/* [7] = */ 21,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 2
	},
	/* [4] = */ {
		/* .width = */ 32,
		/* .height = */ 16,
		/* .mask = */ 0,
		/* .numfit = */ 16,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 2,
			/* [2] = */ 4,
			/* [3] = */ 6,
			/* [4] = */ 8,
			/* [5] = */ 10,
			/* [6] = */ 12,
			/* [7] = */ 14,
			/* [8] = */ 16,
			/* [9] = */ 18,
			/* [10] = */ 20,
			/* [11] = */ 22,
			/* [12] = */ 24,
			/* [13] = */ 26,
			/* [14] = */ 28,
			/* [15] = */ 30,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [5] = */ {
		/* .width = */ 32,
		/* .height = */ 32,
		/* .mask = */ 0,
		/* .numfit = */ 8,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 4,
			/* [2] = */ 8,
			/* [3] = */ 12,
			/* [4] = */ 16,
			/* [5] = */ 20,
			/* [6] = */ 24,
			/* [7] = */ 28,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [6] = */ {
		/* .width = */ 32,
		/* .height = */ 64,
		/* .mask = */ 0,
		/* .numfit = */ 4,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 4,
			/* [2] = */ 16,
			/* [3] = */ 20,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [7] = */ {
		/* .width = */ 32,
		/* .height = */ 128,
		/* .mask = */ 0,
		/* .numfit = */ 4,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 4,
			/* [2] = */ 16,
			/* [3] = */ 20,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 2
	},
	/* [8] = */ {
		/* .width = */ 32,
		/* .height = */ 256,
		/* .mask = */ 0,
		/* .numfit = */ 4,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 4,
			/* [2] = */ 16,
			/* [3] = */ 20,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 4
	},
	/* [9] = */ {
		/* .width = */ 64,
		/* .height = */ 16,
		/* .mask = */ 0,
		/* .numfit = */ 8,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 2,
			/* [2] = */ 8,
			/* [3] = */ 10,
			/* [4] = */ 16,
			/* [5] = */ 18,
			/* [6] = */ 24,
			/* [7] = */ 26,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [10] = */ {
		/* .width = */ 64,
		/* .height = */ 32,
		/* .mask = */ 0,
		/* .numfit = */ 4,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 8,
			/* [2] = */ 16,
			/* [3] = */ 24,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [11] = */ {
		/* .width = */ 64,
		/* .height = */ 64,
		/* .mask = */ 0,
		/* .numfit = */ 2,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 16,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [12] = */ {
		/* .width = */ 64,
		/* .height = */ 128,
		/* .mask = */ 0,
		/* .numfit = */ 2,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 16,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 2
	},
	/* [13] = */ {
		/* .width = */ 64,
		/* .height = */ 256,
		/* .mask = */ 0,
		/* .numfit = */ 2,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 16,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 4
	},
	/* [14] = */ {
		/* .width = */ 128,
		/* .height = */ 16,
		/* .mask = */ 52224,
		/* .numfit = */ 4,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 2,
			/* [2] = */ 8,
			/* [3] = */ 10,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [15] = */ {
		/* .width = */ 128,
		/* .height = */ 32,
		/* .mask = */ 65280,
		/* .numfit = */ 2,
		/* .fit = */ {
			/* [0] = */ 0,
			/* [1] = */ 8,
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [16] = */ {
		/* .width = */ 128,
		/* .height = */ 64,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 1
	},
	/* [17] = */ {
		/* .width = */ 128,
		/* .height = */ 128,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 2
	},
	/* [18] = */ {
		/* .width = */ 128,
		/* .height = */ 256,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 4
	},
	/* [19] = */ {
		/* .width = */ 128,
		/* .height = */ 512,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 8
	},
	/* [20] = */ {
		/* .width = */ 256,
		/* .height = */ 32,
		/* .mask = */ 65280,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 2
	},
	/* [21] = */ {
		/* .width = */ 256,
		/* .height = */ 64,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 2
	},
	/* [22] = */ {
		/* .width = */ 256,
		/* .height = */ 128,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 4
	},
	/* [23] = */ {
		/* .width = */ 256,
		/* .height = */ 256,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 8
	},
	/* [24] = */ {
		/* .width = */ 256,
		/* .height = */ 512,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 16
	},
	/* [25] = */ {
		/* .width = */ 512,
		/* .height = */ 64,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 4
	},
	/* [26] = */ {
		/* .width = */ 512,
		/* .height = */ 128,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 8
	},
	/* [27] = */ {
		/* .width = */ 512,
		/* .height = */ 256,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 16
	},
	/* [28] = */ {
		/* .width = */ 512,
		/* .height = */ 512,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 32
	},
	/* [29] = */ {
		/* .width = */ 1024,
		/* .height = */ 512,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 64
	},
	/* [30] = */ {
		/* .width = */ 1024,
		/* .height = */ 1024,
		/* .mask = */ 65535,
		/* .numfit = */ 1,
		/* .fit = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0,
			/* [31] = */ 0
		},
		/* .extents = */ 128
	}
};

static int s_CurrentDecodeMovie = 0;
int TotalTextureMem = 0;

texbuffer texbuf[1] = {
	/* [0] = */ {
		/* .textures = */ NULL,
		/* .pages = */ NULL,
		/* .textypes = */ NULL,
		/* .nexttexid = */ 0,
		/* .firstpage = */ 0,
		/* .numpages = */ 0,
		/* .max_texid = */ 0,
		/* .HasUnusedPage = */ 0,
		/* .CurrentFillPalettePage = */ 0,
		/* .CurrentSwapPalettePage = */ 0,
		/* .CurrentSwapPaletteNum = */ 0,
		/* .CurrentFillTexturePage = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0
		},
		/* .CurrentSwapTexturePage = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0
		},
		/* .CurrentSwapTextureNum = */ {
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
			/* [29] = */ 0,
			/* [30] = */ 0
		}
	}
};

static int s_MovieTexIds[32];
static int s_NumMovies;
static int s_IPUDMAHandlerID;

void emResetTexBuffer(int num) {
	int i;
	texbuffer *tb;
}

static void emCreateTexBuffer(int num, int firstpage, int numpages, int max_texid) {
	texbuffer *tb;
}

void emSelectTexBuffer(int num) {}

void emRestart() {}

void emReset() {}

void emPrintStats() {
	int i;
}

static int emClearPages(int NumPages, int TexID) {
	int i;
	int StartPage;
	int TotalCleared;
	int n;
	pageinfo *pPage;
	int NumIDs;
	int Extents;
	int j;
	boolean dontSwap;
	emTexture *pTex;
	pageinfo *pPage;
	texsize_t *ClearSize;
	int NumPagesClear;
	int j;
	int n;
	emTexture *pOrig;
	u32 tbp;
	int n;
	emTexture *pOrig;
}

static boolean emGetNextPalettePos(emTexture *tex, int texid) {
	int i;
	int j;
	pageinfo *pPage;
	int *pPageNum;
	int *pTexNum;
	pageinfo *pPage;
	emTexture *pOrig;
	pageinfo *pPage;
}

static boolean emGetNextPos(emTexture *tex, int texid, int MipLevel, boolean debug) {
	int i;
	int j;
	int e;
	int n;
	u32 texmask;
	int SizeIndex;
	texsize_t *size;
	int *pPageNum;
	pageinfo *pPage;
	u32 fitmask;
	pageinfo *pPage;
	int *pPageNum;
	int *pTexNum;
	pageinfo *pPage;
	boolean Found;
	boolean DontSwap;
	emTexture *pTex;
	emTexture *pTex;
	emTexture *pOrig;
	u32 tbp;
	int j;
}

static u32 GSBufferWidth(emTexture *tex, int MipLevel) {
	u32 bw;
}

void emSetupVifLoadPacket(emTexture *texture) {
	u64 regval;
	u32 txf;
	u32 *v;
	int mmin;
	int mmag;
	int filt;
}

static void emLoadTexture(int id, char *filename, texinfo *t) {
	emTexture *texture;
	emTexture miptex;
	int i;
	int j;
}

static void setToIPUtags(u_int *tag, u_char *p, int size) {
	int chunksize;
	u_int *unctag;
	u_char *dmap;
	u_int *p;
	void *addr;
}

static void setDMAtoIPU(u_int *tag) {}

static void setDMAfromIPU(sceIpuRGB32 *rgb32, int count) {}

void emLoadTextureMovie(char *filename, texinfo *t, int *idpos) {
	u8 *pFileData;
	int FileSize;
	int NumFrames;
	emTexture *pTex;
	MovieData *pMovie;
}

static void emCreateTexture(int Width, int Height, int Format, int MipLevels, texinfo *pInfo, int *pTexNum) {
	emTexture *pTex;
	int i;
	int j;
}

static void emSetupTexture(texinfo *pInfo, u8 *pData, int *pTexNum) {
	emTexture *pTex;
}

void emCreateRenderTexture(int Width, int Height, ViewDef *pView, int *pTexNum) {
	emTexture *pTex;
}

void emProcessRenderTexture(int TexID) {
	u64 regval;
	u32 *ref;
	emTexture *pTex;
	ViewDef *pView;
	void *addr;
}

void emLoadTextureAddr(u32 addr, texinfo *t, int *idpos) {}

void emLoadTextureMem(u8 *pData, texinfo *t, int *idpos) {}

void emLoadTextureName(char *filename, texinfo *t, int *idpos) {
	int Size;
	u8 *pData;
	int texnum;
}

void emLoadTextureNum(int id, texinfo *t, int *idpos) {
	int i;
	char filename[1000];
	int Size;
	int TexNum;
	u8 *pData;
}

void emAllocTexture(int pixwidth, int pixheight, int format, int miplevels, texinfo *t, u32 *palette, u8 *data, int *idpos) {
	emTexture *pTex;
}

void emCheckTextureMain(int id) {
	int i;
	int j;
	u32 size;
	emTexture *pTex;
	boolean Loaded;
	int mbx;
	int mby;
	u8 *pData;
	sceGsLoadImage *li;
	void *addr;
	void *addr;
	u8 *pData;
	sceGsLoadImage *li;
	void *addr;
	void *addr;
	sceGsLoadImage *li;
	void *addr;
	void *addr;
	u32 *ref;
	void *addr;
}

void emClearAllTexPages() {
	int i;
	int j;
	int k;
}

u_int getFlags() {
	u_int ret;
}

static boolean DecodeMovieToMem(emTexture *pTex) {
	u_int flag;
	MovieData *pMovie;
}

void DecodeNextMovie() {}

void DecodeFirstMovie() {}

static int handler(int ch) {}

void emMake() {}

void emTick() {
	int i;
}
