// STATUS: NOT STARTED

#ifndef GAME_MOVE_MOVE_H
#define GAME_MOVE_MOVE_H

typedef floordef_s floordef;
typedef walldef_s walldef;
extern float lastfloorheight;

float moveFindFloorHeight(int numfloors, floordef **floors, int switchflags, float *pos, floordef **floorret);
int moveFindRoom(float *pos, float height, float rad);
float moveFindFloor(float *pos, float height, float rad, floordef **floorret, prop **ppPropRet);
float DistFromWallSq(float *Pos, float Height, walldef *pWall, float *HitNorm, float MaxDistSq);
void MoveTestWall(int numwalls, walldef **walls, int switchflags, float *bb[3], float *StartPos, float Radius, float Height, float *MoveDirXZ, float *pHitFrac, float *HitNormFrac, float *pHitDist, float *HitNormDist);
int moveTest(int chr, float *startpos, float *endpos, float height, float rad, float *suggestpos, floordef **floorret, boolean GoingToMove, int ExcludeFlag);
int moveTestDoSlide(int Chr, float *StartPos, float *EndPos, float Height, float Rad, floordef **ppFloorRet, boolean GoingToMove, int ExcludeFlag);
void moveCylGfx(float posx, float posy, float posz, float height, float rad);

#endif // GAME_MOVE_MOVE_H
