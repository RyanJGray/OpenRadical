// STATUS: NOT STARTED

#ifndef GAME_FX_DECAL_H
#define GAME_FX_DECAL_H

typedef void *DecalID;

void decalPreload();
void decalRestart();
void decalReset();
void decalEnd();
void decalNewDecal(int BulletType, int Room, prop *pHitProp, float *Pos, float *Norm);
void decalNewFootDecal(int Chr, float *Pos, float Dir, boolean Left);
DecalID decalNewGlassDecal(int BulletType, prop *pHitProp, int MatrixNum, float *Pos, float *Norm, glasspointdef *glassPoints, int NumClipPolyVertices);
void decalRemoveDecal(DecalID Decal);
void decalRemoveDecalsFromProp(prop *pProp);
void decalSetAlphaScale(DecalID Decal, float Scale);
void decalTick();
void decalDraw(DecalDef *pDecal, float AlphaScale);
void decalGfx(int Room);
void decalGfxMoving();

#endif // GAME_FX_DECAL_H
