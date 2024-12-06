//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GAME_STATS_H
#define GAME_GAME_STATS_H

#include "common.h"

// Forward-declarations.
struct chrdata_s;

typedef struct stats_s {
	float stat[69];
	float statgun[40][5];
	float statchar[14][6];
} stats;

typedef struct chrstats_s {
	u32 count;
} chrstats_t;

typedef struct levelstats_s {
	u32 countstory;
	u32 totaltime;
	u32 besttime[3];
	u32 besttime2P[3];
	u32 countarcade;
} levelstats_t;

typedef struct challengestats_s {
	u32 count;
	int bestscore;
} challengestats_t;

typedef struct lifestats_s {
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
} lifestats_t;

// TODO! Not sure these are even supposed to be defined as extern here? Not accessed by any other functions outside of this file.
/*extern struct internalstats_s matchstats[26];
extern char *awards[16][3];
extern int medals[16][3];
*/

void StatsReset();
void StatsResetStruct(stats *target);
void StatsRestart();
void StatsTick();
void StatsKillMade(struct chrdata_s *killer, struct chrdata_s *killed);
void StatsBodyPartHit(struct chrdata_s *attacker, struct chrdata_s *target, int bodypart);
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
