// STATUS: NOT STARTED

#ifndef GAME_FX_STARFIELD_H
#define GAME_FX_STARFIELD_H

extern star *stars;
extern space_fire *spacefires;
extern float spacefirestart[3];
extern int starfieldtexnum;
extern int spacefiretexnum;

void starfieldPreload();
void setStar(int i);
void starfieldRestart();
void starfieldReset();
void starfieldTick();
void specialParticlesGfx(float *drawpos, u32 *col, int numstars, int texwidth, int texheight);
void starfieldGfx();

#endif // GAME_FX_STARFIELD_H
