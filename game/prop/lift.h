// STATUS: NOT STARTED

#ifndef GAME_PROP_LIFT_H
#define GAME_PROP_LIFT_H

struct liftNode_s {
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
};

typedef liftNode_s liftNode;
typedef setuplift_s setuplift;
typedef liftData_s liftData;
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
