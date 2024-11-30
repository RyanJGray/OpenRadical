//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GUN_CARTRIDGE_H
#define GAME_GUN_CARTRIDGE_H

#include "chr/chr.h"
#include "gun/gun.h"
#include "gun/bullet.h"

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
void cartridgeNew(int player, int flags, int type, chrgun *gun, playergun *pgun, gunInfo_t *gi, fireInfo_t *fi, chrdata *cd);
void cartridgeTick();

#endif // GAME_GUN_CARTRIDGE_H
