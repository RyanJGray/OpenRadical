// STATUS: NOT STARTED

#include "gui.h"

typedef enum {
	MAPMAKER = 1,
	FRONTEND = 2,
	INGAME = 4,
	DEVELOP = 8
};

static int roundedboxTexNum = -1;

static u8 iconloadinfo[63] = {
	/* [0] = */ 1,
	/* [1] = */ 1,
	/* [2] = */ 1,
	/* [3] = */ 1,
	/* [4] = */ 1,
	/* [5] = */ 1,
	/* [6] = */ 1,
	/* [7] = */ 1,
	/* [8] = */ 1,
	/* [9] = */ 9,
	/* [10] = */ 1,
	/* [11] = */ 1,
	/* [12] = */ 1,
	/* [13] = */ 1,
	/* [14] = */ 9,
	/* [15] = */ 1,
	/* [16] = */ 1,
	/* [17] = */ 3,
	/* [18] = */ 3,
	/* [19] = */ 3,
	/* [20] = */ 3,
	/* [21] = */ 3,
	/* [22] = */ 2,
	/* [23] = */ 2,
	/* [24] = */ 1,
	/* [25] = */ 1,
	/* [26] = */ 1,
	/* [27] = */ 1,
	/* [28] = */ 1,
	/* [29] = */ 1,
	/* [30] = */ 1,
	/* [31] = */ 1,
	/* [32] = */ 1,
	/* [33] = */ 1,
	/* [34] = */ 1,
	/* [35] = */ 1,
	/* [36] = */ 2,
	/* [37] = */ 1,
	/* [38] = */ 1,
	/* [39] = */ 1,
	/* [40] = */ 1,
	/* [41] = */ 1,
	/* [42] = */ 1,
	/* [43] = */ 1,
	/* [44] = */ 1,
	/* [45] = */ 1,
	/* [46] = */ 1,
	/* [47] = */ 1,
	/* [48] = */ 1,
	/* [49] = */ 1,
	/* [50] = */ 1,
	/* [51] = */ 1,
	/* [52] = */ 1,
	/* [53] = */ 1,
	/* [54] = */ 1,
	/* [55] = */ 1,
	/* [56] = */ 1,
	/* [57] = */ 1,
	/* [58] = */ 1,
	/* [59] = */ 1,
	/* [60] = */ 1,
	/* [61] = */ 1,
	/* [62] = */ 1
};

static char *miscTextureNames[32] = {
	/* [0] = */ 0x443910,
	/* [1] = */ 0x4438f0,
	/* [2] = */ 0x4438c8,
	/* [3] = */ 0x4438a0,
	/* [4] = */ 0x443878,
	/* [5] = */ 0x443850,
	/* [6] = */ 0x443828,
	/* [7] = */ 0x443808,
	/* [8] = */ 0x4437e8,
	/* [9] = */ 0x4437c0,
	/* [10] = */ 0x443798,
	/* [11] = */ 0x443768,
	/* [12] = */ 0x443740,
	/* [13] = */ 0x443710,
	/* [14] = */ 0x4436e8,
	/* [15] = */ 0x4436c8,
	/* [16] = */ 0x4436a8,
	/* [17] = */ 0x443680,
	/* [18] = */ 0x443658,
	/* [19] = */ 0x443638,
	/* [20] = */ 0x443618,
	/* [21] = */ 0x4435f0,
	/* [22] = */ 0x4435d0,
	/* [23] = */ 0x4435b0,
	/* [24] = */ 0x443590,
	/* [25] = */ 0x443570,
	/* [26] = */ 0x443548,
	/* [27] = */ 0x443520,
	/* [28] = */ 0x4434f8,
	/* [29] = */ 0x4434d8,
	/* [30] = */ 0x4434b0,
	/* [31] = */ 0x443480
};

u8 flashalpha = 0;
u8 quickflash = 0;
static int icontexnum[63];
static u8 icontex_filenames[63][38];
static int miscTextureNum[32];

int miscTextureGetNum(int miscTextureID) {}

void guiPreload() {
	int i;
}

void guiRestart() {
	int i;
}

void guiReset() {}

void guiFlashAlpha() {}

void guiAmountBarGfx(float amount, int basex, int basey, int width, int height, u32 fgcol, u32 bgcol, boolean flipped) {
	int y2;
	int xo;
	int wo;
	int x;
	int w;
	int tu;
	int tu2;
	int tu;
	int tu2;
}

void guiDrawButton(int x, int y, e_button bt, boolean on) {
	int w;
	int h;
}

void guiDrawBlueDPad(int x1, int y1, u32 upAlpha, u32 downAlpha, u32 leftAlpha, u32 rightAlpha) {}

void guiDrawBlueDPadButton(int x1, int y1, int x2, int y2, dpad_button bt, u32 alpha) {
	int xTex;
	int yTex;
	int xTexEnd;
	int yTexEnd;
}

void guiDrawBlueButton(int x1, int y1, int x2, int y2, e_button bt, u32 alpha) {
	int xTex;
	int yTex;
	int xTexEnd;
	int yTexEnd;
}

void guiDrawArrowRight(int x1, int y1, int x2, int y2, u32 rgba) {}

void guiDrawArrowLeft(int x1, int y1, int x2, int y2, u32 rgba) {}

void guiDrawArrowUp(int x1, int y1, int x2, int y2, u32 rgba) {}

void guiDrawArrowDown(int x1, int y1, int x2, int y2, u32 rgba) {}

void guiDrawCircle(int x1, int y1, int x2, int y2, u32 rgba) {}

int guiGetIconTexNum(int iconnum) {}

int guiGetIconWidth(int iconnum) {}

int guiGetIconHeight(int iconnum) {}

void guiDrawIcon(float x, float y, e_icon num, u32 colour) {
	int texnum;
	int w;
	int h;
}

void guiHGradient(int x1, int y1, int x2, int y2, u32 col, u8 alpha1, u8 alpha2) {
	int pts[12];
	u32 col2;
}

void guiVGradient(int x1, int y1, int x2, int y2, u32 col, u8 alpha1, u8 alpha2) {
	int pts[12];
	u32 col2;
}

void guiTriGradient(int x1, int y1, int x2, int y2, u32 col, u8 alpha1, u8 alpha2) {
	int pts[12];
	u32 col2;
}

void guiDrawFormattedText(u8 *text, int basex, int basey, int basefont, int fgcol, int bgcol) {
	int y;
	int font;
	int pos;
	u32 fg;
	u32 bg;
	u8 *newline;
}

void guiDrawBox(int x, int y, int x2, int y2, u32 fgcol, u32 bgcol) {}

void guiDrawRoundBox(int x, int y, int x2, int y2, u32 bgcol, u32 fgcol) {}

void guiLoadingGfx(float scalar) {
	int b;
	int zb;
	int intensity;
	int x;
	int y;
	int w;
	int h;
	u32 fgcol;
	u32 bgcol;
	u8 *s;
	int font;
}
