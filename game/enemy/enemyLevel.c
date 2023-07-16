// STATUS: NOT STARTED

#include "enemyLevel.h"

// warning: multiple differing types with the same name (#144,  not equal)
enum {
	OBJECTIVE1 = 0,
	OBJECTIVE2 = 1,
	OBJECTIVE3 = 2,
	OBJECTIVE4 = 3,
	OBJECTIVE5 = 4,
	OBJECTIVE6 = 5
};

static npcspawninfo spawninfo[100];
static int lvConditionFlag[7];
static setuplsphase *phase;
static setuplssnipergrp *snipergrp;
static int numphases;
static int curattack;
static int attackloopnum;
static int attackchrnum;
static float phasedelay;
static float phasetimer;
static float attackchrdelay;
static float sniperinterval;
static int snipertarget;
static int curphase;
static int curphasehud;

void enemyLevelRestart() {
	int i;
}

void enemyLevelReset() {}

void enemyLevelSetup() {}

void enemyAIDefaultSpawnHandler1() {
	int i;
	setupNPC *npc;
	npcspawninfo *spinf;
	doordata *door;
	int alarmnum;
	int p;
	boolean someonehasbag;
	int padextref;
	pad *padptr;
	int cindex;
	int chrtypeuse;
	int chrtypeoriginal;
	int i;
	int j;
	boolean dospawn;
	ViewDef *pView;
	float dir[3];
	chrdata *cd;
}

void enemyAIDamHandler() {
	int i;
	lvbuttondata *oproombd;
	link *disablelink;
	chrdata *cd;
	int j;
	chrdata *cd;
}

void enemyDamActivateLifts() {
	link *disablelink;
}

void enemyAITombHandler1() {
	int p;
	int got_thing;
}

void enemyAIChineseHandler1() {
	int p;
	int got_thing;
}

void enemyAIMansionHandler1() {}

void enemyAIDocksHandler1() {}

void enemyAIScifiHandler1() {
	int p;
	int got_thing;
}

void enemyAIVillageHandler1() {
	int p;
	int got_thing;
}

void enemyAILaunchHandler1() {}

void enemyAILastStandHandler() {
	int cindex;
	int activechrs;
	int i;
	float timedec;
	u8 *hudmsg;
	int b;
	int basebonus;
	int phasescore;
	int p;
	setupNPC *npc;
	int chrtypeuse;
	int chrtypeoriginal;
	setupNPC *npc;
	int chrtypeuse;
	int chrtypeoriginal;
}
