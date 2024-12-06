//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_PROP_LIFT_H
#define GAME_PROP_LIFT_H

#include "common.h"

// Forward-declarations.
struct prop_s;

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
	struct prop_s *buttonUp;
	struct prop_s *buttonDown;
	struct prop_s *doorLeft;
	struct prop_s *doorRight;
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
	struct prop_s *lift;
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
	struct prop_s *liftProp;
	struct prop_s *liftDoorLeft;
	struct prop_s *liftDoorRight;
	struct prop_s *liftButtonUp;
	struct prop_s *liftButtonDown;
	int numLiftObs;
	liftObData liftObs[28];
} liftData;

extern liftData levellifts[5];

void propRestartLifts();
void propResetLifts();
void propEndLifts();
void propPreloadLift(setuplift *sl);
void liftButtonReset(struct prop_s *p);
void liftButtonOn(struct prop_s *p);
void liftButtonPowerOff(struct prop_s *p);
boolean liftCanActivateButton(struct prop_s *button);
boolean liftIsReadyToEnter(struct prop_s *lift, liftNode *currentNode, liftNode *targetNode);
liftNode* liftGetFromQueue(struct prop_s *lift);
liftNode* liftTakeFromQueue(struct prop_s *lift);
void liftRemoveNodeFromQueue(struct prop_s *lift, liftNode *node);
void liftAddToQueue(struct prop_s *lift, liftNode *node);
boolean liftIsInQueue(struct prop_s *lift, liftNode *node);
boolean liftIsPreviousFloorValid(liftNode *node);
boolean liftIsNextFloorValid(liftNode *node);
void liftDecideAutomaticDirection(struct prop_s *p);
void liftDoorMove(struct prop_s *door, float scalar);
void liftChooseDestination(struct prop_s *p);
void liftStartMovingToDestination(struct prop_s *p);
void liftWaitingProcessDoors(struct prop_s *p);
void liftPropTick(struct prop_s *p);
void liftNodeCall(struct prop_s *lift, liftNode *node, int called);
void liftCall(struct prop_s *lift, int called);
void liftNoPowerMessage(struct prop_s *p, struct prop_s *actor);
void liftButtonUpActivate(struct prop_s *button, struct prop_s *actor);
void liftButtonDownActivate(struct prop_s *button, struct prop_s *actor);
void propNewLift(setuplift *sl);
void liftSetState(struct prop_s *p, int state);
liftData* liftFindNearestLift(struct prop_s *chr);
int liftFindFloor(struct prop_s *chr, int pad);

#endif // GAME_PROP_LIFT_H
