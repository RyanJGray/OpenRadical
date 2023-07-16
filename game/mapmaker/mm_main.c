// STATUS: NOT STARTED

#include "mm_main.h"

editmodeinfo_t editmodeinfo[4] = {
	/* [0] = */ {
		/* .desc = */ 0x3d9,
		/* .icon = */ 37
	},
	/* [1] = */ {
		/* .desc = */ 0x3da,
		/* .icon = */ 38
	},
	/* [2] = */ {
		/* .desc = */ 0x3db,
		/* .icon = */ 39
	},
	/* [3] = */ {
		/* .desc = */ 0x45c3f8,
		/* .icon = */ 54
	}
};

u8 *mmtempbuffer = NULL;
int numpatrols = 0;

patrolroute_t patrols[8] = {
	/* [0] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [1] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [2] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [3] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [4] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [5] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [6] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	},
	/* [7] = */ {
		/* .length = */ 0,
		/* .mode = */ 0,
		/* .nodes = */ {
			/* [0] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [1] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [2] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [3] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [4] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [5] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [6] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			},
			/* [7] = */ {
				/* .pObj = */ NULL,
				/* .padextref = */ 0
			}
		}
	}
};

s16 iHoldPatrol = 0;
s16 iHoldPatrolPt = 0;
int editmode = 0;
u32 editflags = 0;
int editlevel = 0;
int otherlevel = 0;
int warnlevel = 0;
int mapcost = 0;
int flyingobjcost = 0;
object_t *highlightobj = NULL;
s16 highlightobjpad = 0;
item_t *highlightobjitem = NULL;
int iHoldItem = 0;
int iHoldItemAngle = 0;
object_t *highlightplugtile = NULL;
int highlightplugnum = 0;
object_t *usedobj = NULL;
object_t *mmcellobject = NULL;
fix_t lasso_x = 0;
fix_t lasso_y = 0;
int lassocount = 0;
int highlightobjpatrol = 0;
fix_t savemouse_x = 0;
fix_t savemouse_y = 0;

object_t* MM_CheckObject(fix_t mapcol, fix_t maprow) {
	fix_t obw;
	fix_t obh;
	object_t *ob;
	tiledef *ptile;
	int col;
	int row;
}

u8 MM_CellBits(fix_t mx, fix_t my) {
	int x;
	int y;
	int z;
	object_t *ob;
	tiledef *ptile;
	fix_t cx;
	fix_t cy;
	fix_t x1;
	fix_t y1;
	fix_t w;
	fix_t h;
	tiledef *ptile;
}

u16 MM_CellIPad(fix_t mx, fix_t my) {
	int x;
	int y;
	int z;
	object_t *ob;
	tiledef *ptile;
}

u16 MM_PadExtRefUnderCursor() {}

int MM_PadIndexUnderCursor() {
	u16 padextref;
	padfile *pPads;
	int iPadNum;
}

item_t* MM_ItemUnderCursor() {}

static int MM_DoorwayUnderCursor(object_t *pObj) {
	fix_t mx;
	fix_t my;
	int iPlug;
	tiledef *pTile;
	fix_t x1;
	fix_t y1;
	fix_t w;
	fix_t h;
}

int MM_FindPlug(object_t *ob, int pluginx, int pluginy, int pluginz, int plugindir, int pluginlen) {
	int i;
	int ox;
	int oy;
	int oz;
	int numplugs;
	plugdef *p;
	fix_t cx;
	fix_t cy;
}

void MM_FindFacingPlug(object_t *pObjIn, int iPlugIn, object_t **pObjOut, int *iPlugOut) {
	tiledef *pTileIn;
	plugdef *pPlugIn;
	fix_t px;
	fix_t py;
	int save;
}

boolean MM_CheckTilesConnect(object_t *pOb1, object_t *pOb2) {
	tiledef *pTile;
	int iPlug;
	object_t *pFacingObj;
}

static int MM_FindPatrolPoint(object_t *pObj, int iPad) {
	int iPatrol;
	int iPatrolPoint;
	routenode_t *rn;
}

void MM_ClearTilePatrolPoints(object_t *pObj) {
	int iPatrol;
	int iPatrolPt;
	patrolroute_t *pPatrol;
	int i;
}

static boolean MM_CheckPlacement() {
	int saveeditlevel;
	int floor;
	int numcells;
	int x;
	int y;
	fix_t px;
	fix_t py;
	fix_t mx;
	fix_t my;
	tiledef *blk;
	object_t *list;
	u8 *cells;
}

void MM_FindLassoed() {
	fix_t lx1;
	fix_t ly1;
	fix_t lx2;
	fix_t ly2;
	fix_t lw;
	fix_t lh;
	object_t *ob;
	tiledef *ptile;
	fix_t w;
	fix_t h;
	int x;
	int y;
	int col1;
	int row1;
	int col2;
	int row2;
}

static void MM_ClearLassoed() {
	object_t *ob;
}

void MM_PlaceItemOnPad(object_t *pObj, int iPadExtRef, int itemnum, itemangle_t itemangle) {
	item_t *it;
	int groupcounts[20];
	object_t *oblist;
	int i;
	int replaced;
}

void MM_CenterFlyingObj() {
	object_t *obj;
	fix_t minx;
	fix_t miny;
	fix_t maxx;
	fix_t maxy;
	fix_t midx;
	fix_t midy;
	tiledef *blk;
}

void MM_ClearDoors(object_t *ob) {
	tiledef *pTile;
	int i;
	object_t *pFacingObj;
	int iFacingPlug;
}

static void MM_DeleteAllMarked() {
	object_t *ob;
	object_t *nextob;
}

static void MM_DoCopy(boolean cut) {
	object_t *ob;
	object_t *nextob;
	object_t *list;
	object_t *newob;
	fix_t x;
	fix_t y;
}

static boolean MM_DoPaste() {
	fix_t mx;
	fix_t my;
	object_t *ob;
	object_t *list;
}

void MM_SetTileLight(object_t *ob, u8 type, u8 phase, u32 colour) {}

static void MM_ResetPatrols() {}

void MM_ClearMap() {}

static void MM_ClampView() {
	fix_t cx;
	fix_t cy;
}

static void MM_MapViewHelp() {
	fix_t mx;
	fix_t my;
	int cursor;
	object_t *obj;
}

void MM_ClampMouse(fix_t *margins) {}

static void MM_UpdateMapCost() {
	object_t *ob;
}

static int confirmPasteTileNoItems() {
	object_t *list;
}

void mapmakerTick() {
	int buttons;
	int newbuttons;
	float analog_x;
	float analog_y;
	fix_t pan_x;
	fix_t pan_y;
	fix_t zoom;
	fix_t margins[4];
	boolean button_x_depressed;
	object_t *pFacingObj;
	int iFacingPlug;
	int groupcounts[20];
	object_t *oblist;
	int i;
	object_t *ob;
	item_t *it;
	fix_t x;
	fix_t y;
	object_t *pFacingObj;
	int iFacingPlug;
	int iPadExtRef;
	padfile *pPads;
	int numpads;
	int i;
	int j;
	float a;
	float r;
	object_t *pFacingObj;
	int iFacingPlug;
	object_t *pFacingObj;
	int iFacingPlug;
	u32 colour;
	object_t *ob;
	object_t *ob;
	object_t *ob;
	patrolroute_t *pPatrol;
	int i;
	int iPatrol;
	int iPatrolPt;
	patrolroute_t *pPatrol;
	int i;
	fix_t minscale;
	fix_t maxscale;
	fix_t aspect;
	fix_t cmx;
	fix_t cmy;
	float roty;
}

u32 MM_WriteChunk(u8 *buffer, u32 bufpos, int chkid, int size) {
	mmfilechunk *chk;
}

static u16 MM_MakeSeals(object_t *ob) {
	int i;
	u16 mask;
	u16 plugmask;
	tiledef *tile;
	fix_t mx;
	fix_t my;
	fix_t px;
	fix_t py;
}

int MM_CheckGameModes(int showmessage, u8 **returnmsg) {
	int setupflags;
	object_t *ob;
	item_t *item;
	int numbags;
	int numkobags;
	int numnpcs;
	int numteamstarts[4];
	int numteamdrops[4];
	int validteams;
	int i;
}

int MM_CalcFileSize() {
	int size;
}

void MM_GetTranslation(object_t *obj, int *trans) {}

static int gettileref(object_t *tileob) {
	int index;
	object_t *ob;
}

int MM_SaveMapFile(u8 *buffer, boolean quicktestsave) {
	u32 bufpos;
	object_t *ob;
	int numtiles;
	int numdoors;
	int savestate;
	int setupflags;
	mmfilechunk *chunk_doors;
	mmfileinfo *mm;
	int i;
	plugdef *pPlug;
	int iPlug;
	mmfiledoor *door;
	object_t *pFacingObj;
	int iFacingPlug;
	item_t *item;
	int iPatrol;
	patrolroute_t *pPatrol;
	int chunksize;
	mmfilepatrol *mmp;
	int i;
	routenode_t *pn;
	padfile *pPads;
	pad *tmppad;
	int numpads;
	int j;
	int i;
}

int MM_LoadMapFile(u8 *buffer, boolean undoload) {
	mmfiledoor *doors;
	int numdoors;
	object_t **loadedtiles;
	int i;
	int numtiles;
	u8 *bufpos;
	mmfilechunk *chk;
	int i;
	u8 *chunkpos;
	mmfiletile *ftile;
	object_t *ob;
	int j;
	routenode_t *patrolpt;
	int iPatrolPt;
	padfile *pPads;
	object_t *ob;
}

boolean MM_BackupMap() {
	int size;
}

void MM_UndoMap() {}

void mapmakerMake() {}

void mapmakerPreload() {}

void mapmakerReset() {
	int needsave;
}

void mapmakerEnd() {}
