//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_MOVE_MOVE_H
#define GAME_MOVE_MOVE_H

#include "common.h"

// Forward-declarations.
struct prop_s;

enum {
	MOVEMODE_NORMAL = 0,
	MOVEMODE_PUSH = 1,
	MOVEMODE_FALL = 2,
	MOVEMODE_JUMP = 3,
	MOVEMODE_DIE = 4,
	MOVEMODE_REBORN = 5,
	MOVEMODE_LINEUPFIXEDGUN = 6,
	MOVEMODE_FIXEDGUN = 7,
	MOVEMODE_REMOTEDEVICE = 8,
	MOVEMODE_MAX = 9
};

enum {
	MOVEMENTTYPE_NORMAL = 0,
	MOVEMENTTYPE_SKATE = 1,
	MOVEMENTTYPE_NUM = 2
};

typedef struct floorpointdef_s {
	float pos[3];
} floorpointdef;

typedef struct floordef_s {
	u32 numpoints;
	u16 switchmask;
	u16 flags;
	int fxUsage;
	float fxProportion;
	float xzbb[2][2];
	floorpointdef points[0];
} floordef;

typedef struct walldef_s {
	u16 switchmask;
	u16 flags;
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
	float xzbb[2][2];
} walldef;

extern float lastfloorheight;

float moveFindFloorHeight(int numfloors, floordef **floors, int switchflags, float *pos, floordef **floorret);
int moveFindRoom(float *pos, float height, float rad);
float moveFindFloor(float *pos, float height, float rad, floordef **floorret, struct prop_s **ppPropRet);
float DistFromWallSq(float *Pos, float Height, walldef *pWall, float *HitNorm, float MaxDistSq);
void MoveTestWall(int numwalls, walldef **walls, int switchflags, float *bb[3], float *StartPos, float Radius, float Height, float *MoveDirXZ, float *pHitFrac, float *HitNormFrac, float *pHitDist, float *HitNormDist);
int moveTest(int chr, float *startpos, float *endpos, float height, float rad, float *suggestpos, floordef **floorret, boolean GoingToMove, int ExcludeFlag);
int moveTestDoSlide(int Chr, float *StartPos, float *EndPos, float Height, float Rad, floordef **ppFloorRet, boolean GoingToMove, int ExcludeFlag);
void moveCylGfx(float posx, float posy, float posz, float height, float rad);

#endif // GAME_MOVE_MOVE_H
