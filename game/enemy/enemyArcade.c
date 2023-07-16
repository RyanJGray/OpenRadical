// STATUS: NOT STARTED

#include "enemyArcade.h"

// warning: multiple differing types with the same name (#147,  not equal)
enum {
	ATTACK_FIRSTSIGHT = 0,
	ATTACK_ATTACK = 1,
	ATTACK_CLOSEIN = 2,
	ATTACK_BACKOFF = 3,
	ATTACK_CANNOTSEETARGET = 4,
	ATTACK_JUSTLOSTSIGHTOFTARGET = 5,
	ATTACK_KNEEL = 6
};

// warning: multiple differing types with the same name (#147,  not equal)
enum {
	EARM_SELECT_GUN = 0,
	EARM_ADVANCE_TO_GUN = 1,
	EARM_WAITFORGUN = 2,
	EARM_WAITFORGUN_RUN = 3
};

void enemyArcadeRestart() {}

void enemyArcadeReset() {}

void enemyArcadeSetup() {
	int i;
	int propnum;
	chrdata *cd;
}

void enemyAttack(prop *p) {
	chrdata *cd;
	int animpersonality;
	animpersonalityinfo *api;
	attackphase *ap;
	float dx;
	float dy;
	float dz;
	float destpos[3];
	int anim;
}

void enemyStorySetWait(chrdata *cd) {
	float waits[6];
}

int enemyGetExitKneelAnim() {
	int anims[4];
}

int enemyAimOverride(chrdata *cd) {
	int canseeoverride;
}

void enemyAttackNewAnimseq(chrdata *cd, attackphase *ap, int phase) {}

void enemyStoryTestDestPosSetAnim(prop *p, int anim) {
	chrdata *cd;
	int animpersonality;
	animpersonalityinfo *api;
	float destpos[3];
	int flags;
}

void enemyStoryAttack1(prop *p) {
	chrdata *cd;
	int animpersonality;
	animpersonalityinfo *api;
	attackphase *ap;
	float dx;
	float dy;
	float dz;
	int animending;
	int seqending;
	int getnewstatedata;
}

void enemyArcadeUpdateVisTable() {
	float dir[3];
	float pos[3];
	chrdata *cd;
	prop *phit;
	prop *target;
	int targetindex;
	int i;
	int chrindex;
	int leastframe;
	int prevflags;
	chrdata *loopcd;
}

void enemyCheckBestWeapon(prop *p) {
	chrdata *cd;
	int priority;
	int i;
	int numgunsheld;
	int selectguncombo;
	float dx;
	float dy;
	float dz;
	float dist;
	gunInfo_t *gi;
	int favgun;
}

void enemyArm(prop *p) {
	chrdata *cd;
	pickupdata *pd;
	int numweapons;
}

void enemyGetHealth(prop *p) {
	chrdata *cd;
}

void enemyGetArmour(prop *p) {
	chrdata *cd;
}

prop* selectFavouriteWeaponPickup(prop *p, prop *excludegun) {
	chrdata *cd;
	prop *gun;
	gunset *lvgunset;
	int favguncom;
	boolean found;
	pickupdata *pd;
	pad *padptr;
	float dx;
	float dy;
	float dz;
	float dist;
	int i;
}

static boolean weaponPickupIsOkayToSelect(prop *p, prop *gun) {
	chrdata *cd;
	pickupdata *pd;
	pad *padptr;
	float dx;
	float dy;
	float dz;
	float dist;
}

prop* selectCloseWeaponPickup(prop *p, prop *excludegun) {
	chrdata *cd;
	pad *cdpad;
	prop *gun;
	int i;
	prop *dgun;
}

boolean enemyShouldGetHealth(prop *p) {
	chrdata *cd;
	prop *health;
}

boolean enemyShouldGetArmour(prop *p) {
	chrdata *cd;
	prop *armour;
}

int enemyAddDroppedGunToList(prop *pickup) {
	int i;
}

boolean enemyRemoveDroppedGunFromList(prop *pickup) {
	int i;
}
