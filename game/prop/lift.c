// STATUS: NOT STARTED

#include "lift.h"

// warning: multiple differing types with the same name (#95,  not equal)
enum {
	LIFT_NOTCALLED = 0,
	LIFT_CALLEDUP = 1,
	LIFT_CALLEDDOWN = 2
};

// warning: multiple differing types with the same name (#95,  not equal)
enum {
	LIFTDIR_UNDECIDED = 0,
	LIFTDIR_UP = 1,
	LIFTDIR_DOWN = 2
};

static int numLifts;
liftData levellifts[5] = CCC_CANNOT_COMPUTE_ELEMENT_SIZE;

void propRestartLifts() {}

void propResetLifts() {}

void propEndLifts() {}

void propPreloadLift(setuplift *sl) {
	int nodeIndex;
}

void liftButtonReset(prop *p) {}

void liftButtonOn(prop *p) {}

void liftButtonPowerOff(prop *p) {}

boolean liftCanActivateButton(prop *button) {
	liftObData *obData;
	liftNode *node;
}

boolean liftIsReadyToEnter(prop *lift, liftNode *currentNode, liftNode *targetNode) {
	liftData *data;
}

liftNode* liftGetFromQueue(prop *lift) {
	liftData *data;
}

liftNode* liftTakeFromQueue(prop *lift) {
	liftData *data;
	liftNode *node;
	int q;
}

void liftRemoveNodeFromQueue(prop *lift, liftNode *node) {
	liftData *data;
	int count;
	int q;
}

void liftAddToQueue(prop *lift, liftNode *node) {
	liftData *data;
}

boolean liftIsInQueue(prop *lift, liftNode *node) {
	liftData *data;
	int count;
}

boolean liftIsPreviousFloorValid(liftNode *node) {}

boolean liftIsNextFloorValid(liftNode *node) {}

void liftDecideAutomaticDirection(prop *p) {
	liftData *data;
}

void liftDoorMove(prop *door, float scalar) {
	liftObData *doorData;
}

void liftChooseDestination(prop *p) {
	liftData *data;
}

void liftStartMovingToDestination(prop *p) {
	liftData *data;
	float diff[3];
}

void liftWaitingProcessDoors(prop *p) {
	liftData *data;
	float scalar;
}

void liftPropTick(prop *p) {
	liftData *data;
	int n;
	float timeSmooth;
	float diff[3];
	liftObData *doorData;
	liftObData *doorData;
}

void liftNodeCall(prop *lift, liftNode *node, int called) {
	liftData *liftdata;
}

void liftCall(prop *lift, int called) {
	liftData *liftdata;
}

void liftNoPowerMessage(prop *p, prop *actor) {}

void liftButtonUpActivate(prop *button, prop *actor) {
	liftObData *obData;
	liftNode *node;
	liftData *liftData;
}

void liftButtonDownActivate(prop *button, prop *actor) {
	liftObData *obData;
	liftNode *node;
	liftData *liftData;
}

void propNewLift(setuplift *sl) {
	prop *p;
	int nodeIndex;
	int q;
	liftObData *obData;
	liftObData *obData;
	liftObData *obData;
	liftObData *obData;
	liftNode *node;
	liftObData *obData;
	liftObData *obData;
	liftObData *obData;
	liftObData *obData;
}

void liftSetState(prop *p, int state) {
	int o;
	liftData *data;
}

liftData* liftFindNearestLift(prop *chr) {
	chrdata *cd;
	int i;
	int j;
	int padlist[20];
	int listsize;
}

int liftFindFloor(prop *chr, int pad) {}
