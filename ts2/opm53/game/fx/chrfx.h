//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_CHRFX_H
#define GAME_FX_CHRFX_H

#include "common.h"
#include "chr/chr.h"
#include "prop/prop.h"
#include "particle.h"

typedef struct chrfx_s {
	chrdata *chrdata;
	int flags;
	int spawnType;
	int spawnSubType;
	int actionType;
	float spawnTime;
	float actionTime;
	boolean xray;
	int footdecalkeyframe;
	boolean breathOn;
	float breathTimer;
	float breathTimeDest;
	float burn;
	float fadeamount;
	prop *burnAttacker;
	particlegroup *particlefx[1];
} chrfx;

void chrfxPreload();
void chrfxReset();
void chrfxRestart();
void chrfxEnd();
void chrfxTickStart(chrfx *cfx);
void chrfxTickPlayer(chrfx *cfx);
void chrfxGfxPlayer(chrfx *cfx);
void chrfxBreathingTick(chrfx *cfx);
void chrfxDouse(chrfx *cfx);
void chrfxBurn(chrfx *cfx, float amount, prop *burnAttacker);
float chrfxGetBurn(chrfx *cfx);
void chrfxFadeOut(chrfx *cfx, float amount);
void chrfxBurningTick(chrfx *cfx);
void chrfxCloakPowerUp(chrfx *cfx);
void chrfxCloakingTick(chrfx *cfx);
void chrfxFadeOutTick(chrfx *cfx);
void chrfxTick(chrfx *cfx);
void chrfxGfx(chrfx *cfx);
void chrfxSetup(chrfx *cfx, chrdata *cd);
void chrfxUnSetup(chrfx *cfx);
void chrfxDie(chrfx *cfx);
void chrfxRespawn(chrfx *cfx);
boolean chrfxCanMove(chrfx *cfx);

#endif // GAME_FX_CHRFX_H
