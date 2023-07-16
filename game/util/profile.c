// STATUS: NOT STARTED

#include "profile.h"

struct profiledata_s {
	int active;
	int timing;
	float totalframes;
	float filtmax;
	int newmaxtime;
	char *id;
	u32 col;
};

typedef profiledata_s profiledata;

profiledata profdata[20] = {
	/* [0] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [1] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [2] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [3] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [4] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [5] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [6] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [7] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [8] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [9] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [10] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [11] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [12] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [13] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [14] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [15] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [16] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [17] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [18] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	},
	/* [19] = */ {
		/* .active = */ 0,
		/* .timing = */ 0,
		/* .totalframes = */ 0.f,
		/* .filtmax = */ 0.f,
		/* .newmaxtime = */ 0,
		/* .id = */ NULL,
		/* .col = */ 0
	}
};

static int profilenumtiming = 0;

void profileMake() {}

void profileRestart() {}

void profileReset() {}

void profileTick() {}

static void profileSimpleTimeBar(int x, int y, float endframes, float filtmax, u32 col) {
	int i;
	float efr;
	float f;
}

void profileGfx() {}

void profileEnd() {}

void profileStartTiming() {}

void profileStopTiming() {}

float profileTimeGet() {}

void profileStart(int num, char *id, u32 col) {}

void profileFinish(int num) {}

void profileTimeStart(int num) {}

void profileTimeEnd(int num) {}

void profileTimeBar(int x, int y, float startframes, float endframes, u32 col) {
	int i;
	float sfr;
	float efr;
	float f;
}

void profileTimeBarDrawTicks(int x, int y) {
	float f;
	int i;
}

void profileTimeBarDrawBar(int x, int y, float startframes, float endframes, u32 col1, u32 col2) {
	float sfr;
	float efr;
}
