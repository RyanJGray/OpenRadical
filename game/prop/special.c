// STATUS: NOT STARTED

#include "special.h"

char *watertexnames[16] = {
	/* [0] = */ 0x44e0b8,
	/* [1] = */ 0x44e090,
	/* [2] = */ 0x44e068,
	/* [3] = */ 0x44e040,
	/* [4] = */ 0x44e018,
	/* [5] = */ 0x44dff0,
	/* [6] = */ 0x44dfc8,
	/* [7] = */ 0x44dfa0,
	/* [8] = */ 0x44df78,
	/* [9] = */ 0x44df50,
	/* [10] = */ 0x44df28,
	/* [11] = */ 0x44df00,
	/* [12] = */ 0x44ded8,
	/* [13] = */ 0x44deb0,
	/* [14] = */ 0x44de88,
	/* [15] = */ 0x44de60
};

float waterOffsets = 0.f;
float waterOffsett = 0.f;

int electricityOn[12] = {
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
	/* [11] = */ 0
};

float electricityTime[12] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f,
	/* [3] = */ 0.f,
	/* [4] = */ 0.f,
	/* [5] = */ 0.f,
	/* [6] = */ 0.f,
	/* [7] = */ 0.f,
	/* [8] = */ 0.f,
	/* [9] = */ 0.f,
	/* [10] = */ 0.f,
	/* [11] = */ 0.f
};

float electricityTextureOffset[12] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f,
	/* [3] = */ 0.f,
	/* [4] = */ 0.f,
	/* [5] = */ 0.f,
	/* [6] = */ 0.f,
	/* [7] = */ 0.f,
	/* [8] = */ 0.f,
	/* [9] = */ 0.f,
	/* [10] = */ 0.f,
	/* [11] = */ 0.f
};

float hologramAlpha = 0.f;
static float clockRadHours;
static float clockRadMinutes;
static float clockRadSeconds;
static int clockHours;
static int clockMinutes;
static int clockSeconds;
static int clockChimed;
static int GibsInPlay;
static prop *Gibs[20];

texinfo watertexinfo[16] = {
	/* [0] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [1] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [2] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [3] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [4] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [5] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [6] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [7] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [8] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [9] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [10] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [11] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [12] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [13] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [14] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	},
	/* [15] = */ {
		/* .id = */ 0,
		/* .clampu = */ 0,
		/* .clampv = */ 0,
		/* .flags = */ 0
	}
};

float *waterMemory[2] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL
};

float waterperiodx = 0.f;
float waterperiodz = 0.f;
float waterspeedx = 0.f;
float waterspeedz = 0.f;
float wateramplitude = 0.f;
float waterreduction = 0.f;

void propPreloadSpecial() {
	int t;
}

void propRestartSpecial() {
	int i;
}

void propResetSpecial() {}

void propEndSpecial() {}

void propEvictSpecial(prop *p) {
	specialdata *data;
}

void propDeleteSpecial(prop *p) {}

void vtxlistWaterxyzPre(int gfxtype, prop *p) {
	partdef *part;
	gfxchunk *chunk;
	int numvtx;
	float periodx[3];
	float periodz[3];
	float speedx[3];
	float speedz[3];
	float amplitude[3];
	float reduction[3];
	float xmin[3];
	float xmax[3];
	float zmin[3];
	float zmax[3];
	float xdiff;
	float zdiff;
	float x;
	float z;
	float zscalar;
	float rightdist;
	float leftdist;
	float topdist;
	int i;
	int which;
	float *sxyz;
}

void vtxlistWaterxyz(float *sxyz, float *dxyz, int numvtx, int gfxtype, prop *p) {
	float x;
	float z;
	int i;
}

void vtxlistWaterst(float *sst, float *dst, int numvtx) {
	int i;
	float sinevalue;
	float offsets;
}

void propTickWater(prop *p) {
	int i;
	int numvtx;
	u32 *cptr;
	partdef *parts;
	int animspeed;
	int waterframe;
}

prop* propNewWater(int num, float x, float y, float z, float roty) {
	int t;
	prop *p;
}

float specialGetLeverage(prop *p, float *hitpos) {
	specialdata *data;
	float dist[3];
	float lensq;
}

void specialPropSwingNonAxial(prop *p) {
	specialdata *data;
	float rotIntensity;
	float weightPull;
	float oldrot;
}

void specialPropSwingAxial(prop *p) {
	specialdata *data;
	float rotIntensity;
	float weightPull;
	float oldrot;
}

float specialGetSwingMagnitudeAxial(float *bulletnormal, float *normal) {
	float angle;
}

static void streamersPropTick(prop *p) {
	specialdata *data;
	u32 *cptr;
	partdef *parts;
	int numvtx;
	int i;
	float *sxyz;
	float *dxyz;
	float x;
	float unique;
	float framemult;
}

static void reflectionsPropTick(prop *p) {
	u32 *cptr;
	partdef *parts;
	int numvtx;
	int i;
	float *sxyz;
	float *dxyz;
}

static void scannerPropTick(prop *p) {}

static void fanPropTick(prop *p) {}

static void fanshadowPropTick(prop *p) {}

static void fanscifiPropTick(prop *p) {}

static void fanChinesePropTick(prop *p) {}

static void mallfan1PropTick(prop *p) {}

static void mallfan2PropTick(prop *p) {}

void calculateClockTime() {
	int hours;
	int minutes;
	int seconds;
	float hoursf;
	float minutesf;
	float secondsf;
}

static void clockPropTick(prop *p) {}

static void mallclockPropTick(prop *p) {}

void gangsterPaperDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
	float leverage;
}

static void gangsterPaperTick(prop *p) {
	specialdata *data;
	float wind[3];
	int i;
}

void gangsterClothesDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void gangsterClothesTick(prop *p) {
	int i;
	specialdata *data;
}

void pubsignDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void pubsignPropTick(prop *p) {
	int i;
	specialdata *data;
}

void boatsignDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void boatsignPropTick(prop *p) {
	int i;
	specialdata *data;
}

void gongDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void gongPropTick(prop *p) {
	int i;
	specialdata *data;
}

void bannerDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void bannerPropTick(prop *p) {
	specialdata *data;
	int i;
}

void lanternDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void lanternPropTick(prop *p) {
	specialdata *data;
	float wind[3];
	int i;
}

void chandelierDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
}

static void chandelierPropTick(prop *p) {
	specialdata *data;
	float wind[3];
	int i;
}

static void polePropTick(prop *p) {}

static void electricityPropTick(prop *p) {
	int pa;
	int i;
	int count;
	u32 *cptr;
	u32 *sptr;
	partdef *parts;
	int numvtx;
	partdef *part;
	float *sxyz;
	float *dxyz;
	float *sst;
	float *dst;
	float framemult;
	float var1;
	float var2;
}

static void outerwheelsPropTick(prop *p) {}

static void innerwheelsPropTick(prop *p) {
	float y;
	float magy;
	float multiplier;
	float var;
	float framemult;
}

static void spaceship1PropTick(prop *p) {
	u32 *cptr;
	partdef *part;
	int numvtx;
	specialdata *data;
	float oldrot;
	int i;
	float *sst;
	float *dst;
}

void spaceship2PropTick(prop *p) {}

void spaceship3PropTick(prop *p) {}

void bigshipPropTick(prop *p) {}

void greenthingPropTick(prop *p) {
	u32 *cptr;
	partdef *parts;
	int numvtx;
	int i;
	float *sxyz;
	float *dxyz;
	float x;
	float z;
}

static void waterfallPropTick(prop *p) {
	u32 *cptr;
	partdef *parts;
	specialdata *data;
	int numvtx;
	int i;
	float *sst;
	float *dst;
	float change;
}

void hologramPropTick(prop *p) {
	int l;
	int active;
	u32 alpha;
	chrdata *loopcd;
	float distx;
	float distz;
	partdef *parts;
	int numvtx;
	int partnum;
	u32 *cptr;
	u32 *sptr;
	partdef *part;
	int v;
}

void laserPropTick(prop *p) {
	u32 alpha;
	partdef *parts;
	int numvtx;
	int partnum;
	u32 *cptr;
	u32 *sptr;
	partdef *part;
	int v;
}

void planetspawnPropTick(prop *p) {
	u32 *cptr;
	partdef *parts;
	specialdata *data;
	int numvtx;
	int i;
	float *sy;
	u32 *drgba;
	float alphahigh;
	float alphalow;
	u32 alpha;
	float yscalar;
	float gf;
	float bf;
	u32 r;
	u32 g;
}

void planetspawn2PropTick(prop *p) {}

void rotatespawnPropTick(prop *p) {
	int a;
	specialdata *data;
}

void blastspawnPropTick(prop *p) {
	int a;
	specialdata *data;
}

void ringspawnPropTick(prop *p) {
	int a;
	specialdata *data;
}

void splitterdomePropTick(prop *p) {
	int a;
	specialdata *data;
}

void tombtorchPropTick(prop *p) {
	u32 *cptr;
	partdef *parts;
	specialdata *data;
	int numvtx;
	partdef *part;
	int i;
	float *sst;
	float *dst;
	float change;
}

void cranePropTick(prop *p) {
	specialdata *data;
	float rise;
	float roty;
	int i;
	mtx_u mat;
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
	float pos[3];
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
	float pos[3];
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
	float sectiontime;
	float scalar;
}

void neotokyoSign1Tick(prop *p) {}

void neotokyoSign2Tick(prop *p) {
	specialdata *data;
}

void neotokyoSign3Tick(prop *p) {}

void neotokyoTrafficLightsTick(prop *p) {
	specialdata *data;
}

void damRadarPropTick(prop *p) {
	specialdata *data;
	float secpassed;
}

void damRadarSwitchPropActivate(prop *p) {
	float pos[3];
	float bias[3];
	int i;
	particlegroup *pg;
}

void damTurbineTick(prop *p) {
	specialdata *data;
	float secpassed;
}

void damMainTurbineTick(prop *p) {
	specialdata *data;
	float pos[3];
	float bias[3];
}

void damBackupTurbineTick(prop *p) {}

void damTurbineSetState(prop *p, int turbineState) {
	specialdata *data;
}

void damCagePropDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {}

void damCageActivate(prop *p) {
	specialdata *data;
}

void damCagePropTick(prop *p) {
	int i;
	int m;
	float wind[3];
	specialdata *data;
	float destpos;
	float destpos;
}

void damComputerDeskTick(prop *p) {}

void damComputerSwitched(prop *p) {}

void specialSetDamDial(prop *p, int state) {
	specialdata *data;
}

void damPipeWheelTick(prop *p) {
	specialdata *data;
	float secpassed;
}

void damPipeWheelActivate(prop *p, prop *actor) {
	specialdata *data;
}

boolean specialDamWheelOn(prop *p) {
	specialdata *data;
}

prop* propNewSpecial(int num, float *pos, float *rot, float *extra, void *ref, void (*callback)(/* parameters unknown */)) {
	prop *p;
	specialdata *data;
	mtx_u rotmtx;
	float up[3];
	float frac;
	int a;
	float soundpos[3];
}

void propSpecialGibWoodenObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

void propSpecialGibMetalObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

void propSpecialGibGlassObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

void propSpecialGibCardObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

void propSpecialGibLeafObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

void propSpecialGibStoneObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

void propSpecialGibFruitObject(float *CentrePos, float *Direction, int NumOfGibs, float GroundHeight) {
	int i;
	float RandomDirection[4];
	float rot[3];
}

static void specialDeleteOldestGib() {}

static void specialDeleteGib(prop *p) {}

static void specialCheckSpaceForGib() {}

static void specialCleanUpBeforeDeleteGib(prop *p) {
	int i;
	int OneLess;
}

void GibPropTick(prop *p) {
	specialdata *data;
	int alpha;
}

void damFireExtDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	specialdata *data;
	float frac;
	float frac;
	float frac;
	specialdata *data;
}

static void propFireExtActivate(prop *p, prop *actor) {
	chrdata *cd;
	int didowngun;
}

void propSpecialFireExtTick(prop *p) {
	specialdata *data;
	chrdata *chdata;
	gunInfo_t *gi;
	prop *hit;
	float hitpos[3];
	float hitnorm[3];
	float testdir[3];
	float testpos[3];
	float From[3];
	float Normal[3];
	mtx_u tmpmtx;
	glassResults glassRes;
	int i;
	glassHit *hit;
	glassdef *glass;
	float col[3];
	float ndir[3];
	float dot;
	float reflect[3];
	float frac;
	float frac;
}

void specialFileCabinetActivate(prop *p, prop *actor) {}

void specialFileCabinetTick(prop *p) {
	int mtxindex;
	mtx_u tmpmtx;
}

void specialFileCabinetBurningTick(prop *p) {
	float secpassed;
	float dir[3];
	float pos[3];
	mtx_u Mtx;
	float BulNorm[3];
	float HitPos[3];
}

static boolean specialFireExtFadeAway(prop *p) {
	specialdata *data;
	int alpha;
}

void specialRailSpiderTestTick(prop *p) {
	remotedata *data;
	float temp;
	float LensPos[3];
	boolean result;
}

static void specialRailJunctionBox(prop *p) {
	remotedata *data;
}

static boolean specialRailPipesCorridor(prop *p, float Vel) {}

static boolean specialRailFirstR1(prop *p, float Vel) {
	float anglefac;
}

static boolean specialRailFirstR2(prop *p, float Vel) {
	float anglefac;
}

static boolean specialRailOverhangR1(prop *p, float Vel) {}

static boolean specialRailOverhangR2(prop *p, float Vel) {}

static boolean specialRailSlopeR1(prop *p, float Vel) {
	float anglefac;
}

static boolean specialRailSlopeR2(prop *p, float Vel) {
	float anglefac;
}

static boolean specialRailSlopeR3(prop *p, float Vel) {
	float anglefac;
}

static boolean specialRailBossR1(prop *p, float Vel) {
	float angle;
	float delta[3];
	float deltasize;
	float npos[3];
	mtx_u tmpmtx;
	float frac;
	float frac;
}

static boolean specialRailBossR2(prop *p, float Vel) {
	float angle;
	float delta[3];
	float deltasize;
	float npos[3];
	mtx_u tmpmtx;
	float frac;
	float frac;
}

void specialRailPutOnNearestSection(prop *p) {
	remotedata *rd;
	float TempVec[3];
}
