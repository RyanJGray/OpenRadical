// STATUS: NOT STARTED

#include "chrfx.h"

void chrfxPreload() {}

void chrfxReset() {}

void chrfxRestart() {}

void chrfxEnd() {}

void chrfxTickStart(chrfx *cfx) {}

void chrfxTickPlayer(chrfx *cfx) {}

void chrfxGfxPlayer(chrfx *cfx) {
	int blend;
	int zbstate;
}

static void chrfxFootDecal(chrfx *cfx) {
	prop *p;
	int keyframetags;
	boolean Left;
	int keyframenum;
	mtx_u mtx;
	mtx_u tmpmtx;
	float decalpos[3];
	float rotyDeg;
}

void chrfxBreathingTick(chrfx *cfx) {
	prop *p;
	float secpassed;
	float breathPos[3];
	float breathDir[3];
	float breathVel[3];
	mtx_u matrix;
	mtx_u finalmtx;
}

void chrfxDouse(chrfx *cfx) {}

void chrfxBurn(chrfx *cfx, float amount, prop *burnAttacker) {}

float chrfxGetBurn(chrfx *cfx) {}

void chrfxFadeOut(chrfx *cfx, float amount) {}

void chrfxBurningTick(chrfx *cfx) {
	prop *p;
	float secpassed;
	float pos[3];
	float dir[3];
	float height;
	float diffx;
	float diffz;
	chrdata *cd;
	chrdata *hitcd;
}

void chrfxCloakPowerUp(chrfx *cfx) {}

void chrfxCloakingTick(chrfx *cfx) {
	prop *p;
}

void chrfxFadeOutTick(chrfx *cfx) {
	prop *p;
	prop *gl;
	prop *gr;
	int alpha;
}

void chrfxTick(chrfx *cfx) {
	prop *p;
}

void chrfxGfx(chrfx *cfx) {
	int blend;
	int zbstate;
}

void chrfxSetup(chrfx *cfx, chrdata_s *cd) {}

void chrfxUnSetup(chrfx *cfx) {}

void chrfxDie(chrfx *cfx) {
	int f;
}

void chrfxRespawn(chrfx *cfx) {}

boolean chrfxCanMove(chrfx *cfx) {}
