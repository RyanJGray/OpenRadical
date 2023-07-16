// STATUS: NOT STARTED

#include "lv.h"

int lvgamenum = 2;
int lvlevelnum = 0;
int lvnumplayers = 0;

void lvRestartBefore() {}

void lvResetBefore() {}

void lvPreload() {}

void lvRestartAfter() {}

void lvResetAfter() {
	ViewDef *view;
}

void lvEnd() {}

void lvTickBefore() {}

void lvTickAfter() {}

void lvTickView() {}

void lvTickPlayer() {}

void lvGfxPlayer() {
	void *addr;
}

void lvGfxAfter() {
	float timeScalar;
	float timeClamp;
	float flashTime;
	float flashClamp;
	u32 rgba;
}
