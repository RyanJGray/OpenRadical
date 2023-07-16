// STATUS: NOT STARTED

#include "move.h"

float lastfloorheight = -3.40282347e+38f;
static float s_HitNormFrac[2];

static float calcfloorheight(float *p1, float *p2, float *p3, float x, float z) {
	float d1[3];
	float d2[3];
	float a;
	float b;
	float c;
	float d;
	int i;
}

float moveFindFloorHeight(int numfloors, floordef **floors, int switchflags, float *pos, floordef **floorret) {
	floordef *floor;
	floordef *bestfloor;
	float bestheight;
	int f;
	floorpointdef *p1;
	floorpointdef *p2;
	int i;
	int f1;
	int f2;
	int inside;
	float height;
	float dx1;
	float dz1;
	float dx2;
	float dz2;
}

static float moveFindFloorRoom(int room, float *pos, floordef **floorret, prop **ppStandOnProp) {
	floordef **ppFloors;
	floordef *pBestFloor;
	floordef *pFloor;
	float BestHeight;
	prop *pProp;
	float Height;
}

int moveFindRoom(float *pos, float height, float rad) {
	float bestheight;
	float tmppos[3];
	float bb[2][3];
	int rooms[21];
	int i;
	int numrooms;
	int bestroom;
	float h;
	float Dir[3];
	float FloorPos[3];
}

float moveFindFloor(float *pos, float height, float rad, floordef **floorret, prop **ppPropRet) {
	float tmppos[3];
	float bb[2][3];
	float bestheight;
	floordef *bestfloor;
	prop *pBestProp;
	int rooms[21];
	int i;
	int numrooms;
	floordef *floor;
	prop *pProp;
	float h;
}

float DistFromWallSq(float *Pos, float Height, walldef *pWall, float *HitNorm, float MaxDistSq) {
	float Vector[2];
	float WallDirection[2];
	float DirectionSizeSq;
	float DistSq;
	float t;
}

void MoveTestWall(int numwalls, walldef **walls, int switchflags, float *bb[3], float *StartPos, float Radius, float Height, float *MoveDirXZ, float *pHitFrac, float *HitNormFrac, float *pHitDist, float *HitNormDist) {
	float *HitNormDist;
	walldef *wall;
	float BestDist;
	float BestFrac;
	float BestHitNormFrac[2];
	float BestHitNormDist[2];
	int w;
	float HitNorm[2];
	float Dist;
	float hitnorm[2];
	float frac;
	float HitNorm[2];
	float Dist;
	float HitNorm[2];
	float Dist;
}

int moveTest(int chr, float *startpos, float *endpos, float height, float rad, float *suggestpos, floordef **floorret, boolean GoingToMove, int ExcludeFlag) {
	float movedirxz[2];
	float bb[2][3];
	float bestfrac;
	float BestHitNormFrac[2];
	float startheight;
	float endheight;
	int rooms[21];
	int i;
	int numrooms;
	u32 flags;
	float BestDist;
	float BestHitNormDist[2];
	chrdata *pChrInfo;
	boolean HorizontalMovement;
	int BestHitChr;
	float Frac;
	float HitNormFrac[2];
	float HitNormDist[2];
	float HitDist;
	float Frac;
	float HitNormFrac[2];
	float HitNormDist[2];
	float HitDist;
	int HitChr;
	float dot;
	float slidelensq;
	float reduce;
	float slidedir[2];
	float AmountMoveFromWall[2];
	boolean CalculatePos;
	float Dist;
	float *pPosUse;
	floordef *pFloor;
	prop *pStandOnProp;
}

int moveTestDoSlide(int Chr, float *StartPos, float *EndPos, float Height, float Rad, floordef **ppFloorRet, boolean GoingToMove, int ExcludeFlag) {
	chrdata *pChrInfo;
	float SuggestPos[3];
	float SuggestPos1[3];
	int Flags;
	float dx;
	float dy;
	float dz;
	float LastFloorHeight;
	floordef *pLastFloor;
	float EndHeight;
	float HitNorm[2];
	boolean Slide;
	boolean FirstMoveHitChr;
	int FirstMoveLastChrHit;
	float StartDir[2];
	float EndPosOrig[3];
	boolean DoneThird;
	float Dir[2];
	float Dot;
	float Dir[2];
	float Dot;
	float RLen;
	float Vec[2];
	float CheckDistSq;
}

void moveCylGfx(float posx, float posy, float posz, float height, float rad) {
	u32 *ref;
	int i;
	void *addr;
	float ang1;
	float sin1;
	float cos1;
	float ang2;
	float sin2;
	u32 col;
}
