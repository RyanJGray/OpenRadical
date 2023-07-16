// STATUS: NOT STARTED

#ifndef GAME_MAPMAKER_MMFILE_H
#define GAME_MAPMAKER_MMFILE_H

typedef struct {
	char name[32];
	u32 datemod;
	u16 block;
	u16 size;
} mapentry_t;

struct gamefile2_s {
	u32 crc;
	u32 magic;
	int numentries;
	mapentry_t mapentries[0];
};

typedef gamefile2_s gamefile2_t;
extern gamefile2_t *mapdir1;

void MM_FileDirBuiltinMaps();
void MM_FilePreloadBuiltinMaps();
boolean MM_FileLoadBuiltinMap(int samplemapnum);
u8* MM_FileGetChunk(u8 *buffer, int iChunkId);
int MM_FileGetItemCount(u8 *buffer, int itemnum);
int MM_FileDirSize();
int MM_FileMaxSize();
void MM_FileDirReset();
void MM_FileReset();
int MM_FileOffset(int blocknum);
void MM_FileDirLoaded(gamefile2_t *dir);
int MM_FileGetFreeBlock();
int MM_FileEntryNew(mapentry_t *newentry);
void MM_FileEntryDelete(int entrynum);

#endif // GAME_MAPMAKER_MMFILE_H
