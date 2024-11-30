//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_ENEMY_ENEMY_H
#define GAME_ENEMY_ENEMY_H

#include "common.h"
#include "lv/lvsetup.h"
#include "prop/prop.h"

typedef struct padInfo_s {
	int padnum;
	int nextpadnum;
	int finaldestpadnum;
	int curroute[250];
	int curroutelen;
	int curhallroute[250];
	int curhallroutelen;
} padInfo;

struct pad_s {
	int extref;
	u32 flags;
	short int hallnum;
	short int room;
	float pos[3];
	float roty;
	int size;
};

typedef struct padprop_s {
	int pad;
	prop *prop;
} padprop;

typedef struct explosioninfo_s {
	float pos[3];
	int id;
} explosioninfo;

typedef struct lookup_s {
	int canseechr;
	int framechecked;
	int framechanged;
} lookup;

extern lookup *visTable;
extern setupheader *setup;
extern int numEscorts;
extern int numBases;
extern int numlifts;
extern int totactivespawnedchars;
extern int numchractive;
extern int numPickupBags;
extern int canplayreactsfx;
extern int numDrawnChrs;
extern int teamflag[5];
extern prop *escort[5];
extern padprop bagspawn[6];
extern int updateNPCindex;
extern prop *bases[10];
extern prop *droppedgunlist[20];
extern int AI_alertstate;
extern int activeSleepGrps[10];
extern int numNPCcreated;
extern chrdata *chractivelist[58];
extern prop *chr[58];
extern padprop weaponspawn[35];
extern padprop healthspawn[25];
extern padprop dropspawn[20];
extern padprop lifts[5];
extern explosioninfo aiexplosiondata[20];

void enemyRestart();
void enemyReset();
void enemyPreload();
void enemySetup();
void enemyAITickBefore();
void enemyOverSeer();
void enemyTick(prop *p);
void enemyEnd();
void updatePos(prop *p);
void rotateChr(prop *p);
void setAnimation(prop *p);
void setZombieAnimation(prop *p);
void zombieAdvanceAnim(prop *p);
int findNextPad(prop *p, padInfo *pad, int addmultipliers);
void updatePlayerPadPos();
void enemyCheckValidPad(int chrindex);
void updateNPCPadPos(prop *p);
void checkProgress(prop *p);
void enemyGunUpdate(prop *p);
void enemyDetonateMines(prop *p);
void enemyTrackTarget(prop *p);
int enemyAdvancePads(prop *p, int destpad);
void enemyDefend(prop *p);
int enemyGetChrActiveListIndex(int id);
prop* enemyCycleThroughTargets(prop *p);
int enemyChooseDropToDefend(prop *p);
int enemyChooseDefendPad(prop *p, int defpad);
int enemyOnPad(prop *p, int padcheck);
prop* enemySelectLaststandBase(int start);
int enemyReselectTarget(prop *p);
int enemyGetTargetPad(prop *p);
int selectDrop(prop *p);
void followTargetPassive(prop *p);
void enemyOnFire(prop *p);
void runAway(prop *p);
float enemyReactTime(prop *p);
void enemyInformAboutDeath(prop *p);
void enemyDying(prop *p);
void enemySpawn(prop *p);
void enemySelectTarget(prop *p);
prop* enemySelectDeathMatchTarget(prop *p, int reselecting);
prop* enemySelectStoryTarget(prop *p, int reselecting);
prop* suggestTarget(prop *p, prop *suggtarget, int flag);
void findbearings(prop *p);
void findmypad(prop *p);
int awareOfTarget(prop *p, int canchangetarget);
int checkInFrontOfPos(float *pos1, float *pos1dir, float *pos2, float dotcomp);
int checkInFront(prop *p, float *pos, float dotcomp);
int checkSeeFOV(prop *p, float *pos, float dotcomp);
int checkInFrontOfPadPtr(pad_s *padptr, float *pos, float dotcomp);
float checkInFrontOfDir(float *dir1, float *dir2, float dotcomp);
int checkAimingFront(prop *p1, prop *p2, float dotcomp);
int checkSide(prop *p, float *pos, float dotcomp);
void enemyDie(prop *p, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, int parthit, int deathflag);
void enemyInformHit(prop *p, prop *attacker, int animparthit, int bullettype);
void drawLine(float *pos1, float *pos2, u32 col, float yoffset);
void enemyAddToWeaponList(prop *prop, int padnum);
void enemyAddToBagList(prop *prop, int padnum);
void enemyAddToHealthList(prop *prop, int padnum);
void enemyAddToDropList(prop *prop, int padnum);
void enemyAddToPropList(setupprop *sp, prop *prop);
void enemyAddToLiftList(setuplift *sl, prop *prop);
int enemyGetNumBases();
prop* enemyGetBase(int b);
void enemyAddToEscortList(prop *prop);
void enemySetRoom(prop *p, int firsttime);
void enemySetMoveMode(prop *p, int movemode);
int enemyTriggered(prop *p);
void enemyNoRoute(prop *p);
void moveValidPad(prop *p);
int enemyFiredAt(prop *p);
int enemySafeToFire(prop *p);
void enemyDeleteNPC(prop *p);
void enemyCopyNPCdataToChr(chrdata *cd);
int enemyCreateNPC(setupNPC *npc, int pad, int typeuse, int typeoriginal, int extradata1);
void enemyAITickAfter();
void enemyPreCalcEnemyRoutes();
void enemyCheckAllRoutes();
void enemyAddToExplosionList(float *pos, int id);
void enemyRemoveFromExplosionList(int id);
int enemyExplosionNearby(prop *p);
void enemyUpdateCampDetect(chrdata *cd);
int campingPad(int padnum);
int enemyRoomDrawn(int roomcheck);
padprop* enemyGetPadProp(int padnum);
prop* checkCoopTarget(prop *p);
void enemyShowStatsGfx();
void enemyAddToActiveList(prop *p);
void enemyRemoveFromActiveList(prop *p);
void enemyVisTableSet(int index1, int index2, int cansee);
int enemyVisTableCanSeeChr(int index1, int index2);
int enemyVisTableFrameChecked(int index1, int index2);
int enemyVisTableFrameChanged(int index1, int index2);
int enemyCanSeeTarget(chrdata *cd, int canchangetarget);
int enemyGetNumPickupDrops();
padprop* enemyGetDrop(int d);
int enemyGetDropNumFromProp(prop *p);
int enemyGetDropNumFromPad(int pad);
void setDisableLinks(int enable);
pad_s* enemyGetNPCsPad(chrdata *cd);
boolean enemyChrIsOnPad(chrdata *cd, int padnum);
void enemyHandleLift(prop *p);
void enemyGameOver(prop *p);
void enemySetGameOver();
void enemyCheckDoorway(prop *p);
void enemySendGroupToSleep(int sleepgrp);
void enemyAwakeSleepGroup(int sleepgrp);
int enemyGetNumPickupWeapons();
padprop* enemyGetWeaponSpawn(int w);
int enemyGetNumPickupHealth();
padprop* enemyGetHealthSpawn(int h);

#endif // GAME_ENEMY_ENEMY_H
