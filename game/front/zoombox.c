// STATUS: NOT STARTED

#include "zoombox.h"

zoomboxinfo_t zoomboxes[4] = {
	/* [0] = */ {
		/* .s = */ {
			/* .x1 = */ 0,
			/* .y1 = */ 0,
			/* .x2 = */ 0,
			/* .y2 = */ 0
		},
		/* .bgcol = */ 0,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .width = */ 0,
		/* .height = */ 0,
		/* .frame = */ 0
	},
	/* [1] = */ {
		/* .s = */ {
			/* .x1 = */ 0,
			/* .y1 = */ 0,
			/* .x2 = */ 0,
			/* .y2 = */ 0
		},
		/* .bgcol = */ 0,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .width = */ 0,
		/* .height = */ 0,
		/* .frame = */ 0
	},
	/* [2] = */ {
		/* .s = */ {
			/* .x1 = */ 0,
			/* .y1 = */ 0,
			/* .x2 = */ 0,
			/* .y2 = */ 0
		},
		/* .bgcol = */ 0,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .width = */ 0,
		/* .height = */ 0,
		/* .frame = */ 0
	},
	/* [3] = */ {
		/* .s = */ {
			/* .x1 = */ 0,
			/* .y1 = */ 0,
			/* .x2 = */ 0,
			/* .y2 = */ 0
		},
		/* .bgcol = */ 0,
		/* .left = */ 0,
		/* .top = */ 0,
		/* .width = */ 0,
		/* .height = */ 0,
		/* .frame = */ 0
	}
};

void zoomboxInit(int playernum, rect_t *sizes, u32 bgcol) {
	zoomboxinfo_t *zb;
}

void zoomboxSet(int playernum, rect_t *sizes, u32 bgcol) {
	zoomboxinfo_t *zb;
}

void zoomboxTick(int playernum) {
	int cx;
	int cy;
	int w;
	int h;
	zoomboxinfo_t *zb;
}

void zoomboxGfx(int playernum) {
	zoomboxinfo_t *zb;
}
