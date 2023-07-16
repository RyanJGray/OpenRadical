// STATUS: NOT STARTED

#include "enemy.h"

// warning: multiple differing types with the same name (#143,  not equal)
enum {
	EHL_CALLLIFT = 0,
	EHL_WAITFORLIFT = 1,
	EHL_INLIFT = 2,
	EHL_ENTERLIFT = 3,
	EHL_EXITLIFT = 4,
	EHL_WAITFORTARGET = 5
};

// warning: multiple differing types with the same name (#143,  not equal)
enum {
	ONFIRE_CHOOSEPAD = 0,
	ONFIRE_GOTOPAD = 1
};

// warning: multiple differing types with the same name (#143,  not equal)
enum {
	RAW_NULL = 0,
	RAW_CHOOSE_DEST = 1,
	RAW_PROGRESS = 2,
	RAW_STOP = 3
};

struct padinf_s {
	float dist;
	int padnum;
	float dot;
};

// warning: multiple differing types with the same name (#143,  not equal)
enum {
	ENR_START = 0,
	ENR_TARGET = 1,
	ENR_CHOOSENEWTARGET = 2,
	ENR_STAND = 3,
	ENR_FIRE = 4
};

lookup *visTable = NULL;
setupheader_s *setup = NULL;
int numEscorts = 0;
int numBases = 0;
int numlifts = 0;
int totactivespawnedchars = 0;
int numchractive = 0;
static int numtriggerpads = 0;
static int updateplayer = 0;
static int checksleepplayer = 0;
static int checksleepframe = 4;
static int npctimesliceindex = 0;
static int currAIEventHandler = 0;
static int numPickupWeapons = 0;
int numPickupBags = 0;
static int numPickupHealth = 0;
static int numPickupDrops = 0;
static int framecheck = 0;
static int updatechr = 0;
static int debug_numlinetests = 0;

static float reacttimes[15] = {
	/* [0] = */ 0.05f,
	/* [1] = */ 0.15f,
	/* [2] = */ 0.2f,
	/* [3] = */ 0.35f,
	/* [4] = */ 0.45f,
	/* [5] = */ 0.75f,
	/* [6] = */ 0.85f,
	/* [7] = */ 0.95f,
	/* [8] = */ 1.f,
	/* [9] = */ 1.1f,
	/* [10] = */ 1.5f,
	/* [11] = */ 1.75f,
	/* [12] = */ 2.f,
	/* [13] = */ 2.5f,
	/* [14] = */ 3.75f
};

int canplayreactsfx = 0;
int numDrawnChrs = 0;

int teamflag[5] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0
};

prop *escort[5] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL
};

padprop bagspawn[6] = {
	/* [0] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [1] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [2] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [3] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [4] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [5] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	}
};

int updateNPCindex = 0;

prop *bases[10] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL
};

prop *droppedgunlist[20] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL
};

int AI_alertstate = 0;

int activeSleepGrps[10] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0
};

int numNPCcreated = 0;

chrdata_s *chractivelist[58] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL,
	/* [20] = */ NULL,
	/* [21] = */ NULL,
	/* [22] = */ NULL,
	/* [23] = */ NULL,
	/* [24] = */ NULL,
	/* [25] = */ NULL,
	/* [26] = */ NULL,
	/* [27] = */ NULL,
	/* [28] = */ NULL,
	/* [29] = */ NULL,
	/* [30] = */ NULL,
	/* [31] = */ NULL,
	/* [32] = */ NULL,
	/* [33] = */ NULL,
	/* [34] = */ NULL,
	/* [35] = */ NULL,
	/* [36] = */ NULL,
	/* [37] = */ NULL,
	/* [38] = */ NULL,
	/* [39] = */ NULL,
	/* [40] = */ NULL,
	/* [41] = */ NULL,
	/* [42] = */ NULL,
	/* [43] = */ NULL,
	/* [44] = */ NULL,
	/* [45] = */ NULL,
	/* [46] = */ NULL,
	/* [47] = */ NULL,
	/* [48] = */ NULL,
	/* [49] = */ NULL,
	/* [50] = */ NULL,
	/* [51] = */ NULL,
	/* [52] = */ NULL,
	/* [53] = */ NULL,
	/* [54] = */ NULL,
	/* [55] = */ NULL,
	/* [56] = */ NULL,
	/* [57] = */ NULL
};

static int totalmaxactive;

prop *chr[58] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL,
	/* [20] = */ NULL,
	/* [21] = */ NULL,
	/* [22] = */ NULL,
	/* [23] = */ NULL,
	/* [24] = */ NULL,
	/* [25] = */ NULL,
	/* [26] = */ NULL,
	/* [27] = */ NULL,
	/* [28] = */ NULL,
	/* [29] = */ NULL,
	/* [30] = */ NULL,
	/* [31] = */ NULL,
	/* [32] = */ NULL,
	/* [33] = */ NULL,
	/* [34] = */ NULL,
	/* [35] = */ NULL,
	/* [36] = */ NULL,
	/* [37] = */ NULL,
	/* [38] = */ NULL,
	/* [39] = */ NULL,
	/* [40] = */ NULL,
	/* [41] = */ NULL,
	/* [42] = */ NULL,
	/* [43] = */ NULL,
	/* [44] = */ NULL,
	/* [45] = */ NULL,
	/* [46] = */ NULL,
	/* [47] = */ NULL,
	/* [48] = */ NULL,
	/* [49] = */ NULL,
	/* [50] = */ NULL,
	/* [51] = */ NULL,
	/* [52] = */ NULL,
	/* [53] = */ NULL,
	/* [54] = */ NULL,
	/* [55] = */ NULL,
	/* [56] = */ NULL,
	/* [57] = */ NULL
};

padprop weaponspawn[35] = {
	/* [0] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [1] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [2] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [3] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [4] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [5] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [6] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [7] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [8] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [9] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [10] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [11] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [12] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [13] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [14] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [15] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [16] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [17] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [18] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [19] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [20] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [21] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [22] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [23] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [24] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [25] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [26] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [27] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [28] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [29] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [30] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [31] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [32] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [33] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [34] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	}
};

padprop healthspawn[25] = {
	/* [0] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [1] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [2] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [3] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [4] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [5] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [6] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [7] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [8] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [9] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [10] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [11] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [12] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [13] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [14] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [15] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [16] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [17] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [18] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [19] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [20] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [21] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [22] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [23] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [24] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	}
};

padprop dropspawn[20] = {
	/* [0] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [1] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [2] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [3] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [4] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [5] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [6] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [7] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [8] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [9] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [10] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [11] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [12] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [13] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [14] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [15] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [16] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [17] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [18] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [19] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	}
};

padprop lifts[5] = {
	/* [0] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [1] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [2] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [3] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	},
	/* [4] = */ {
		/* .pad = */ 0,
		/* .prop = */ NULL
	}
};

explosioninfo aiexplosiondata[20] = {
	/* [0] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [1] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [2] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [3] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [4] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [5] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [6] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [7] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [8] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [9] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [10] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [11] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [12] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [13] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [14] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [15] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [16] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [17] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [18] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	},
	/* [19] = */ {
		/* .pos = */ {
			/* [0] = */ 0.f,
			/* [1] = */ 0.f,
			/* [2] = */ 0.f
		},
		/* .id = */ 0
	}
};

static triggerpad triggerpads[100];
static int numExplosions;
static int sendtosleep[58];

void enemyRestart() {
	int i;
}

void enemyReset() {}

void enemyPreload() {
	int chrtypeuse;
	int chrtypeoriginal;
	int i;
	int i;
}

void enemySetup() {
	int i;
	int chrtypeuse;
	int chrtypeoriginal;
	int chrtype;
}

void enemyAITickBefore() {
	chrdata *cd;
	int i;
	int j;
	int k;
	int remove;
	int lp;
}

void enemyOverSeer() {
	int i;
	chrdata *cd;
}

void enemyTick(prop *p) {
	chrdata *cd;
	float timeinc;
	int i;
}

void enemyEnd() {}

void updatePos(prop *p) {
	mtx_u rotmtx;
	float pos[3];
	float movepos[3];
	float movdir[3];
	float movdist;
	float rlen;
	chrdata *cd;
	int chrnum;
}

void rotateChr(prop *p) {
	float diffrot;
	float rottarget;
	float rotdest;
	float angleinc;
	float dx;
	float dz;
	chrdata *cd;
	pad *padptr;
	int i;
	pickupdata *pd;
}

static void rotateFaceTarget(prop *p) {
	float rottarget;
	float dz;
	chrdata *cd;
}

void setAnimation(prop *p) {
	chrdata *cd;
	float z1;
	float z2;
	float frames;
	float trans;
}

void setZombieAnimation(prop *p) {
	chrdata *cd;
}

void zombieAdvanceAnim(prop *p) {
	chrdata *cd;
	float choice;
}

int findNextPad(prop *p, padInfo *pad, int addmultipliers) {
	chrdata *cd;
	int destpadnum;
	int i;
	int i;
	int i;
	int curhallnum;
	int tmpdestpadnum;
	int i;
}

void updatePlayerPadPos() {
	chrdata *cd;
	int i;
	int pad;
	int padlist[20];
	int listsize;
}

void enemyCheckValidPad(int chrindex) {
	chrdata *cd;
	prop *p;
	int pad;
	float dx;
	float dy;
	float dz;
	float movepos[3];
}

void updateNPCPadPos(prop *p) {
	chrdata *cd;
	int pad;
	int padlist[20];
	int listsize;
}

void checkProgress(prop *p) {
	chrdata *cd;
	float dist;
	float dx;
	float dy;
	float dz;
}

void enemyGunUpdate(prop *p) {
	chrdata *cd;
	gunChrFireChoiceTable table;
	gunChrFireChoiceTable table;
	gunChrFireChoiceTable table;
}

void enemyDetonateMines(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	float distsq;
	int i;
}

void enemyTrackTarget(prop *p) {
	chrdata *cd;
	int destpad;
	int aware;
	float dx;
	float dy;
	float dz;
	pad *pad1;
}

int enemyAdvancePads(prop *p, int destpad) {
	chrdata *cd;
	float dist;
	float dx;
	float dy;
	float dz;
	pad *destplacepad;
	pad *cdpad;
}

void enemyDefend(prop *p) {
	chrdata *cd;
	prop *newtarget;
}

int enemyGetChrActiveListIndex(int id) {
	int i;
}

prop* enemyCycleThroughTargets(prop *p) {
	chrdata *cd;
	chrdata *prevtcd;
	prop *chosenchr;
	float bestdist;
	int i;
	chrdata *checkcd;
	float xd;
	float yd;
	float zd;
	prop *cp;
}

int enemyChooseDropToDefend(prop *p) {
	chrdata *cd;
	pickupdata *pd;
	int i;
	int dropnum;
	int bestdefdrop;
	float numdef;
	float numatt;
	float ratioda;
	float bestratioda;
	padextrainfo *padex;
}

int enemyChooseDefendPad(prop *p, int defpad) {
	int i;
	int listsize;
	int padlist[20];
	int bestpad;
	float rlen;
	float dir2[3];
	float bestdot;
	float dot;
	float dir1[3];
	mtx_u mtx;
}

int enemyOnPad(prop *p, int padcheck) {
	chrdata *cd;
	int i;
	chrdata *checkcd;
}

prop* enemySelectLaststandBase(int start) {
	int choosebase;
	int loopcount;
}

int enemyReselectTarget(prop *p) {
	chrdata *cd;
	prop *target;
	int choosebase;
	int d;
	int i;
	boolean Reselect;
	float dx;
	float dy;
	float dz;
	float dist;
	float closestdist;
	chrdata *closestcd;
	prop *tp;
	boolean cansee;
	boolean hasseen;
	chrdata *checkcd;
	prop *pCarrier;
	boolean Attacker;
	boolean CarrierMyTeam;
	chrdata *checkcd;
	chrdata *checkcd;
}

int enemyGetTargetPad(prop *p) {
	chrdata *cd;
	int destpad;
}

int selectDrop(prop *p) {
	int i;
	chrdata *cd;
}

void followTargetPassive(prop *p) {
	chrdata *cd;
	int i;
	int numlinkedpads;
	int destpad;
	int linkedpads[5];
	float dx;
	float dy;
	float dz;
	float dist;
	float rotdif;
	float stopdist;
	float closedist;
	float tooclose;
	float toofar;
	float idletime;
	float chrdist;
	float tgtdist;
	float movepos[3];
}

void enemyOnFire(prop *p) {
	chrdata *cd;
	int numlinkedpads;
	int i;
	int destpad;
	int linkedpads[5];
}

void runAway(prop *p) {
	int PAD_LIST_MAX;
	int HALL_LIST_MAX;
	chrdata *cd;
	chrdata *tcd;
	int i;
	int j;
	int k;
	int l;
	float dist;
	float dx;
	float dy;
	float dz;
	padinf_s *padlist[0];
	int *padlist2[0];
	int padlistsize;
	int padlist2size;
	int destpadnum;
	float min_pad_gdist;
	float max_pad_gdist;
	float rlen;
	float dot;
	float dir1[3];
	float dir2[3];
	float totalroutecost;
	padInfo pi;
	pad *pad1;
	int *halllist[0];
	int halllistsize;
	int *hallpads;
	int numhallpads;
	boolean checkgdist;
	int *disabledlinks[0];
	int numdisabledlinks;
}

float enemyReactTime(prop *p) {
	chrdata *cd;
	int skill;
	float time;
}

void enemyInformAboutDeath(prop *p) {
	chrdata *cd;
	int i;
	chrdata *alcd;
	prop *alp;
	float distsq;
	float dir[3];
}

void enemyDying(prop *p) {
	chrdata *cd;
	int found;
	int found;
}

void enemySpawn(prop *p) {
	float movepos[3];
	float suggestpos[3];
	chrdata *cd;
	int chrnum;
	int i;
	pad *startpadptr;
	int padnum;
}

void enemySelectTarget(prop *p) {
	chrdata *cd;
	prop *selection[58];
	prop *lasttarget;
	prop *target;
	int numtargets;
	int i;
	int count;
	int dropnum;
	float weight;
	float bestweight;
	float dx;
	float dy;
	float dz;
	float bestdistsq;
	float distsq;
	chrdata *loopcd;
	chrdata *loopcd;
	int d;
	padextrainfo *padex;
	pickupdata *pd;
	chrdata *loopcd;
	prop *pBest;
	float BestDist;
	chrdata *loopcd;
	float dx;
	float dy;
	float dz;
	float Dist;
}

prop* enemySelectDeathMatchTarget(prop *p, int reselecting) {
	chrdata *cd;
	prop *selection[58];
	prop *target;
	int numtargets;
	int i;
	float weight;
	float bestweight;
	float dx;
	float dy;
	float dz;
	chrdata *checkcd;
}

prop* enemySelectStoryTarget(prop *p, int reselecting) {
	chrdata *cd;
	prop *target;
	int i;
	float dx;
	float dy;
	float dz;
	float distsq;
	float bestdistsq;
	chrdata *checkcd;
	prop *checkp;
	chrdata *checkcd;
	prop *checkp;
}

prop* suggestTarget(prop *p, prop *suggtarget, int flag) {
	int i;
	int bestplayer;
	float dx;
	float dy;
	float dz;
	float dist;
	float bestdist;
}

void findbearings(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	float movepos[3];
	int testpad;
}

void findmypad(prop *p) {
	chrdata *cd;
	float dist;
	float dx;
	float dy;
	float dz;
}

int awareOfTarget(prop *p, int canchangetarget) {
	chrdata *cd;
	float tdistsq;
	float dx;
	float dy;
	float dz;
	float tspeedfactor;
	float testfovy;
	chrdata *tcd;
}

int checkInFrontOfPos(float *pos1, float *pos1dir, float *pos2, float dotcomp) {
	float vbetween[3];
	float dot;
	float frac;
}

int checkInFront(prop *p, float *pos, float dotcomp) {
	float vbetween[3];
	float dir[3];
	float dot;
	float rlen;
	mtx_u mtx;
}

int checkSeeFOV(prop *p, float *pos, float dotcomp) {
	float vbetween[3];
	float dir[3];
	float dot;
	float rlen;
	mtx_u tmpmtx;
	mtx_u finalmtx;
}

int checkInFrontOfPadPtr(pad_s *padptr, float *pos, float dotcomp) {
	float vbetween[3];
	float dir[3];
	float dot;
	float rlen;
	mtx_u mtx;
}

float checkInFrontOfDir(float *dir1, float *dir2, float dotcomp) {
	float dot;
}

int checkAimingFront(prop *p1, prop *p2, float dotcomp) {
	float vbetween[3];
	float dir[3];
	float dot;
	float rlen;
	mtx_u mtx;
}

int checkSide(prop *p, float *pos, float dotcomp) {
	float vbetween[3];
	float dir[3];
	float dot;
	mtx_u mtx;
}

void enemyDie(prop *p, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, int parthit, int deathflag) {
	chrdata *cd;
	chrdata *attackerdata;
}

void enemyInformHit(prop *p, prop *attacker, int animparthit, int bullettype) {
	chrdata *cd;
}

void drawLine(float *pos1, float *pos2, u32 col, float yoffset) {
	u32 *ref;
	int i;
	int oldzbmode;
	void *addr;
}

void enemyAddToWeaponList(prop *prop, int padnum) {}

void enemyAddToBagList(prop *prop, int padnum) {}

void enemyAddToHealthList(prop *prop, int padnum) {}

void enemyAddToDropList(prop *prop, int padnum) {}

void enemyAddToPropList(setupprop *sp, prop *prop) {
	basedata *bd;
}

void enemyAddToLiftList(setuplift *sl, prop *prop) {}

int enemyGetNumBases() {}

prop* enemyGetBase(int b) {}

void enemyAddToEscortList(prop *prop) {}

void enemySetRoom(prop *p, int firsttime) {
	chrdata *cd;
	float start[3];
	float diff[3];
	int thisroom;
	int lastroom;
	int nextroom;
	mtx_u tmpmtx;
	mtx_u mtx;
	float trypos[3];
}

void enemySetMoveMode(prop *p, int movemode) {
	chrdata *cd;
}

int enemyTriggered(prop *p) {
	chrdata *cd;
	int i;
	float dx;
	float dy;
	float dz;
	float distsq;
}

void enemyNoRoute(prop *p) {
	chrdata *cd;
	prop *newtarget;
	int nextpad;
	int i;
	boolean dooropened;
}

void moveValidPad(prop *p) {
	chrdata *cd;
	int i;
	int j;
	int k;
	int padlist[20];
	int listsize;
	float dist;
	float dx;
	float dy;
	float dz;
}

int enemyFiredAt(prop *p) {
	chrdata *cd;
	float distsq;
	float dx;
	float dy;
	float dz;
}

int enemySafeToFire(prop *p) {
	int i;
	chrdata *cd;
	chrdata *cd_other;
	float distsq;
	float targetdistsq;
	float dx;
	float dz;
	float fov;
}

void enemyDeleteNPC(prop *p) {
	chrdata *cd;
}

void enemyCopyNPCdataToChr(chrdata *cd) {
	prop *p;
	pad *startpadptr;
	gunset *lvgunset;
	setupNPC *npc;
	int guntype;
	gunInfo_s *gi;
}

int enemyCreateNPC(setupNPC *npc, int pad, int typeuse, int typeoriginal, int extradata1) {
	int i;
	int cindex;
	chrdata *cd;
}

void enemyAITickAfter() {
	int i;
	chrdata *cd;
	prop *p;
	float dx;
	float dy;
	float dz;
	float dist;
	pad *cdpad;
}

void enemyPreCalcEnemyRoutes() {
	int i;
	int j;
	int w;
	int k;
	int index;
	int bestpad[5];
	int bestindex;
	padInfo pi;
	float totalcost;
	float healthcost;
	float guncost;
	float bestweight;
	float armourcost;
	float bestcost[5];
	prop *bestprop[5];
	gunset *lvgunset;
	int numguncombo[5];
	int gunlistcombos[5];
	pickupdata *pd;
	int g;
	pad *plpad;
	float dx;
	float dy;
	float dz;
	int h;
	int d;
	int k;
}

void enemyCheckAllRoutes() {}

void enemyAddToExplosionList(float *pos, int id) {}

void enemyRemoveFromExplosionList(int id) {}

int enemyExplosionNearby(prop *p) {
	int i;
	int index;
	float distsq;
	float bestdistsq;
}

void enemyUpdateCampDetect(chrdata *cd) {
	float dx;
	float dy;
	float dz;
	float distsq;
	int framediff;
	prop *p;
}

int campingPad(int padnum) {}

int enemyRoomDrawn(int roomcheck) {
	int i;
	int j;
	ViewDef *pView;
}

padprop* enemyGetPadProp(int padnum) {
	int i;
}

prop* checkCoopTarget(prop *p) {
	chrdata *cd;
}

void enemyShowStatsGfx() {}

void enemyAddToActiveList(prop *p) {}

void enemyRemoveFromActiveList(prop *p) {
	chrdata *cd;
	int index;
	int i;
}

void enemyVisTableSet(int index1, int index2, int cansee) {}

int enemyVisTableCanSeeChr(int index1, int index2) {}

int enemyVisTableFrameChecked(int index1, int index2) {}

int enemyVisTableFrameChanged(int index1, int index2) {}

int enemyCanSeeTarget(chrdata *cd, int canchangetarget) {}

int enemyGetNumPickupDrops() {}

padprop* enemyGetDrop(int d) {}

int enemyGetDropNumFromProp(prop *p) {
	int i;
}

int enemyGetDropNumFromPad(int pad) {
	int i;
}

void setDisableLinks(int enable) {
	int i;
}

pad_s* enemyGetNPCsPad(chrdata *cd) {
	pad *startpadptr;
	pad *p1padptr;
}

boolean enemyChrIsOnPad(chrdata *cd, int padnum) {
	prop *p;
	float dx;
	float dy;
	float dz;
	float dist;
	pad *padptr;
}

void enemyHandleLift(prop *p) {
	chrdata *cd;
	liftData *liftdata;
	liftNode *liftnode;
	int flooron;
	int nextpad;
}

static int findlift(prop *p) {
	chrdata *cd;
	int i;
	int j;
	int padlist[20];
	int listsize;
}

static int liftfindfloor(prop *p, int pad) {
	chrdata *cd;
	liftData *liftdata;
	int i;
}

void enemyGameOver(prop *p) {}

void enemySetGameOver() {
	int i;
}

void enemyCheckDoorway(prop *p) {
	int i;
	chrdata *cd;
	doordata *door;
	link *doorlink;
	int j;
}

void enemySendGroupToSleep(int sleepgrp) {
	int i;
	int atchrs;
	chrdata *cd;
}

void enemyAwakeSleepGroup(int sleepgrp) {}

int enemyGetNumPickupWeapons() {}

padprop* enemyGetWeaponSpawn(int w) {}

int enemyGetNumPickupHealth() {}

padprop* enemyGetHealthSpawn(int h) {}
