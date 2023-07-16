// STATUS: NOT STARTED

#include "sky.h"

struct vertice_s {
	float x;
	float y;
	float z;
	float u;
	float v;
	u32 col;
};

typedef vertice_s vertice;

struct skymesh_s {
	vertice vertices[9][9];
	int uResolution;
	int vResolution;
	float pTL[2];
	float pTR[2];
	float pBL[2];
	float radius;
	float height;
	float heightadjust;
	int texturenum;
	u32 col;
	u32 outercol;
};

typedef skymesh_s skymesh;
static int skytexnum = -1;
static float cloudSpeedU = 0.f;
static float cloudSpeedV = 0.f;
static float cloudScrollU = 0.f;
static float cloudScrollV = 0.f;
static float cloudsRot = 0.f;
boolean cloudsEnabled = 0;
static skymesh cloudmeshes[3][3];
static float skytime;
static u32 cloudcol;
static u32 outercloudcol;

void skySetMeshVertices(skymesh *mesh) {
	float uVector[2];
	float vVector[2];
	float uInterval[2];
	float vInterval[2];
	float uCurrent[2];
	float vCurrent[2];
	int x;
	int y;
	vertice *v;
	float pos2d[2];
	float horizontalScaled;
	float degree;
	float horizontalInverse;
	float colScale;
	float colScaleInv;
	float c1;
	float c2;
	float c3;
	float c4;
}

void skyMeshTick(skymesh *mesh, float translateu, float translatev, float periodx, float periodz, float amplitudex, float amplitudez, float speedx, float speedz) {
	float uMultiplier[2];
	float vMultiplier[2];
	float uIntervalTex[2];
	float vIntervalTex[2];
	int x;
	int y;
	float uVector[2];
	float vVector[2];
	float uInterval[2];
	float vInterval[2];
	vertice *v;
	float uVal;
	float vVal;
}

void skyMeshGfx(mtx_u *finalmtx, skymesh *mesh) {
	int x;
	int y;
	u32 *ref;
	vertice *v1;
	vertice *v2;
	vertice *v3;
	vertice *v4;
	int num;
	emTexture *pTex;
	void *addr;
	void *addr;
}

void skyCloudsMeshesReset() {
	float radius;
	float height;
	float heightadjust;
	int xGrid;
	int yGrid;
	float sectionSize;
	skymesh *mesh;
}

void skyCloudsMeshesTick() {
	float secpassed;
	int yGrid;
	int xGrid;
}

void skyCloudsMeshesGfx() {
	mtx_u *finalmtx;
	mtx_u movemtx;
	mtx_u transmtx;
	mtx_u rotmtx;
	int yGrid;
	int xGrid;
	float skypos[3];
}

void skyPreload() {}

void skyReset() {}

void skyResetAfter() {}

void skyRestart() {}

void skyEnd() {}

void skyTick() {
	float secpassed;
}

void skyGfx() {
	int blend;
	int zbstate;
}
