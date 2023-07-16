// STATUS: NOT STARTED

#ifndef GAME_FX_ROOMLIGHT_H
#define GAME_FX_ROOMLIGHT_H

struct roomlightinit_s {
	int type;
	float speed;
	float frac;
	u32 mincol;
	u32 maxcol;
	u32 col;
};

typedef roomlightinit_s roomlightinit;
extern roomlightinit *roomlightinitial;
extern float ambientlights[225][3];
extern char ambientlightfilename[100];

void roomlightRestart();
void roomlightReset();
void roomlightEnd();
boolean roomlightGetRoomColourIntensity(int Room, u32 *pColour, u32 *pIntensity);
void ambientlightPreload();
void roomlightTick();
void roomlightSet(int room, int type, float speed, float frac, u32 mincol, u32 maxcol);

#endif // GAME_FX_ROOMLIGHT_H
