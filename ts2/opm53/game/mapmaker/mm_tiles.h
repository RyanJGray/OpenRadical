//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_MAPMAKER_MM_TILES_H
#define GAME_MAPMAKER_MM_TILES_H

#include "common.h"

enum {
  TILEROT_0 = 0,
  TILEROT_90 = 1,
  TILEROT_180 = 2,
  TILEROT_270 = 3,
  TILEROT_NUM = 4
};

typedef enum {
  TILE_DRMD_FOCUSED = 1,
  TILE_DRMD_INSERTOK = 2,
  TILE_DRMD_REDERROR = 3,
  TILE_DRMD_MARKED = 4,
  TILE_DRMD_FOCUSEDMARKED = 5,
  TILE_DRMD_GHOSTVIEW = 6,
  TILE_DRMD_OUTLINETILE = 7
} tiledrmd_t;

typedef struct {
  u8 dir;
  u8 x;
  u8 y;
  u8 z;
  u8 length;
} plugdef;

typedef struct tiledef_s {
  int width;
  int height;
  int slices;
  u8 *cells[4];
  u16 *ipads[4];
  int cost;
  int numplugs;
  plugdef plugs[16];
  struct tiledef_s *next;
} tiledef;

extern tiledef *tiles[30];
extern int numtiles;

void MM_ResetTiles();
void MM_ClearTiles();
void MM_LoadTiles();

#endif // GAME_MAPMAKER_MM_TILES_H
