// STATUS: NOT STARTED

#ifndef GAME_MAPMAKER_MM_TILES_H
#define GAME_MAPMAKER_MM_TILES_H

struct tiledef_s {
	int width;
	int height;
	int slices;
	u8 *cells[4];
	u16 *ipads[4];
	int cost;
	int numplugs;
	plugdef plugs[16];
	tiledef_s *next;
};

typedef tiledef_s tiledef;
extern tiledef *tiles[30];
extern int numtiles;

void MM_ResetTiles();
void MM_ClearTiles();
void MM_LoadTiles();

#endif // GAME_MAPMAKER_MM_TILES_H
