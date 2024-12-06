//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GUN_GUN_H
#define GAME_GUN_GUN_H

#include "common.h"
#include "bullet.h"

// Forward-declarations.
struct chrdata_s;
struct prop_s;
struct player_s;

typedef struct ammoInfo_s {
	int maxAmmo;
	char *filename;
	int name;
	boolean hudBar;
	u32 barBgCol;
	u32 barFgCol;
} ammoInfo_t;

typedef struct gunPropInfo_s {
	int playerPropNum;
	int chrPropNum;
	int pickupPropNum;
	int ammoPropNum;
	int promoPropNum;
	float pickupScale;
	float promoScale;
	float promoRotY;
	float promoRotX;
} gunPropInfo_t;

typedef struct gunDofs_s {
	int shootDof[2];
	int muzzleDof[2];
	int leftWristDof;
	int rightWristDof;
	int cartridgeDof;
	int trajectoryDof;
	int barrelDof;
	int hammerDof;
} gunDofs_t;

typedef struct gunParts_s {
	int muzzlePartNum[2];
	int slider1PartNum;
	int slider2PartNum;
	int barrelPartNum;
	int hammerPartNum;
} gunParts_t;

typedef struct gunInfo_s {
	gunPropInfo_t propInfo;
	int gunFlags;
	int animationFlags;
	int ammoType;
	int clipCount;
	int defaultAmmo;
	int ammoTypeSecondary;
	int clipCountSecondary;
	int reloadDelay;
	int pickupSoundNum;
	float autoAimFovDot;
	float offset[3];
	float rot[3];
	int hudType;
	float zoomfovy;
	float minzoomfovy;
	float maxzoomfovy;
	fireInfo_t fireInfo[2];
	gunDofs_t playerGunDofs;
	gunDofs_t chrGunDofs;
	gunParts_t playerGunParts;
	gunParts_t chrGunParts;
} gunInfo_t;

typedef struct guncombo_s {
	int priority;
	int gunType[2];
	int name;
} guncombo;

typedef struct chrgun_s {
	float tpShootPos[4];
	float tpCartridgePos[4];
	float tpTrajectoryPos[4];
	int gunType;
	int ammo[17];
	struct prop_s *chrgunprop;
	int lastShotFramesPassed;
	int fireState;
	float repeatSoundTime;
	int repeatSoundVoice;
} chrgun;

typedef struct playergun_s {
	float fpShootPos[4];
	float fpCartridgePos[4];
	float fpTrajectoryPos[4];
	int state;
	float stateTime;
	int nextGunType;
	struct prop_s *playergunprop;
	int fireMode;
	int repeat;
	float recoilRotationX;
	float extraRotationZ;
	float recoilVelocity[3];
	float sliderRecoilVelocityZ;
	float barrelRotation;
	float barrelVelocity;
	float noiseOffset[3];
	float noiseVelocity[3];
	float noiseScalar;
	float sineScalar;
	int animationStage;
	float hammerRotation;
	float cockRotation;
	struct prop_s *shotgunCartridge[2];
	int framesPassedSinceFired;
	int gunShot;
	int singleReloadNeeded;
	int assaultShotgunFlag;
	struct prop_s *playerprop;
	chrgun *cgun;
	int ownerType;
	int ownerNum;
	int visibleAmmoFired;
	float dualShockPower;
} playergun;

typedef struct gunChrFireChoiceTable_s {
	int singleHand[2];
	int repeatHand[2];
	boolean singleShotAble[2];
	boolean repeatShotAble[2];
	boolean reloadPossible;
	boolean reloadNecessary[2];
	boolean changeNecessary;
} gunChrFireChoiceTable;

extern ammoInfo_t ammoInfo[17];
extern gunInfo_t gunInfo[0];
extern short int fixedgunname;
extern guncombo guncombos[40];
extern int gunsinventory[40];

void gunSetAmmoToMax(struct chrdata_s *cd, int gunComboIndex);
void gunPreload();
void gunRestart();
void gunReset();
void gunAddAmmo(struct chrdata_s *cd, int ammoType, int ammo);
int gunGetGunAmmo(struct chrdata_s *cd, int ammoType);
boolean gunShouldSwitchTo(struct chrdata_s *cd, int desiredGunCombo);
void gunPickedUpAmmo(struct chrdata_s *cd, int ammoType, int oldAmmo);
boolean gunShouldSwitchToOnPickup(struct chrdata_s *cd, int guncombo);
boolean gunShouldKeepWithNoAmmo(struct chrdata_s *cd, int guncombo);
boolean gunCanDetonateMines(struct chrdata_s *cd);
boolean gunHandAble(struct chrdata_s *cd, int hand);
boolean gunHandActive(struct chrdata_s *cd, int hand);
boolean gunBothHandsActive(struct chrdata_s *cd);
boolean gunIsPunching(struct chrdata_s *cd);
boolean gunDoesAutoAim(struct chrdata_s *cd);
void gunChangeToComboWithAmmo(struct chrdata_s *chrdat);
boolean gunIsLeftGunVisible(playergun *plgun, chrgun *cgun);
boolean gunHasChrAmmoForFire(struct chrdata_s *cd, chrgun *cgun, int fireMode, int repeatMode);
boolean gunHasChrAmmoForAnyFire(struct chrdata_s *cd, chrgun *cgun, int repeatMode);
void gunFireCartridges(playergun *plgun, chrgun *cgun, gunInfo_t *gi, fireInfo_t *fi);
void gunCalculateTPShootPos(chrgun *cgun, int fireMode);
void gunCalculateFPShootPos(struct player_s *player, playergun *plgun, int fireMode);
void gunPlayerFireShots(playergun *plgun);
void gunDebugPrintStats();
void gunEnemyFire(struct prop_s *p, int hand, int fireMode, int repeatMode);
void gunRemoteFire(struct prop_s *p, chrgun *gun, int fireMode, int repeatMode, int ownertype, struct chrdata_s *cd);
void gunNPCThrowGrenade(struct prop_s *p, float *dir, struct prop_s *target);
int gunGetBulletType(playergun *pGun);
void gunCreateBullet(struct prop_s *p, chrgun *gun, playergun *pgun, int fireMode, float *dir, int ownerType, struct chrdata_s *cd, int shellsfx);
void gunResetChrGun(chrgun *cgun);
void gunResetPlayerGun(playergun *plgun);
void gunClearPlayerGun(playergun *plgun);
void gunResetPlayerReload(playergun *plgun, chrgun *cgun);
void gunResetPlayerChange(playergun *plgun, chrgun *cgun);
void gunUpdateTNTFuse(playergun *plgun, chrgun *cgun, float frac);
void gunSetPlayerZoom(struct player_s *pPlayer, int GunType);
void gunDoPunch(playergun *plgun);
void gunDetonateRemoteMines(struct chrdata_s *cd);
void gunEnemyUpdate(struct prop_s *p, int hand);
boolean gunEnemyReload(struct chrdata_s *cd);
void gunPlayerTick();
void gunEnemyTick();
void gunPlayerGfx();
void gunEnd();
int gunGetPickupSfx(int gunComboIndex);
boolean gunIsPlayergunFiring(playergun *plgun);
boolean gunShouldAIAimAtFloor(int gunType, int fireMode);
void gunGetChrFireChoices(int flags, struct chrdata_s *cd, gunChrFireChoiceTable *table);
void gunReturnAmmoToChr(struct chrdata_s *cd, chrgun *cgun);
void gunPlayerTickNotLocal();
int gunGetChrLeftWristDofID(int gunType);
int gunGetChrRightWristDofID(int gunType);
int gunGetChrMuzzleDofID(int gunType, int fireMode);
int gunGetChrMuzzlePartNum(int gunType, int fireMode);
float gunGetAutoAimFovDot(int gunType);

#endif // GAME_GUN_GUN_H
