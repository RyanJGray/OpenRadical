// STATUS: NOT STARTED

#ifndef GAME_GAME_CHALLENGE_H
#define GAME_GAME_CHALLENGE_H

struct challengecondition_s {
	u16 conditionflags;
	u16 scoretype;
	int attribute;
	int source;
	int comp;
	int data1;
};

typedef challengecondition_s challengecondition_t;

struct setupchallenge_s {
	short int title;
	int levelnum;
	int gamemode;
	int gameflags;
	challengecondition_t *conditions;
	int numconditions;
	int gunset;
	gunset guns;
	challengechrset *chrset;
	challengeplayerstart playerstart;
	short int description;
};

typedef setupchallenge_s setupchallenge;

setupchallenge* challengeGetSetupNum(int challengenum);
setupchallenge* challengeGetSetup();
int challengeGetScore();
boolean challengeIsBestScore();
u8* challengeFormatScore(int challengenum, int score);
challengecondition_t* challengeGetScoreCondition(int challengenum);
void challengeRestart();
int GetChallengeTimeLeft();
void challengeGetDisplayScore(u8 **head, u8 **sub);
void challengeGetDisplayFailed(u8 **head, u8 **sub, u8 **reason);
void challengeTick();

#endif // GAME_GAME_CHALLENGE_H
