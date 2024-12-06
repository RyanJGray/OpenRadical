//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_CHRFX_H
#define GAME_FX_CHRFX_H

#include "common.h"
#include "particle.h"

// Forward-declarations;
struct prop_s;
struct chrdata_s;

typedef struct chrfx_s {
  struct chrdata_s *chrdata;
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
  struct prop_s *burnAttacker;
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
void chrfxBurn(chrfx *cfx, float amount, struct prop_s *burnAttacker);
float chrfxGetBurn(chrfx *cfx);
void chrfxFadeOut(chrfx *cfx, float amount);
void chrfxBurningTick(chrfx *cfx);
void chrfxCloakPowerUp(chrfx *cfx);
void chrfxCloakingTick(chrfx *cfx);
void chrfxFadeOutTick(chrfx *cfx);
void chrfxTick(chrfx *cfx);
void chrfxGfx(chrfx *cfx);
void chrfxSetup(chrfx *cfx, struct chrdata_s *cd);
void chrfxUnSetup(chrfx *cfx);
void chrfxDie(chrfx *cfx);
void chrfxRespawn(chrfx *cfx);
boolean chrfxCanMove(chrfx *cfx);

#endif // GAME_FX_CHRFX_H
