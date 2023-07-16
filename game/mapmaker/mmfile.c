// STATUS: NOT STARTED

#include "mmfile.h"

struct builtinmapinfo_s {
	short int name;
	u8 *file;
};

typedef builtinmapinfo_s builtinmapinfo_t;

static builtinmapinfo_t builtinmaps[10] = {
	/* [0] = */ {
		/* .name = */ 1116,
		/* .file = */ 0x445798
	},
	/* [1] = */ {
		/* .name = */ 1117,
		/* .file = */ 0x445770
	},
	/* [2] = */ {
		/* .name = */ 1118,
		/* .file = */ 0x445748
	},
	/* [3] = */ {
		/* .name = */ 1119,
		/* .file = */ 0x445720
	},
	/* [4] = */ {
		/* .name = */ 1120,
		/* .file = */ 0x4456f8
	},
	/* [5] = */ {
		/* .name = */ 1121,
		/* .file = */ 0x4456d0
	},
	/* [6] = */ {
		/* .name = */ 1122,
		/* .file = */ 0x4456a8
	},
	/* [7] = */ {
		/* .name = */ 1123,
		/* .file = */ 0x445680
	},
	/* [8] = */ {
		/* .name = */ 1124,
		/* .file = */ 0x445658
	},
	/* [9] = */ {
		/* .name = */ 1125,
		/* .file = */ 0x445630
	}
};

gamefile2_t *mapdir1 = NULL;

void MM_FileDirBuiltinMaps() {
	int i;
}

void MM_FilePreloadBuiltinMaps() {
	int i;
}

boolean MM_FileLoadBuiltinMap(int samplemapnum) {
	preloadfileinfo *pl;
}

u8* MM_FileGetChunk(u8 *buffer, int iChunkId) {
	u8 *bufpos;
	mmfilechunk *chk;
}

int MM_FileGetItemCount(u8 *buffer, int itemnum) {
	u8 *bufpos;
	int i;
	int numtiles;
	int itemcount;
	mmfilechunk *chk;
	u8 *chunkpos;
	mmfiletile *ftile;
	int j;
}

int MM_FileDirSize() {}

int MM_FileMaxSize() {}

void MM_FileDirReset() {}

void MM_FileReset() {
	int allocsize;
}

int MM_FileOffset(int blocknum) {}

void MM_FileDirLoaded(gamefile2_t *dir) {}

int MM_FileGetFreeBlock() {
	int i;
	u8 blockmap[100];
}

int MM_FileEntryNew(mapentry_t *newentry) {
	int entrynum;
}

void MM_FileEntryDelete(int entrynum) {}
