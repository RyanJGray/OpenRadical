// STATUS: NOT STARTED

#include "bg.h"

struct portalcalcdata_s {
	float bb[2][3];
	int scrmin[2];
	int scrmax[2];
	int backfacing;
	int culled;
};

typedef portalcalcdata_s portalcalcdata;

struct tileloadinfo_s {
	room *rooms;
	portal **portals;
	texinfo *textures;
	volume *volumes;
	int numrooms;
	int numportals;
	int numtextures;
	int numvolumes;
	int roomstart;
	int portalstart;
	int texturestart;
	int lighttype;
	int lightphase;
	u16 seals;
	u32 col;
};

typedef tileloadinfo_s tileloadinfo;

struct tmppointdata_s {
	float proj[4];
	int out;
};

typedef tmppointdata_s tmppointdata;

struct tmppointarray_s {
	tmppointdata *points[20];
	int numpoints;
};

typedef tmppointarray_s tmppointarray;
static portalcalcdata *portaldata = NULL;
roombbinfo *roombb = NULL;
static int bgGetRoomsFirstTick = 0;
static texinfo *leveltextures = NULL;
static room *levelrooms = NULL;
static portal **levelportals = NULL;
static volume *levelvolumes = NULL;
int bgNumRooms = 0;
int bgNumPortals = 0;
int bgNumVolumes = 0;
prop **roomprops = NULL;
int *roomVisibilityAllViews = NULL;
static int *roomstack;
static u16 roomseals[200];
static int numeachtile[30];
static int port_numrooms[30];
static u8 port_levelrooms[30][200];
static float leftfrac;
static float rightfrac;
static float topfrac;
static float bottomfrac;
static tmppointdata *tpd;
static int freepointindex;

int bgGetLevelTextureID(int leveltextureindex) {}

void bgLoad(u8 *filename) {
	u32 *bgfile;
	int i;
	u32 *vpos;
	int w;
}

void bgCalcRoomVisibility() {
	int room;
	int i;
	boolean visibleToAny;
	ViewDef *pView;
}

static void bgVolumeTransform(volume *v, leveltile *lt, mtx_u *transmtx) {}

static void bgWeatherTransform(weatherdef *weather, mtx_u *transmtx) {}

static void bgRoombbTransform(float *bb[3], leveltile *lt, mtx_u *transmtx) {
	float oldbb[2][3];
}

static void bgPortalTransform(portal *p, mtx_u *transmtx) {
	int i;
}

static void bgObBoundsTransform(obdef *ob, leveltile *lt) {
	partdef *parts;
	int PartNum;
	partdef *part;
	gfxchunk *chunk;
	obbounds *bounds;
	gfxpointers *ptr;
	int gfxtype;
	float *xyzp;
	int i;
	float oldmins[3];
	float oldmaxs[3];
	ColPoly *pPoly;
	float *v;
	float tmp;
}

void bgTileLoad(tileloadinfo *tile, leveltile *lt, int tileset) {
	u32 *tilefile;
	mtx_u transmtx;
	preloadinfo *pi_tile;
	preloadinfo *pi_pads;
	int i;
	int filesize;
	u32 *vpos;
	int i;
	int w;
}

void bgTileSetRoomNums(tileloadinfo *tile) {
	int i;
	portal *p;
	volume *v;
	room *r;
}

void bgTileSetPortalNums(tileloadinfo *tile) {
	int i;
	int j;
	room *r;
	int *roomportalnums;
	int numportals;
}

void bgTileSetTextureNums(tileloadinfo *tile) {
	int i;
	int g;
	room *r;
	partdef *part;
}

static void bgTileLoadLevel() {
	u8 *bufpos;
	tileloadinfo *tiles;
	int i;
	int j;
	int k;
	int r;
	int done;
	int bgNumTextures;
	int numtiles;
	int tileset;
	mmfilechunk *chk;
	u8 *chunkpos;
	leveltile lt;
	int numitems;
	int trans[3];
	tiledef *pTileDef;
	tileloadinfo *tile;
	portal *p1;
	portal *p2;
	float dot;
	float midpoint1[3];
	float min1[3];
	float max1[3];
	float midpoint2[3];
	float min2[3];
	float max2[3];
	float middist[3];
	float mindist[3];
	float maxdist[3];
	float middistsq;
	float mindistsq;
	float maxdistsq;
	int p1room;
	int p2room;
	int *roomportalnums;
	int numportals;
	int p;
	portal *p;
	int *roomportalnums;
	int numportals;
	int p;
	roomlightinit *rli;
}

static boolean bgIsFloorWithinWeatherBounds(int room, floordef *floor) {
	weatherdef **weather;
	int w;
	weatherdef *wdef;
	int p;
	float *pos;
}

static void bgRoomInitBB() {
	int i;
	int j;
	int k;
	room *r;
	roombbinfo *rbb;
	floordef **floors;
	walldef **walls;
	partdef *parts;
	float *pt;
	walldef *w;
	partdef *part;
	int v;
	int numvtx;
	int gfxtype;
	float *sxyz;
	float x;
	float y;
	float z;
	float halfroomsize[3];
	float floorvolume;
}

static void bgPortalInitBB() {
	int i;
	int j;
	portal *p;
	portalcalcdata *pd;
}

void bgPreload() {
	u8 *bufpos;
	int i;
	int numtiles;
	int tileset;
	mmfilechunk *chk;
	u8 *chunkpos;
	int numitems;
	u8 *filename;
	static u8 bgfilename[64];
}

void bgPreloadTextures() {
	u8 bgfilename[64];
	u32 *bgfile;
	int i;
}

static void bgCreateRoomProps(boolean isTileSet) {
	int i;
}

void bgRestart() {}

void bgReset() {
	u8 filename[64];
}

void bgEnd() {}

void bgGetPropRoomClipRec(prop *p) {
	int i;
	roomcalcdata *pData;
}

void bgGfx() {
	int i;
	int l;
	int r;
	int oldzbmode;
	char roomstring[1000];
	int done_cstick;
	int l;
	int nr;
	int num;
}

void bgGetRoomsTick() {
	int i;
	int j;
	int l;
	int r;
	int cp;
	int neighbours[20];
	int numNeighbours;
	int inlist;
	ViewDef *pView;
	int l;
	int nr;
	int num;
}

int bgRoomGetLevel(int room) {}

int bgRoomBBIntersectionNumRooms(float *bb[3]) {
	int numrooms;
	int e;
	room *r;
}

int bgPosGetRooms(float *pos, int *rooms, int maxrooms) {
	int numrooms;
	int i;
	roombbinfo *rbb;
}

void bgRoomBBIntersectionArray(int *therooms, float *bb[3]) {
	int i;
	room *r;
}

int bgRoomBBIntersection(float *bb[3], int *rooms, int maxrooms) {
	int i;
	int numrooms;
	int done;
	room *r;
}

int bgFloorBBIntersection(float *bb[3], int *rooms, int maxrooms) {
	int i;
	int numrooms;
	int done;
	roombbinfo *rbb;
}

int bgFloorBBIntersectionXZ(float *bb[3], int *rooms, int maxrooms) {
	int i;
	int numrooms;
	int done;
	roombbinfo *rbb;
}

int bgWallBBIntersection(float *bb[3], int *rooms, int maxrooms) {
	int i;
	int numrooms;
	int done;
	roombbinfo *rbb;
}

int bgPortalBBIntersection(float *bb[3], int *rooms, int maxrooms) {
	int i;
	int numrooms;
	portalcalcdata *pd;
	int r1;
	int r2;
	int r;
	int already1;
	int already2;
}

int bgGetNeighbours(int room, int *rooms, int maxrooms) {
	int *roomportalnums;
	int i;
	int j;
	int numportals;
	int numrooms;
	portal *p;
	int otherroom;
	int already;
}

partdef* bgGetPart(int room) {}

int bgGetNumFloors(int room) {}

floordef** bgGetFloors(int room) {}

int bgGetNumWalls(int room) {}

walldef** bgGetWalls(int room) {}

int bgGetNumGlass(int room) {}

glassdef** bgGetGlass(int room) {}

int bgGetNumSpecial(int room) {}

specialdef** bgGetSpecial(int room) {}

weatherdef** bgGetWeather(int room) {}

volume* bgGetVolume(int num) {
	int i;
}

static void bgPortalCalcInit() {
	int i;
}

void bgPortalDisable(int num) {
	portal *p;
}

void bgPortalEnable(int num) {
	portal *p;
}

static int bgGetPortalFromRooms(int r1, int r2) {
	int *roomportalnums;
	int i;
	int numportals;
	portal *p;
	int otherroom;
}

void bgPortalDisableFromRooms(int r1, int r2) {}

void bgPortalEnableFromRooms(int r1, int r2) {}

static int bgPortalBackFaceTest(int room, float *campos, portal *p) {
	float delta[3];
	float dot;
}

static void bgPortalCalcBackFace(int room) {
	int *roomportalnums;
	int numportals;
	int i;
	int pnum;
	portal *p;
	portalcalcdata *pd;
	int otherroom;
}

static void bgPortalCalcRoomDepth(int room, int level) {
	int *roomportalnums;
	int numportals;
	int i;
	int pnum;
	portal *p;
	portalcalcdata *pd;
	int otherroom;
}

static void bgRoomCalcClip(int room) {
	int *roomportalnums;
	int numportals;
	int scrmin[2];
	int scrmax[2];
	int i;
	int pnum;
	portal *p;
	portalcalcdata *pd;
	int otherroom;
	int pnum;
	portal *p;
	portalcalcdata *pd;
	int otherroom;
}

static void bgPortalCalcOutCode(tmppointdata *point) {}

static void bgPortalPlaneClip(tmppointarray *pa1, tmppointarray *pa2, float clipsign, float clipfrac, int clipaxis, int clipplane) {
	int j;
	tmppointdata *point1;
	tmppointdata *point2;
	tmppointdata *newpoint;
	float bc1;
	float bc2;
	float f;
}

static int bgPortalCalcPos(int room, mtx_u *mpmatrix) {
	int *roomportalnums;
	int numportals;
	int inscrmin[2];
	int inscrmax[2];
	int retval;
	int i;
	int j;
	int pnum;
	portal *p;
	portalcalcdata *pd;
	int otherroom;
	tmppointarray pointarray1;
	tmppointarray pointarray2;
	int scrpos[20][2];
	int outall;
	tmppointdata *point;
	tmppointdata *point;
}

void bgPortalTick() {
	mtx_u mpmatrix;
	int room;
	int i;
	int l;
	int r;
}

void bgPortalGfx() {}

static void bgPortalGfxRoom(int room) {}

void bgPortalRectGfx() {}

static void bgPortalRectGfxRoom(int room, int all, u32 col) {}

void bgVolumeGfx() {}

void bgFloorGfx() {}

static void bgFloorGfxRoom(int room) {}

void bgWallGfx() {}

static void bgWallGfxRoom(int room) {}

void bgBBGfx() {}

void bgWeatherBBGfx() {
	weatherdef **weather;
	int oldzbmode;
	float v1[3];
	float v2[3];
	float v3[3];
	float v4[3];
	float v5[3];
	float v6[3];
	float v7[3];
	float v8[3];
	mtx_u *pView;
	int w;
	weatherdef *wdef;
}

int bgPortalCrossed(float *startpos, float *dir, int startroom, int notroom, int infinite, float *hitpos, float *newdir) {
	int *roomportalnums;
	int numportals;
	int i;
	int j;
	int besthitroom;
	float besthitpos[3];
	float besthitdistsq;
	int pnum;
	portal *p;
	int otherroom;
	float d;
	float m;
	float denom;
	float *p1;
	float *p2;
	float pos[3];
	float *abc;
	int outside;
	int x;
	int y;
	float tmphitdistsq;
}

int bgLineGetEndRoom(float *Pos, int PosRoom, float *Dir, int Infinite) {
	int thisroom;
	int lastroom;
	float tmppos[3];
	float tmpdir[3];
}

prop* bgLineTest(int startroom, float *startpos, float *dir, int infinite, float *hitpos, float *hitnorm, int *newroom, int excludeflag, int CollisionTypeFlag, glassResults *glassRes) {
	float besthitpos[3];
	float besthitnorm[3];
	float maxhitdistsq;
	float besthitdistsq;
	prop *besthitprop;
	int thisroom;
	int lastroom;
	int nextroom;
	float tmppos[3];
	float tmpdir[3];
	float tmphitpos[3];
	float tmphitnorm[3];
	float tmphitdistsq;
	float delta[3];
	prop *hitprop;
	float frac;
}

int bgAmountGlassLeft() {
	int i;
	int AmountLeft;
	int g;
	glassdef *pGlass;
}

int bgAllGlassBroken() {}

void bgTick() {}

float bgCalcFloorVolume(floordef *floor) {
	float volume;
	float dir1[3];
	float dir2[3];
}
