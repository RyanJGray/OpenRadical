// STATUS: NOT STARTED

#ifndef GAME_FX_SPRAY_H
#define GAME_FX_SPRAY_H

struct sprayParticle_s {
	int viewmask;
	int type;
	float time;
	float lifeTime;
	float pos[4];
};

typedef sprayParticle_s sprayParticle;

void sprayPreload();
void sprayRestart();
void sprayReset();
void sprayEnd();
int sprayGetMax();
int sprayGetCurrent();
sprayParticle* sprayGet(int index);
void sprayNew(int type, int viewmask, float x, float y, float z);
void sprayTick();
void sprayGfx();

#endif // GAME_FX_SPRAY_H
