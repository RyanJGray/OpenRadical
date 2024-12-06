//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GAME_CHEATS_H
#define GAME_GAME_CHEATS_H

#include "common.h"
#include "unlock.h"

// warning: multiple differing types with the same name (size not equal)
typedef struct cheatdef_s {
	short int name;
	int flags;
	unlockconditionset_t *unlockset;
} cheatdef_t;

extern cheatdef_t cheatdefs[15];
extern u32 unlockedcheats;
extern u32 selectedcheats;
extern u32 allowedcheats;

void cheatsUpdate();
u32 cheatsChrSelect();
u32 cheatsArcade();
u32 cheatsStory();
void cheatsMake();
void cheatsReset();

#endif // GAME_GAME_CHEATS_H
