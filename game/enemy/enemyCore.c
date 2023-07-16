// STATUS: NOT STARTED

#include "enemyCore.h"

struct coredropinfo_s {
	prop *prop;
	int owner;
	int teamdefenders[5];
	int defenderlist[14];
	int totaldefenders;
	int teamattackers[5];
	int totalattackers;
	int attackerlist[14];
};

typedef coredropinfo_s coredropinfo;

struct corechrinfo_s {
	int prevmsg;
	int prevmsgdata;
	int numattackers;
};

typedef corechrinfo_s corechrinfo;
static coredropinfo dropcoreinfo[20];
static corechrinfo chrcoreinfo[58];

void enemyCoreReset() {}

void enemyCoreRestart() {}

void enemyCoreSetup() {
	int i;
}

void enemyCoreTickBefore() {}

void enemyCoreTick() {
	int i;
	chrdata *cd;
	float dist1;
	float xd;
	float yd;
	float zd;
	prop *drop;
	prop *p;
	corechrinfo *cci;
	pad *pad;
}

void enemyCoreTickAfter() {}

void enemyCoreSendMessage(int msg, int chr, int data) {
	corechrinfo *cci;
	int team;
}

void enemyCoreEnd() {}

int enemyCoreGetNumDropDefenders(int drop) {}

int enemyCoreGetNumDropTeamDefenders(int drop, int team) {}

int enemyCoreGetNumDropAttackers(int drop) {}

int enemyCoreGetNumDropTeamAttackers(int drop, int team) {}

int enemyCoreGetDropOwner(int drop) {}

int enemyCoreGetNumChrsAttackingChr(int c) {}
