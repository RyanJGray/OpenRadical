//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GAME_OBJECTIVES_H
#define GAME_GAME_OBJECTIVES_H

#include "common.h"
#include "lv/lvsetup.h"
#include "prop/prop.h"
#include "fx/specialfx.h"

// Forward-declarations.
struct bullet_s;

enum {
	OBJECTIVE_TYPE_NONE = -1,
	OBJECTIVE_TYPE_MAIN = 0,
	OBJECTIVE_TYPE_SECONDARY = 1,
	OBJECTIVE_TYPE_BONUS = 2,
	OBJECTIVE_NUM_TYPES = 3
};

enum {
	OBJECTIVE_STATE_NOTINLEVEL = 0,
	OBJECTIVE_STATE_UNREVEALED = 1,
	OBJECTIVE_STATE_INCOMPLETE = 2,
	OBJECTIVE_STATE_FAILED = 3,
	OBJECTIVE_STATE_COMPLETE = 4
};

enum {
	OBJECTIVE_FLAG_COUNTER = 1
};

typedef struct objective_s {
	u8 *text;
	int flags;
	int (*handler1)(/* parameters unknown */);
	int (*handler2)(/* parameters unknown */);
	int type[3];
	int state;
} objective;

typedef struct checkpoint_s {
	float pos[3];
	float radiusxz;
	float radiusy;
} checkpoint;

typedef struct checkrect_s {
	float min[3];
	float max[3];
} checkrect;

extern int numCurrentObjectives;
extern int numObjectives[3];
extern int currentObjectives[10];

u8* objectivesGetBriefing();
u8* objectivesGetText(objective *obj);
u8* objectivesGetSubtitle(int type);
void objectivesGetCounters(objective *obj, int *c1, int *c2);
boolean objectivesIsChrInCheckpoint(int chrid, checkpoint *point);
boolean objectivesIsPosInCheckpoint(float *pos, checkpoint *point);
boolean objectivesIsChrInCheckrect(int chrid, checkrect *rect);
int objectivesGetType(int id);
boolean objectiveIsComplete(int id);
void objectivesTellHud(objective *obj);
void objectiveComplete(int id);
void objectiveSetUnRevealed(int id);
void objectiveReveal(int id);
void objectiveFail(int id);
void objectivesAdd(int id);
int objectivesGetNum();
int objectivesGetNumOfType(int type);
int objectivesGetNumMain();
int objectivesGetNumSecondary();
int objectivesGetNumBonus();
objective* objectivesGetUsingType(int index, int type);
objective* objectivesGetMain(int index);
objective* objectivesGetSecondary(int index);
objective* objectivesGetBonus(int index);
void objectivesReset();
void objectivesRestart();
void objectivesTick();
void objectivesProcessDeath(prop *p);
void objectivesProcessLift(prop *p);
void objectivesMineExplosion(struct bullet_s *b);
void damObjectivesSetup();
void damObjectivesApache(prop *p);
void damObjectivesSteam(specialfx *spfx);
void damObjectivesRadar(prop *p);
void damObjectivesCave(prop *p);
void damObjectivesCage(prop *p);
void damObjectivesCageSwitch(prop *p);
void damObjectivesLaser1(prop *p);
void damObjectivesLaser2(prop *p);
void damObjectivesPipeWheel(prop *p);
void damObjectivesPipeDial(prop *p);
void damObjectivesMainTurbine(prop *p);
void damObjectivesBackupTurbine(prop *p);
void damObjectivesFileCabinetDestroyed(prop *p, prop *actor);
void damObjectivesCabinet(prop *p);
void damObjectivesSetLiftView();
void damObjectivesSetLaserView();
void damObjectivesLaserPowerOn();
void damObjectivesSetSiteView();
void damObjectivesSitePowerOn();
void damObjectivesCageSwitchActivate(lvbuttondata *bd);
void damObjectivesPowerOn();
void damObjectivesRevealSite();
void damObjectivesComputerActivate(prop *p, prop *actor);
void damObjectivesComputerTurbinesDestroyed(prop *notused1, prop *notused2);
void damObjectivesComputer(prop *p);
void damObjectivesRevealCopter();
void damObjectivesRevealPower();
void damObjectivesRevealPressure(prop *actor);
void damObjectivesTick();

#endif // GAME_GAME_OBJECTIVES_H
