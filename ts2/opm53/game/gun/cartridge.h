//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GUN_CARTRIDGE_H
#define GAME_GUN_CARTRIDGE_H

// Forward-declarations.
#include "util/matrix.h"

struct prop_s;
struct chrdata_s;
struct chrgun_s;
struct playergun_s;
struct gunInfo_s;
struct fireInfo_s;

typedef struct cartridge_s {
  union mtx_u rotationmatrix;
  struct prop_s *prop;
  float rotvel[3];
  int time;
  float baseHeightWhenFired;
  int drawflags;
} cartridge;

typedef struct cartridgeGroup_s {
  cartridge cartridges[10];
  int startCartridge;
  int numCartridges;
} cartridgeGroup;

typedef struct playerGunAnimationInfo_s {
  float recoilStrength;
  float recoilStrengthRotX;
  float strengthRotZ;
  float unrecoilSpeed;
  float recoilStrengthSlider;
  float unrecoilSpeedSlider;
  float barrelVelocity;
  float barrelVelocitySlowdown;
  float sineAmount;
  float sineSlowdown;
  float noiseAmount;
  float noiseSlowdown;
  float hammerSpeed;
  float hammerRotation;
  float hammerBackSpeed;
} playerGunAnimationInfo_t;

extern int cartridgeProps[5];
extern cartridgeGroup cartridgeGroups[2];

void cartridgePreload();
void cartridgeRestart();
void cartridgeReset();
void cartridgeEnd();
void cartridgeNew(int player, int flags, int type, struct chrgun_s *gun,
                  struct playergun_s *pgun, struct gunInfo_s *gi,
                  struct fireInfo_s *fi, struct chrdata_s *cd);
void cartridgeTick();

#endif // GAME_GUN_CARTRIDGE_H
