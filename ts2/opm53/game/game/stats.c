//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "stats.h"

typedef struct internalstats_s {
	stats game;
	int succesivekills;
	float killtimes[20];
	int recentkill;
	int repeatkills;
	float repeatkilltime;
} internalstats;

static short int medaltext[48] = {
	/* [0] = */ 772,
	/* [1] = */ 773,
	/* [2] = */ 774,
	/* [3] = */ 775,
	/* [4] = */ 776,
	/* [5] = */ 777,
	/* [6] = */ 778,
	/* [7] = */ 779,
	/* [8] = */ 780,
	/* [9] = */ 781,
	/* [10] = */ 782,
	/* [11] = */ 783,
	/* [12] = */ 784,
	/* [13] = */ 785,
	/* [14] = */ 786,
	/* [15] = */ 787,
	/* [16] = */ 788,
	/* [17] = */ 789,
	/* [18] = */ 790,
	/* [19] = */ 791,
	/* [20] = */ 792,
	/* [21] = */ 793,
	/* [22] = */ 794,
	/* [23] = */ 795,
	/* [24] = */ 796,
	/* [25] = */ 797,
	/* [26] = */ 798,
	/* [27] = */ 799,
	/* [28] = */ 800,
	/* [29] = */ 801,
	/* [30] = */ 802,
	/* [31] = */ 803,
	/* [32] = */ 804,
	/* [33] = */ 805,
	/* [34] = */ 806,
	/* [35] = */ 807,
	/* [36] = */ 808,
	/* [37] = */ 809,
	/* [38] = */ 810,
	/* [39] = */ 811,
	/* [40] = */ 812,
	/* [41] = */ 813,
	/* [42] = */ 814,
	/* [43] = */ 815,
	/* [44] = */ 816,
	/* [45] = */ 817,
	/* [46] = */ 818,
	/* [47] = */ 819
};

internalstats matchstats[26] = {0};

char *awards[16][3] = {NULL};

int medals[16][3] = {0};

void StatsReset() {}

void StatsResetStruct(stats *target) {
	int s;
	int g;
	int c;
}

void StatsRestart() {}

void StatsTick() {}

void StatsKillMade(chrdata *killer, chrdata *killed) {
	int currentmultikills;
	int e;
	int f;
	float time;
	float thistime;
}

void StatsBodyPartHit(chrdata *attacker, chrdata *target, int bodypart) {}

int StatsGetMax(int statsentry, int players) {
	float max;
	int maxchr;
	int i;
}

int StatsGetMin(int statsentry, int players) {
	float min;
	int minchr;
	int i;
}

float StatsGetAverage(int statsentry, int players) {
	float average;
	int i;
}

void StatsCalc() {
	int i;
	int g;
	float time;
	int favouritegun;
	int favouritegunshots;
	float favouriteguntime;
	float pickuptimes;
}

void StatsCalcMedals() {
	int i;
	int c;
	int g;
	float charweaponpower[26];
	float totalweaponpower;
	float time;
	float ratio;
	int m;
	float medalscore[26][48];
	int maxchr;
	int maxchr;
	int maxchr;
	float value;
	float value;
	float value;
	int maxchr;
	int maxchr;
	int maxchr;
	int maxchr;
	int maxchr;
	int maxchr;
	int maxchr;
	int maxchr;
	float average;
	float average;
	int maxchr;
	int maxchr;
	float average;
	float value;
	float ratio;
	float average;
	float value;
	float ratio;
	float average;
	float value;
	float ratio;
	float value;
	float value;
	float value;
	float value;
	float value;
	float value;
	int leadmost;
	float leadmosttime;
	float value;
	int maxchr;
	int maxchr;
	int max;
	int maxchr;
	int min;
	int minchr;
	int totalkills;
	float average;
	float ratio;
	int minchr;
	int maxchr;
	int maxchr;
	int e;
	int t;
	int j;
	int g;
	boolean found;
	int m;
}

void StatsSet(int statsentry, int chr, float parm1) {}

void StatsAdd(int statsentry, int chr, float parm1) {}

float StatsGet(int statsentry, int chr) {}

float StatsGetGun(int statsentry, int chr, int gun) {}

float StatsGetChar(int statsentry, int chr, int chr2) {}

void StatsSetGun(int statsentry, int chr, int gun, float parm1) {}

void StatsAddGun(int statsentry, int chr, int gun, float parm1) {}

void StatsSetChar(int statsentry, int chr, int chr2, float parm1) {}

void StatsAddChar(int statsentry, int chr, int chr2, float parm1) {}

void StatsLifeReset(lifestats_t *lifestats) {
	int g;
	int m;
}

void StatsAddToLife(lifestats_t *lifestats, int i) {
	int g;
	int m;
	int e;
}

void StatsGetOverallLifestats(lifestats_t *overall, lifestats_t *story, lifestats_t *arcade, lifestats_t *challenge) {
	int g;
	int m;
}

char* StatsGetAward(int player, int awardnum) {}

int StatsGetNumAwards(int player) {
	int count;
	int i;
}
