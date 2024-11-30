//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "enemySingle.h"

enum {
	EMS_START = 0,
	EMS_STAND = 1,
	EMS_CROUCH = 2,
	EMS_STANDFIRE = 3,
	EMS_CHANGETARGETBASE_LS = 4,
	EMS_CHECKLOSTTARGET_LS = 5
};

enum {
	EAC_SETUP = 0,
	EAC_READY = 1,
	EAC_CROUCH = 2,
	EAC_STAND = 3,
	EAC_THROWGRENADE = 4,
	EAC_THROWFINISH = 5,
	EAC_STANDFIRE = 6,
	EAC_CRATESHOOT = 7
};

enum {
	ZOM_ATK_ADVANCE = 0
};

enum {
	ATTACKOBJECT_FIRSTENTRY = 0,
	ATTACKOBJECT_GETRANGE = 1,
	ATTACKOBJECT_INRANGE = 2,
	ATTACKOBJECT_FIRE = 3,
	ATTACKOBJECT_CROUCHFIRE = 4,
	ATTACKOBJECT_PAUSE = 5,
	ATTACKOBJECT_CHECKLOSTTARGET = 6,
	ATTACKOBJECT_CHECKRANGE = 7
};

enum {
	SNIPEATTACK_CHOOSESNIPEPAD = 0,
	SNIPEATTACK_ADVANCETOSNIPEPAD = 1,
	SNIPEATTACK_CHOOSETARGET = 2,
	SNIPEATTACK_CHOOSINGTARGET = 3,
	SNIPEATTACK_SHOOT = 4,
	SNIPEATTACK_CHECKLOSTTARGET = 5
};

enum {
	BARRELROBOT_SLEEP = 0,
	BARRELROBOT_SPINHEAD = 1,
	BARRELROBOT_AWAKEN = 2,
	BARRELROBOT_TRACKTARGET = 3,
	BARRELROBOT_TURN = 4,
	BARRELROBOT_SIT = 5,
	BARRELROBOT_SITSHOOT = 6
};

typedef struct ambushDesc_s {
	int animstage1;
	int animstage2;
	int animstage3;
	int animstage4;
} ambushDesc;

enum {
	EA_START = 0,
	EA_READY = 1,
	EA_AMBUSH = 2,
	EA_ATTACK = 3,
	EA_BACK = 4
};

enum {
	EPD_SETUP = 0,
	EPD_WAITFORTRIGGER = 1,
	EPD_GETUP = 2
};

enum {
	EPB_SETUP = 0,
	EPB_WAITFORTRIGGER = 1,
	EPB_GETTOBUTTON = 2,
	EPB_PRESSBUTTON = 3,
	EPB_FINISHED = 4
};

aifireinfo firerange[33] = {
	/* [0] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 2
	},
	/* [1] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 6
	},
	/* [2] = */ {
		/* .minrange = */ 10.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 6
	},
	/* [3] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 40.f,
		/* .repeatfire = */ 1
	},
	/* [4] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 6
	},
	/* [5] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 6
	},
	/* [6] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 15
	},
	/* [7] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 6
	},
	/* [8] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 40.f,
		/* .repeatfire = */ 1
	},
	/* [9] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 3
	},
	/* [10] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 15
	},
	/* [11] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 1
	},
	/* [12] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 1
	},
	/* [13] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 1
	},
	/* [14] = */ {
		/* .minrange = */ 6.f,
		/* .maxrange = */ 12.f,
		/* .repeatfire = */ 1
	},
	/* [15] = */ {
		/* .minrange = */ 6.f,
		/* .maxrange = */ 12.f,
		/* .repeatfire = */ 1
	},
	/* [16] = */ {
		/* .minrange = */ 6.f,
		/* .maxrange = */ 12.f,
		/* .repeatfire = */ 1
	},
	/* [17] = */ {
		/* .minrange = */ 10.f,
		/* .maxrange = */ 22.f,
		/* .repeatfire = */ 1
	},
	/* [18] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 6
	},
	/* [19] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 35.f,
		/* .repeatfire = */ 2
	},
	/* [20] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 10
	},
	/* [21] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 1
	},
	/* [22] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 2
	},
	/* [23] = */ {
		/* .minrange = */ 12.f,
		/* .maxrange = */ 25.f,
		/* .repeatfire = */ 2
	},
	/* [24] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 1
	},
	/* [25] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 1
	},
	/* [26] = */ {
		/* .minrange = */ 8.f,
		/* .maxrange = */ 18.f,
		/* .repeatfire = */ 1
	},
	/* [27] = */ {
		/* .minrange = */ 0.f,
		/* .maxrange = */ 0.f,
		/* .repeatfire = */ 0
	},
	/* [28] = */ {
		/* .minrange = */ 0.f,
		/* .maxrange = */ 0.f,
		/* .repeatfire = */ 0
	},
	/* [29] = */ {
		/* .minrange = */ 0.f,
		/* .maxrange = */ 0.f,
		/* .repeatfire = */ 0
	},
	/* [30] = */ {
		/* .minrange = */ 0.f,
		/* .maxrange = */ 0.f,
		/* .repeatfire = */ 0
	},
	/* [31] = */ {
		/* .minrange = */ 0.f,
		/* .maxrange = */ 0.f,
		/* .repeatfire = */ 0
	},
	/* [32] = */ {
		/* .minrange = */ 0.f,
		/* .maxrange = */ 0.f,
		/* .repeatfire = */ 0
	}
};

int numLvButtons = 0;

static int stationaryPatrolRt[4] = {
	/* [0] = */ 0,
	/* [1] = */ -3,
	/* [2] = */ -10,
	/* [3] = */ -1
};

static int sleepplayercheck = 0;
static int sleepcheckindex = 0;
int debugwokenupstat = 0;

ambushDesc ambushdesc[10] = {
	/* [0] = */ {
		/* .animstage1 = */ 76,
		/* .animstage2 = */ 90,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 88
	},
	/* [1] = */ {
		/* .animstage1 = */ 77,
		/* .animstage2 = */ 91,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 89
	},
	/* [2] = */ {
		/* .animstage1 = */ 76,
		/* .animstage2 = */ 94,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 92
	},
	/* [3] = */ {
		/* .animstage1 = */ 77,
		/* .animstage2 = */ 95,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 93
	},
	/* [4] = */ {
		/* .animstage1 = */ 76,
		/* .animstage2 = */ 98,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 96
	},
	/* [5] = */ {
		/* .animstage1 = */ 77,
		/* .animstage2 = */ 99,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 97
	},
	/* [6] = */ {
		/* .animstage1 = */ 76,
		/* .animstage2 = */ 101,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 96
	},
	/* [7] = */ {
		/* .animstage1 = */ 77,
		/* .animstage2 = */ 102,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 100
	},
	/* [8] = */ {
		/* .animstage1 = */ 76,
		/* .animstage2 = */ 105,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 103
	},
	/* [9] = */ {
		/* .animstage1 = */ 77,
		/* .animstage2 = */ 106,
		/* .animstage3 = */ -1,
		/* .animstage4 = */ 104
	}
};

static alarmdata levelalarms[5];
static int numAlarms;

lvbuttondata levelbuttons[10] = {
	/* [0] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [1] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [2] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [3] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [4] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [5] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [6] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [7] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [8] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	},
	/* [9] = */ {
		/* .setupref = */ 0,
		/* .chrpadnum = */ 0,
		/* .prop = */ NULL,
		/* .type = */ 0,
		/* .flags = */ 0,
		/* .handlerfn = */ NULL,
		/* .status = */ 0,
		/* .activater = */ NULL,
		/* .timer1 = */ 0.f,
		/* .data1 = */ 0,
		/* .fdata1 = */ 0.f,
		/* .vdata1 = */ NULL
	}
};

static communicationList commList[12];

void enemySingleRestart() {}

void enemySingleReset() {}

void enemySingleSetup() {
	int i;
	int chrtypeuse;
	int chrtypeoriginal;
	prop *p;
	setupNPC *npc;
	int chrtypeuse;
	int chrtypeoriginal;
}

void enemyAddToButtonList(setupbutton *sb, prop *p) {
	lvbuttondata *b;
}

int enemyGetButtonNumFromSetupRef(int setupref) {
	int i;
	lvbuttondata *b;
}

void enemyAddToAlarmList(setupalarm *sa) {
	alarmdata *a;
}

int enemyGetAlarmNumFromSetupRef(int setupref) {
	int i;
	alarmdata *a;
}

void enemyAlarmTick() {
	alarmdata *a;
	float timeinc;
	int i;
	int alarmOn;
}

void enemyAlarmSetState(int i, int newstate, void *data1) {
	alarmdata *a;
}

void enemySnipe1(prop *p) {
	chrdata *cd;
	int canseetarget;
}

void enemyStandShoot(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	float playertopropdist;
	float closestplayerdist;
	int i;
	int lastsawtarget;
	int waittime;
	int canseetarget;
}

void enemyCharge(prop *p) {
	chrdata *cd;
	int canseetarget;
	int dx;
	int dy;
	int dz;
}

void enemyPatrol(prop *p) {
	chrdata *cd;
	float dist;
	float dx;
	float dy;
	float dz;
	float compdist;
	int padnum;
	int *pr;
	int psize;
	int aware;
	int index;
	int index;
}

static int enemyPatrolIsTurning(prop *p) {}

static int enemyPatrolCanPlayTurn(prop *p, int animPatrol) {
	int animframe;
}

static void enemyPatrolPlayTurn(prop *p, int animPatrol) {
	int choice;
}

static int enemyPatrolCanReact(prop *p, float tweentime) {
	float tagtime;
}

static boolean eacGetToCrouch(prop *p) {}

static boolean eacGetToStand(prop *p) {}

void enemyAmbushCrouch(prop *p) {
	chrdata *cd;
	float OUTFLANK_ANGLE;
	float dx;
	float dy;
	float dz;
	float choose;
	pad *padptr;
	int canseetarget;
	int lastsawtarget;
	int waittime;
	int animframe;
	int tagframe;
	float dir[3];
	float rlen;
	mtx_u rotmtx;
	int animframe;
	int startshoottag;
	int stopshoottag;
}

boolean handleOutOfAmmo(chrdata *cd) {}

void enemySingleZombieAttack(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	float distsq;
	float rottarget;
	int doingSwipe;
	int canseetarget;
	float choice;
}

void swipeTest(prop *p, int righthand) {
	mtx_u tmpmtx;
	mtx_u mtx;
	chrdata *cd;
	float shoulder[3];
	float end[3];
	float hitpos[3];
	prop *hitprop;
	float Dir[3];
	float frac;
}

void enemyAttackObject(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	int canseetarget;
}

void enemySnipeAttack(prop *p) {
	chrdata *cd;
	int i;
	float dx;
	float dy;
	float dz;
	int canseetarget;
}

void enemyBarrelRobot(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	float dist;
	float rot;
	int padnum;
	int seetarget;
}

void enemyRemoveFromCommList(prop *p) {
	chrdata *cd;
	int i;
	int index;
	int listnum;
}

void enemyAddToCommList(prop *p) {
	chrdata *cd;
}

void enemySleep(prop *p) {
	chrdata *cd;
}

void enemyFromSleepToAwake(prop *p) {
	chrdata *cd;
}

void enemyAwake(prop *p) {
	chrdata *cd;
	int aware;
}

void enemyPlayActivationSound(prop *p) {
	chrdata *cd;
}

void enemySetIdleAnimation(prop *p) {
	chrdata *cd;
	animData ad;
}

void enemyInformOthers(int informertype, void *data1, int data2) {
	int ignorechr;
	int commlistnum;
	int i;
	chrdata *infcd;
	int alertpad;
	chrdata *loopcd;
	int j;
	boolean doclone;
	float dx;
	float dy;
	float dz;
	chrdata *clonecd;
}

int enemyStoryPlayerAtPad(int extref) {
	int p;
}

static chrdata* enemyCreateCloneNPC(chrdata *parentcd) {
	setupNPC *parentnpc;
	int chrtypeuse;
	int chrtypeoriginal;
	int cindex;
	chrdata *newcd;
	int padextref;
}

void enemySingleUpdateVisTable() {
	float dir[3];
	float pos[3];
	chrdata *cd;
	prop *phit;
	prop *target;
	int found;
	int exit;
	int prevflags;
	int prevNPCindex;
	int i;
	int leastframe;
	int chrindex;
	chrdata *loopcd;
	float dir[3];
	float pos[3];
}

void enemyShowAlertStateGfx() {}

void enemyAmbush(prop *p) {
	chrdata *cd;
	pad *padptr;
	int ambush;
	int canseetarget;
	int lastsawtarget;
	int waittime;
}

void enemyPlaySound(prop *p, int sfx) {
	chrdata *cd;
}

void enemyPlayDead(prop *p) {
	chrdata *cd;
	animData ad;
}

void enemyPressButton(prop *p) {
	chrdata *cd;
	lvbuttondata *bd;
}

boolean enemyAlarmIsOn(int i) {}

int enemyGetNumAlarms() {}

alarmdata* enemyGetAlarm(int i) {}

lvbuttondata_s* enemyGetButton(int i) {}

int enemyGetNumButtons() {}
