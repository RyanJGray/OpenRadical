// STATUS: NOT STARTED

#include "mm_tiles.h"

tiledef *tiles[30] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL,
	/* [20] = */ NULL,
	/* [21] = */ NULL,
	/* [22] = */ NULL,
	/* [23] = */ NULL,
	/* [24] = */ NULL,
	/* [25] = */ NULL,
	/* [26] = */ NULL,
	/* [27] = */ NULL,
	/* [28] = */ NULL,
	/* [29] = */ NULL
};

int numtiles = 0;
static u8 *tilemem;
static int tilemem_pos;

static int MM_TileBufferSize(int tilenum) {
	tiledef *t;
	int size;
}

void MM_ResetTiles() {
	int size;
	int i;
}

void MM_ClearTiles() {}

static tiledef* MM_AllocTile(int tilenum) {
	int i;
	tiledef *ptrtile;
	u8 *mem;
}

static void MM_MakeTileRotations(int tilenum) {
	int i;
	int r;
	int slice;
	tiledef *blk;
	tiledef *rot;
	int x;
	int y;
	u8 *dest;
	u8 *src;
	int x;
	int y;
	u16 *dest;
	u16 *src;
}

void MM_LoadTiles() {
	int i;
	tiledef *tdef;
}
