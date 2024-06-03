// STATUS: NOT STARTED

#include "remote.h"

void remoteGetStandPos(prop *pProp, float Angle, float *Pos) {
	float ActivePos[3];
	float CentrePos[3];
	mtx_u Mtx;
	float *dof;
}

float remoteGetStandAngle(prop *pProp, float *Pos) {
	float CentrePos[3];
	mtx_u Mtx;
	float *dof;
	float Angle;
}

static boolean checkCameraCanSee(prop *p, prop *checkprop) {
	remotedata *pd;
	float Dir[3];
	float LookPos[3];
	float ay;
	float dist;
	float lookdirx;
	float lookdiry;
	prop *hit;
}

void remotePropFixedGunTick(prop *p) {
	mtx_u tmpmtx;
	int i;
	remotedata *pd;
	chrdata *pChr;
	prop *pProp;
	player *pPlayer;
	int NewButs;
	float dx;
	float dy;
	float dz;
	float DistSq;
	float PivotePos[3];
	prop *pProp;
	player *pPlayer;
	chrdata *pChr;
	int NewButs;
	float AngleDiff;
	float AmountAdd;
	float StandPos[3];
	boolean YThere;
	boolean XThere;
	boolean PosThere;
	prop *pProp;
	chrdata *pChr;
	player *pPlayer;
	int NewButs;
	float *dof;
	int e;
	prop *p;
	obdef *ob;
	partdef *parts;
	int num;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

void remotePropAttachedTick(prop *p) {
	mtx_u tmpmtx;
	partdef *parts;
	float *dof;
	float dir[3];
	float pos[3];
	int i;
	int mtxindex;
	int canshoot;
	remotedata *pd;
	int shootthisframe;
	prop *pPlayerProp;
	chrdata *cd;
	float shootdirx;
	float shootdiry;
	float frac;
	prop *seen;
	prop *playerprop;
	chrdata *cd;
	float *anotherdof;
}

void remotePropTick(prop *p) {
	remotedata *pd;
	int i;
}

void remoteGunDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	HitInfoDef hitinfo;
	remotedata *pd;
	float explosionPos[3];
	remotedata *pd;
}

static void cameraDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	remotedata *rd;
	HitInfoDef hitinfo;
	float explosionPos[3];
	float up[3];
	int i;
	particlegroup *pg2;
}

void railBotDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	remotedata *rd;
	floordef **ppFloors;
	floordef *pFloor;
	float explosionPos[3];
	float up[3];
	int i;
	particlegroup *pg2;
}

static void remoteRailBotFallToGround(prop *p) {
	float explosionPos[3];
	float up[3];
}

float* remoteGetPivoteOffset(prop *pProp) {
	partdef *pParts;
	remotedata *rd;
}

float* remoteGetBarrelOffset(prop *pProp) {
	partdef *pParts;
}

float* remoteGetShootPosOffset(prop *pProp) {
	partdef *pParts;
}

void remoteGetPivotePos(prop *Prop, float *Pos) {
	float ThePos[3];
	mtx_u Mtx;
	float *dof;
}

void remoteGetLensePos(prop *Prop, float *Pos) {
	remotedata *rd;
	partdef *Parts;
	mtx_u Mtx;
	mtx_u CompoundMtx;
	float ThePos[3];
	float PivotPos[3];
	float *dof;
	partdef *Parts;
	mtx_u Mtx;
	mtx_u CompoundMtx;
	float ThePos[3];
	float PivotPos[3];
	float *dof;
}

void remoteGetShootPos(prop *Prop, float *Pos) {
	remotedata *rd;
	partdef *Parts;
	mtx_u Mtx;
	mtx_u CompoundMtx;
	float ThePos[3];
	float PivotPos[3];
	float *dof;
}

void remoteGetBarrelRotPos(prop *Prop, float *Pos) {
	remotedata *rd;
	partdef *Parts;
	mtx_u Mtx;
	mtx_u CompoundMtx;
	float ThePos[3];
	float PivotPos[3];
	float *dof;
}

prop* remotePropNew(setupremote *sr, float *pos, float roty, int data1, int team) {
	prop *p;
	remotedata *rd;
	partdef *parts;
	float PivotePos[3];
	float LensePos[3];
	int ammoType;
	float TargetVec[3];
	float Zaxis[3];
	float frac;
}

void remotePropDrawBounds(prop *p) {}

void propRailBotTick(prop *p) {}

void propRailBotBossRoomTick(prop *p) {
	mtx_u tmpmtx;
	float *dof;
	float dir[3];
	float pos[3];
	int i;
	int canshoot;
	remotedata *pd;
	int shootthisframe;
	prop *pPlayerProp;
	chrdata *cd;
	float shootdirx;
	float shootdiry;
	float frac;
	prop *seen;
	prop *playerprop;
	chrdata *cd;
}
