// STATUS: NOT STARTED

#include "front.h"

gvdisp disp_off[0] = {
};

gvdisp disp_none[0] = {
};

gvdisp disp_onoff[0] = {
};

gvdisp disp_yesno[0] = {
};

frontdef_t *front = NULL;

frontdef_t frontdefs[4] = {
	/* [0] = */ {
		/* .num = */ 0,
		/* .pagesArray = */ NULL,
		/* .pages = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL,
			/* [2] = */ NULL
		},
		/* .boxes = */ NULL,
		/* .flags = */ 0,
		/* .buttonhold = */ 0,
		/* .numpages = */ 0,
		/* .pagetoset = */ NULL,
		/* .pagetosetnum = */ 0,
		/* .mouse_x = */ 0,
		/* .mouse_y = */ 0,
		/* .cursor_drawer = */ NULL
	},
	/* [1] = */ {
		/* .num = */ 0,
		/* .pagesArray = */ NULL,
		/* .pages = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL,
			/* [2] = */ NULL
		},
		/* .boxes = */ NULL,
		/* .flags = */ 0,
		/* .buttonhold = */ 0,
		/* .numpages = */ 0,
		/* .pagetoset = */ NULL,
		/* .pagetosetnum = */ 0,
		/* .mouse_x = */ 0,
		/* .mouse_y = */ 0,
		/* .cursor_drawer = */ NULL
	},
	/* [2] = */ {
		/* .num = */ 0,
		/* .pagesArray = */ NULL,
		/* .pages = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL,
			/* [2] = */ NULL
		},
		/* .boxes = */ NULL,
		/* .flags = */ 0,
		/* .buttonhold = */ 0,
		/* .numpages = */ 0,
		/* .pagetoset = */ NULL,
		/* .pagetosetnum = */ 0,
		/* .mouse_x = */ 0,
		/* .mouse_y = */ 0,
		/* .cursor_drawer = */ NULL
	},
	/* [3] = */ {
		/* .num = */ 0,
		/* .pagesArray = */ NULL,
		/* .pages = */ {
			/* [0] = */ NULL,
			/* [1] = */ NULL,
			/* [2] = */ NULL
		},
		/* .boxes = */ NULL,
		/* .flags = */ 0,
		/* .buttonhold = */ 0,
		/* .numpages = */ 0,
		/* .pagetoset = */ NULL,
		/* .pagetosetnum = */ 0,
		/* .mouse_x = */ 0,
		/* .mouse_y = */ 0,
		/* .cursor_drawer = */ NULL
	}
};

pagedef_t *currentpage = NULL;
static hitbox_t boxes[4][128];
static pagedef_t *pages[4];

u8* gvGetStringValue(gamevar *gv) {
	u8 *s;
	gvdisp *disp;
	float f;
}

void gvSetValue(gamevar *gv, int value) {
	int oldvalue;
}

int gvDispIndex(gvdisp *disp, int dispvalue) {
	int i;
}

void frontGetPageSize(pagedef_t *page, rect_t *size) {
	int i;
	hitbox_t *box;
}

hitbox_t* frontGetBox(pagedef_t *page, u16 id) {
	hitbox_t *box;
	int numboxes;
	int i;
}

void frontControlsTick(int j) {
	static s8 btnticks[4][4] = {
		/* [0] = */ {
			/* [0] = */ 8,
			/* [1] = */ 8,
			/* [2] = */ 8,
			/* [3] = */ 8
		},
		/* [1] = */ {
			/* [0] = */ 8,
			/* [1] = */ 8,
			/* [2] = */ 8,
			/* [3] = */ 8
		},
		/* [2] = */ {
			/* [0] = */ 8,
			/* [1] = */ 8,
			/* [2] = */ 8,
			/* [3] = */ 8
		},
		/* [3] = */ {
			/* [0] = */ 8,
			/* [1] = */ 8,
			/* [2] = */ 8,
			/* [3] = */ 8
		}
	};
	int i;
	int buttons;
	float analog_x;
	float analog_y;
	u8 analog_tap[4];
	int gp;
}

void frontMouseTick() {
	static float speed_x;
	static float speed_y;
	float analog_x;
	float analog_y;
}

static void frontFocusTick(pagedef_t *guipage) {
	int i;
	u32 cx;
	u32 cy;
	hitbox_t *hb;
	int numboxes;
}

void frontClearPages() {
	int e;
}

void frontClear() {}

void frontRestart() {
	int i;
}

void frontReset() {
	int i;
	int f;
}

void frontSet(int playernum) {}

frontdef_t* frontGet(int playernum) {}

void frontPageSetup(pagedef_t *page, pageinit_t *init) {}

void frontTickCore() {
	int playernum;
	boolean stickyfocus;
	pagedef_t *page;
	int i;
	int curbox;
	boolean allTicked;
	boolean topUpdated;
	int i;
	pagedef_t *page;
}

void frontTick() {}

void frontGfxCore() {
	pagedef_t *page;
	hitbox_t *box;
	int numboxes;
	int i;
	int j;
}

void frontGfx() {}

void frontEnd() {
	int i;
}

void frontPageSet(int pagenum, pageinit_t *init) {}

pagedef_t* frontPageActivate(pageinit_t *init) {
	pagedef_t *page;
	int e;
}

pagedef_t* frontPageAdd(pageinit_t *init) {
	pagedef_t *page;
	int e;
}

pagedef_t* frontPageGet(pageinit_t *init) {
	int i;
}

pagedef_t* frontGetTopPage() {}

void frontPageRemoveInit(pageinit_t *init) {
	int i;
	int f;
}

void frontPageRemove(pagedef_t *page) {
	int i;
	int f;
}
