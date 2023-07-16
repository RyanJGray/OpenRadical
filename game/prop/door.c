// STATUS: NOT STARTED

#include "door.h"

doordata *leveldoors = NULL;
int numdoors = 0;

prop *doors[40] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL,
	/* [20] = */ NULL,
	/* [21] = */ NULL,
	/* [22] = */ NULL,
	/* [23] = */ NULL,
	/* [24] = */ NULL,
	/* [25] = */ NULL,
	/* [26] = */ NULL,
	/* [27] = */ NULL,
	/* [28] = */ NULL,
	/* [29] = */ NULL,
	/* [30] = */ NULL,
	/* [31] = */ NULL,
	/* [32] = */ NULL,
	/* [33] = */ NULL,
	/* [34] = */ NULL,
	/* [35] = */ NULL,
	/* [36] = */ NULL,
	/* [37] = */ NULL,
	/* [38] = */ NULL,
	/* [39] = */ NULL
};

void restartDoors() {}

prop* doorNewInVolume(int propnum, int volnum, int id, int key, int extrefpadnum, int doorflags) {
	volume *v;
	prop *d;
}

prop* doorNew(int propnum, int id, int key, float x, float y, float z, int extrefpadnum, int doorflags) {
	prop *p;
	doordata *door;
	int i;
	int padnum;
	link *l;
}

boolean doorActivate(prop *p, prop *actor) {
	doordata *data;
	boolean activate;
	int i;
}

void doorPropTick(prop *p) {
	doordata *door;
	link *doorlink;
	int i;
	chrdata *chr;
	prop *chrprop;
	float doorspeed;
	float doorspeed;
	partdef *parts;
	int numleft;
	int numright;
	partdef *parts;
	int numleft;
	int numright;
	partdef *parts;
	int numleft;
	int numright;
}

void doorLock(int id) {
	prop *p;
	doordata *door;
}

void doorUnlock(int id) {
	prop *p;
	doordata *door;
}

void doorOpen(int id) {
	prop *p;
	doordata *door;
}

void doorClose(int id) {
	prop *p;
	doordata *door;
}

doordata* doorIDgetData(int doorid) {}

prop* doorIDgetProp(int doorid) {}

int doorIDisOpen(int doorid) {}
