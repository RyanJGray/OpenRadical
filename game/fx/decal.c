// STATUS: NOT STARTED

#include "decal.h"

struct DecalDef_s {
	float Pos[8][4];
	float UV[8][2];
	DecalDef_s *pNext;
	DecalDef_s *pPrev;
	int Type;
	int NumPoints;
	int TexNum;
	int Room;
	int MatrixNum;
	prop *pProp;
	float AlphaScale;
	float AlphaScale1;
	u32 Col;
};

typedef DecalDef_s DecalDef;

struct FootDecalDef_s {
	DecalDef Decal;
	int ChrID;
	float Dir;
};

typedef FootDecalDef_s FootDecalDef;

struct DecalCreateDef_s {
	int Type;
	int TexNum;
	float Scale;
	u32 Col;
	float Dir;
	boolean RandomUV;
	int Chr;
	boolean LeftFoot;
	HitInfoDef HitInfo;
	float DecalPos[3];
	float DecalNorm[3];
};

typedef DecalCreateDef_s DecalCreateDef;

typedef struct {
	HitInfoDef HitInfo;
	float DecalPos[3];
	float DecalNorm[3];
} PolysDoneDef;

static int s_DecalCreateListRead = 0;
static int s_DecalCreateListWrite = 0;

static struct s_DecalTextures[13] {
	int TexNum;
	float Size;
	char *pFileName;
} = {
	/* [0] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.12f,
		/* .pFileName = */ 0x4514d8
	},
	/* [1] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.12f,
		/* .pFileName = */ 0x4514a8
	},
	/* [2] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.5f,
		/* .pFileName = */ 0x451480
	},
	/* [3] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.5f,
		/* .pFileName = */ 0x451458
	},
	/* [4] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.5f,
		/* .pFileName = */ 0x451430
	},
	/* [5] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.075f,
		/* .pFileName = */ 0x451400
	},
	/* [6] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.075f,
		/* .pFileName = */ 0x4513d0
	},
	/* [7] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.075f,
		/* .pFileName = */ 0x4513a0
	},
	/* [8] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.075f,
		/* .pFileName = */ 0x451370
	},
	/* [9] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.075f,
		/* .pFileName = */ 0x451340
	},
	/* [10] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.3f,
		/* .pFileName = */ 0x451310
	},
	/* [11] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.3f,
		/* .pFileName = */ 0x4512e0
	},
	/* [12] = */ {
		/* .TexNum = */ -1,
		/* .Size = */ 0.15f,
		/* .pFileName = */ 0x4512b8
	}
};

static DecalDef *s_Decals = NULL;
static int s_DecalsToGroup = 0;
static int s_NumGroups = 0;
static int s_MovingPropRoom = 0;
static int s_MaxNumDecals = 500;
static FootDecalDef *s_FootDecals = NULL;
static DecalCreateDef s_DecalCreateList[15];
static int s_NextDecal[29];
static DecalDef *s_pDecalDrawList[225];
static int s_NextFootDecal;

void decalPreload() {
	int i;
}

void decalRestart() {
	int i;
}

void decalReset() {}

void decalEnd() {}

static boolean decalClipToPoly(DecalDef *pDecal, float *Norm, int UStartEdge, int VStartEdge, float *pPolyVertex, u8 *pPolyVertexIndex, int PolyNumVertices, int *ReturnEdges[2]) {
	int i;
	float DecalPoints1[24];
	float DecalPoints2[24];
	float *pRead;
	float *pWrite;
	int NumReadPoints;
	int NumWritePoints;
	float dx;
	float dy;
	float dz;
	float ULengthSq;
	float VLengthSq;
	float UBaseLine[2][3];
	float VBaseLine[2][3];
	int ReturnEdgeIndex;
	float *pPoint;
	float *pNextPoint;
	float PlaneNorm[3];
	float LineVec[3];
	int j;
	float *pReadPoint;
	float *pPrevReadPoint;
	boolean Inside;
	boolean PrevInside;
	float Vec[3];
	boolean EdgeNotAdded;
	float frac;
	float Dist;
	float *pWritePoint;
	float *pWritePoint;
	float LineDir[3];
	float Denom;
	float d;
	float m;
	float *pWritePoint;
	float LineDir[3];
	float Denom;
	float d;
	float m;
	float *Point;
}

static int decalGetRoomFromProp(prop *pProp) {}

static void decalAddToDrawList(DecalDef *pDecal, int Room) {
	int i;
	int Group;
	int GroupStart;
	int Group;
	int GroupStart;
}

static void decalRemoveFromDrawList(DecalDef *pDecal) {}

static DecalDef* decalGetNextDecal(int Type, int Room) {
	DecalDef *pDecal;
	int Group;
	int DecalNum;
}

static void decalConfirmUsed(DecalDef *pDecal) {
	int Group;
}

static DecalID decalAddNewDecal(int Type, int TexNum, float Dir, int UStartEdge, int VStartEdge, float Scale, u32 Col, prop *pHitProp, int MatrixNum, int Room, float *Pos, float *Norm, float *pPolyVertex, u8 *pPolyVertexIndex, int PolyNumVertices, int *ReturnEdges[2], HitInfoDef *ReturnAddInst) {
	float *Pos;
	DecalDef *pDecal;
	float Size;
	float TmpVec[3];
	float UpVec[3];
	float AlongVec[3];
	float DecalPos[4][3];
	float frac;
	float frac;
	mtx_u mtx;
	int i;
}

static void decalGetBulletTexScaleCol(int BulletType, int *pTex, float *pScale, u32 *pCol) {}

static void decalNewDecalMain(int BulletType, int Room, prop *pHitProp, float *Pos, float *Norm) {
	DecalCreateDef *pDecalCreate;
	obdef *pOb;
	partdef *pParts;
	partdef *pPart;
	float TestPos[3];
	float TestDir[3];
	mtx_u Matrix;
	mtx_u InvMatrix;
	float frac;
}

void decalNewDecal(int BulletType, int Room, prop *pHitProp, float *Pos, float *Norm) {
	prop *pProp;
	float Dir[3];
	float HitPos[3];
	float HitNorm[3];
	HitInfoDef HitDone[5];
	int i;
	int DoneIndex;
	boolean Add;
	boolean Add;
	boolean Add;
	boolean Add;
	boolean Add;
}

void decalNewFootDecal(int Chr, float *Pos, float Dir, boolean Left) {
	DecalCreateDef *pDecalCreate;
	float TestDir[3];
	float TestPos[3];
	int Room;
	float Dir[3];
	float Dir[3];
}

DecalID decalNewGlassDecal(int BulletType, prop *pHitProp, int MatrixNum, float *Pos, float *Norm, glasspointdef *glassPoints, int NumClipPolyVertices) {
	int Room;
	int TexNum;
	int UStartEdge;
	int VStartEdge;
	u8 VertexIndex[10];
	DecalID Result;
	float Scale;
	u32 Col;
	float pClipPolyVertices[40];
	int e;
	float Dir;
	mtx_u Matrix;
	mtx_u Matrix1;
	mtx_u Matrix2;
}

void decalRemoveDecal(DecalID Decal) {}

void decalRemoveDecalsFromProp(prop *pProp) {
	int i;
}

void decalSetAlphaScale(DecalID Decal, float Scale) {}

static void decalAddPoly(obinst *pInst, int PartNum, int GFXType, int ChunkNum, int PolyNum, float *EdgePos, float *DecalPos, float *DecalNorm, PolysDoneDef *PolysDone, int *pPolysDoneWrite) {
	PolysDoneDef *PolysDone;
	int *pPolysDoneWrite;
	obdef *pOb;
	partdef *pParts;
	partdef *pPart;
	obbounds *pBounds;
	int k;
	boolean Test;
	float PolyNorm[3];
	float NormsDot;
	float Vector[3];
	float Dist;
}

void decalTick() {
	int i;
	DecalDef *pDecal;
	DecalCreateDef *pDecalCreate;
	int HitPart;
	int HitChunk;
	int HitPoly;
	int HitType;
	obinst *pHitInst;
	float Scale;
	u32 Col;
	PolysDoneDef PolysDone[10];
	int PolysDoneRead;
	int PolysDoneWrite;
	int TexNum;
	int UStartEdge;
	int VStartEdge;
	float Dir;
	int i;
	DecalID Decal;
	HitInfoDef AddInst[4];
	obinst *pHitInst;
	prop *pHitProp;
	int Room;
	obdef *pOb;
	partdef *pParts;
	partdef *pPart;
	gfxchunk *pChunk;
	obbounds *pHitBounds;
	gfxpointers *ptr;
	float *xyzp;
	int EdgesCrossed[8][2];
	int Vertex1;
	int Vertex2;
	float *pPoint;
	int PolyNumTest;
	AdjPoly *pAdjPoly;
}

void decalDraw(DecalDef *pDecal, float AlphaScale) {
	float ScrPos[8][4];
	int j;
	boolean XSection[3];
	boolean YSection[3];
	mtx_u FinalMatrix;
	mtx_u *pViewMtx;
	mtx_u Matrix;
	mtx_u Matrix1;
	u32 *ref;
	float q[8];
	u32 x[8];
	u32 y[8];
	float AlphaScaleSize;
	float MaxSizeX;
	float MaxSizeY;
	float Size;
	float SizeX;
	float SizeY;
	float Alpha;
	int Col;
	void *addr;
}

void decalGfx(int Room) {
	int OldZBMode;
	DecalDef *pDecal;
}

void decalGfxMoving() {
	int OldZBMode;
	DecalDef *pDecal;
}
