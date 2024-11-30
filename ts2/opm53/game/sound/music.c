// STATUS: NOT STARTED

#include "music.h"

typedef enum {
	MUSIC_OFF = 0,
	MUSIC_PAUSED = 1,
	MUSIC_RUNNING = 2
};

int tunenum = 0;

char *tunefilenames[34] = {
	/* [0] = */ NULL,
	/* [1] = */ 0x42abb8,
	/* [2] = */ 0x42ab90,
	/* [3] = */ 0x42ab60,
	/* [4] = */ 0x42ab38,
	/* [5] = */ 0x42ab18,
	/* [6] = */ 0x42aaf0,
	/* [7] = */ 0x42aac0,
	/* [8] = */ 0x42aaa0,
	/* [9] = */ 0x42aa80,
	/* [10] = */ 0x42aa58,
	/* [11] = */ 0x42aa30,
	/* [12] = */ 0x42aa08,
	/* [13] = */ 0x42a9e0,
	/* [14] = */ 0x42a9b8,
	/* [15] = */ 0x42a990,
	/* [16] = */ 0x42a968,
	/* [17] = */ 0x42a940,
	/* [18] = */ 0x42a918,
	/* [19] = */ 0x42a8f0,
	/* [20] = */ 0x42a8c8,
	/* [21] = */ 0x42a898,
	/* [22] = */ 0x42a868,
	/* [23] = */ 0x42a840,
	/* [24] = */ 0x42a818,
	/* [25] = */ 0x42a7e8,
	/* [26] = */ 0x42a7c0,
	/* [27] = */ 0x42a7a0,
	/* [28] = */ 0x42a778,
	/* [29] = */ 0x42a750,
	/* [30] = */ 0x42a728,
	/* [31] = */ 0x42a700,
	/* [32] = */ 0x42a6d8,
	/* [33] = */ 0x42a6b8
};

static int musicstate = 0;
static int musicopened = 0;

char streamFilename[64] = {
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
	/* [31] = */ 0,
	/* [32] = */ 0,
	/* [33] = */ 0,
	/* [34] = */ 0,
	/* [35] = */ 0,
	/* [36] = */ 0,
	/* [37] = */ 0,
	/* [38] = */ 0,
	/* [39] = */ 0,
	/* [40] = */ 0,
	/* [41] = */ 0,
	/* [42] = */ 0,
	/* [43] = */ 0,
	/* [44] = */ 0,
	/* [45] = */ 0,
	/* [46] = */ 0,
	/* [47] = */ 0,
	/* [48] = */ 0,
	/* [49] = */ 0,
	/* [50] = */ 0,
	/* [51] = */ 0,
	/* [52] = */ 0,
	/* [53] = */ 0,
	/* [54] = */ 0,
	/* [55] = */ 0,
	/* [56] = */ 0,
	/* [57] = */ 0,
	/* [58] = */ 0,
	/* [59] = */ 0,
	/* [60] = */ 0,
	/* [61] = */ 0,
	/* [62] = */ 0,
	/* [63] = */ 0
};

static void musicOpen(int tunenum) {}

static void musicClose() {}

static int musicGetState() {}

static void musicStart() {}

static void musicStop() {}

void musicPrintState() {}

int musicDefinitelyStopped() {}

static void musicStopClose() {}

void musicSetVol(int vol, int rightnow) {}

void musicSetFrontEndVolume() {
	int musicvol;
}

void musicMake() {}

void musicRestart() {}

void musicReset() {}

void musicEnd() {}

void musicTick() {
	static int destvol = 16383;
	static int curvol = 16383;
}

void musicSet(int tuneEnumValue) {}

void musicPause() {}

void musicResume() {}
