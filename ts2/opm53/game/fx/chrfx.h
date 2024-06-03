// STATUS: NOT STARTED

#ifndef GAME_FX_CHRFX_H
#define GAME_FX_CHRFX_H

struct chrfx_s {
	chrdata_s *chrdata;
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
	prop_s *burnAttacker;
	particlegroup_s *particlefx[1];
};

typedef chrfx_s chrfx;
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
void chrfxSetup(chrfx *cfx, chrdata_s *cd);
void chrfxUnSetup(chrfx *cfx);
void chrfxDie(chrfx *cfx);
void chrfxRespawn(chrfx *cfx);
boolean chrfxCanMove(chrfx *cfx);

#endif // GAME_FX_CHRFX_H
