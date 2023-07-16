// STATUS: NOT STARTED

#ifndef GAME_GAME_DEMO_H
#define GAME_GAME_DEMO_H

struct demoheader_s {
	resetgameparms gameparms;
};

typedef demoheader_s demoheader_t;

void demoMakeHeader();
void demoLoad(int demonum);
demoheader_t* demoGetHeader();
void demoStart(int demonum);
void demoEnd();

#endif // GAME_GAME_DEMO_H
