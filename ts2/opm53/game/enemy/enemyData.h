// STATUS: NOT STARTED

#ifndef GAME_ENEMY_ENEMYDATA_H
#define GAME_ENEMY_ENEMYDATA_H

struct animsequence_s {
	int numanims;
	int animnum[10];
};

typedef animsequence_s animsequence;

struct attackphase_s {
	int numattackseqs;
	int seq[14];
};

typedef attackphase_s attackphase;

struct animpersonalityinfo_s {
	float backoffdist;
	float closeindist;
	int closeinprob;
	int attackprob;
	int backoffprob;
	int defaultanim;
};

typedef animpersonalityinfo_s animpersonalityinfo;
extern animpersonalityinfo animPersonalityInfo[10];
extern animsequence animseqs[70];
extern char *animseqs_str[70];
extern attackphase attackphases[10][5];


#endif // GAME_ENEMY_ENEMYDATA_H
