// STATUS: NOT STARTED

#include "car.h"

boolean debugTracker = 0;
static carpath dynamicPaths[50];
static int currentDynamicPath;

void carReset() {}

void carRestart() {}

void carEnd() {}

carpath* pathPreAllocatePaths(int numpaths) {}

static void carUpdateAbsSinePath(prop *p, float dist) {
	float distleft;
	cardata *data;
	carPathTracker *tracker;
	float d[3];
	float deltaang;
	float pathlen;
	float destdirx;
	float centrex;
	float centrez;
	float deltaang;
	float pathlen;
	float destdirx;
	float centrex;
	float centrez;
}

static void carUpdateRelSinePath(prop *p, float dist) {
	float distleft;
	cardata *data;
	carPathTracker *tracker;
	int advance;
	float changeScalar;
	float d[3];
	float done[3];
	float target[3];
	float change;
	float diff[3];
	float radius;
	float deltaang;
	float pathlen;
	float radius;
	float deltaang;
	float pathlen;
	float currentangle;
	float destangle;
}

void carSinePathNodeChanged(prop *p) {
	carPathTracker *tracker;
	float opprot;
	float opprot;
}

static carpath* carGetSplinePrevPoint(prop *p, carpath *path) {
	cardata *data;
	carpath *prevpath;
}

static carpath* carGetSplineNextPoint(prop *p, carpath *path) {
	cardata *data;
	carpath *nextpath;
}

static float carGetSplineSectionLength(float *point1, float *point2, float *point3, float *point4) {
	float newpoint[3];
	float lastpoint[3];
	float dist;
	int t;
	float d[3];
}

static void carSetSplineLengths(prop *p) {
	cardata *data;
	float point1[3];
	float point2[3];
	float point3[3];
	float point4[3];
	carpath *path1;
	carpath *path2;
	carpath *path3;
	carpath *path4;
}

static void carSplineCalcTrackerSlow(prop *p, carPathTracker *tracker) {
	cardata *data;
	carpath *path1;
	carpath *path2;
	carpath *path3;
	carpath *path4;
	carpath *oldpath;
	float distanceBetweenPoints;
	int t;
	float newpoint[3];
	float lastpoint[3];
	float d[3];
}

void carSplineCalcTrackerFast(prop *p, carPathTracker *tracker, float errorMargin, float desiredDist, carpath *path1, carpath *path2, carpath *path3, carpath *path4) {
	float accuracyUpperBound;
	float accuracyLowerBound;
	float accuracy;
	float newpoint[3];
	int count;
	float d[3];
}

static void carUpdateSplinePath(prop *p, float distMoved) {
	cardata *data;
	carpath *path1;
	carpath *path2;
	carpath *path3;
	carpath *path4;
	carpath *oldpath;
	carPathTracker *posTracker;
	float scalarLinear;
	float distanceBetweenPoints;
	int trackerIndex;
	carPathTracker *tracker;
}

void carResetTracker(prop *p, carPathTracker *tracker) {
	cardata *data;
}

prop* carPropNew(int propnum, int mode, int flags, carpath *paths, int numPaths) {
	prop *p;
	cardata *data;
	int f;
}

static void carResetToStart(prop *p) {
	cardata *data;
	float padpos[3];
	int tr;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	carPathTracker tracker;
	float d[3];
	float dnorm[3];
	carPathTracker tracker;
	float d[3];
	float dnorm[3];
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	float *dofMiddle;
	float *dofEnd;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	carPathTracker tracker;
	float d[3];
}

void carPropTick(prop *p) {
	mtx_u tmpmtx;
	int padlist[20];
	cardata *data;
	float movescale;
	int r;
	int pa;
	int glowson1;
	int glowson2;
	int glowson3;
	int pa;
	int glowson1;
	int glowson2;
	int glowson3;
	mtx_u mat;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	obdef *ob;
	partdef *parts;
	float d[3];
	float dlen;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	float posd[3];
	float d[3];
	float dlen;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	mtx_u tmpmtx;
	float *dofMiddle;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	obdef *ob;
	partdef *parts;
	float d[3];
	float d[3];
}

static void disableLinks(prop *p, int resetlinks) {
	int i;
	int j;
	int k;
	float length;
	float depth;
}

void carProcessEvent(prop *p, carpath *eventPath) {
	cardata *data;
	mtx_u tmpmtx;
	float d[3];
	float dist;
	float distinv;
	float newpos[3];
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

void taxiDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {}

void copterDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {}
