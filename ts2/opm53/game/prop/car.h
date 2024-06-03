// STATUS: NOT STARTED

#ifndef GAME_PROP_CAR_H
#define GAME_PROP_CAR_H

struct carPathTracker_s {
	carpath *currentPath;
	float pos[3];
	float distance;
	float scalarCurve;
	float scalarCurveChange;
};

typedef carPathTracker_s carPathTracker;
extern boolean debugTracker;

void carReset();
void carRestart();
void carEnd();
carpath* pathPreAllocatePaths(int numpaths);
void carSinePathNodeChanged(prop *p);
void carSplineCalcTrackerFast(prop *p, carPathTracker *tracker, float errorMargin, float desiredDist, carpath *path1, carpath *path2, carpath *path3, carpath *path4);
void carResetTracker(prop *p, carPathTracker *tracker);
prop* carPropNew(int propnum, int mode, int flags, carpath *paths, int numPaths);
void carPropTick(prop *p);
void carProcessEvent(prop *p, carpath *eventPath);
void taxiDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void copterDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);

#endif // GAME_PROP_CAR_H
