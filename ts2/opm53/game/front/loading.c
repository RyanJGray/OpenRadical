// STATUS: NOT STARTED

#include "loading.h"

typedef struct {
	short int TimeZone;
	u_char Aspect;
	u_char DateNotation;
	u_char Language;
	u_char Spdif;
	u_char SummerTime;
	u_char TimeNotation;
} sceScfT10kConfig;

typedef enum {
	STATE_AUTOLANGUAGE = 0,
	STATE_LANGUAGE = 1,
	STATE_LOADINGSCREEN = 2
};

static int state;
static int count;

void loadingReset() {}

void loadingPreload() {}

void loadingTick() {
	resetgameparms p;
}

void loadingGfx() {
	int texture;
	int ulx;
	int uly;
	int w;
	int h;
	u8 text[2000];
	int texture;
	int texwidth;
	int texheight;
	char *s;
	int sx;
	int sy;
	int y;
}
