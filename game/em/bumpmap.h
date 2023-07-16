// STATUS: NOT STARTED

#ifndef GAME_EM_BUMPMAP_H
#define GAME_EM_BUMPMAP_H

struct bumpmapPlane_s {
	float normal[3];
	rgba_t *palette[4];
	int frameUpdated[4];
};

typedef bumpmapPlane_s bumpmapPlane;
extern float bulletFiredTime;

void bumpmapPreload();
void bumpmapReset();
void bumpmapRestart();
void bumpmapEnd();
void bumpmapTick();
void bumpmapTickPlayer();
void bumpmapSetPlane(bumpmapPlane *plane);
void bumpmapGfxProp(prop *p);

#endif // GAME_EM_BUMPMAP_H
