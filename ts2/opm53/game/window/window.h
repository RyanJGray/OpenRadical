//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_WINDOW_WINDOW_H
#define GAME_WINDOW_WINDOW_H

typedef struct window_s {
	int left;
	int right;
	int midx;
	int width;
	int halfwidth;
	int top;
	int bottom;
	int midy;
	int height;
	int halfheight;
	float scalex;
	float scaley;
	int scaleshiftx;
	int scaleshifty;
	float zbufferrange;
	float zbufferoffset;
	float zbufferbias;
} window_t;

extern int screen_left;
extern int screen_right;
extern int screen_midx;
extern int screen_width;
extern int screen_halfwidth;
extern int screen_top;
extern int screen_bottom;
extern int screen_midy;
extern int screen_height;
extern int screen_halfheight;
extern window_t defaultwindow;
extern struct window_s *currentwindow;

void windowMake();
void windowRestart();
void windowReset();
void windowEnd();
void windowSetCurrent(window_t *window);
void windowSet(int x1, int y1, int x2, int y2);
void windowSetEx(window_t *window, int x1, int y1, int x2, int y2);
void windowRecalcEx(window_t *window);
void windowSetZBEx(window_t *window, float zbufferoffset, float zbufferrange, float zbias);
void windowSetZB(float zbufferoffset, float zbufferrange, float zbias);
void windowSave();
void windowSwitch();
void windowGfx();
void windowGfxEx(window_t *window);

#endif // GAME_WINDOW_WINDOW_H
