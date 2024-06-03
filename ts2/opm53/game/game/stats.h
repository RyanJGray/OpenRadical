// STATUS: NOT STARTED

#ifndef GAME_GAME_STATS_H
#define GAME_GAME_STATS_H

struct stats_s {
	float stat[69];
	float statgun[40][5];
	float statchar[14][6];
};

typedef stats_s stats;

struct lifestats_s {
	int totalgames;
	int totalframesplayed;
	int totalkills;
	int totaltimeskilled;
	int succesivekills;
	int multikills;
	int repeatkills;
	int totalshots;
	int totalhits;
	float headhits;
	float bodyhits;
	float armhits;
	float leghits;
	int headsshotoff;
	int headspunchedoff;
	int glasshits;
	int gunshots[41];
	float guntime[41];
	int timesplitterskilled;
	int itemsrecovered;
	float disttravelled;
	char medalcollected[48];
};

typedef lifestats_s lifestats_t;
extern internalstats matchstats[26];
extern char *awards[16][3];
extern int medals[16][3];

void StatsReset();
void StatsResetStruct(stats *target);
void StatsRestart();
void StatsTick();
void StatsKillMade(chrdata *killer, chrdata *killed);
void StatsBodyPartHit(chrdata *attacker, chrdata *target, int bodypart);
int StatsGetMax(int statsentry, int players);
int StatsGetMin(int statsentry, int players);
float StatsGetAverage(int statsentry, int players);
void StatsCalc();
void StatsCalcMedals();
void StatsSet(int statsentry, int chr, float parm1);
void StatsAdd(int statsentry, int chr, float parm1);
float StatsGet(int statsentry, int chr);
float StatsGetGun(int statsentry, int chr, int gun);
float StatsGetChar(int statsentry, int chr, int chr2);
void StatsSetGun(int statsentry, int chr, int gun, float parm1);
void StatsAddGun(int statsentry, int chr, int gun, float parm1);
void StatsSetChar(int statsentry, int chr, int chr2, float parm1);
void StatsAddChar(int statsentry, int chr, int chr2, float parm1);
void StatsLifeReset(lifestats_t *lifestats);
void StatsAddToLife(lifestats_t *lifestats, int i);
void StatsGetOverallLifestats(lifestats_t *overall, lifestats_t *story, lifestats_t *arcade, lifestats_t *challenge);
char* StatsGetAward(int player, int awardnum);
int StatsGetNumAwards(int player);

#endif // GAME_GAME_STATS_H
