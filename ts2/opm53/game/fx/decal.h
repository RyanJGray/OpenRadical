//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_DECAL_H
#define GAME_FX_DECAL_H

#include "common.h"
#include "prop/prop.h"

typedef struct DecalDef_s {
	float Pos[8][4];
	float UV[8][2];
	struct DecalDef_s *pNext;
	struct DecalDef_s *pPrev;
	int Type;
	int NumPoints;
	int TexNum;
	int Room;
	int MatrixNum;
	prop *pProp;
	float AlphaScale;
	float AlphaScale1;
	u32 Col;
} DecalDef;

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
