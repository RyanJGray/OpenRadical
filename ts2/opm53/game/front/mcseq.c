// STATUS: NOT STARTED

#include "mcseq.h"

typedef enum {
	mcseq_state_busy = 0,
	mcseq_state_idle = 1,
	mcseq_state_fail = 2,
	mcseq_state_message = 3,
	mcseq_state_checkcards = 4,
	mcseq_state_selectcard_init = 5,
	mcseq_state_selectcard_pollstart = 6,
	mcseq_state_selectcard_pollloop = 7,
	mcseq_state_selectcard_pollwait = 8,
	mcseq_state_selectcard_done = 9,
	mcseq_state_ask_format = 10,
	mcseq_state_recheckcard = 11,
	mcseq_state_checkdir = 12,
	mcseq_state_checkcreatedir = 13,
	mcseq_state_checkspacedir = 14,
	mcseq_state_dircreated = 15,
	mcseq_state_checkicons = 16,
	mcseq_state_action = 17,
	mcseq_state_action_done = 18,
	mcseq_state_savefile_create = 19,
	mcseq_state_savefile_overwrite = 20,
	mcseq_state_savefile_start = 21,
	mcseq_state_savefile_end = 22,
	mcseq_state_poll_loop = 23,
	mcseq_state_poll_wait = 24
};

typedef enum {
	mca_loadfile = 0,
	mca_savefile = 1
};

u32 mcseq_slotcolours[9] = {
	/* [0] = */ 8320,
	/* [1] = */ 10880,
	/* [2] = */ 8320,
	/* [3] = */ 2688,
	/* [4] = */ 8320,
	/* [5] = */ 8320,
	/* [6] = */ 10880,
	/* [7] = */ 10880,
	/* [8] = */ 8256
};

static int mcseq_state = 1;

static menuitem_t mi_msg = {
	/* .text = */ NULL,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 0,
	/* .flags = */ 32,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static menuitem_t mi_card = {
	/* .text = */ NULL,
	/* .left = */ 0,
	/* .top = */ 0,
	/* .id = */ 0,
	/* .flags = */ 32,
	/* .data = */ NULL,
	/* .next = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	},
	/* .spare = */ {
		/* [0] = */ NULL,
		/* [1] = */ NULL
	}
};

static pageinit_t mcseq_page = {
	/* .tick = */ &mcseq_pageTick,
	/* .draw_before = */ &mcseq_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

u32 mcseq_flags = 0;
int mcseq_msgflags = 0;
static u8 mcseq_windowopened;
static u8 *mcseq_title;
static u8 *mcseq_titleact;
static u8 *mcseq_msg;
static u8 *mcseq_msg2;
static int mcseq_pollcount;
static int pollcounter;
static int mcseq_extras;
static u8 *mcseq_extra[1];
static int mcseq_controller;
static int mcseq_user;
static int mcseq_action;
static u8 mcseq_filename[128];
static u8 *mcseq_buffer;
static int mcseq_length;
static int mcseq_seek;
static boolean mcseq_overwrite;
static int mcseq_result;
static int mcseq_statesuccess;
static int mcseq_statefailure;
static int pollcard;
static int mcseq_pollcards[8];
static int mcseq_cards[8];
static int mcseq_free[8];
static int mcseq_states[8];
static int mcseq_curcard;
static int availentries;
static int useclusters;
static menuitem_t mi_msgs[12];
static u8 slotnames[8][32];

u8* mcseqSlotMakeName(int cardnum) {
	static u8 mcseq_slotname[32];
	int port;
	int slot;
	int i;
}

u8* mcseqSlotGetLongName() {}

u8* mcseqSlotGetShortName() {
	int len;
}

static int mcseqTick() {
	int i;
	static u8 msg[128];
	int next;
	int numps2cards;
	int n;
	char filename[128];
	char dirname[128];
	int gamedir;
	char dirname[128];
	int gamedir;
}

static void mcseqWindowSet() {
	rect_t s;
}

static void mcseq_pageDraw(pagedef_t *page) {
	hitbox_t *box;
	int msg1h;
	int msg2h;
	s16 pos[2];
	rect_t s;
}

static void mcseq_pageTick(pagedef_t *page) {
	hitbox_t *box;
	menuitem_t *mi;
	s16 pos[2];
	int i;
	int drawcards[8];
	int numcards;
	int numoptions;
	int extra;
	int tw;
	int dw;
}

static void mcseqWindowOpen() {}

void mcseqWindowClose() {}

int mcseqGetRequiredSpace() {}

int mcseqGetResult() {}

int mcseqGetState() {}

void mcseqLoad(int num, u8 *title, u8 *titleact, u8 *filename, u8 *buffer, int length, int seekstart) {}

void mcseqSave(int num, u8 *title, u8 *titleact, u8 *filename, u8 *buffer, int length, int seekstart) {}

void mcseqController(int num) {}

void mcseqAddOption(u8 *text) {}

void mcseqPollLoop() {}

int mcseqPollCount() {}

void mcseqUnvalidateCards() {
	int i;
}

int mcseqGetCurCard() {}

void mcseqSetCurCard(int card) {}

int mcseqGetNumCards() {
	int i;
	int numcards;
}

void mcseqMake() {}

void mcseqMessage(int flags, char *line1, char *line2) {
	static u8 messageline1[256];
	static u8 messageline2[256];
}

u8* mcseqGetMsg(int msgnum) {
	u8 *msg;
}
