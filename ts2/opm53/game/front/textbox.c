// STATUS: NOT STARTED

#include "textbox.h"

typedef enum {
	MOR = 252,
	SPC = 253,
	BAK = 254,
	END = 255
};

static int specialcharcol[4] = {
	/* [0] = */ 0,
	/* [1] = */ 3,
	/* [2] = */ 7,
	/* [3] = */ 9
};

static int specialcharw[4] = {
	/* [0] = */ 3,
	/* [1] = */ 4,
	/* [2] = */ 2,
	/* [3] = */ 2
};

static u8 chartab1[0] = {
};

static u8 chartab2[0] = {
};

textbox_t *textbox = NULL;
static textbox_t tbinfo[4];

void stringeditDraw(int playernum, boolean toppage) {
	int i;
	int fx;
	int fy;
	int fw;
	int x1;
	int y1;
	int wx;
	int wy;
	int font;
	int col;
	u8 s[2];
	u8 *t;
	int xx;
	int yy;
	int sc;
	int font;
	int tw;
	int editw;
	int edith;
	int tw;
	int th;
}

void stringeditTick(int playernum) {
	int newbut;
	u8 *rowchars;
	u8 c;
	u8 *rowchars;
	u8 c;
	u8 s[2];
	int c;
	int font;
	boolean accept;
	u8 *curline;
	int numlines;
	int i;
	u8 *word;
	int n;
}

void stringeditStart(int playernum, u8 *pstring, int maxlen, int numlines, int editwidth, int alignleft, int aligntop) {}

void stringeditSet(int playernum) {}
