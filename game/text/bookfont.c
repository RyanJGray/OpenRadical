// STATUS: NOT STARTED

#include "bookfont.h"

int bookfontentries = 103;

letter bookfont[103] = {
	/* [0] = */ {
		/* .l = */ 0,
		/* .t = */ 0,
		/* .r = */ 5,
		/* .b = */ 1,
		/* .yoffset = */ 10
	},
	/* [1] = */ {
		/* .l = */ 0,
		/* .t = */ 1,
		/* .r = */ 4,
		/* .b = */ 14,
		/* .yoffset = */ 3
	},
	/* [2] = */ {
		/* .l = */ 5,
		/* .t = */ 1,
		/* .r = */ 13,
		/* .b = */ 6,
		/* .yoffset = */ 3
	},
	/* [3] = */ {
		/* .l = */ 14,
		/* .t = */ 1,
		/* .r = */ 27,
		/* .b = */ 14,
		/* .yoffset = */ 3
	},
	/* [4] = */ {
		/* .l = */ 28,
		/* .t = */ 1,
		/* .r = */ 39,
		/* .b = */ 17,
		/* .yoffset = */ 1
	},
	/* [5] = */ {
		/* .l = */ 40,
		/* .t = */ 1,
		/* .r = */ 57,
		/* .b = */ 16,
		/* .yoffset = */ 2
	},
	/* [6] = */ {
		/* .l = */ 58,
		/* .t = */ 1,
		/* .r = */ 72,
		/* .b = */ 16,
		/* .yoffset = */ 2
	},
	/* [7] = */ {
		/* .l = */ 73,
		/* .t = */ 1,
		/* .r = */ 78,
		/* .b = */ 6,
		/* .yoffset = */ 3
	},
	/* [8] = */ {
		/* .l = */ 79,
		/* .t = */ 1,
		/* .r = */ 86,
		/* .b = */ 18,
		/* .yoffset = */ 255
	},
	/* [9] = */ {
		/* .l = */ 87,
		/* .t = */ 1,
		/* .r = */ 94,
		/* .b = */ 18,
		/* .yoffset = */ 255
	},
	/* [10] = */ {
		/* .l = */ 95,
		/* .t = */ 1,
		/* .r = */ 104,
		/* .b = */ 7,
		/* .yoffset = */ 6
	},
	/* [11] = */ {
		/* .l = */ 105,
		/* .t = */ 1,
		/* .r = */ 117,
		/* .b = */ 10,
		/* .yoffset = */ 5
	},
	/* [12] = */ {
		/* .l = */ 118,
		/* .t = */ 1,
		/* .r = */ 122,
		/* .b = */ 6,
		/* .yoffset = */ 11
	},
	/* [13] = */ {
		/* .l = */ 0,
		/* .t = */ 21,
		/* .r = */ 7,
		/* .b = */ 23,
		/* .yoffset = */ 8
	},
	/* [14] = */ {
		/* .l = */ 8,
		/* .t = */ 21,
		/* .r = */ 12,
		/* .b = */ 23,
		/* .yoffset = */ 14
	},
	/* [15] = */ {
		/* .l = */ 13,
		/* .t = */ 21,
		/* .r = */ 21,
		/* .b = */ 34,
		/* .yoffset = */ 3
	},
	/* [16] = */ {
		/* .l = */ 22,
		/* .t = */ 21,
		/* .r = */ 34,
		/* .b = */ 35,
		/* .yoffset = */ 3
	},
	/* [17] = */ {
		/* .l = */ 35,
		/* .t = */ 21,
		/* .r = */ 42,
		/* .b = */ 34,
		/* .yoffset = */ 3
	},
	/* [18] = */ {
		/* .l = */ 43,
		/* .t = */ 21,
		/* .r = */ 55,
		/* .b = */ 34,
		/* .yoffset = */ 3
	},
	/* [19] = */ {
		/* .l = */ 56,
		/* .t = */ 21,
		/* .r = */ 67,
		/* .b = */ 35,
		/* .yoffset = */ 3
	},
	/* [20] = */ {
		/* .l = */ 68,
		/* .t = */ 21,
		/* .r = */ 80,
		/* .b = */ 34,
		/* .yoffset = */ 3
	},
	/* [21] = */ {
		/* .l = */ 81,
		/* .t = */ 21,
		/* .r = */ 93,
		/* .b = */ 35,
		/* .yoffset = */ 3
	},
	/* [22] = */ {
		/* .l = */ 94,
		/* .t = */ 21,
		/* .r = */ 106,
		/* .b = */ 35,
		/* .yoffset = */ 3
	},
	/* [23] = */ {
		/* .l = */ 107,
		/* .t = */ 21,
		/* .r = */ 119,
		/* .b = */ 34,
		/* .yoffset = */ 3
	},
	/* [24] = */ {
		/* .l = */ 0,
		/* .t = */ 41,
		/* .r = */ 11,
		/* .b = */ 55,
		/* .yoffset = */ 3
	},
	/* [25] = */ {
		/* .l = */ 12,
		/* .t = */ 41,
		/* .r = */ 23,
		/* .b = */ 55,
		/* .yoffset = */ 3
	},
	/* [26] = */ {
		/* .l = */ 24,
		/* .t = */ 41,
		/* .r = */ 28,
		/* .b = */ 51,
		/* .yoffset = */ 6
	},
	/* [27] = */ {
		/* .l = */ 29,
		/* .t = */ 41,
		/* .r = */ 33,
		/* .b = */ 54,
		/* .yoffset = */ 3
	},
	/* [28] = */ {
		/* .l = */ 34,
		/* .t = */ 41,
		/* .r = */ 46,
		/* .b = */ 50,
		/* .yoffset = */ 5
	},
	/* [29] = */ {
		/* .l = */ 47,
		/* .t = */ 41,
		/* .r = */ 59,
		/* .b = */ 48,
		/* .yoffset = */ 6
	},
	/* [30] = */ {
		/* .l = */ 60,
		/* .t = */ 41,
		/* .r = */ 71,
		/* .b = */ 50,
		/* .yoffset = */ 5
	},
	/* [31] = */ {
		/* .l = */ 72,
		/* .t = */ 41,
		/* .r = */ 84,
		/* .b = */ 55,
		/* .yoffset = */ 2
	},
	/* [32] = */ {
		/* .l = */ 85,
		/* .t = */ 41,
		/* .r = */ 104,
		/* .b = */ 59,
		/* .yoffset = */ 0
	},
	/* [33] = */ {
		/* .l = */ 105,
		/* .t = */ 41,
		/* .r = */ 120,
		/* .b = */ 54,
		/* .yoffset = */ 3
	},
	/* [34] = */ {
		/* .l = */ 0,
		/* .t = */ 61,
		/* .r = */ 12,
		/* .b = */ 74,
		/* .yoffset = */ 3
	},
	/* [35] = */ {
		/* .l = */ 13,
		/* .t = */ 61,
		/* .r = */ 27,
		/* .b = */ 76,
		/* .yoffset = */ 2
	},
	/* [36] = */ {
		/* .l = */ 28,
		/* .t = */ 61,
		/* .r = */ 42,
		/* .b = */ 74,
		/* .yoffset = */ 3
	},
	/* [37] = */ {
		/* .l = */ 43,
		/* .t = */ 61,
		/* .r = */ 56,
		/* .b = */ 74,
		/* .yoffset = */ 3
	},
	/* [38] = */ {
		/* .l = */ 57,
		/* .t = */ 61,
		/* .r = */ 68,
		/* .b = */ 74,
		/* .yoffset = */ 3
	},
	/* [39] = */ {
		/* .l = */ 69,
		/* .t = */ 61,
		/* .r = */ 84,
		/* .b = */ 76,
		/* .yoffset = */ 2
	},
	/* [40] = */ {
		/* .l = */ 85,
		/* .t = */ 61,
		/* .r = */ 98,
		/* .b = */ 74,
		/* .yoffset = */ 3
	},
	/* [41] = */ {
		/* .l = */ 99,
		/* .t = */ 61,
		/* .r = */ 104,
		/* .b = */ 74,
		/* .yoffset = */ 3
	},
	/* [42] = */ {
		/* .l = */ 105,
		/* .t = */ 61,
		/* .r = */ 115,
		/* .b = */ 75,
		/* .yoffset = */ 3
	},
	/* [43] = */ {
		/* .l = */ 0,
		/* .t = */ 81,
		/* .r = */ 14,
		/* .b = */ 94,
		/* .yoffset = */ 3
	},
	/* [44] = */ {
		/* .l = */ 15,
		/* .t = */ 81,
		/* .r = */ 26,
		/* .b = */ 94,
		/* .yoffset = */ 3
	},
	/* [45] = */ {
		/* .l = */ 27,
		/* .t = */ 81,
		/* .r = */ 42,
		/* .b = */ 94,
		/* .yoffset = */ 3
	},
	/* [46] = */ {
		/* .l = */ 43,
		/* .t = */ 81,
		/* .r = */ 56,
		/* .b = */ 94,
		/* .yoffset = */ 3
	},
	/* [47] = */ {
		/* .l = */ 57,
		/* .t = */ 81,
		/* .r = */ 72,
		/* .b = */ 96,
		/* .yoffset = */ 2
	},
	/* [48] = */ {
		/* .l = */ 73,
		/* .t = */ 81,
		/* .r = */ 85,
		/* .b = */ 94,
		/* .yoffset = */ 3
	},
	/* [49] = */ {
		/* .l = */ 86,
		/* .t = */ 81,
		/* .r = */ 101,
		/* .b = */ 96,
		/* .yoffset = */ 2
	},
	/* [50] = */ {
		/* .l = */ 102,
		/* .t = */ 81,
		/* .r = */ 116,
		/* .b = */ 94,
		/* .yoffset = */ 3
	},
	/* [51] = */ {
		/* .l = */ 0,
		/* .t = */ 101,
		/* .r = */ 13,
		/* .b = */ 116,
		/* .yoffset = */ 2
	},
	/* [52] = */ {
		/* .l = */ 14,
		/* .t = */ 101,
		/* .r = */ 27,
		/* .b = */ 114,
		/* .yoffset = */ 3
	},
	/* [53] = */ {
		/* .l = */ 28,
		/* .t = */ 101,
		/* .r = */ 41,
		/* .b = */ 115,
		/* .yoffset = */ 3
	},
	/* [54] = */ {
		/* .l = */ 42,
		/* .t = */ 101,
		/* .r = */ 57,
		/* .b = */ 114,
		/* .yoffset = */ 3
	},
	/* [55] = */ {
		/* .l = */ 58,
		/* .t = */ 101,
		/* .r = */ 78,
		/* .b = */ 114,
		/* .yoffset = */ 3
	},
	/* [56] = */ {
		/* .l = */ 79,
		/* .t = */ 101,
		/* .r = */ 93,
		/* .b = */ 114,
		/* .yoffset = */ 3
	},
	/* [57] = */ {
		/* .l = */ 94,
		/* .t = */ 101,
		/* .r = */ 109,
		/* .b = */ 114,
		/* .yoffset = */ 3
	},
	/* [58] = */ {
		/* .l = */ 110,
		/* .t = */ 101,
		/* .r = */ 123,
		/* .b = */ 114,
		/* .yoffset = */ 3
	},
	/* [59] = */ {
		/* .l = */ 0,
		/* .t = */ 121,
		/* .r = */ 6,
		/* .b = */ 138,
		/* .yoffset = */ 1
	},
	/* [60] = */ {
		/* .l = */ 7,
		/* .t = */ 121,
		/* .r = */ 15,
		/* .b = */ 134,
		/* .yoffset = */ 3
	},
	/* [61] = */ {
		/* .l = */ 16,
		/* .t = */ 121,
		/* .r = */ 22,
		/* .b = */ 138,
		/* .yoffset = */ 1
	},
	/* [62] = */ {
		/* .l = */ 23,
		/* .t = */ 121,
		/* .r = */ 33,
		/* .b = */ 129,
		/* .yoffset = */ 3
	},
	/* [63] = */ {
		/* .l = */ 34,
		/* .t = */ 121,
		/* .r = */ 47,
		/* .b = */ 123,
		/* .yoffset = */ 3
	},
	/* [64] = */ {
		/* .l = */ 48,
		/* .t = */ 121,
		/* .r = */ 54,
		/* .b = */ 124,
		/* .yoffset = */ 3
	},
	/* [65] = */ {
		/* .l = */ 55,
		/* .t = */ 121,
		/* .r = */ 67,
		/* .b = */ 132,
		/* .yoffset = */ 6
	},
	/* [66] = */ {
		/* .l = */ 68,
		/* .t = */ 121,
		/* .r = */ 79,
		/* .b = */ 135,
		/* .yoffset = */ 3
	},
	/* [67] = */ {
		/* .l = */ 80,
		/* .t = */ 121,
		/* .r = */ 92,
		/* .b = */ 132,
		/* .yoffset = */ 6
	},
	/* [68] = */ {
		/* .l = */ 93,
		/* .t = */ 121,
		/* .r = */ 104,
		/* .b = */ 135,
		/* .yoffset = */ 3
	},
	/* [69] = */ {
		/* .l = */ 105,
		/* .t = */ 121,
		/* .r = */ 116,
		/* .b = */ 132,
		/* .yoffset = */ 6
	},
	/* [70] = */ {
		/* .l = */ 117,
		/* .t = */ 121,
		/* .r = */ 125,
		/* .b = */ 135,
		/* .yoffset = */ 2
	},
	/* [71] = */ {
		/* .l = */ 0,
		/* .t = */ 141,
		/* .r = */ 11,
		/* .b = */ 155,
		/* .yoffset = */ 6
	},
	/* [72] = */ {
		/* .l = */ 12,
		/* .t = */ 141,
		/* .r = */ 22,
		/* .b = */ 154,
		/* .yoffset = */ 3
	},
	/* [73] = */ {
		/* .l = */ 23,
		/* .t = */ 141,
		/* .r = */ 27,
		/* .b = */ 154,
		/* .yoffset = */ 3
	},
	/* [74] = */ {
		/* .l = */ 28,
		/* .t = */ 141,
		/* .r = */ 34,
		/* .b = */ 158,
		/* .yoffset = */ 3
	},
	/* [75] = */ {
		/* .l = */ 35,
		/* .t = */ 141,
		/* .r = */ 45,
		/* .b = */ 154,
		/* .yoffset = */ 3
	},
	/* [76] = */ {
		/* .l = */ 46,
		/* .t = */ 141,
		/* .r = */ 50,
		/* .b = */ 154,
		/* .yoffset = */ 3
	},
	/* [77] = */ {
		/* .l = */ 51,
		/* .t = */ 141,
		/* .r = */ 66,
		/* .b = */ 151,
		/* .yoffset = */ 6
	},
	/* [78] = */ {
		/* .l = */ 67,
		/* .t = */ 141,
		/* .r = */ 78,
		/* .b = */ 151,
		/* .yoffset = */ 6
	},
	/* [79] = */ {
		/* .l = */ 79,
		/* .t = */ 141,
		/* .r = */ 91,
		/* .b = */ 152,
		/* .yoffset = */ 6
	},
	/* [80] = */ {
		/* .l = */ 92,
		/* .t = */ 141,
		/* .r = */ 103,
		/* .b = */ 155,
		/* .yoffset = */ 6
	},
	/* [81] = */ {
		/* .l = */ 104,
		/* .t = */ 141,
		/* .r = */ 115,
		/* .b = */ 155,
		/* .yoffset = */ 6
	},
	/* [82] = */ {
		/* .l = */ 116,
		/* .t = */ 141,
		/* .r = */ 124,
		/* .b = */ 151,
		/* .yoffset = */ 6
	},
	/* [83] = */ {
		/* .l = */ 0,
		/* .t = */ 161,
		/* .r = */ 10,
		/* .b = */ 172,
		/* .yoffset = */ 6
	},
	/* [84] = */ {
		/* .l = */ 11,
		/* .t = */ 161,
		/* .r = */ 19,
		/* .b = */ 175,
		/* .yoffset = */ 3
	},
	/* [85] = */ {
		/* .l = */ 20,
		/* .t = */ 161,
		/* .r = */ 31,
		/* .b = */ 172,
		/* .yoffset = */ 6
	},
	/* [86] = */ {
		/* .l = */ 32,
		/* .t = */ 161,
		/* .r = */ 43,
		/* .b = */ 171,
		/* .yoffset = */ 6
	},
	/* [87] = */ {
		/* .l = */ 44,
		/* .t = */ 161,
		/* .r = */ 60,
		/* .b = */ 171,
		/* .yoffset = */ 6
	},
	/* [88] = */ {
		/* .l = */ 61,
		/* .t = */ 161,
		/* .r = */ 72,
		/* .b = */ 171,
		/* .yoffset = */ 6
	},
	/* [89] = */ {
		/* .l = */ 73,
		/* .t = */ 161,
		/* .r = */ 84,
		/* .b = */ 175,
		/* .yoffset = */ 6
	},
	/* [90] = */ {
		/* .l = */ 85,
		/* .t = */ 161,
		/* .r = */ 96,
		/* .b = */ 171,
		/* .yoffset = */ 6
	},
	/* [91] = */ {
		/* .l = */ 97,
		/* .t = */ 161,
		/* .r = */ 109,
		/* .b = */ 165,
		/* .yoffset = */ 7
	},
	/* [92] = */ {
		/* .l = */ 110,
		/* .t = */ 161,
		/* .r = */ 118,
		/* .b = */ 164,
		/* .yoffset = */ 8
	},
	/* [93] = */ {
		/* .l = */ 0,
		/* .t = */ 181,
		/* .r = */ 15,
		/* .b = */ 188,
		/* .yoffset = */ 6
	},
	/* [94] = */ {
		/* .l = */ 16,
		/* .t = */ 181,
		/* .r = */ 20,
		/* .b = */ 192,
		/* .yoffset = */ 4
	},
	/* [95] = */ {
		/* .l = */ 21,
		/* .t = */ 181,
		/* .r = */ 32,
		/* .b = */ 192,
		/* .yoffset = */ 4
	},
	/* [96] = */ {
		/* .l = */ 33,
		/* .t = */ 181,
		/* .r = */ 46,
		/* .b = */ 192,
		/* .yoffset = */ 4
	},
	/* [97] = */ {
		/* .l = */ 47,
		/* .t = */ 181,
		/* .r = */ 56,
		/* .b = */ 188,
		/* .yoffset = */ 6
	},
	/* [98] = */ {
		/* .l = */ 57,
		/* .t = */ 181,
		/* .r = */ 67,
		/* .b = */ 192,
		/* .yoffset = */ 4
	},
	/* [99] = */ {
		/* .l = */ 68,
		/* .t = */ 181,
		/* .r = */ 80,
		/* .b = */ 195,
		/* .yoffset = */ 2
	},
	/* [100] = */ {
		/* .l = */ 81,
		/* .t = */ 181,
		/* .r = */ 91,
		/* .b = */ 192,
		/* .yoffset = */ 4
	},
	/* [101] = */ {
		/* .l = */ 92,
		/* .t = */ 181,
		/* .r = */ 102,
		/* .b = */ 192,
		/* .yoffset = */ 4
	},
	/* [102] = */ {
		/* .l = */ 0,
		/* .t = */ 0,
		/* .r = */ 16,
		/* .b = */ 1,
		/* .yoffset = */ 10
	}
};
