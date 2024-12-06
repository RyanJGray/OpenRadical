//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_ENEMY_ENEMYSINGLE_H
#define GAME_ENEMY_ENEMYSINGLE_H

#include "common.h"
#include "lv/lvsetup.h"

// Forward-declarations.
struct chrdata_s;
struct lvbuttondata_s;
struct prop_s;
struct setupalarm_s;
struct setupbutton_s;

typedef struct aifireinfo_s {
  float minrange;
  float maxrange;
  int repeatfire;
} aifireinfo;

typedef struct alarmdata_s {
  int setupref;
  int commlist;
  float duration;
  struct prop_s *triggerprop;
  int state;
  float timer1;
  float timer2;
} alarmdata;

extern aifireinfo firerange[33];
extern int numLvButtons;
extern int debugwokenupstat;
extern struct lvbuttondata_s levelbuttons[10];

void enemySingleRestart();
void enemySingleReset();
void enemySingleSetup();
void enemyAddToButtonList(struct setupbutton_s *sb, struct prop_s *p);
int enemyGetButtonNumFromSetupRef(int setupref);
void enemyAddToAlarmList(struct setupalarm_s *sa);
int enemyGetAlarmNumFromSetupRef(int setupref);
void enemyAlarmTick();
void enemyAlarmSetState(int i, int newstate, void *data1);
void enemySnipe1(struct prop_s *p);
void enemyStandShoot(struct prop_s *p);
void enemyCharge(struct prop_s *p);
void enemyPatrol(struct prop_s *p);
void enemyAmbushCrouch(struct prop_s *p);
boolean handleOutOfAmmo(struct chrdata_s *cd);
void enemySingleZombieAttack(struct prop_s *p);
void swipeTest(struct prop_s *p, int righthand);
void enemyAttackObject(struct prop_s *p);
void enemySnipeAttack(struct prop_s *p);
void enemyBarrelRobot(struct prop_s *p);
void enemyRemoveFromCommList(struct prop_s *p);
void enemyAddToCommList(struct prop_s *p);
void enemySleep(struct prop_s *p);
void enemyFromSleepToAwake(struct prop_s *p);
void enemyAwake(struct prop_s *p);
void enemyPlayActivationSound(struct prop_s *p);
void enemySetIdleAnimation(struct prop_s *p);
void enemyInformOthers(int informertype, void *data1, int data2);
int enemyStoryPlayerAtPad(int extref);
void enemySingleUpdateVisTable();
void enemyShowAlertStateGfx();
void enemyAmbush(struct prop_s *p);
void enemyPlaySound(struct prop_s *p, int sfx);
void enemyPlayDead(struct prop_s *p);
void enemyPressButton(struct prop_s *p);
boolean enemyAlarmIsOn(int i);
int enemyGetNumAlarms();
alarmdata *enemyGetAlarm(int i);
struct lvbuttondata_s *enemyGetButton(int i);
int enemyGetNumButtons();

#endif // GAME_ENEMY_ENEMYSINGLE_H
