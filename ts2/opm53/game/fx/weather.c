// STATUS: NOT STARTED

#include "weather.h"

struct fireFlyParticle_s {
	float pos[3];
	float velocity[3];
	float destPos[3];
	float timeThisWay;
	float lifetime;
	float totalLifetime;
};

typedef fireFlyParticle_s fireFlyParticle;

struct snowParticle_s {
	float pos[3];
	float velocity[3];
	float wind;
};

typedef snowParticle_s snowParticle;

struct precBlockPrecalc_s {
	float blockPos[3];
	boolean autopass;
};

typedef precBlockPrecalc_s precBlockPrecalc;

struct weatherBoundsData_s {
	float distsqFromPlayer[4];
	float precipitationScale[4];
	fireFlyParticle fireFlies[2];
	int blocksx;
	int blocksy;
	int blocksz;
	float *clippingx;
	float *clippingy;
	float *clippingz;
	precBlockPrecalc *blocks;
};

typedef weatherBoundsData_s weatherBoundsData;

struct weatherRoomData_s {
	float distsqFromPlayer[4];
	float splashScale[4];
	int fxUsage;
	int numBounds;
	weatherBoundsData *bounds;
};

typedef weatherRoomData_s weatherRoomData;
snowParticle *snowBlockParticles = NULL;
weatherRoomData *weatherRooms = NULL;
static int snowballtexnum = -1;
static int fireFlyTexNum = -1;

weatherdata defaultweather = {
	/* .type = */ 0,
	/* .magnitude = */ 0,
	/* .wind = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.5f
	},
	/* .windvariation = */ {
		/* [0] = */ 0.3f,
		/* [1] = */ 0.3f,
		/* [2] = */ 0.3f
	},
	/* .precipitationalpha = */ 0,
	/* .splashalpha = */ 0
};

static int snowcpu = 1;
static float splashTime;
static int numSplashes;
static u32 precipitationalpha;
static u32 splashalpha;
static u32 precipitationcol;
static float precipitationwind[3];
static boolean rainEnabled;
static boolean snowEnabled;
static boolean fireFlyEnabled;

weatherinfo weather = {
	/* .numweatherdata = */ 0,
	/* .data = */ NULL,
	/* .currentweather = */ 0,
	/* .destweather = */ 0,
	/* .ratio = */ 0.f,
	/* .windspeed = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 0.f,
		/* [2] = */ 0.f
	},
	/* .windtime = */ 0.f
};

weatherdata* weatherGetCurrentWeatherData() {}

float weatherCalcPositionalTime(float *pos) {}

void weatherCalcWindAtTime(float *wind, float time) {
	float medscalar[3];
	float lowscalar[3];
}

void weatherGetWindAtPosition(float *pos, int room, float *wind) {}

float weatherCalcWindStrengthInDir(float *pos, int room, float *dir) {
	float wind[3];
}

void weatherWindTick() {}

void weatherPrecipitationReset() {
	int room;
	weatherRoomData *wRoom;
	weatherdef **weather;
}

void weatherPrecipitationEnd() {}

void weatherBlockPrecalc(float blocksizex, float blocksizey, float blocksizez) {
	int room;
	weatherRoomData *wRoom;
	weatherdef **weather;
	int w;
	weatherBoundsData *bounds;
	weatherdef *wdef;
	int totalblocks;
	float startBlockNumf[3];
	int startBlockNum[3];
	float endBlockNumf[3];
	int endBlockNum[3];
	boolean autopass;
	float blockPos[3];
	float blockPosEnd[3];
	int x;
	int y;
	int z;
	float startz;
	float startzClip;
	float endzClip;
	float startzBlockNumf;
	int startzBlockNum;
	float startx;
	float startxClip;
	float endxClip;
	float startxBlockNumf;
	int startxBlockNum;
	precBlockPrecalc *pbp;
	float starty;
	float startyClip;
	float endyClip;
	float startyBlockNumf;
	int startyBlockNum;
}

void weatherSnowPreload() {}

void weatherSnowRestart() {
	int s;
}

void weatherSnowReset() {}

void weatherSnowEnd() {}

void weatherSnowTick() {
	float secpassed;
	int pl;
	weatherdata *wd;
	float high[3];
	float medscalar[3];
	float low[3];
	float extra[3];
	int roomindex;
	ViewDef *pView;
	int room;
	weatherRoomData *wRoom;
	weatherdef **weather;
	int w;
	float dist[3];
	float distsq;
	weatherBoundsData *bounds;
	weatherdef *wdef;
	float centrepos[3];
	int s;
	snowParticle *sp;
}

void weatherSnowGfx() {
	int roomindex;
	int texwidth;
	int texheight;
	float fovscale;
	float snowscale;
	float bbmin[3];
	float bbmax[3];
	float forward[3];
	float right[3];
	float up[3];
	float pos[3];
	float rightamount;
	void *addr;
	int room;
	weatherRoomData *wRoom;
	weatherdef **weather;
	int w;
	weatherBoundsData *bounds;
	weatherdef *wdef;
	float distsq;
	u32 *pos;
	int num;
	u32 alpha;
	u32 rgba;
	int x;
	int y;
	int z;
	float startzClip;
	float endzClip;
	float startxClip;
	float endxClip;
	precBlockPrecalc *pbp;
	int s;
	float startyClip;
	float endyClip;
	float blockPosx;
	float blockPosy;
	float blockPosz;
	snowParticle *sp;
	int thisnum;
	u32 *ref;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
	float snowpos[3];
	float pos[3];
	float newpos[4];
	float scrpos1[2];
	float scrpos2[2];
	float scrpos3[2];
	float scrpos4[2];
	float q;
	u32 *ref;
	float scale;
	void *addr;
	int thisnum;
	u32 *ref;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
}

void weatherRainPreload() {}

void weatherRainRestart() {}

void weatherRainReset() {}

void weatherRainEnd() {}

void weatherRainTick() {
	float secpassed;
	int pl;
	int e;
	int newSplash;
	weatherdata *wd;
	int currentRainAlpha;
	float high[3];
	float medscalar[3];
	float roomsdrawntotalfloorvolume;
	float averagefloorvolume;
	int roomindex;
	ViewDef *pView;
	int room;
	roombbinfo *rbb;
	int room;
	weatherRoomData *wRoom;
	weatherdef **weather;
	int w;
	float dist[3];
	float distsq;
	roombbinfo *rbb;
	float volumeproportion;
	weatherBoundsData *bounds;
	weatherdef *wdef;
	float centrepos[3];
	int found;
	ViewDef *pView;
	int tried;
	int splashroom;
	weatherRoomData *wRoom;
	floordef **floors;
	floordef *floor;
	float floorProportion;
	float u;
	float v;
	float dir1[3];
	float dir2[3];
	float randomval[20];
	float bias;
	int point;
	int numpoints;
	float totalrandom;
	float pos[3];
}

void weatherRainGfx() {
	int blend;
	int roomindex;
	u32 *ref;
	int room;
	weatherdef **weather;
	weatherRoomData *wRoom;
	int w;
	weatherdef *wdef;
	weatherBoundsData *bounds;
	float distsq;
	int r;
	float boundsize[3];
	float volume;
	int numraindrops;
	u32 rgba;
	float newpos1[4];
	float newpos2[4];
	int x1;
	int y1;
	int x2;
	int y2;
	int z1;
	int z2;
	float q1;
	float q2;
	float worldpos1[4];
	float worldpos2[4];
	void *addr;
}

void weatherFireFlyPreload() {}

void weatherFireFlyRestart() {
	int room;
	weatherRoomData *wRoom;
	int w;
	int fly;
}

void weatherFireFlyReset() {}

void weatherFireFlyEnd() {}

void weatherFireFlyGetPos(float *pos, weatherdef *wdef) {
	float roomsize0;
	float roomsize1;
	float roomsize2;
}

void weatherFireFlyTick() {
	float secpassed;
	int room;
	weatherRoomData *wRoom;
	int w;
	int fly;
	weatherdef *wdef;
	float diff[3];
	fireFlyParticle *flyParticle;
}

void weatherFireFlyGfx() {
	int roomindex;
	int texwidth;
	int texheight;
	float fovscale;
	float flyscale;
	int room;
	weatherRoomData *wRoom;
	int w;
	int fly;
	fireFlyParticle *flyParticle;
	float pos[3];
	float newpos[4];
	float scrpos1[2];
	float scrpos2[2];
	float scrpos3[2];
	float scrpos4[2];
	float q;
	u32 *ref;
	float scale;
	float lifeScalar;
	u32 rgba;
	float alpha;
	void *addr;
}

void weatherPreload() {
	setupheader *setup;
	int w;
	int type;
}

void weatherRestart() {}

void weatherReset() {}

void weatherEnd() {}

void weatherSet(int numweatherdata, weatherdata *weatherdat) {}

void weatherTick() {
	weatherdata *wd;
}

void weatherGfx() {
	weatherdata *wd;
	int oldzbmode;
}

boolean weatherIsInsideWeatherBounds(float *pos, int numRooms, int *rooms) {
	int n;
	weatherdef **weather;
	int w;
	weatherdef *wbb;
}

int weatherGetCurrentWeather() {}

void weatherSetSnow(boolean state) {
	weatherdata *wd;
}
