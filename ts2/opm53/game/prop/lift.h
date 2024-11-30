//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_PROP_LIFT_H
#define GAME_PROP_LIFT_H

#include "prop/prop.h"

enum {
	LIFT_NOTCALLED = 0,
	LIFT_CALLEDUP = 1,
	LIFT_CALLEDDOWN = 2
};

enum {
	LIFTDIR_UNDECIDED = 0,
	LIFTDIR_UP = 1,
	LIFTDIR_DOWN = 2
};

enum {
	LIFTFLAGS_WAITING = 1,
	LIFTFLAGS_TIMETOENTER = 2,
	LIFTFLAGS_AUTOMATIC = 4,
	LIFTFLAGS_DOORS = 8
};

enum {
	LIFTSTATE_NOPOWER = 0,
	LIFTSTATE_POWERING_UP = 1,
	LIFTSTATE_POWER = 2
};

// Forward-declarations
struct liftData_s;

typedef struct liftNode_s {
	int valid;
	float pos[3];
	int padref;
	int leftDoorPropnum;
	float leftDoorPos[3];
	float leftDoorRoty;
	float leftDoorMove[3];
	int rightDoorPropnum;
	float rightDoorPos[3];
	float rightDoorRoty;
	float rightDoorMove[3];
	int buttonUpPropnum;
	float buttonUpPos[3];
	float buttonUpRoty;
	int buttonDownPropnum;
	float buttonDownPos[3];
	float buttonDownRoty;
	int liftCalled;
	float durationCalled;
	prop *buttonUp;
	prop *buttonDown;
	prop *doorLeft;
	prop *doorRight;
	int floor;
} liftNode;

typedef struct setuplift_s {
	int createflags;
	int propnum;
	float roty;
	int defaultLiftFlags;
	int padref;
	float liftSpeed;
	float liftTimeEvaluate;
	float liftTimeWaiting;
	float doorOpenTime;
	float doorCloseTime;
	int leftDoorPropnum;
	float leftDoorPos[3];
	float leftDoorRoty;
	float leftDoorMove[3];
	int rightDoorPropnum;
	float rightDoorPos[3];
	float rightDoorRoty;
	float rightDoorMove[3];
	int buttonUpPropnum;
	float buttonUpPos[3];
	float buttonUpRoty;
	int buttonDownPropnum;
	float buttonDownPos[3];
	float buttonDownRoty;
	liftNode nodes[6];
} setuplift;

typedef struct liftObData_s {
	prop *lift;
	struct liftData_s *liftData;
	liftNode *nodeBelongTo;
	float start[3];
	float dest[3];
	float scalar;
} liftObData;

typedef struct liftData_s {
	setuplift *setup;
	liftNode *liftNodes;
	liftNode *liftStart;
	liftNode *liftDest;
	int liftState;
	float powerTime;
	int liftFlags;
	int floor;
	int pad;
	int numinlift;
	float liftTime;
	int liftCalled;
	int liftDir;
	float time;
	void (*liftButtonResetFunction)(/* parameters unknown */);
	liftNode *liftQueue[6];
	prop *liftProp;
	prop *liftDoorLeft;
	prop *liftDoorRight;
	prop *liftButtonUp;
	prop *liftButtonDown;
	int numLiftObs;
	liftObData liftObs[28];
} liftData;

extern liftData levellifts[5];

void propRestartLifts();
void propResetLifts();
void propEndLifts();
void propPreloadLift(setuplift *sl);
void liftButtonReset(prop *p);
void liftButtonOn(prop *p);
void liftButtonPowerOff(prop *p);
boolean liftCanActivateButton(prop *button);
boolean liftIsReadyToEnter(prop *lift, liftNode *currentNode, liftNode *targetNode);
liftNode* liftGetFromQueue(prop *lift);
liftNode* liftTakeFromQueue(prop *lift);
void liftRemoveNodeFromQueue(prop *lift, liftNode *node);
void liftAddToQueue(prop *lift, liftNode *node);
boolean liftIsInQueue(prop *lift, liftNode *node);
boolean liftIsPreviousFloorValid(liftNode *node);
boolean liftIsNextFloorValid(liftNode *node);
void liftDecideAutomaticDirection(prop *p);
void liftDoorMove(prop *door, float scalar);
void liftChooseDestination(prop *p);
void liftStartMovingToDestination(prop *p);
void liftWaitingProcessDoors(prop *p);
void liftPropTick(prop *p);
void liftNodeCall(prop *lift, liftNode *node, int called);
void liftCall(prop *lift, int called);
void liftNoPowerMessage(prop *p, prop *actor);
void liftButtonUpActivate(prop *button, prop *actor);
void liftButtonDownActivate(prop *button, prop *actor);
void propNewLift(setuplift *sl);
void liftSetState(prop *p, int state);
liftData* liftFindNearestLift(prop *chr);
int liftFindFloor(prop *chr, int pad);

#endif // GAME_PROP_LIFT_H
