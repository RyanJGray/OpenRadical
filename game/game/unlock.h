// STATUS: NOT STARTED

#ifndef GAME_GAME_UNLOCK_H
#define GAME_GAME_UNLOCK_H

struct unlockcondition_s {
	int type;
	int data1;
	int data2type;
	int data2;
};

typedef unlockcondition_s unlockcondition_t;

struct unlockconditionset_s {
	int numconditions;
	unlockcondition_t conditions[0];
};

typedef unlockconditionset_s unlockconditionset_t;

boolean chrPlayable(int chrnum);
boolean chrAvail(int chrnum);
boolean levelAvailSTORY(int levelnum, int use2Ptimes);
boolean levelAvail(int levelnum);
boolean botsetAvail(int arcadebotset);
boolean challengeModeAvail();
boolean challengeAvail(int challengenum);
boolean unlockedset(unlockconditionset_t *ucset);
boolean unlockedEx(unlockcondition_t *uc, int use2Ptimes);

#endif // GAME_GAME_UNLOCK_H
