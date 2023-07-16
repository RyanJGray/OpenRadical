// STATUS: NOT STARTED

#ifndef GAME_ENEMY_ENEMYSINGLE_H
#define GAME_ENEMY_ENEMYSINGLE_H

typedef void (*lvbtnhandlerfn)(/* parameters unknown */);

struct lvbuttondata_s {
	int setupref;
	int chrpadnum;
	prop_s *prop;
	int type;
	int flags;
	lvbtnhandlerfn handlerfn;
	boolean status;
	prop_s *activater;
	float timer1;
	int data1;
	float fdata1;
	void *vdata1;
};

struct aifireinfo_s {
	float minrange;
	float maxrange;
	int repeatfire;
};

typedef aifireinfo_s aifireinfo;

struct alarmdata_s {
	int setupref;
	int commlist;
	float duration;
	prop *triggerprop;
	int state;
	float timer1;
	float timer2;
};

typedef alarmdata_s alarmdata;
extern aifireinfo firerange[33];
extern int numLvButtons;
extern int debugwokenupstat;
extern ambushDesc ambushdesc[10];
extern lvbuttondata levelbuttons[10];

void enemySingleRestart();
void enemySingleReset();
void enemySingleSetup();
void enemyAddToButtonList(setupbutton *sb, prop *p);
int enemyGetButtonNumFromSetupRef(int setupref);
void enemyAddToAlarmList(setupalarm *sa);
int enemyGetAlarmNumFromSetupRef(int setupref);
void enemyAlarmTick();
void enemyAlarmSetState(int i, int newstate, void *data1);
void enemySnipe1(prop *p);
void enemyStandShoot(prop *p);
void enemyCharge(prop *p);
void enemyPatrol(prop *p);
void enemyAmbushCrouch(prop *p);
boolean handleOutOfAmmo(chrdata *cd);
void enemySingleZombieAttack(prop *p);
void swipeTest(prop *p, int righthand);
void enemyAttackObject(prop *p);
void enemySnipeAttack(prop *p);
void enemyBarrelRobot(prop *p);
void enemyRemoveFromCommList(prop *p);
void enemyAddToCommList(prop *p);
void enemySleep(prop *p);
void enemyFromSleepToAwake(prop *p);
void enemyAwake(prop *p);
void enemyPlayActivationSound(prop *p);
void enemySetIdleAnimation(prop *p);
void enemyInformOthers(int informertype, void *data1, int data2);
int enemyStoryPlayerAtPad(int extref);
void enemySingleUpdateVisTable();
void enemyShowAlertStateGfx();
void enemyAmbush(prop *p);
void enemyPlaySound(prop *p, int sfx);
void enemyPlayDead(prop *p);
void enemyPressButton(prop *p);
boolean enemyAlarmIsOn(int i);
int enemyGetNumAlarms();
alarmdata* enemyGetAlarm(int i);
lvbuttondata_s* enemyGetButton(int i);
int enemyGetNumButtons();

#endif // GAME_ENEMY_ENEMYSINGLE_H
