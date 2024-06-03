// STATUS: NOT STARTED

#ifndef GAME_FX_ROOMFX_H
#define GAME_FX_ROOMFX_H


void fogfxPreload();
void fogfxReset();
void fogfxRestart();
void fogfxTick();
void fogfxGfx();
void roomfxPreload();
void roomfxReset();
void roomfxRestart();
void roomfxEnd();
roomfx* roomfxNew();
void roomfxFree(roomfx *rfx);
void roomfxTick();
void roomfxGfx();
void roomfxNewMiniwaveFromBullet(float *hitpos, bullet *b);
void roomfxNewShockwave(float *hitpos, float power);
void roomfxNewOutline();
void roomfxShockwaveTickSetVertices(roomfx *rfx, prop *p, int partNum, int gfxtype, float *sxyz);
void roomfxShockwaveTick(roomfx *rfx);
void roomfxMiniwaveTickSetVertices(roomfx *rfx, prop *p, int partNum, int gfxtype, float *sxyz);
void roomfxMiniwaveTick(roomfx *rfx);
void roomfxOutlineTickSetVertices(roomfx *rfx, prop *p, int partNum, int gfxtype, u32 *sgif, float intensity);
void roomfxOutlineTick(roomfx *rfx);

#endif // GAME_FX_ROOMFX_H
