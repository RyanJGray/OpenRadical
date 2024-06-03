// STATUS: NOT STARTED

#include "ingame.h"

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	RANKINGS_SCORES = 0,
	RANKINGS_KILLS = 1,
	RANKINGS_LOSSES = 2,
	RANKINGS_NUMTYPES = 3
};

struct rankData_s {
	bubblesort_t table[58];
	bubblesort_t *rank[18];
	int numRank;
	int playerRank;
};

typedef rankData_s rankData;

struct igmplayer_s {
	mtx_u scrollMatrixDl;
	mtx_u tentacleMatrixDl;
	mtx_u scrollMatrixUcodeBuffer[2];
	mtx_u tentacleMatrixUcodeBuffer[2];
	mtx_u *scrollMatrixUcode;
	mtx_u *tentacleMatrixUcode;
	mtx_u barsMatrix;
	mtx_u perspectiveMatrix;
	int mnum;
	float frustrumHalfWidth;
	float frustrumHalfHeight;
	window_t window;
	int level;
	int oldLevel;
	int flags;
	float time;
	float worldpos[3];
	float startworldpos[3];
	float destworldpos[3];
	textSettings3D textSettings;
	float exitTime;
	float tentacleRotateTimeVertical;
	float tentacleRotateTimeHorizontal;
	float tentacleRotateAngleVertical;
	float tentacleRotateAngleHorizontal;
	float tentacleDirectionHorizontal;
	rankData rankings[3];
	pagedef_t *scrollPageIn;
	pagedef_t *scrollPageOut;
	float scrollTime;
	float scrollDurationX;
	float scrollDurationY;
	prop *inventoryProp;
	int inventoryPropItemID;
	int inventoryItemID;
	float inventoryItemTime;
	float inventoryScale;
	int numInventoryItems;
	int inventoryIDs[20];
	s8 *inventoryItemNames[20];
	boolean inventoryItemSelectable[20];
	int inventoryItemAmmo[20];
	int inventoryItemAmmoType[20];
	int inventoryItemAmmoSecondary[20];
	int inventoryItemAmmoTypeSecondary[20];
	int inventoryItemClipCount[20];
	playerprefs_t newprefs;
	int newcontrols[42];
	int tmpcontrols[42];
};

typedef igmplayer_s igmplayer_t;

struct igmparms_s {
	igmplayer_t plr[4];
};

typedef igmparms_s igmparms_t;

struct menufxTentacleNode_s {
	float pos[4];
	float points[8][4];
	float stq[8][3];
	float radius;
	float circlex[8];
	float circley[8];
	float axis1[3];
	float axis2[3];
};

typedef menufxTentacleNode_s menufxTentacleNode;

struct menufxTentacle_s {
	menufxTentacleNode nodes[10];
	float startpos[3];
	float endpos[3];
	float time;
	float noiseval0;
	float noiseval1;
	float noiseSpeed;
	float noiseOffset;
};

typedef menufxTentacle_s menufxTentacle;

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	PAGEBAR_ON = 0,
	PAGEBAR_OFF = 1,
	PAGEBAR_NA = 2
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_SETUPCONFIRM_TITLE = 0,
	IGM_SETUPCONFIRM_YES = 1,
	IGM_SETUPCONFIRM_NO = 2,
	IGM_SETUPCONFIRM_NUM = 3
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	GAME_AXIS_HORIZONTAL = 0,
	GAME_AXIS_VERTICAL = 1,
	GAME_AXIS_EITHER = 2
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_SETUP_TITLE = 0,
	IGM_SETUP_CONFIGURATION = 1,
	IGM_SETUP_VIEW = 2,
	IGM_SETUP_L1 = 3,
	IGM_SETUP_L2 = 4,
	IGM_SETUP_R1 = 5,
	IGM_SETUP_R2 = 6,
	IGM_SETUP_SQUARE = 7,
	IGM_SETUP_TRIANGLE = 8,
	IGM_SETUP_CIRCLE = 9,
	IGM_SETUP_CROSS = 10,
	IGM_SETUP_R3 = 11,
	IGM_SETUP_RIGHT_ANALOGUE = 12,
	IGM_SETUP_RIGHT_ANALOGUE_UPDOWN = 13,
	IGM_SETUP_RIGHT_ANALOGUE_LEFTRIGHT = 14,
	IGM_SETUP_L3 = 15,
	IGM_SETUP_LEFT_ANALOGUE = 16,
	IGM_SETUP_LEFT_ANALOGUE_UPDOWN = 17,
	IGM_SETUP_LEFT_ANALOGUE_LEFTRIGHT = 18,
	IGM_SETUP_DPAD = 19,
	IGM_SETUP_DPAD_UPDOWN = 20,
	IGM_SETUP_DPAD_LEFTRIGHT = 21,
	IGM_SETUP_ACCEPT = 22,
	IGM_SETUP_CANCEL = 23,
	IGM_SETUP_NUM = 24
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_PREFSACCEPT_TITLE = 0,
	IGM_PREFSACCEPT_YES = 1,
	IGM_PREFSACCEPT_NO = 2,
	IGM_PREFSACCEPT_NUM = 3
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_PREFS_TITLE = 0,
	IGM_PREFS_AUTOAIM = 1,
	IGM_PREFS_INVERSELOOK = 2,
	IGM_PREFS_AIMMODE = 3,
	IGM_PREFS_CROUCHMODE = 4,
	IGM_PREFS_AUTOLOOKAHEAD = 5,
	IGM_PREFS_WEAPONCHANGE = 6,
	IGM_PREFS_VIBRATION = 7,
	IGM_PREFS_VIBRATIONMODE = 8,
	IGM_PREFS_ACCEPT = 9,
	IGM_PREFS_CANCEL = 10,
	IGM_PREFS_NUM = 11
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_CONFIRMEND_TITLE = 0,
	IGM_CONFIRMEND_YES = 1,
	IGM_CONFIRMEND_NO = 2,
	IGM_CONFIRMEND_NUM = 3
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_CONFIRMRESTART_TITLE = 0,
	IGM_CONFIRMRESTART_YES = 1,
	IGM_CONFIRMRESTART_NO = 2,
	IGM_CONFIRMRESTART_NUM = 3
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_STATS_TITLE = 0,
	IGM_STATS_NUM = 1
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_AWARDS_TITLE = 0,
	IGM_AWARDS_NUM = 1
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_ENDGAME_TITLE = 0,
	IGM_ENDGAME_CONTINUERESTART = 1,
	IGM_ENDGAME_QUIT = 2,
	IGM_ENDGAME_NUM = 3
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_OPTIONS_TITLE = 0,
	IGM_OPTIONS_CONTINUE = 1,
	IGM_OPTIONS_SETUP = 2,
	IGM_OPTIONS_PREFERENCES = 3,
	IGM_OPTIONS_RESTART = 4,
	IGM_OPTIONS_QUIT = 5,
	IGM_OPTIONS_NUM = 6
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_SCORES_TITLE = 0,
	IGM_SCORES_NUM = 1
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_INVENTORY_TITLE = 0,
	IGM_INVENTORY_NUM = 1
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_STATUS_TITLE = 0,
	IGM_STATUS_NUM = 1
};

// warning: multiple differing types with the same name (#29,  not equal)
enum {
	IGM_BRIEFING_TITLE = 0,
	IGM_BRIEFING_NUM = 1
};

float igmDefaultYStart[0][6] = {
};

float igmDefaultYEnd[0][6] = {
};

float igmDefaultIconX[0][6] = {
};

menufxCurveData igmCurveData = {
	/* .circleposx = */ 0.f,
	/* .circleposy = */ 0.f,
	/* .circleradiusx = */ 0.55f,
	/* .circleradiusy = */ 0.55f,
	/* .circleoutlineradiusx = */ 0.65f,
	/* .circleoutlineradiusy = */ 0.65f,
	/* .circleSteps = */ 4,
	/* .extrapolationChange = */ 0.1f
};

menufxColorScheme menufxColors[3] = {
	/* [0] = */ {
		/* .titlefg = */ {
			/* [0] = */ 64,
			/* [1] = */ 127,
			/* [2] = */ 75,
			/* [3] = */ 0
		},
		/* .titlebg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .normalfg = */ {
			/* [0] = */ 45,
			/* [1] = */ 70,
			/* [2] = */ 45,
			/* [3] = */ 0
		},
		/* .normalbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .highlightedfg = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 0
		},
		/* .highlightedbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .disabledfg = */ {
			/* [0] = */ 20,
			/* [1] = */ 40,
			/* [2] = */ 20,
			/* [3] = */ 0
		},
		/* .disabledbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		},
		/* .normalarrow = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .highlightedarrow = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .selectedarrow = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .disabledarrow = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 127
		}
	},
	/* [1] = */ {
		/* .titlefg = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .titlebg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 64
		},
		/* .normalfg = */ {
			/* [0] = */ 100,
			/* [1] = */ 100,
			/* [2] = */ 100,
			/* [3] = */ 127
		},
		/* .normalbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 64
		},
		/* .highlightedfg = */ {
			/* [0] = */ 0,
			/* [1] = */ 120,
			/* [2] = */ 120,
			/* [3] = */ 127
		},
		/* .highlightedbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 80,
			/* [3] = */ 127
		},
		/* .disabledfg = */ {
			/* [0] = */ 60,
			/* [1] = */ 60,
			/* [2] = */ 60,
			/* [3] = */ 60
		},
		/* .disabledbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 64
		},
		/* .normalarrow = */ {
			/* [0] = */ 30,
			/* [1] = */ 45,
			/* [2] = */ 70,
			/* [3] = */ 70
		},
		/* .highlightedarrow = */ {
			/* [0] = */ 45,
			/* [1] = */ 75,
			/* [2] = */ 105,
			/* [3] = */ 127
		},
		/* .selectedarrow = */ {
			/* [0] = */ 105,
			/* [1] = */ 115,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .disabledarrow = */ {
			/* [0] = */ 30,
			/* [1] = */ 40,
			/* [2] = */ 50,
			/* [3] = */ 55
		}
	},
	/* [2] = */ {
		/* .titlefg = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .titlebg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 64
		},
		/* .normalfg = */ {
			/* [0] = */ 100,
			/* [1] = */ 100,
			/* [2] = */ 100,
			/* [3] = */ 127
		},
		/* .normalbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 64
		},
		/* .highlightedfg = */ {
			/* [0] = */ 0,
			/* [1] = */ 120,
			/* [2] = */ 120,
			/* [3] = */ 127
		},
		/* .highlightedbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 80,
			/* [3] = */ 127
		},
		/* .disabledfg = */ {
			/* [0] = */ 60,
			/* [1] = */ 80,
			/* [2] = */ 100,
			/* [3] = */ 127
		},
		/* .disabledbg = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 64
		},
		/* .normalarrow = */ {
			/* [0] = */ 30,
			/* [1] = */ 45,
			/* [2] = */ 70,
			/* [3] = */ 70
		},
		/* .highlightedarrow = */ {
			/* [0] = */ 45,
			/* [1] = */ 75,
			/* [2] = */ 105,
			/* [3] = */ 127
		},
		/* .selectedarrow = */ {
			/* [0] = */ 105,
			/* [1] = */ 115,
			/* [2] = */ 127,
			/* [3] = */ 127
		},
		/* .disabledarrow = */ {
			/* [0] = */ 0,
			/* [1] = */ 0,
			/* [2] = */ 0,
			/* [3] = */ 0
		}
	}
};

boolean tentaclesSetup = 0;
boolean tentaclesTicked = 0;

static float menueyepos[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

static float menulookat[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ -1.f
};

static float menuup[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 1.f,
	/* [2] = */ 0.f
};

static float startmenueyepos[3] = {
	/* [0] = */ -3.75f,
	/* [1] = */ 0.3f,
	/* [2] = */ 0.f
};

static float startmenulookat[3] = {
	/* [0] = */ 0.15f,
	/* [1] = */ 0.f,
	/* [2] = */ -1.f
};

static float startmenuup[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.5f,
	/* [2] = */ -0.5f
};

static int setup_controlNames[42] = {
	/* [0] = */ 1186,
	/* [1] = */ 1187,
	/* [2] = */ 1190,
	/* [3] = */ 1188,
	/* [4] = */ 1182,
	/* [5] = */ 1189,
	/* [6] = */ 1194,
	/* [7] = */ 1195,
	/* [8] = */ 1196,
	/* [9] = */ 1197,
	/* [10] = */ 1198,
	/* [11] = */ 1199,
	/* [12] = */ 1200,
	/* [13] = */ 1201,
	/* [14] = */ 1183,
	/* [15] = */ 1184,
	/* [16] = */ 1191,
	/* [17] = */ 1192,
	/* [18] = */ 1194,
	/* [19] = */ 1195,
	/* [20] = */ 1196,
	/* [21] = */ 1197,
	/* [22] = */ 1198,
	/* [23] = */ 1199,
	/* [24] = */ 1200,
	/* [25] = */ 1201,
	/* [26] = */ 1183,
	/* [27] = */ 1184,
	/* [28] = */ 1191,
	/* [29] = */ 1192,
	/* [30] = */ 1174,
	/* [31] = */ 1176,
	/* [32] = */ 1177,
	/* [33] = */ 1175,
	/* [34] = */ 1193,
	/* [35] = */ 1185,
	/* [36] = */ 1174,
	/* [37] = */ 1176,
	/* [38] = */ 1177,
	/* [39] = */ 1175,
	/* [40] = */ 1193,
	/* [41] = */ 1185
};

static pageinit_t setupconfirm_page = {
	/* .tick = */ setupconfirm_pageTick,
	/* .draw_before = */ setupconfirm_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ setupconfirm_pageConstruct
};

static int gameControlsToButtonOption[42] = {
	/* [0] = */ 1,
	/* [1] = */ 2,
	/* [2] = */ 3,
	/* [3] = */ 4,
	/* [4] = */ 5,
	/* [5] = */ 8,
	/* [6] = */ 11,
	/* [7] = */ 12,
	/* [8] = */ 13,
	/* [9] = */ 14,
	/* [10] = */ 15,
	/* [11] = */ 16,
	/* [12] = */ 17,
	/* [13] = */ 18,
	/* [14] = */ 6,
	/* [15] = */ 7,
	/* [16] = */ 9,
	/* [17] = */ 10,
	/* [18] = */ -1,
	/* [19] = */ -1,
	/* [20] = */ -1,
	/* [21] = */ -1,
	/* [22] = */ -1,
	/* [23] = */ -1,
	/* [24] = */ -1,
	/* [25] = */ -1,
	/* [26] = */ -1,
	/* [27] = */ -1,
	/* [28] = */ -1,
	/* [29] = */ -1,
	/* [30] = */ -1,
	/* [31] = */ -1,
	/* [32] = */ -1,
	/* [33] = */ -1,
	/* [34] = */ -1,
	/* [35] = */ -1,
	/* [36] = */ -1,
	/* [37] = */ -1,
	/* [38] = */ -1,
	/* [39] = */ -1,
	/* [40] = */ -1,
	/* [41] = */ -1
};

static int gameControlsToAxisOption[42][3] = {
	/* [0] = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [1] = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [2] = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [3] = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [4] = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [5] = */ {
		/* [0] = */ -1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [6] = */ {
		/* [0] = */ 1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [7] = */ {
		/* [0] = */ 1,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [8] = */ {
		/* [0] = */ 3,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [9] = */ {
		/* [0] = */ 3,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [10] = */ {
		/* [0] = */ 2,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [11] = */ {
		/* [0] = */ 2,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [12] = */ {
		/* [0] = */ 4,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [13] = */ {
		/* [0] = */ 4,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [14] = */ {
		/* [0] = */ 6,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [15] = */ {
		/* [0] = */ 6,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [16] = */ {
		/* [0] = */ 5,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [17] = */ {
		/* [0] = */ 5,
		/* [1] = */ -1,
		/* [2] = */ -1
	},
	/* [18] = */ {
		/* [0] = */ -1,
		/* [1] = */ 1,
		/* [2] = */ -1
	},
	/* [19] = */ {
		/* [0] = */ -1,
		/* [1] = */ 1,
		/* [2] = */ -1
	},
	/* [20] = */ {
		/* [0] = */ -1,
		/* [1] = */ 3,
		/* [2] = */ -1
	},
	/* [21] = */ {
		/* [0] = */ -1,
		/* [1] = */ 3,
		/* [2] = */ -1
	},
	/* [22] = */ {
		/* [0] = */ -1,
		/* [1] = */ 2,
		/* [2] = */ -1
	},
	/* [23] = */ {
		/* [0] = */ -1,
		/* [1] = */ 2,
		/* [2] = */ -1
	},
	/* [24] = */ {
		/* [0] = */ -1,
		/* [1] = */ 4,
		/* [2] = */ -1
	},
	/* [25] = */ {
		/* [0] = */ -1,
		/* [1] = */ 4,
		/* [2] = */ -1
	},
	/* [26] = */ {
		/* [0] = */ -1,
		/* [1] = */ 6,
		/* [2] = */ -1
	},
	/* [27] = */ {
		/* [0] = */ -1,
		/* [1] = */ 6,
		/* [2] = */ -1
	},
	/* [28] = */ {
		/* [0] = */ -1,
		/* [1] = */ 5,
		/* [2] = */ -1
	},
	/* [29] = */ {
		/* [0] = */ -1,
		/* [1] = */ 5,
		/* [2] = */ -1
	},
	/* [30] = */ {
		/* [0] = */ 1,
		/* [1] = */ -1,
		/* [2] = */ 1
	},
	/* [31] = */ {
		/* [0] = */ 2,
		/* [1] = */ -1,
		/* [2] = */ 0
	},
	/* [32] = */ {
		/* [0] = */ 4,
		/* [1] = */ -1,
		/* [2] = */ 1
	},
	/* [33] = */ {
		/* [0] = */ 3,
		/* [1] = */ -1,
		/* [2] = */ 0
	},
	/* [34] = */ {
		/* [0] = */ 5,
		/* [1] = */ -1,
		/* [2] = */ 2
	},
	/* [35] = */ {
		/* [0] = */ 6,
		/* [1] = */ -1,
		/* [2] = */ 2
	},
	/* [36] = */ {
		/* [0] = */ -1,
		/* [1] = */ 1,
		/* [2] = */ 1
	},
	/* [37] = */ {
		/* [0] = */ -1,
		/* [1] = */ 2,
		/* [2] = */ 0
	},
	/* [38] = */ {
		/* [0] = */ -1,
		/* [1] = */ 4,
		/* [2] = */ 1
	},
	/* [39] = */ {
		/* [0] = */ -1,
		/* [1] = */ 3,
		/* [2] = */ 0
	},
	/* [40] = */ {
		/* [0] = */ -1,
		/* [1] = */ 5,
		/* [2] = */ 2
	},
	/* [41] = */ {
		/* [0] = */ -1,
		/* [1] = */ 6,
		/* [2] = */ 2
	}
};

static pageinit_t setup_page = {
	/* .tick = */ setup_pageTick,
	/* .draw_before = */ setup_pageGfx,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ setup_pageConstruct
};

static pageinit_t prefsaccept_page = {
	/* .tick = */ prefsaccept_pageTick,
	/* .draw_before = */ prefsaccept_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ prefsaccept_pageConstruct
};

static pageinit_t prefs_page = {
	/* .tick = */ prefs_pageTick,
	/* .draw_before = */ prefs_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ prefs_pageConstruct
};

static pageinit_t confirmendgame_page = {
	/* .tick = */ confirmendgame_pageTick,
	/* .draw_before = */ confirmendgame_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ confirmendgame_pageConstruct
};

static pageinit_t confirmrestartgame_page = {
	/* .tick = */ confirmrestartgame_pageTick,
	/* .draw_before = */ confirmrestartgame_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ confirmrestartgame_pageConstruct
};

static pageinit_t stats_page = {
	/* .tick = */ stats_pageTick,
	/* .draw_before = */ stats_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ stats_pageConstruct
};

static pageinit_t awards_page = {
	/* .tick = */ awards_pageTick,
	/* .draw_before = */ awards_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ awards_pageConstruct
};

static pageinit_t endgame_page = {
	/* .tick = */ endgame_pageTick,
	/* .draw_before = */ endgame_pageGfx,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ endgame_pageConstruct
};

static pageinit_t options_page = {
	/* .tick = */ options_pageTick,
	/* .draw_before = */ options_pageGfx,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ options_pageConstruct
};

static pageinit_t pause_page = {
	/* .tick = */ pause_pageTick,
	/* .draw_before = */ pause_pageGfx,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ pause_pageConstruct
};

static pageinit_t scores_page = {
	/* .tick = */ scores_pageTick,
	/* .draw_before = */ scores_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ scores_pageConstruct
};

static pageinit_t inventory_page = {
	/* .tick = */ inventory_pageTick,
	/* .draw_before = */ inventory_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ inventory_pageConstruct
};

static pageinit_t status_page = {
	/* .tick = */ status_pageTick,
	/* .draw_before = */ status_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ status_pageConstruct
};

static pageinit_t briefing_page = {
	/* .tick = */ briefing_pageTick,
	/* .draw_before = */ briefing_pageGfx,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ briefing_pageConstruct
};

static igmparms_t igmparms;
static int pauseplayer;

menufxTentacle igmTentacles[17] = {
	/* [0] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [1] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [2] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [3] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [4] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [5] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [6] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [7] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [8] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [9] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [10] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [11] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [12] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [13] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [14] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [15] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	},
	/* [16] = */ {
		/* .nodes = */ {
			/* [0] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [1] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [2] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [3] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [4] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [5] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [6] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [7] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [8] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			},
			/* [9] = */ {
				/* .pos = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f
				},
				/* .points = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f,
						/* [3] = */ 0.f
					}
				},
				/* .stq = */ {
					/* [0] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [1] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [2] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [3] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [4] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [5] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [6] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					},
					/* [7] = */ {
						/* [0] = */ 0.f,
						/* [1] = */ 0.f,
						/* [2] = */ 0.f
					}
				},
				/* .radius = */ 0.f,
				/* .circlex = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .circley = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f,
					/* [3] = */ 0.f,
					/* [4] = */ 0.f,
					/* [5] = */ 0.f,
					/* [6] = */ 0.f,
					/* [7] = */ 0.f
				},
				/* .axis1 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .axis2 = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				}
			}
		},
		/* .startpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .endpos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .time = */ 0.f,
		/* .noiseval0 = */ 0.f,
		/* .noiseval1 = */ 0.f,
		/* .noiseSpeed = */ 0.f,
		/* .noiseOffset = */ 0.f
	}
};

float igmGetLevelOutTime() {}

boolean igmShouldShowScores() {}

boolean igmShouldShowStatus() {}

boolean igmShouldShowBriefing() {}

boolean igmShouldShowAwards() {}

boolean igmShouldShowStats() {}

boolean igmShouldShowInventory() {}

int ingamemenuIsActive(int playernum) {}

static pageinit_t* igmGetPageLeft(pagedef_t *page) {}

static pageinit_t* igmGetPageRight(pagedef_t *page) {}

static pageinit_t* igmGetPageLeftFromInit(pageinit_t *init) {
	igmplayer_t *igm;
}

static pageinit_t* igmGetPageRightFromInit(pageinit_t *init) {}

void menufxSetupTentacles() {
	int t;
	float startpos[3];
	int n;
	float offset[3];
	menufxTentacleNode *node;
	float scalar;
	int p;
	float angle;
	float pScalar;
}

void menufxUnSetupTentacles() {}

void menufxTentacleSetPos(menufxTentacle *tentacle, menufxTentacleNode *node, float scalar) {
	float basicpos[3];
	float dir[3];
	float ndir[3];
	float noise1;
	float noise2;
	float up[3];
	float curve;
	float dampening;
	float frac;
}

void menufxTentacleTick(menufxTentacle *tentacle) {
	float timeIntro;
	float timeClamp;
	int n;
	menufxTentacleNode *node;
	int p;
}

void menufxTentaclesTick() {}

void menufxDrawTentacleGlow(menufxTentacle *tentacle, int index) {
	igmplayer_t *igm;
	float startposTrans[4];
	float startq;
	float dir[2];
	int n;
	float zfloat;
	int zval;
	float nstartscalar;
	float nendscalar;
	float endposTrans[4];
	float startpos3extended;
	float endpos3extended;
	float invlen;
	float nextdir[2];
	float posTL[2];
	float posBL[2];
	float posTR[2];
	float posBR[2];
	float width;
	float endq;
	float startintensity;
	float endintensity;
	u32 abgrStart;
	u32 abgrEnd;
	u32 *ref;
	void *addr;
}

void menufxDrawTentacle(menufxTentacle *tentacle) {
	int n;
	int texture;
	int localplayers;
	int stripPoints;
	int quadWordSize;
	menufxTentacleNode *curnode;
	menufxTentacleNode *nextnode;
	int p;
	u32 *ref;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
}

void menufxDrawTentacles() {
	igmplayer_t *igm;
	float time;
	int t;
	void *addr;
}

float menufxGeometryGetXFromCircleLH(float y, float xcirclepos, float ycirclepos, float radiusx, float radiusy) {
	float radiussq;
	float ydiff;
	float ydiffsq;
	float xRelative;
}

float menufxGeometryGetXFromCircleRH(float y, float xcirclepos, float ycirclepos, float radiusx, float radiusy) {
	float radiussq;
	float ydiff;
	float ydiffsq;
}

void menufxGeometryGetSurfacePos(float *combinedpos, menufxGeometrySurface *surface, float s, float t, float *posOrigin) {
	float pos0[3];
	float pos1[3];
	float pos2[3];
	float pos3[3];
	float pos0Rel[3];
	float pos1Rel[3];
	float pos2Rel[3];
	float pos3Rel[3];
	float sInv;
	float tInv;
	float scalar;
	menufxGeometryEdge *edge;
	float diff[3];
	float diff[3];
	float diff[3];
	float diff[3];
}

void menufxGeometryGetNormal(float *normal, menufxGeometrySurface *surface, float s, float t) {
	float sInv;
	float tInv;
	float *n0;
	float *n1;
	float *n2;
	float *n3;
}

void menufxGeometryRenderSurface(menufxGeometrySurface *surface, u32 rgba, int texture) {
	int tcount;
	int stepsS;
	int stepsT;
	float changeS;
	float changeT;
	float sStep;
	float tStep;
	float combinedpos0[3];
	float combinedpos1[3];
	float combinedpos2[3];
	float combinedpos3[3];
	float texco0[3];
	float texco1[3];
	float texco2[3];
	float texco3[3];
	float *posOrigin;
	float t;
	u32 *ref;
	u32 col;
	int num;
	emTexture *pTex;
	void *addr;
	void *addr;
}

void menufxConstructBarGeometry(menufxGeometryBar *bar, boolean leftCurve, boolean rightCurve, menufxGeometryPoint *topLeftCP, menufxGeometryPoint *topLeft, menufxGeometryPoint *bottomLeft, menufxGeometryPoint *bottomLeftCP, int stepsLeft, menufxGeometryPoint *topRightCP, menufxGeometryPoint *topRight, menufxGeometryPoint *bottomRight, menufxGeometryPoint *bottomRightCP, int stepsRight) {
	menufxGeometryPoint *topRight;
	menufxGeometryPoint *bottomRight;
	float topLeftX;
	float bottomLeftX;
	float topRightX;
	float bottomRightX;
	float nearz;
	float farz;
}

u32 menufxChangeAlpha(u32 color, float multiplier) {}

void menufxRenderGeometryBar(menufxGeometryBar *bar) {
	igmplayer_t *igm;
	float time;
	float timescalar;
	int e;
	u32 rgbaTexture;
	void *addr;
}

void menufxGeometryBarTick(igmplayer_t *igm, pagedef_t *page, menufxItem *mi, int menuitemflags, float highlighttime, float bartime) {
	menufxGeometryBar *bar;
	float noise;
	mtx_u transposemtx;
	float scalartime;
	float scalartimeClamp;
	float degreeRotate;
	float moveAmount;
	float centrepos[3];
	float moveDist;
	float forwardTime;
	float backTime;
	float distance;
	float time;
	float time;
	float zmiddle;
	float time;
	float timeClamp;
	float timescalar;
	float angle;
	menufxCurveData *cdata;
	float rotateposx;
}

void menufxDrawBarIcon(pagedef_t *page, menufxItem *mi, int order) {
	igmplayer_t *igm;
	float texttime;
	float textscalar;
	float textscalarclamp;
	u32 alpha;
	u32 rgba;
	u32 abgr;
	float pos[3];
	float pos1[3];
	float pos2[3];
	float pos3[3];
	float pos4[3];
	float size;
	float halfsize;
	float timeHighlightedScalar;
	float timeHighlightedExp;
	void *addr;
}

void menufxItemDrawBarText(pagedef_t *page, menufxItem *mi, int order) {
	igmplayer_t *igm;
	float texttime;
	float textscalar;
	float textscalarclamp;
	float textPos[2];
	int alpha;
	textfx fx;
	u32 textfg;
	menufxColorScheme *scheme;
	float alphachange;
	u32 *col;
	u32 *col;
	u32 *col;
}

void menufxItemDrawText(pagedef_t *page, menufxItem *mi, float alphaScalar) {
	igmplayer_t *igm;
	int textfg;
	int textbg;
	menufxColorScheme *scheme;
	int x;
	int y;
	u32 *bgcol;
	u32 *fgcol;
	u32 *bgcol;
	u32 *fgcol;
	u32 *bgcol;
	u32 *fgcol;
	u32 *bgcol;
	u32 *fgcol;
	u32 *bgcol;
	int arrowSize;
	int textx;
	int leftarrowx;
	int rightarrowx;
	int arrowBottom;
	u32 *colleft;
	u32 *colright;
	int arrowcolleft;
	menufxItemOption *option;
	float timeScalar;
}

void menufxItemReset(menufxItem *mi) {}

void menufxItemTick(pagedef_t *page, menufxItem *mi) {
	igmplayer_t *igm;
	int o;
	menufxItemOption *option;
}

int menufxItemGetWidth(menufxItem *mi) {}

int menufxItemGetHeight(menufxItem *mi) {
	int height;
}

menufxItem* pageGetSwitchedItem(pagedef_t *page, int itemIndex) {}

void menufxHighlightItem(pagedef_t *page, int itemIndex) {}

void menufxSetupStraightBars(pagedef_t *page) {
	int b;
}

void menufxSetupBarsWithCircularControlPoints(pagedef_t *page) {
	float *pos;
	float y;
	int b;
	menufxCurveData *cdata;
	menufxControlPointSet *cps;
	int count;
	int firstBarItem;
	int lastBarItem;
}

static void ingamemenuPageReady(pagedef_t *page, int defaultItem) {
	igmplayer_t *igm;
	int b;
	float offset;
	int s;
}

void igmUpdateMatrices(igmplayer_t *igm) {
	mtx_u tmpmtx;
	float eyepos[3];
	float lookat[3];
	float up[3];
	float moveTime;
	float diffeyepos[3];
	float difflookat[3];
	float diffup[3];
	float frac;
	float timeScalarVertical;
	float timeScalarHorizontal;
	float timeClampVertical;
	float timeClampHorizontal;
	float angleChangeVertical;
	float angleChangeHorizontal;
	float aspect;
	float windowRatio;
}

static void igmPageOut(pagedef_t *page) {
	igmplayer_t *igm;
}

static void igmPageIn(pagedef_t *page) {
	int s;
	int o;
}

static pagedef_t* igmPageNew(pageinit_t *pageinit) {
	pagedef_t *page;
}

static boolean igmCanChangePage(pageinit_t *pageinit) {
	igmplayer_t *igm;
}

static void igmPageDown(pageinit_t *pageinit) {
	igmplayer_t *igm;
	pagedef_t *newpage;
}

static void igmPageDownNoLevel(pageinit_t *pageinit) {
	igmplayer_t *igm;
}

static void igmPageUp(pageinit_t *pageinit) {
	igmplayer_t *igm;
	pagedef_t *newpage;
}

static void igmPageUpNoLevel(pageinit_t *pageinit) {
	igmplayer_t *igm;
}

static void igmPageLeft(pageinit_t *pageinit) {
	igmplayer_t *igm;
	pagedef_t *newpage;
}

static void igmPageRight(pageinit_t *pageinit) {
	igmplayer_t *igm;
	pagedef_t *newpage;
}

static void igmTopScrollLeft(pagedef_t *page) {}

static void igmTopScrollRight(pagedef_t *page) {}

int ingamemenuShouldRenderGame(int player) {
	igmplayer_t *igm;
}

static void ingamemenuFocus(pagedef_t *page) {
	float diffX;
	float diffY;
	igmplayer_t *igm;
}

static void ingamemenuResetScroll(int playernum) {
	igmplayer_t *igm;
}

void igmRemovalCheck(pagedef_t *page) {
	igmplayer_t *igm;
}

void ingamemenuTickBefore() {
	int i;
}

void ingamemenuTickPlayerBefore() {
	igmplayer_t *igm;
	float secpassed;
	float scrollScalarX;
	float scrollClampX;
	float scrollScalarY;
	float scrollClampY;
	float scalar;
	float pixels;
	int topBarHeight;
}

float igmGetSwitchScalar(pagedef_t *page, int itemID, int switchValue) {}

static void ingamemenuPageTick(pagedef_t *page) {
	float diffy;
	int oldItem;
	float pos[3];
	float newpos[4];
	float q;
	int e;
	igmplayer_t *igm;
	float showy;
	menufxItem *mi;
	int oldOption;
	menufxItem *mi;
	int oldOption;
}

void ingamemenuTickPlayerAfter() {
	igmplayer_t *igm;
}

static void igmDrawPostEffects() {
	igmplayer_t *igm;
	float fadeIntensity;
	u32 rgba;
	float time;
}

static void igmDrawBackground() {
	float time;
	float timeadj;
	int texture;
}

void ingamemenuGfxPlayerBefore() {
	igmplayer_t *igm;
}

static float igmGetGuiTimeScalar() {
	igmplayer_t *igm;
	float guitime;
}

static void igmTopArrowGfx(pagedef_t *page) {
	igmplayer_t *igm;
	u32 rgba;
	int texture;
	int xsize;
	int ysize;
	int halfxsize;
	int halfysize;
	int y;
	int x;
	int x;
}

static void igmScrollUpDownArrowGfx(pagedef_t *page) {
	int x1;
	int x2;
	int y1;
	int arrowSize;
}

static void igmButtonBackGfx(pagedef_t *page, u32 alpha) {
	igmplayer_t *igm;
	int x;
	int yButton;
	int yText;
	u8 *s;
	int width;
	int xButton;
}

static void igmButtonSelectGfx(pagedef_t *page, u32 alpha) {
	int x;
	int yButton;
	int yText;
	u8 *s;
	int width;
	int xButton;
}

static void igmButtonLeftRightGfx(pagedef_t *page, u32 alphaOn, u32 alphaOff) {
	int x;
	int yDPad;
	int yText;
	u8 *s;
}

static void igmButtonUpDownGfx(pagedef_t *page, u32 alphaOn, u32 alphaOff) {
	int x;
	int yDPad;
	int yText;
	u8 *s;
}

static void igmPageBarGfx(pagedef_t *page) {
	u32 rgbaOn;
	u32 rgbaOff;
	int texture;
	int texwidth;
	int texheight;
	int p;
	int availableSpaceX;
	int y;
	int sizex;
	int sizey;
	int state[6];
	int valid;
	int count;
	int x;
}

static float overlayScale(pagedef_t *page) {
	igmplayer_t *igm;
	float moveTime;
	float moveTimeClamp;
}

static void ingamemenuPageGfx(pagedef_t *page) {
	int s;
	int o;
	igmplayer_t *igm;
	menufxItem *mi;
}

void ingamemenuGfxPlayerAfter() {
	igmplayer_t *igm;
	u8 *s;
}

void ingamemenuPreload() {}

void ingamemenuRestart() {}

void ingamemenuReset() {}

void ingamemenuEnd() {}

static void ingamemenuRoot(int playernum) {
	igmplayer_t *igm;
}

void ingamemenuActivate(int playernum) {}

void ingamemenuSelect(int playernum) {}

static void ingamemenuWait(int playernum) {}

void ingamemenuPause(int playernum) {
	int p;
}

void ingamemenuEndScreen(int playernum) {}

static void ingamemenuClear(int playernum) {
	igmplayer_t *igm;
}

void ingamemenuExit(int playernum) {
	int oldfront;
}

void ingamemenuCheckUnpause() {
	int i;
	int numunpaused;
}

static void ingamemenuPreventChanges() {
	int i;
}

static void igmPageDarkenGfx(pagedef_t *page, float startScalar, float endScalar, float fadeScalar, u32 darkenAlpha) {}

static void overlayDarkenSegment(pagedef_t *page, float startScalar, u32 startAlpha, float endScalar, u32 endAlpha, int texwidth, int texheight) {
	float scale;
	float normalHalfWidth;
	float normalHalfHeight;
	float mx;
	float my;
	float sy;
	float ey;
	float darkenHalfWidth;
	float darkensx;
	float darkenex;
	int texYStart;
	int texYEnd;
	u32 abgrStart;
	u32 abgrEnd;
}

static void overlayDarkenSplit(pagedef_t *page, float startScalar, u32 startAlpha, float endScalar, u32 endAlpha, int texwidth, int texheight) {
	float scalarDiff;
	float t;
	u32 alphaDiff;
	u32 midAlpha;
}

static void overlayDarkenGfx(pagedef_t *page, float startScalar, float endScalar, float fadeScalar, u32 darkenAlpha) {
	int texture;
	int texwidth;
	int texheight;
	float fadeInScalar;
	float fadeOutScalar;
}

void objectiveMessage(objective *obj, int xLeft, int yDesc, int xRight, int yState, int alpha, boolean ingamemenu) {
	u32 textcol;
	u32 fgcol;
	u32 bgcol;
	u8 *s;
	int c1;
	int c2;
	int xMid;
	u8 *s2;
}

static void igmCalculateRankings(rankData *rankings, int type) {
	chrdata *mychr;
	int i;
	u8 teamdone[59];
	int t;
	int i;
	int n;
	chrdata *chr;
	int i;
	int k;
}

static void igmRankingsTableTick(pagedef_t *page, int type) {
	igmplayer_t *igm;
	rankData *rankings;
	int textSpacing;
	int windowHeight;
	int xLeft;
	int xRight;
	int yTop;
	int yBottom;
	int freespace;
}

static void igmRankingsTableGfx(pagedef_t *page, int type) {
	igmplayer_t *igm;
	rankData *rankings;
	int i;
	chrdata *mychr;
	int x1;
	int x2;
	int y1;
	int textSpacing;
	chrdata *chr;
	u32 fgcol;
	u32 bgcol;
	u8 *s;
	int k;
}

static int setup_getMissingControls(boolean *missingTable) {
	igmplayer_t *igm;
	int count;
	int gc;
}

void setupconfirm_setControls() {
	igmplayer_t *igm;
}

void setupconfirm_pageAccept(pagedef_t *page) {}

void setupconfirm_pageReject(pagedef_t *page) {}

void setupconfirm_pageCancel(pagedef_t *page) {}

static void setupconfirm_pageGfx(pagedef_t *page) {
	igmplayer_t *igm;
	boolean missingTable[42];
	int items;
	int xCentre;
	int y;
	int gap;
	int biggap;
	int gc;
	u8 *s;
}

static void setupconfirm_pageConstruct(pagedef_t *page) {
	igmplayer_t *igm;
	int xCentre;
	int y;
	menufxItem *mi;
	boolean missingControls[42];
}

static void setupconfirm_pageTick(pagedef_t *page) {}

static void setup_setNewControls() {
	igmplayer_t *igm;
}

static boolean setup_anyChanges() {
	igmplayer_t *igm;
}

static void setup_pageAccept(pagedef_t *page) {
	igmplayer_t *igm;
	boolean missingControls[42];
}

static void setup_pageCancel(pagedef_t *page) {}

static void setup_pageBack(pagedef_t *page) {}

static void menufxItemSetupButtonControlOptions(menufxItem *mi, int x, int y) {
	int gc;
	int o;
}

static void menufxItemSetupAxisControlOptions(menufxItem *mi, int switchItem, int x, int y, int axisType) {
	int o;
	int gc;
}

static void setup_setControl(pagedef_t *page, int itemID, int joyB) {
	igmplayer_t *igm;
	int gc;
}

static void setup_setAxis(pagedef_t *page, int itemID, int itemSwitch, int joyAxis) {
	igmplayer_t *igm;
	int gc;
}

static void setup_setDPad(pagedef_t *page, int itemID, int itemSwitch, int joyB1, int joyB2) {
	igmplayer_t *igm;
	int alert;
	int b1;
	int b2;
}

static void setup_setSwitchAimControl(pagedef_t *page) {
	igmplayer_t *igm;
}

static void setup_setControls(pagedef_t *page) {
	int item;
}

static void setup_configonchange(pagedef_t *page, menufxItem *mi, int oldvalue) {
	igmplayer_t *igm;
}

static void igmClearControlAutomaticChanges(int playernum) {
	igmplayer_t *igm;
}

static void setup_processAutoChange(pagedef_t *page, menufxItem *mi) {
	igmplayer_t *igm;
	int gc;
}

static boolean setup_doesGameAxisConflictWithGameControl(int gcaxis, int gc) {}

static void setup_getControl(pagedef_t *page, int itemID, int joyB, int oldvalue) {
	igmplayer_t *igm;
	int gc;
	int axisgc;
	int currentOption;
}

static void setup_getAxis(pagedef_t *page, int itemID, int itemSwitch, int joyAxis, int oldvalue) {
	igmplayer_t *igm;
	int gc;
	int axisgc;
	int currentOption;
}

static void setup_getDPad(pagedef_t *page, int itemID, int switchItem, int joyBut1, int joyBut2, int oldvalue) {
	igmplayer_t *igm;
	int gc;
	int axisgc;
	int count;
	int currentOption;
}

static void setup_onChange(pagedef_t *page, menufxItem *mi, int oldvalue) {
	igmplayer_t *igm;
	int s;
}

static void setup_aimControlsToggle(pagedef_t *page, menufxItem *mi, int oldvalue) {
	int oldSwitch;
	int currentSwitch;
	int item;
}

static void setup_pagePrepare() {
	igmplayer_t *igm;
}

static void setup_pageConstruct(pagedef_t *page) {
	igmplayer_t *igm;
	int xLeft;
	int xRight;
	int xControlLeft;
	int xControlRight;
	int y;
	int s;
	int o;
	menufxItem *mi;
}

static void setup_pageGfx(pagedef_t *page) {
	int xCentre;
	int yCentre;
	int s;
	u32 arrowcol;
	int arrowSize;
	int x1;
	int x2;
	int y1;
	int texture;
	int l;
	int itemID;
	float alphaScalar;
	menufxItem *mi;
	int x;
	int y;
	int height;
	u32 *col;
	u32 rgba;
	int bracketX;
	int bracketStartY[6];
	int bracketEndY[6];
	int joinx[6];
	int joiny[6];
	int endx[6];
	int endy[6];
	int l;
	int startIndex;
	int yChange;
	menufxItem *mi;
	float alphaScalar;
	u32 rgba;
}

static void setup_pageTick(pagedef_t *page) {
	igmplayer_t *igm;
	float scrollWindowHeight;
}

static void prefsaccept_pageAccept(pagedef_t *page) {
	igmplayer_t *igm;
}

void prefsaccept_pageReject(pagedef_t *page) {}

static void prefsaccept_pageGfx(pagedef_t *page) {}

static void prefsaccept_pageConstruct(pagedef_t *page) {
	int xCentre;
	int y;
	menufxItem *mi;
}

static void prefsaccept_pageTick(pagedef_t *page) {}

static void prefs_setMenuOptions(pagedef_t *page) {
	igmplayer_t *igm;
	int controlflags;
}

static void prefs_getMenuOptions(pagedef_t *page) {
	igmplayer_t *igm;
}

static void prefs_pageCancel(pagedef_t *page) {
	igmplayer_t *igm;
}

static void prefs_pagePrepare() {
	igmplayer_t *igm;
}

static void prefs_pageConstruct(pagedef_t *page) {
	int xLeft;
	int xRight;
	int y;
	menufxItem *mi;
}

static void prefs_pageGfx(pagedef_t *page) {}

static void prefs_pageTick(pagedef_t *page) {}

static void confirmendgame_pageYesSelect(pagedef_t *page) {
	igmplayer_t *igm;
}

static void confirmendgame_pageNoSelect(pagedef_t *page) {}

static void confirmendgame_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void confirmendgame_pageGfx(pagedef_t *page) {}

static void confirmendgame_pageTick(pagedef_t *page) {}

static void confirmrestartgame_pageYesSelect(pagedef_t *page) {
	igmplayer_t *igm;
}

static void confirmrestartgame_pageNoSelect(pagedef_t *page) {}

static void confirmrestartgame_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void confirmrestartgame_pageGfx(pagedef_t *page) {}

static void confirmrestartgame_pageTick(pagedef_t *page) {}

void stats_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void stats_pageGfx(pagedef_t *page) {
	igmplayer_t *igm;
	int normalfont;
	char *s;
	int y;
	int left;
	int right;
	float accuracyf;
	int accuracy;
	int headhits;
}

static void stats_pageTick(pagedef_t *page) {}

void awards_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void awards_pageGfx(pagedef_t *page) {
	igmplayer_t *igm;
	char *s;
	int y;
	int centerx;
	int biggap;
	int smallgap;
	int headergap;
	int e;
}

static void awards_pageTick(pagedef_t *page) {}

static void endgame_pageQuit(pagedef_t *page) {
	igmplayer_t *igm;
}

static void endgame_pageRestart(pagedef_t *page) {
	igmplayer_t *igm;
}

static void endgame_pageContinueRestartSelect(pagedef_t *page) {}

static void endgame_pageGfx(pagedef_t *page) {
	igmplayer_t *igm;
	int normalfont;
	int x;
	u8 *s;
}

static void endgame_pageTick(pagedef_t *page) {
	igmplayer_t *igm;
}

void endgame_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void options_pageContinueSelect(pagedef_t *page) {
	igmplayer_t *igm;
}

static void options_pageRestartSelect(pagedef_t *page) {}

static void options_pageQuitSelect(pagedef_t *page) {
	igmplayer_t *igm;
}

static void options_pageSetupSelect(pagedef_t *page) {}

static void options_pagePrefsSelect(pagedef_t *page) {}

static void options_pageGfx(pagedef_t *page) {}

static void options_pageTick(pagedef_t *page) {}

void options_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
	int count;
}

static void pause_pageGfx(pagedef_t *page) {
	int bigfont;
	int font;
	char *s;
}

static void pause_pageTick(pagedef_t *page) {}

static void pause_pageConstruct(pagedef_t *page) {}

static int scores_getRankingType() {}

void scores_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
	u8 *text;
}

static void scores_pageGfx(pagedef_t *page) {}

static void scores_pageTick(pagedef_t *page) {}

void inventory_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void inventory_pageGfx(pagedef_t *page) {
	int textSpacing;
	igmplayer_t *igm;
	int x1;
	int y1;
	int e;
	int width;
	int height;
	int ammoType;
	int x2;
	int y2;
	int ammoName;
	int ammoTypeSecondary;
	u8 *text;
	float amount;
	int ammoName;
	float amount;
	u32 alpha;
	u32 rgba;
}

static void inventory_pageTick(pagedef_t *page) {
	int e;
	int menuIndex;
	igmplayer_t *igm;
	chrdata *cd;
	int textSpacing;
	inventoryItem *item;
	int ammo;
	int ammoType;
	int ammoSecondary;
	int ammoTypeSecondary;
	int clipCount;
	int guntype;
	manualLighting *lighting;
	int propnum;
	float roty;
	float rotx;
	int guntype;
	int m;
	float scale;
	int maxShowItems;
	int windowHeight;
	boolean showingGfx;
	int numShowItems;
	int xLeft;
	int xRight;
	int yTop;
	int yBottom;
	int freespace;
	float showy;
	int oldIndex;
	int oldIndex;
}

void status_pageObjectives(pagedef_t *page, boolean draw) {
	int objectiveRight;
	int y;
	int type;
	int offsetx;
	int offsety;
	int o;
	objective *obj;
	int height;
}

void status_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void status_pageGfx(pagedef_t *page) {}

static void status_pageTick(pagedef_t *page) {}

void briefing_pageConstruct(pagedef_t *page) {
	menufxItem *mi;
}

static void briefing_pageGfx(pagedef_t *page) {}

static void briefing_pageTick(pagedef_t *page) {}
