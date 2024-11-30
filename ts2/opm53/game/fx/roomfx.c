// STATUS: NOT STARTED

#include "roomfx.h"

typedef enum {
	ROOMFXTYPE_NONE = 0,
	ROOMFXTYPE_SHOCKWAVE = 1,
	ROOMFXTYPE_MINIWAVE = 2,
	ROOMFXTYPE_OUTLINE = 3
};

struct roomfx_s {
	int type;
	int frame;
	float time;
	float endtime;
	int room;
	prop *fxprop;
	float pos[3];
	float power;
	float dir[3];
	int partindex;
	int chunkindex;
	int polyindex;
	partdef *part;
};

typedef roomfx_s roomfx;
static int numRoomfx;
static roomfx roomfxArray[8];

void fogfxPreload() {}

void fogfxReset() {}

void fogfxRestart() {}

void fogfxTick() {}

void fogfxGfx() {}

void roomfxPreload() {}

void roomfxReset() {}

void roomfxRestart() {}

void roomfxEnd() {}

roomfx* roomfxNew() {
	int fxIndex;
	int f;
	int leastrecentframe;
	int f;
	int framecompare;
}

void roomfxFree(roomfx *rfx) {}

void roomfxTick() {}

void roomfxGfx() {}

void roomfxNewMiniwaveFromBullet(float *hitpos, bullet *b) {}

void roomfxNewShockwave(float *hitpos, float power) {}

void roomfxNewOutline() {}

void roomfxShockwaveTickSetVertices(roomfx *rfx, prop *p, int partNum, int gfxtype, float *sxyz) {
	u32 *cptr;
	int numvtx;
	float *dxyz;
	int v;
	float scalar;
	float x;
	float y;
	float z;
	float w;
	float distx;
	float disty;
	float distz;
	float distscalar;
	float behindwave;
	float proximity;
	float amplitude;
	float offset;
	float dirx;
	float dirz;
}

void roomfxShockwaveTick(roomfx *rfx) {
	int r;
	float scalar;
	obinst *inst;
	partdef *parts;
	int e;
	int g;
	int pl;
	float distx;
	float disty;
	float distz;
	float distscalar;
	float behindwave;
	float proximity;
}

void roomfxMiniwaveTickSetVertices(roomfx *rfx, prop *p, int partNum, int gfxtype, float *sxyz) {}

void roomfxMiniwaveTick(roomfx *rfx) {}

void roomfxOutlineTickSetVertices(roomfx *rfx, prop *p, int partNum, int gfxtype, u32 *sgif, float intensity) {
	u32 *cptr;
	int numgiftags;
	int numvtx;
	u32 *dgif;
	int c;
	u32 outlinecol;
	u32 *drgba;
	int c;
}

void roomfxOutlineTick(roomfx *rfx) {
	int r;
	float intensity;
	obinst *inst;
	partdef *parts;
	int e;
}
