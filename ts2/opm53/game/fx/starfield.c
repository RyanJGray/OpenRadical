// STATUS: NOT STARTED

#include "starfield.h"

struct star_s {
	float radiusx;
	float radiusz;
	float signx;
	float signz;
	float time;
	float speed;
	u32 col;
};

typedef star_s star;

struct space_fire_s {
	float offsetx;
	float offsety;
	float offsetz;
	float time;
	float speed;
	u32 col;
};

typedef space_fire_s space_fire;
star *stars = NULL;
space_fire *spacefires = NULL;

float spacefirestart[3] = {
	/* [0] = */ -20.f,
	/* [1] = */ -10.f,
	/* [2] = */ 90.f
};

int starfieldtexnum = 0;
int spacefiretexnum = 0;

void starfieldPreload() {}

void setStar(int i) {}

void starfieldRestart() {
	int i;
}

void starfieldReset() {}

void starfieldTick() {}

void specialParticlesGfx(float *drawpos, u32 *col, int numstars, int texwidth, int texheight) {
	float fovscale;
	float pos[3];
	float newpos[3];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	u32 *ref;
	int size;
	int clip;
	int s;
	void *addr;
}

void starfieldGfx() {
	float stardrawpos[200][3];
	u32 starcol[200];
	float firedrawpos[50][3];
	u32 firecol[50];
	int s;
	int draw;
	int drawfire;
	float start[3];
	float diffz;
	int alpha;
	float start[3];
	float diffz;
	int alpha;
	float destz;
	float diffz;
	int alpha;
	float start[3];
	float diffz;
	float distt;
	int alpha;
	int oldzbmode;
}
