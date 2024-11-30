// STATUS: NOT STARTED

#include "apache.h"

typedef enum {
	APACHEMODE_FLY_IN = 0,
	APACHEMODE_ATTACK = 1,
	APACHEMODE_CIRCLE = 2,
	APACHEMODE_CRASHING = 3,
	APACHEMODE_DEAD = 4
};

float hoverpos[3] = {
	/* [0] = */ 50.f,
	/* [1] = */ 43.5f,
	/* [2] = */ 10.f
};

float deathpos[5] = {
	/* [0] = */ 2.9f,
	/* [1] = */ 23.f,
	/* [2] = */ -53.f,
	/* [3] = */ 340.f,
	/* [4] = */ 0.7f
};

float riselocs[4][5] = {
	/* [0] = */ {
		/* [0] = */ 0.f,
		/* [1] = */ 5.f,
		/* [2] = */ -190.f,
		/* [3] = */ 190.f,
		/* [4] = */ 50.f
	},
	/* [1] = */ {
		/* [0] = */ 50.f,
		/* [1] = */ 3.f,
		/* [2] = */ -30.f,
		/* [3] = */ 190.f,
		/* [4] = */ 0.6f
	},
	/* [2] = */ {
		/* [0] = */ 50.f,
		/* [1] = */ 10.f,
		/* [2] = */ 6.f,
		/* [3] = */ 180.f,
		/* [4] = */ 0.1f
	},
	/* [3] = */ {
		/* [0] = */ 50.f,
		/* [1] = */ 18.2f,
		/* [2] = */ 12.f,
		/* [3] = */ 180.f,
		/* [4] = */ 0.6f
	}
};

float circlelocs[7][5] = {
	/* [0] = */ {
		/* [0] = */ 62.f,
		/* [1] = */ 55.f,
		/* [2] = */ 48.f,
		/* [3] = */ 190.f,
		/* [4] = */ 0.6f
	},
	/* [1] = */ {
		/* [0] = */ 70.f,
		/* [1] = */ 52.f,
		/* [2] = */ 80.f,
		/* [3] = */ 140.f,
		/* [4] = */ 0.3f
	},
	/* [2] = */ {
		/* [0] = */ 47.f,
		/* [1] = */ 60.f,
		/* [2] = */ 112.f,
		/* [3] = */ 120.f,
		/* [4] = */ 0.8f
	},
	/* [3] = */ {
		/* [0] = */ 27.f,
		/* [1] = */ 50.f,
		/* [2] = */ 70.f,
		/* [3] = */ 0.f,
		/* [4] = */ 1.1f
	},
	/* [4] = */ {
		/* [0] = */ 30.f,
		/* [1] = */ 50.f,
		/* [2] = */ 35.f,
		/* [3] = */ 350.f,
		/* [4] = */ 0.05f
	},
	/* [5] = */ {
		/* [0] = */ 32.f,
		/* [1] = */ 48.f,
		/* [2] = */ 16.f,
		/* [3] = */ 315.f,
		/* [4] = */ 0.7f
	},
	/* [6] = */ {
		/* [0] = */ 55.f,
		/* [1] = */ 48.f,
		/* [2] = */ -3.f,
		/* [3] = */ 180.f,
		/* [4] = */ 0.3f
	}
};

float movevec[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

float targetpos[3] = {
	/* [0] = */ 50.f,
	/* [1] = */ 45.f,
	/* [2] = */ 9.f
};

float gunrotate[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

float randomvec[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

float *target = riselocs;
int soundhandle = 0;
int soundstart = 0;
int apachemode = 0;

boolean apachelauncheron[4] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0
};

float accel = 0.f;
float targetangle = 0.f;
float speed = 0.f;
int hangaroundf = 0;
int rocketfiretime = 0;
int nextrocketfire = 0;
int gunfiretime = 0;
int explosiontime = 0;
int explosioncount = 0;

float apachelauncherhealth[4] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f,
	/* [3] = */ 0.f
};

int apachelaunchersactive = 0;
int gunactive = 0;
int gunchangetime = 0;

void apachePropNew(prop *p) {}

void apacheDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed) {
	float exPos[3];
	float up[3];
	HitInfoDef hitinfo;
	int launcherdead;
	float pos[3];
	mtx_u makemtx;
	mtx_u tmpmtx;
	prop *p;
	int dofID;
	obinst *inst;
	obdef *ob;
	partdef *parts;
}

void ApacheFireRockets(prop *p, float *playpos) {
	float playdir[3];
	float facedir[3];
	float frac;
	float vec[3];
	float pos[3];
	chrgun gun;
	mtx_u makemtx;
	mtx_u tmpmtx;
	float *mdof;
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
}

void ApacheGunTick(prop *p, float *playpos, player *play) {
	float apachefacedir[3];
	float gunfacedir[3];
	float tmpvec[3];
	float playdir[3];
	float shootpos[3];
	mtx_u tmpmtx;
	mtx_u makemtx;
	float xang;
	float yang;
	float ydif;
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	prop *p;
	float frac;
	chrgun gun;
}

int apacheGetTargetPlayer(prop *p) {
	int numplayers;
	boolean p1ondam;
	boolean p2ondam;
	float p1dist;
	float p2dist;
}

void copterPropTick(prop *p) {
	mtx_u tmpmtx;
	int pa;
	specialdata *data;
	float mvec[3];
	float playpos[3];
	float frameaccel;
	int targetplayer;
	float exPos[3];
	float spos[3];
	prop *p;
	obinst *inst;
	obdef *ob;
	partdef *parts;
	float rotmove;
	float rotdif;
	float rotatespeed;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	obdef *ob;
	partdef *parts;
	prop *p;
	obdef *ob;
	partdef *parts;
}
