// STATUS: NOT STARTED

#include "game.h"

struct laststanddef_s {
	int levelnum;
	float x;
	float z;
	float radius;
	float patroltime;
};

typedef laststanddef_s laststanddef;

struct zonesgminfo_s {
	float teamscore[5];
	float scoreinc;
};

typedef zonesgminfo_s zonesgminfo;
int demo_completed = 0;
int demo_aborted = 0;
int demo_timeout = 0;
int demo_attractend = 0;
int demo_attractabort = 0;

storyinfo_t storydata[9] = {
	/* [0] = */ {
		/* .title = */ 739,
		/* .levelnum = */ 23,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [1] = */ {
		/* .title = */ 740,
		/* .levelnum = */ 21,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [2] = */ {
		/* .title = */ 741,
		/* .levelnum = */ 14,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [3] = */ {
		/* .title = */ 742,
		/* .levelnum = */ 2,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [4] = */ {
		/* .title = */ 743,
		/* .levelnum = */ 5,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [5] = */ {
		/* .title = */ 744,
		/* .levelnum = */ 9,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [6] = */ {
		/* .title = */ 745,
		/* .levelnum = */ 8,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [7] = */ {
		/* .title = */ 746,
		/* .levelnum = */ 24,
		/* .male = */ 0,
		/* .female = */ 1
	},
	/* [8] = */ {
		/* .title = */ 747,
		/* .levelnum = */ 27,
		/* .male = */ 0,
		/* .female = */ 1
	}
};

teaminfo_t teamdata[5] = {
	/* [0] = */ {
		/* .name = */ 748,
		/* .colour = */ 4224
	},
	/* [1] = */ {
		/* .name = */ 749,
		/* .colour = */ 32640
	},
	/* [2] = */ {
		/* .name = */ 750,
		/* .colour = */ 128
	},
	/* [3] = */ {
		/* .name = */ 751,
		/* .colour = */ 4224
	},
	/* [4] = */ {
		/* .name = */ 752,
		/* .colour = */ 20608
	}
};

gamemodeinfo_t gamemodedata[9] = {
	/* [0] = */ {
		/* .name = */ 0,
		/* .useteamspawns = */ 0,
		/* .useteamdrops = */ 0
	},
	/* [1] = */ {
		/* .name = */ 753,
		/* .useteamspawns = */ 0,
		/* .useteamdrops = */ 0
	},
	/* [2] = */ {
		/* .name = */ 754,
		/* .useteamspawns = */ 1,
		/* .useteamdrops = */ 1
	},
	/* [3] = */ {
		/* .name = */ 755,
		/* .useteamspawns = */ 0,
		/* .useteamdrops = */ 0
	},
	/* [4] = */ {
		/* .name = */ 756,
		/* .useteamspawns = */ 1,
		/* .useteamdrops = */ 0
	},
	/* [5] = */ {
		/* .name = */ 757,
		/* .useteamspawns = */ 1,
		/* .useteamdrops = */ 1
	},
	/* [6] = */ {
		/* .name = */ 758,
		/* .useteamspawns = */ 1,
		/* .useteamdrops = */ 0
	},
	/* [7] = */ {
		/* .name = */ 759,
		/* .useteamspawns = */ 1,
		/* .useteamdrops = */ 0
	},
	/* [8] = */ {
		/* .name = */ 760,
		/* .useteamspawns = */ 1,
		/* .useteamdrops = */ 1
	}
};

u32 charcolours[14] = {
	/* [0] = */ 8320,
	/* [1] = */ 32640,
	/* [2] = */ 8320,
	/* [3] = */ 32640,
	/* [4] = */ 32640,
	/* [5] = */ 8320,
	/* [6] = */ 20608,
	/* [7] = */ 32640,
	/* [8] = */ 128,
	/* [9] = */ 20608,
	/* [10] = */ 32640,
	/* [11] = */ 20608,
	/* [12] = */ 20608,
	/* [13] = */ 32640
};

static laststanddef lsdesc[5] = {
	/* [0] = */ {
		/* .levelnum = */ 25,
		/* .x = */ 0.f,
		/* .z = */ 0.f,
		/* .radius = */ 10.f,
		/* .patroltime = */ 5.f
	},
	/* [1] = */ {
		/* .levelnum = */ 9,
		/* .x = */ 32.78f,
		/* .z = */ 6.37f,
		/* .radius = */ 8.f,
		/* .patroltime = */ 5.f
	},
	/* [2] = */ {
		/* .levelnum = */ 12,
		/* .x = */ -12.29f,
		/* .z = */ -4.51f,
		/* .radius = */ 4.f,
		/* .patroltime = */ 5.f
	},
	/* [3] = */ {
		/* .levelnum = */ 5,
		/* .x = */ 15.86f,
		/* .z = */ -56.9f,
		/* .radius = */ 4.f,
		/* .patroltime = */ 2.f
	},
	/* [4] = */ {
		/* .levelnum = */ 8,
		/* .x = */ -0.28f,
		/* .z = */ -0.05f,
		/* .radius = */ 10.f,
		/* .patroltime = */ 2.f
	}
};

static zonesgminfo zonesinfo = {
	/* .teamscore = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f,
		/* [3] = */ 0.f,
		/* [4] = */ 0.f
	},
	/* .scoreinc = */ 0.25f
};

int doingminimalreset = 0;
int minimalresetdone = 0;

resetgameparms curgameparms = {
	/* .numplayers = */ 0,
	/* .numlocalplayers = */ 0,
	/* .numbots = */ 0,
	/* .numteams = */ 0,
	/* .teamnums = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* .chrtypes = */ {
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
		/* [13] = */ 0
	},
	/* .chrteams = */ {
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
		/* [13] = */ 0
	},
	/* .levelnum = */ 0,
	/* .challengenum = */ 0,
	/* .gamemode = */ 0,
	/* .gameskill = */ 0,
	/* .gameflags = */ 0,
	/* .miscflags = */ 0,
	/* .timelimit = */ 0,
	/* .killlimit = */ 0,
	/* .scorelimit = */ 0,
	/* .inactivitytimer = */ 0,
	/* .demonum = */ 0,
	/* .teamactive = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* .totalbotskill = */ 0
};

resetgameparms deferedgameparms = {
	/* .numplayers = */ 0,
	/* .numlocalplayers = */ 0,
	/* .numbots = */ 0,
	/* .numteams = */ 0,
	/* .teamnums = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* .chrtypes = */ {
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
		/* [13] = */ 0
	},
	/* .chrteams = */ {
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
		/* [13] = */ 0
	},
	/* .levelnum = */ 0,
	/* .challengenum = */ 0,
	/* .gamemode = */ 0,
	/* .gameskill = */ 0,
	/* .gameflags = */ 0,
	/* .miscflags = */ 0,
	/* .timelimit = */ 0,
	/* .killlimit = */ 0,
	/* .scorelimit = */ 0,
	/* .inactivitytimer = */ 0,
	/* .demonum = */ 0,
	/* .teamactive = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0
	},
	/* .totalbotskill = */ 0
};

int gameframe = 0;
int gamestate = 0;
float gamestatetime = 0.f;
static int bagowner;
static int numkobagpos;
static int kobagpos[20];
static int bagspawntimer;
static int kobagpropnum;
static int escortee_destpad;
static bubblesort_t ranktableteam[58];

bubblesort_t *gameranksteam[58] = {
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

int gameranksizeteam = 0;
static bubblesort_t ranktablechr[58];

bubblesort_t *gamerankschr[58] = {
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

int gameranksizechr = 0;
static int endlevelcount;

boolean gameIsPlayingGame() {}

u8* gameGetTeamName(int team) {}

u8* gameFormatBagTagTime(int frames) {
	int mins;
}

u8* gameFormatTime(int frames) {
	static u8 timestr[20];
	int hours;
	int secs;
}

boolean gameModeDisplayRank() {}

int UnlockCombo() {}

int UnlockCombo2() {}

void gameSetState(int state) {}

boolean gameModeIsArcade() {}

static boolean gameStatusUpdated() {
	boolean update;
	int i;
	levelstats_t *st;
	int leveltime;
	u32 *besttimes;
	challengestats_t *cs;
	chrdata *chr;
	chrstats_t *st;
	levelstats_t *st;
}

void gameEndLevelSound() {
	int sfx;
}

void gameLevelRestart() {}

void gameLevelImmediateQuit() {}

void gameLevelQuit() {}

void gameRankingMessages() {
	int pl;
	player *player;
}

void gameLevelCompleted() {
	int i;
}

static void gmStoryTick() {}

static void gmDeathmatchTick() {
	int best;
	int i;
	u8 *s;
	int i;
	u8 done[58];
	int t;
	int count;
	int left;
	int doit;
	u8 *msg;
}

static void gmBagTagTick() {
	int newbagowner;
	int i;
	u8 *msg;
}

static void gmCtfTick() {
	int i;
}

static void knockoutSetup() {
	int i;
	setupheader *setup;
	setuppickup *sp;
}

void gmSpawnKnockOutBag(int ghostbagnum, int padnum) {
	prop *p;
	pickupdata *pd;
	float dy;
}

static void gmKnockOutTick() {
	int i;
	int visbags;
	int ghostbagnum;
	int start;
	int end;
	int padnum;
	prop *p;
	pickupdata *pd;
}

static void gmEscortSetup() {
	setupheader *setup;
	int i;
	setuppickup *sp;
}

int gmEscorteeReachedDest() {
	prop *escortee_prop;
	chrdata *escortee_chr;
}

static void gmEscortTick() {
	prop *escortee_prop;
	chrdata *escortee_chr;
	int i;
}

static laststanddef* getLastStandInfo(int levelnum) {}

int gmLastStandAllBasesDestroyed() {
	int i;
}

static void gmLastStandTick() {
	int i;
	int numdeadplayers;
	laststanddef *ls;
	prop *pop;
	chrdata *chr;
	float dx;
	float dz;
}

static void gmZonesTick() {
	int d;
	int t;
	pickupdata *pd;
}

int gameGetRankTeam(int teamnum) {
	int i;
}

int gameGetRankChr(int chrnum) {
	int i;
}

char* gameConvertRankToString(int ranking) {
	char *s;
}

static void gameLevelTick() {
	u8 teamdone[59];
	int i;
	int t;
	u8 *msg;
	int i;
	int i;
	int i;
	int i;
}

void gameDeferedReset(resetgameparms *p) {}

void gameRestart() {
	int i;
	int t;
}

void gameRestartAfter() {}

void gameReset() {}

void gameResetAfter() {}

void gameEndCutscene() {}

void gameEndIntro() {
	int i;
	chrdata *hitcd;
}

void gameTick() {
	int i;
	resetgameparms pp;
	int i;
}

void gameEnd() {}

boolean gameTerminateButtonsPressed() {
	int i;
}

boolean gameSkipButtonsPressed() {
	int i;
}
