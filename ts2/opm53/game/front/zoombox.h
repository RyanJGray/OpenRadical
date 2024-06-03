// STATUS: NOT STARTED

#ifndef GAME_FRONT_ZOOMBOX_H
#define GAME_FRONT_ZOOMBOX_H

struct rect_s {
	int x1;
	int y1;
	int x2;
	int y2;
};

typedef rect_s rect_t;

struct zoomboxinfo_s {
	rect_t s;
	u32 bgcol;
	int left;
	int top;
	int width;
	int height;
	int frame;
};

typedef zoomboxinfo_s zoomboxinfo_t;
extern zoomboxinfo_t zoomboxes[4];

void zoomboxInit(int playernum, rect_t *sizes, u32 bgcol);
void zoomboxSet(int playernum, rect_t *sizes, u32 bgcol);
void zoomboxTick(int playernum);
void zoomboxGfx(int playernum);

#endif // GAME_FRONT_ZOOMBOX_H
