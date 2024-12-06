//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FRONT_ZOOMBOX_H
#define GAME_FRONT_ZOOMBOX_H

#include "common.h"
#include "mapmaker/mm_draw.h"

typedef struct zoomboxinfo_s {
  rect_t s;
  u32 bgcol;
  int left;
  int top;
  int width;
  int height;
  int frame;
} zoomboxinfo_t;
extern zoomboxinfo_t zoomboxes[4];

void zoomboxInit(int playernum, rect_t *sizes, u32 bgcol);
void zoomboxSet(int playernum, rect_t *sizes, u32 bgcol);
void zoomboxTick(int playernum);
void zoomboxGfx(int playernum);

#endif // GAME_FRONT_ZOOMBOX_H
