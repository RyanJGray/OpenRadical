//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GAME_UNLOCK_H
#define GAME_GAME_UNLOCK_H

#include "common.h"

typedef struct unlockcondition_s {
	int type;
	int data1;
	int data2type;
	int data2;
} unlockcondition_t;

typedef struct unlockconditionset_s {
	int numconditions;
	unlockcondition_t conditions[0];
} unlockconditionset_t;

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
