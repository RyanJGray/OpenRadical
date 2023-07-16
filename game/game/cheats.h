// STATUS: NOT STARTED

#ifndef GAME_GAME_CHEATS_H
#define GAME_GAME_CHEATS_H

// warning: multiple differing types with the same name (#40, size not equal)
struct cheatdef_s {
	short int name;
	int flags;
	unlockconditionset_t *unlockset;
};

typedef cheatdef_s cheatdef_t;
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
