// STATUS: NOT STARTED

#include "timers.h"

static int numtimers = 0;

timer timers[75] = {
	/* [0] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [1] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [2] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [3] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [4] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [5] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [6] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [7] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [8] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [9] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [10] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [11] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [12] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [13] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [14] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [15] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [16] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [17] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [18] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [19] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [20] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [21] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [22] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [23] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [24] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [25] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [26] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [27] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [28] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [29] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [30] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [31] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [32] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [33] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [34] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [35] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [36] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [37] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [38] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [39] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [40] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [41] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [42] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [43] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [44] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [45] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [46] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [47] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [48] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [49] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [50] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [51] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [52] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [53] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [54] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [55] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [56] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [57] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [58] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [59] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [60] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [61] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [62] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [63] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [64] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [65] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [66] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [67] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [68] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [69] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [70] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [71] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [72] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [73] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	},
	/* [74] = */ {
		/* .type = */ 0,
		/* .time = */ 0,
		/* .lasttime = */ 0,
		/* .duration = */ 0.f,
		/* .data = */ NULL,
		/* .function = */ NULL
	}
};

void timerRestart() {}

void timerReset() {}

int timerNew(int type, float time, void *data, void (*function)(/* parameters unknown */)) {}

void timerTick() {
	int i;
	int deltatime;
}

void timerEnd() {}

void timerRelease(int id) {}
