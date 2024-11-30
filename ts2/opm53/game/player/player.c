// STATUS: NOT STARTED

#include "player.h"

typedef enum {
	AUTOCENTRE_ALLOW = 0,
	AUTOCENTRE_PROHIBIT = 1,
	AUTOCENTRE_ACTIVE = 2,
	AUTOCENTRE_NUM = 3
};

short int handicapstrings[7] = {
	/* [0] = */ 1274,
	/* [1] = */ 1275,
	/* [2] = */ 1276,
	/* [3] = */ 1277,
	/* [4] = */ 1278,
	/* [5] = */ 1279,
	/* [6] = */ 1280
};

float crouchSpeed[2] = {
	/* [0] = */ 4.f,
	/* [1] = */ 8.f
};

float runSpeed[2] = {
	/* [0] = */ 8.f,
	/* [1] = */ 20.f
};

float walkSpeed[2] = {
	/* [0] = */ 4.f,
	/* [1] = */ 8.f
};

float runStrafeSpeed[2] = {
	/* [0] = */ 7.f,
	/* [1] = */ 3.f
};

float walkStrafeSpeed[2] = {
	/* [0] = */ 3.f,
	/* [1] = */ 1.4f
};

float maxForwardAccel[2] = {
	/* [0] = */ 5.f,
	/* [1] = */ 1.8f
};

float maxForwardDecel[2] = {
	/* [0] = */ 5.f,
	/* [1] = */ 0.5f
};

float maxStrafeAccel[2] = {
	/* [0] = */ 8.f,
	/* [1] = */ 4.f
};

int playerConfigNames[7] = {
	/* [0] = */ 1205,
	/* [1] = */ 1206,
	/* [2] = */ 1207,
	/* [3] = */ 1208,
	/* [4] = */ 1209,
	/* [5] = */ 1210,
	/* [6] = */ 1211
};

static int nexttestfrom = -1;
static int nexttestto = -1;
player *players = NULL;
player *currentplayer = NULL;
static int autoaimskipframes;

void playerprintpos(int p) {}

void playerSetWindow(player *p) {}

static void playerSetStartGun(player *p) {
	chrdata *cd;
	int GunCombo;
	gunset *lvgunset;
}

void playerSetStartPos(player *p) {
	int padnum;
	pad *padptr;
	setupheader *setup;
	int nthone;
	int i;
	chrdata *cd;
	int Pad;
	int padnum;
}

float playerGetAxis(player *player, int gameControl) {}

void playerPreload() {
	int i;
	int skypropnum;
	int chrtype;
}

void playerSetDefaultControls(int confignum, int *controls) {}

void playerSetControls(player *p) {
	playerprefs_t *pprefs;
	int confignum;
}

void playerRestart() {
	int i;
	int j;
	player *p;
	int chrtype;
	chrdesc *pchr;
	chrdata *pdat;
	static playerprefs_t demoplayer_prefs;
	prop *hat;
	int propnum;
	chrdata *cd;
}

void playerReset() {
	int i;
	player *p;
}

void playerDirtyPosReset() {
	int i;
	player *p;
}

void playerRespawn(player *ply) {
	chrdata *chr;
	int j;
}

static void playerDeathMessage(player *p) {
	chrdata *killer;
}

void playerDie(player *p, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, int parthit, int deathflag) {
	chrdata *attackerdata;
}

void playerOnGroundDie(player *p, int bullettype, float *hitpos, float *bulletnorm, int parthit, int deathflag) {
	chrdata *cd;
}

void playerMessage(player *player, u8 *text) {}

static void playerAutoAimRestart() {}

static void playerAutoAimCalc(float *lookdir, float *cdir, autoaiminfo *aa) {
	float rdist;
	float ncdir[3];
}

void playerAutoAimTick() {
	mtx_u tmpmtx;
	mtx_u mtx;
	int donetest;
	int counter;
	player *p;
	autoaiminfo *aa;
	chrdata *cd;
	chrdata *playercd;
	float cpos[3];
	float cdir[3];
	prop *hitprop;
}

static void playerDeathView() {
	prop *pProp;
	chrdata *pChrData;
	int i;
	boolean FindNewTarget;
	float DeathViewWantedDir[3];
	boolean WantedDirSet;
	float Dir[3];
	chrdata *cd;
	prop *p;
	float Dir[3];
	float DirNorm[3];
	float Dot;
	float frac;
	float dx;
	float dy;
	float dz;
	float frac;
	float frac;
	float frac;
}

void playerHandleZoom() {
	chrdata *cd;
	int f;
	boolean toggleZoom;
	float zoomaxis;
}

void playerCalculateSway() {
	float swayamount;
}

static void playerSetCamDef() {}

static void playerGetJoyLookMove(float *JoyLook, float *JoyMove) {}

static void playerUpdateDirXY(float *JoyLook, float *JoyMove, float *RotAmount) {
	chrdata *cplayerdata;
	float filter;
	prop *rp;
	remotedata *rd;
	float Dist;
	prop *pRemoteProp;
	float MaxY;
	float MinY;
	float MinY1;
	float HalfWay;
}

static int playerBestAutoAimChr(float *AimPos, float *AimDir) {
	chrdata *cplayerdata;
	mtx_u tmpmtx;
	mtx_u mtx;
	float bestdot;
	int i;
	int best;
	remotedata *rd;
	chrdata *cd;
	autoaiminfo *aa;
	float cpos[3];
	float cdir[3];
	float frac;
}

static void playerGetAimInfo(float *JoyLook) {
	chrdata *cplayerdata;
	float dx;
	float dy;
	float AimPos[3];
	float AimDir[3];
	int Best;
	chrdata *cd;
	float AimPos[3];
	float AimDir[3];
	int Best;
	chrdata *cd;
}

void playerTick() {
	chrdata *cplayerdata;
	mtx_u tmpmtx;
	mtx_u mtx;
	u32 Flags;
	int i;
	chrdata *loopcd;
	float up[3];
	float newpos[3];
	float fwdist;
	float strafedist;
	float movecx;
	float movesx;
	float lookcx;
	float looksx;
	float lookcy;
	float looksy;
	float RotAmount[2];
	float JoyLook[2];
	float JoyMove[2];
	float dx;
	float dy;
	float dz;
	float diff;
	float maxchange;
	float diff;
	float maxchange;
	float frac;
	float frac;
	float MaxMove[2];
	float MinMove[2];
	float forward;
	float backward;
	float d1[3];
	float d2[3];
	float a;
	float b;
	float c;
	int i;
	int dopush;
	float pushx;
	float pushz;
	float FloorHeight;
	float FloorHeightDiff;
	float FloorMoveHeight;
	float push[3];
	float thispushlen;
	float pushfrac;
	float FallHeight;
	mtx_u rotmtx;
	prop *pRemoteProp;
	remotedata *pd;
	float AngleDiff;
	float StandPos[3];
	float AmountAdd;
	prop *pRemoteProp;
	float StandPos[3];
	int i;
	float dir[3];
	int lastroom;
	int thisroom;
	int origroom;
	int nextroom;
	float dir[3];
	float tmppos[3];
	float tmpdir[3];
	int rooms[10];
	float bb[2][3];
	int numrooms;
	float dirNeg[3];
	int e;
	int e;
}

void playerFrustrumGfx() {}

void playerHitPosGfx() {}

static void playerselectanim(float fwaxis, float strafeaxis, float turnaxis) {
	prop *playerprop;
	float z1;
	float z2;
	float frames;
	float trans;
	int daxis;
	chrdata *pcd;
}

void playerEnd() {}

float anglediff(float a1, float a2) {
	float diff;
}

void debugtesthits() {
	float pos[3];
	float pos2[3];
	float dir[3];
	float hitpos[3];
	float hitnorm[3];
	int newroom;
	prop *chrhit;
}

int playerGetHudType(player *player) {
	chrdata *cd;
	int type;
}

boolean playerIsDead(player *player) {}
