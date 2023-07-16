// STATUS: NOT STARTED

#ifndef GAME_FRONT_FRONTFX_H
#define GAME_FRONT_FRONTFX_H

extern int bgtexnum;
extern int bgtexnum2;
extern int bgtexnum3;
extern int frontstate;
extern int logotop1num;
extern int logotop2num;
extern float frontfxtime;
extern float fronttime;
extern float globalscalex;
extern float globalscaley;
extern float flarescalarx;
extern float flarescalary;
extern float flareintensity[6];
extern int logoposx;
extern int logoposy;
extern float frontbgtime;
extern float frontbgtranslatex1;
extern float frontbgtranslatey1;
extern float frontbgtranslatex2;
extern float frontbgtranslatey2;
extern float frontbgtranslatex3;
extern float frontbgtranslatey3;
extern ringfx rings[7];
extern char frontfxalpha[512];
extern float frontfxgoodiestime;
extern int frontfxlpos;

void frontfxPreload();
void frontfxReset();
boolean frontfxFinished(int state);
void frontfxTick(int state);
void frontfxGfx(int state);
void frontfxLogoGfx(int state);
void frontfxRenderLayer(int logo, float scalex, float scaley, float red, float green, float blue, float alpha);
void frontfxPageIn();
void frontfxPageOut();
void frontfxSetupRing(int index, u32 ringCol, u32 glowCol);
void frontfxRingTick(int index);
void frontfxRingGfx(int index);
void frontfxBgReset();
void frontfxBgTick();
void frontfxWaveyTexture(int texnum, u32 rgba, int repeatx, int repeaty, float bgperiodx1, float bgperiodx2, float bgperiody1, float bgperiody2, float bgspeedx1, float bgspeedx2, float bgspeedy1, float bgspeedy2, float amplitudex, float amplitudey, float translatex, float translatey);
void frontfxBgGfx();
void frontfxGoodiesReset();
void frontfxGoodiesTick();
void frontfxGoodiesGfx();

#endif // GAME_FRONT_FRONTFX_H
