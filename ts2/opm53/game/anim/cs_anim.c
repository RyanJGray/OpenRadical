// STATUS: NOT STARTED

#include "cs_anim.h"

void cs_calMatrices(cs_animheader *cs, int slotnum, cs_obinst *inst, int relocating) {
	int i;
	int key1;
	int key2;
	int frame;
	quaternion q;
	quaternion q1;
	quaternion q2;
	animinfo *ai1;
	animData ad1;
	animData ad2;
	float frac;
	animInfoProp *pAnimCycle;
}

static void cs_calGlobalMatrices(cs_obinst *inst, mtx_u *m, int mnum) {}

static void cs_calweights(cs_obinst *inst, int relocating) {
	int i;
	int *bind;
}

static void cs_fillgfxmtxslots(cs_obinst *inst, int relocating) {
	int i;
	int *bind;
}
