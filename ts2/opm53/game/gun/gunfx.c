// STATUS: NOT STARTED

#include "gunfx.h"

// warning: multiple differing types with the same name (#109,  not equal)
enum {
	FLAME_NONE = -1,
	FLAME_BG = 0,
	FLAME_PROP = 1,
	FLAME_CORPSE = 2,
	FLAME_CHR_TP = 3,
	FLAME_THROW_FP = 4,
	FLAME_THROW_TP = 5,
	NUM_FLAME_TYPES = 6
};

struct flameparticle_s {
	float pos[3];
	int chrnum;
	int viewnum;
	int gunfxType;
	int type;
	float time;
	float endtime;
	float dir[3];
	float rot;
	float sizeInitial;
	float sizeRange;
	float sizeMax;
	float zbias;
	int room;
};

typedef flameparticle_s flameparticle;

struct fcol_s {
	float r;
	float g;
	float b;
	float a;
};

typedef fcol_s fcol;

static fcol firecolours[9] = {
	/* [0] = */ {
		/* .r = */ 16.f,
		/* .g = */ 16.f,
		/* .b = */ 127.f,
		/* .a = */ 64.f
	},
	/* [1] = */ {
		/* .r = */ 16.f,
		/* .g = */ 16.f,
		/* .b = */ 112.f,
		/* .a = */ 64.f
	},
	/* [2] = */ {
		/* .r = */ 127.f,
		/* .g = */ 112.f,
		/* .b = */ 64.f,
		/* .a = */ 48.f
	},
	/* [3] = */ {
		/* .r = */ 127.f,
		/* .g = */ 80.f,
		/* .b = */ 48.f,
		/* .a = */ 48.f
	},
	/* [4] = */ {
		/* .r = */ 127.f,
		/* .g = */ 64.f,
		/* .b = */ 32.f,
		/* .a = */ 48.f
	},
	/* [5] = */ {
		/* .r = */ 127.f,
		/* .g = */ 64.f,
		/* .b = */ 32.f,
		/* .a = */ 48.f
	},
	/* [6] = */ {
		/* .r = */ 127.f,
		/* .g = */ 48.f,
		/* .b = */ 16.f,
		/* .a = */ 48.f
	},
	/* [7] = */ {
		/* .r = */ 127.f,
		/* .g = */ 32.f,
		/* .b = */ 0.f,
		/* .a = */ 32.f
	},
	/* [8] = */ {
		/* .r = */ 64.f,
		/* .g = */ 32.f,
		/* .b = */ 32.f,
		/* .a = */ 16.f
	}
};

char *fireTextureNames[8] = {
	/* [0] = */ 0x450688,
	/* [1] = */ 0x450668,
	/* [2] = */ 0x450648,
	/* [3] = */ 0x450628,
	/* [4] = */ 0x450608,
	/* [5] = */ 0x4505e8,
	/* [6] = */ 0x4505c8,
	/* [7] = */ 0x4505a8
};

static fcol extinguishercolours[9] = {
	/* [0] = */ {
		/* .r = */ 120.f,
		/* .g = */ 120.f,
		/* .b = */ 127.f,
		/* .a = */ 70.f
	},
	/* [1] = */ {
		/* .r = */ 115.f,
		/* .g = */ 115.f,
		/* .b = */ 127.f,
		/* .a = */ 60.f
	},
	/* [2] = */ {
		/* .r = */ 110.f,
		/* .g = */ 110.f,
		/* .b = */ 127.f,
		/* .a = */ 50.f
	},
	/* [3] = */ {
		/* .r = */ 105.f,
		/* .g = */ 105.f,
		/* .b = */ 127.f,
		/* .a = */ 45.f
	},
	/* [4] = */ {
		/* .r = */ 100.f,
		/* .g = */ 100.f,
		/* .b = */ 127.f,
		/* .a = */ 40.f
	},
	/* [5] = */ {
		/* .r = */ 100.f,
		/* .g = */ 97.f,
		/* .b = */ 127.f,
		/* .a = */ 35.f
	},
	/* [6] = */ {
		/* .r = */ 100.f,
		/* .g = */ 100.f,
		/* .b = */ 127.f,
		/* .a = */ 30.f
	},
	/* [7] = */ {
		/* .r = */ 103.f,
		/* .g = */ 100.f,
		/* .b = */ 127.f,
		/* .a = */ 20.f
	},
	/* [8] = */ {
		/* .r = */ 100.f,
		/* .g = */ 100.f,
		/* .b = */ 127.f,
		/* .a = */ 10.f
	}
};

char *bwFlameTextureNames[8] = {
	/* [0] = */ 0x450788,
	/* [1] = */ 0x450768,
	/* [2] = */ 0x450748,
	/* [3] = */ 0x450728,
	/* [4] = */ 0x450708,
	/* [5] = */ 0x4506e8,
	/* [6] = */ 0x4506c8,
	/* [7] = */ 0x4506a8
};

static float flameRise[2] = {
	/* [0] = */ 0.02f,
	/* [1] = */ 0.f
};

static int numFlames[6];
static flameparticle flames[200];
static int currentflame;
static float flameChrFpAngle;
static int fireTextureNum[8];
static int bwFlameTextureNum[8];

void gunfxPreload() {
	int i;
}

void gunfxReset() {}

void gunfxRestart() {
	int i;
	int f;
}

void gunfxEnd() {}

void gunfxTickPlayer() {}

void gunfxGfxPlayer() {
	int blend;
	int zbstate;
	chrdata *cd;
	int red;
	int green;
	int blue;
	int alpha;
	int e;
	float noiseval1[2];
	float noiseval2[2];
	float noiseval3[2];
	float wave;
	float scalar;
	float indexf;
	int flameColIndex;
	int flameColIndexNext;
	float indexTween;
	float invIndexTween;
}

void gunfxTick() {
	float secpassed;
	int type;
	float scalar;
	float moveRateAffect;
}

void gunfxGfx() {
	int gunfx;
	int count;
	int *textures;
	fcol *colours;
	flameparticle *fp;
	float scalar;
	int texture;
	int texwidth;
	int texheight;
	u32 abgr;
	float pos[3];
	float newpos[4];
	float scrpos1[2];
	float scrpos2[2];
	float scrpos3[2];
	float scrpos4[2];
	float q;
	int startColIndex;
	float indexf;
	int flameColIndex;
	int flameColIndexNext;
	float indexTween;
	float invIndexTween;
	int red;
	int green;
	int blue;
	int alpha;
	u32 *ref;
	float cosamount;
	float sinamount;
	float scale;
	float rotrad;
	void *addr;
}

void gunfxNewFlameProp(int gunfxType, prop *p, float *pos, float *dir, float lifetime) {
	flameparticle *fp;
}

void gunfxNewFlameBg(int gunfxType, int room, float *pos, float *dir, float timeStart) {
	flameparticle *fp;
}

void gunfxNewFlameChrThirdPerson(int gunfxType, chrdata *cd, float *pos, float *dir) {
	flameparticle *fp;
}

void gunfxNewFlameThrowFirstPerson(int gunfxType, chrdata *cd, float *pos, float *dir) {
	flameparticle *fp;
}

void gunfxNewFlameThrowThirdPerson(int gunfxType, chrdata *cd, float *pos, float *dir) {
	flameparticle *fp;
}

void gunfxNewFlameCorpse(int gunfxType, prop *corpse, float *pos, float *dir, float sizeScalar) {
	flameparticle *fp;
}

void gunfxMakeChrfxThirdPersonToCorpse(int chrnum) {}
