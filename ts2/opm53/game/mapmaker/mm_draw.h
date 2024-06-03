// STATUS: NOT STARTED

#ifndef GAME_MAPMAKER_MM_DRAW_H
#define GAME_MAPMAKER_MM_DRAW_H

typedef int fix_t;

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
	s8 x;
	s8 y;
	s8 z;
	u8 orientation;
} drawdoor_t;

extern drawdoor_t *drawdoors;
extern u32 patrolcolour[8];
extern int w_x;
extern int w_y;
extern int w_w;
extern int w_h;
extern fix_t m_x;
extern fix_t m_y;
extern fix_t m_x2;
extern fix_t m_y2;
extern fix_t m_w;
extern fix_t m_h;
extern fix_t scale_mtowx;
extern fix_t scale_mtowy;
extern fix_t scale_wtomx;
extern fix_t scale_wtomy;
extern u8 mapname[32];
extern u8 mapdesc[128];
extern u8 panning;
extern u8 *button_text[6];
extern int min_x;
extern int min_y;
extern int max_x;
extern int max_y;
extern int min_w;
extern int min_h;
extern int max_w;
extern int max_h;

void MM_DrawRect(fix_t mx, fix_t my, fix_t mx2, fix_t my2, u32 colour);
void MM_DrawLine(fix_t mx, fix_t my, fix_t mx2, fix_t my2, u32 colour);
void MM_CenterMap();
void MM_InitView();
void MM_PanWindow(fix_t x, fix_t y);
u32 MM_WYSIWYGTileColour(int lighttype, int lightphase, u32 col);
void MM_DrawTile(fix_t mx, fix_t my, tiledef *tile, tiledrmd_t drawmode, object_t *mapobj);
void MM_DrawGrid();
void MM_DrawButtonHelp(int x, int y);
void MM_DrawLasso();
void mmDraw2DView();
void MM_DrawLevelBox();
void MM_DrawPopup(u8 *text, rect_t *r, int bgcol);
void MM_DrawMemFree(int x1, int y1);
void mapmakerGfx();
fix_t FMul(fix_t a, fix_t b);
fix_t FDiv(fix_t a, fix_t b);

#endif // GAME_MAPMAKER_MM_DRAW_H
