// STATUS: NOT STARTED

#ifndef GAME_GUN_GUN_H
#define GAME_GUN_GUN_H

struct ammoInfo_s {
	int maxAmmo;
	char *filename;
	int name;
	boolean hudBar;
	u32 barBgCol;
	u32 barFgCol;
};

typedef ammoInfo_s ammoInfo_t;
typedef gunInfo_s gunInfo_t;

struct guncombo_s {
	int priority;
	int gunType[2];
	int name;
};

typedef guncombo_s guncombo;
typedef chrgun_s chrgun;
typedef playergun_s playergun;

struct gunChrFireChoiceTable_s {
	int singleHand[2];
	int repeatHand[2];
	boolean singleShotAble[2];
	boolean repeatShotAble[2];
	boolean reloadPossible;
	boolean reloadNecessary[2];
	boolean changeNecessary;
};

typedef gunChrFireChoiceTable_s gunChrFireChoiceTable;
typedef chrdata_s chrdata;
extern ammoInfo_t ammoInfo[17];
extern gunInfo_t gunInfo[0];
extern short int fixedgunname;
extern guncombo guncombos[40];
extern int gunsinventory[40];

void gunSetAmmoToMax(chrdata *cd, int gunComboIndex);
void gunPreload();
void gunRestart();
void gunReset();
void gunAddAmmo(chrdata *cd, int ammoType, int ammo);
int gunGetGunAmmo(chrdata *cd, int ammoType);
boolean gunShouldSwitchTo(chrdata *cd, int desiredGunCombo);
void gunPickedUpAmmo(chrdata *cd, int ammoType, int oldAmmo);
boolean gunShouldSwitchToOnPickup(chrdata *cd, int guncombo);
boolean gunShouldKeepWithNoAmmo(chrdata *cd, int guncombo);
boolean gunCanDetonateMines(chrdata *cd);
boolean gunHandAble(chrdata *cd, int hand);
boolean gunHandActive(chrdata *cd, int hand);
boolean gunBothHandsActive(chrdata *cd);
boolean gunIsPunching(chrdata *cd);
boolean gunDoesAutoAim(chrdata *cd);
void gunChangeToComboWithAmmo(chrdata *chrdat);
boolean gunIsLeftGunVisible(playergun *plgun, chrgun *cgun);
boolean gunHasChrAmmoForFire(chrdata *cd, chrgun *cgun, int fireMode, int repeatMode);
boolean gunHasChrAmmoForAnyFire(chrdata *cd, chrgun *cgun, int repeatMode);
void gunFireCartridges(playergun *plgun, chrgun *cgun, gunInfo_t *gi, fireInfo_t *fi);
void gunCalculateTPShootPos(chrgun *cgun, int fireMode);
void gunCalculateFPShootPos(player *player, playergun *plgun, int fireMode);
void gunPlayerFireShots(playergun *plgun);
void gunDebugPrintStats();
void gunEnemyFire(prop *p, int hand, int fireMode, int repeatMode);
void gunRemoteFire(prop *p, chrgun *gun, int fireMode, int repeatMode, int ownertype, chrdata *cd);
void gunNPCThrowGrenade(prop *p, float *dir, prop *target);
int gunGetBulletType(playergun *pGun);
void gunCreateBullet(prop *p, chrgun *gun, playergun *pgun, int fireMode, float *dir, int ownerType, chrdata *cd, int shellsfx);
void gunResetChrGun(chrgun *cgun);
void gunResetPlayerGun(playergun *plgun);
void gunClearPlayerGun(playergun *plgun);
void gunResetPlayerReload(playergun *plgun, chrgun *cgun);
void gunResetPlayerChange(playergun *plgun, chrgun *cgun);
void gunUpdateTNTFuse(playergun *plgun, chrgun *cgun, float frac);
void gunSetPlayerZoom(player *pPlayer, int GunType);
void gunDoPunch(playergun *plgun);
void gunDetonateRemoteMines(chrdata *cd);
void gunEnemyUpdate(prop *p, int hand);
boolean gunEnemyReload(chrdata *cd);
void gunPlayerTick();
void gunEnemyTick();
void gunPlayerGfx();
void gunEnd();
int gunGetPickupSfx(int gunComboIndex);
boolean gunIsPlayergunFiring(playergun *plgun);
boolean gunShouldAIAimAtFloor(int gunType, int fireMode);
void gunGetChrFireChoices(int flags, chrdata *cd, gunChrFireChoiceTable *table);
void gunReturnAmmoToChr(chrdata *cd, chrgun *cgun);
void gunPlayerTickNotLocal();
int gunGetChrLeftWristDofID(int gunType);
int gunGetChrRightWristDofID(int gunType);
int gunGetChrMuzzleDofID(int gunType, int fireMode);
int gunGetChrMuzzlePartNum(int gunType, int fireMode);
float gunGetAutoAimFovDot(int gunType);

#endif // GAME_GUN_GUN_H
