// STATUS: NOT STARTED

#include "window.h"

int screen_left = 0;
int screen_right = 0;
int screen_midx = 0;
int screen_width = 0;
int screen_halfwidth = 0;
int screen_top = 0;
int screen_bottom = 0;
int screen_midy = 0;
int screen_height = 0;
int screen_halfheight = 0;

window_t defaultwindow = {
	/* .left = */ 0,
	/* .right = */ 0,
	/* .midx = */ 0,
	/* .width = */ 0,
	/* .halfwidth = */ 0,
	/* .top = */ 0,
	/* .bottom = */ 0,
	/* .midy = */ 0,
	/* .height = */ 0,
	/* .halfheight = */ 0,
	/* .scalex = */ 0.f,
	/* .scaley = */ 0.f,
	/* .scaleshiftx = */ 0,
	/* .scaleshifty = */ 0,
	/* .zbufferrange = */ 0.f,
	/* .zbufferoffset = */ 0.f,
	/* .zbufferbias = */ 0.f
};

window_s *currentwindow = NULL;
static window_t windowsave;

void windowMake() {}

void windowRestart() {}

void windowReset() {}

void windowEnd() {}

void windowSetCurrent(window_t *window) {}

void windowSet(int x1, int y1, int x2, int y2) {}

void windowSetEx(window_t *window, int x1, int y1, int x2, int y2) {}

void windowRecalcEx(window_t *window) {}

void windowSetZBEx(window_t *window, float zbufferoffset, float zbufferrange, float zbias) {}

void windowSetZB(float zbufferoffset, float zbufferrange, float zbias) {}

void windowSave() {}

void windowSwitch() {
	window_t tmp;
}

void windowGfx() {}

void windowGfxEx(window_t *window) {
	u32 *ref;
	void *addr;
}
