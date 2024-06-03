// STATUS: NOT STARTED

#include "spray.h"

static int spraytexnum = -1;
static sprayParticle sprayParticles[240];
static int currentSpray;
static float sprayTime;

void sprayPreload() {}

void sprayRestart() {
	int spray;
}

void sprayReset() {}

void sprayEnd() {}

int sprayGetMax() {}

int sprayGetCurrent() {}

sprayParticle* sprayGet(int index) {}

void sprayNew(int type, int viewmask, float x, float y, float z) {
	sprayParticle *sp;
}

void sprayTick() {}

void sprayGfx() {
	float fovscale;
	float spraysize;
	int spray;
	sprayParticle *sp;
	float timeScalar;
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float size;
	u32 col;
	u8 alpha;
	float scale;
}
