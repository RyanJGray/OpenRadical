// STATUS: NOT STARTED

#include "signon.h"

gamevar gv_autosave = {
	/* .value = */ 1,
	/* .min = */ 0,
	/* .max = */ 1,
	/* .flags = */ 0,
	/* .display = */ disp_yesno,
	/* .onChange = */ NULL,
	/* .suffix = */ NULL,
	/* .marginright = */ 0,
	/* .arrowleftofs = */ 0,
	/* .arrowrightofs = */ 0
};

signondata_t *signonarray = NULL;

signoninfo_t signoninfo[144] = {
	/* [0] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [1] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [2] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [3] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [4] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [5] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [6] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [7] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [8] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [9] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [10] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [11] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [12] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [13] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [14] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [15] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [16] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [17] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [18] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [19] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [20] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [21] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [22] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [23] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [24] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [25] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [26] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [27] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [28] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [29] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [30] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [31] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [32] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [33] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [34] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [35] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [36] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [37] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [38] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [39] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [40] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [41] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [42] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [43] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [44] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [45] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [46] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [47] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [48] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [49] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [50] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [51] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [52] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [53] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [54] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [55] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [56] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [57] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [58] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [59] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [60] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [61] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [62] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [63] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [64] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [65] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [66] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [67] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [68] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [69] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [70] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [71] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [72] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [73] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [74] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [75] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [76] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [77] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [78] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [79] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [80] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [81] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [82] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [83] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [84] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [85] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [86] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [87] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [88] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [89] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [90] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [91] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [92] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [93] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [94] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [95] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [96] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [97] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [98] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [99] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [100] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [101] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [102] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [103] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [104] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [105] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [106] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [107] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [108] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [109] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [110] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [111] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [112] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [113] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [114] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [115] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [116] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [117] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [118] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [119] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [120] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [121] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [122] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [123] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [124] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [125] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [126] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [127] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [128] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [129] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [130] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [131] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [132] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [133] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [134] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [135] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [136] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [137] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [138] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [139] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [140] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [141] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [142] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	},
	/* [143] = */ {
		/* .card = */ 0,
		/* .fileid = */ 0
	}
};

static int playersignon[16];
static gamestatus_t *curgamestatus;
static gamestatus_t multiplayer_gamestatus;

void playerprefsNew(playerprefs_t *pprefs) {}

void statsCombine(int numplayers) {
	int sonum;
	int p;
	int i;
	gamestatus_t *gst;
	levelstats_t *lvin;
	levelstats_t *lvout;
	int skill;
	challengestats_t *chin;
	challengestats_t *chout;
	int score;
	int bestscore;
}

gamestatus_t* statsGet() {}

gamestatus_t* statsGetPlayer(int playernum) {
	int sonum;
}

void statsDebug(gamestatus_t *status) {
	int i;
}

static void statsNew(gamestatus_t *gamestatus) {
	int i;
}

gamesettings_t* settingsGet() {
	int sonum;
}

static void settingsNew(gamesettings_t *gamesettings) {}

int signonFileGetFree(signondata_t *array) {
	int i;
}

int signonGetFree() {
	int i;
}

u32 signonMakeFileId() {
	int frame;
	u32 time;
}

int signonNew(u8 *signonname) {
	int i;
	signondata_t *so;
}

int signonFileGetName(signondata_t *array, u8 *name) {
	int i;
}

int signonGetName(u8 *name) {
	int i;
	int n;
}

void signonCheckSlot(gamefile1_t *sofile, int cardnum) {
	boolean done;
	int i;
	int n;
}

void signonAddFile(gamefile1_t *sofile, int cardnum) {
	int i;
	int j;
	int n;
	signondata_t *fso;
}

int signonFileCount(signondata_t *array) {
	int i;
}

void signonFileDelete(signondata_t *array, int signonnum) {}

int signonFileSize() {}

void signonDelete(int signonnum) {
	int i;
	int so;
}

int signonCount() {
	int i;
}

int signonMemCount() {
	int i;
	int count;
}

void signonSet(int playernum, int signonnum) {}

void signonMake() {
	int i;
}

void debugsignon() {
	int i;
}

int signonGet(int playernum) {}
