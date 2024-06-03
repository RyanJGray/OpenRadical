// STATUS: NOT STARTED

#include "text.h"

// warning: multiple differing types with the same name (#12,  not equal)
enum {
	FONTLOADFLAG_DUMMY = 1,
	FONTLOADFLAG_FRONTEND = 2,
	FONTLOADFLAG_LEVEL = 4,
	FONTLOADFLAG_MAPMAKER = 8,
	FONTLOADFLAG_CREDITS = 16,
	FONTLOADFLAG_CLAMP = 32,
	FONTLOADFLAG_LANGUAGE = 64
};

struct capsinfo_s {
	u8 left;
	u8 width;
	u8 height;
	u8 basechar;
};

typedef capsinfo_s capsinfo_t;

struct textCallbackData_s {
	textfx *fx;
	mtx_u *matrix;
	textSettings3D *settings;
	int yFadeTopStart;
	int yFadeTopEnd;
	int yFadeBottomStart;
	int yFadeBottomEnd;
};

typedef textCallbackData_s textCallbackData;

static fontsel fontSelection[4] = {
	/* [0] = */ {
		/* .filename = */ 0x42a288,
		/* .fontLoadFlags = */ 14,
		/* .data = */ future32font,
		/* .height = */ 30,
		/* .fixedwidth = */ 24,
		/* .texnum = */ -1
	},
	/* [1] = */ {
		/* .filename = */ NULL,
		/* .fontLoadFlags = */ 0,
		/* .data = */ NULL,
		/* .height = */ 0,
		/* .fixedwidth = */ 0,
		/* .texnum = */ -1
	},
	/* [2] = */ {
		/* .filename = */ 0x42a268,
		/* .fontLoadFlags = */ 31,
		/* .data = */ bookfont,
		/* .height = */ 15,
		/* .fixedwidth = */ 8,
		/* .texnum = */ -1
	},
	/* [3] = */ {
		/* .filename = */ 0x42a240,
		/* .fontLoadFlags = */ 15,
		/* .data = */ booklightfont,
		/* .height = */ 16,
		/* .fixedwidth = */ 8,
		/* .texnum = */ -1
	}
};

static fontStyle fontStyles[12] = {
	/* [0] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 0.5f,
		/* .scaley = */ 0.5f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -4
	},
	/* [1] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 0.5f,
		/* .scaley = */ 0.75f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -4
	},
	/* [2] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 0.58f,
		/* .scaley = */ 0.7f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -4
	},
	/* [3] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 0.65f,
		/* .scaley = */ 0.75f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -4
	},
	/* [4] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 0.8f,
		/* .scaley = */ 0.8f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -4
	},
	/* [5] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 1.f,
		/* .scaley = */ 1.f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -6
	},
	/* [6] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 1.4f,
		/* .scaley = */ 1.4f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -6
	},
	/* [7] = */ {
		/* .fontSel = */ 0,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 2.f,
		/* .scaley = */ 2.f,
		/* .extra = */ futurefontextra,
		/* .grid = */ futuregrid,
		/* .nonFixedExtraWidth = */ -6
	},
	/* [8] = */ {
		/* .fontSel = */ 3,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 0.75f,
		/* .scaley = */ 0.75f,
		/* .extra = */ booklightfontextra,
		/* .grid = */ booklightgrid,
		/* .nonFixedExtraWidth = */ -1
	},
	/* [9] = */ {
		/* .fontSel = */ 3,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 1.f,
		/* .scaley = */ 1.f,
		/* .extra = */ booklightfontextra,
		/* .grid = */ booklightgrid,
		/* .nonFixedExtraWidth = */ -1
	},
	/* [10] = */ {
		/* .fontSel = */ 2,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 1.f,
		/* .scaley = */ 1.f,
		/* .extra = */ bookfontextra,
		/* .grid = */ bookgrid,
		/* .nonFixedExtraWidth = */ -1
	},
	/* [11] = */ {
		/* .fontSel = */ 2,
		/* .fixedWidth = */ 0,
		/* .scalex = */ 1.25f,
		/* .scaley = */ 1.25f,
		/* .extra = */ bookfontextra,
		/* .grid = */ bookgrid,
		/* .nonFixedExtraWidth = */ -1
	}
};

int currentFontStyle = 0;
fontsel *fontSelPtr = NULL;
fontStyle *fontStylePtr = NULL;

u8 ascii8to7[128] = {
	/* [0] = */ 95,
	/* [1] = */ 33,
	/* [2] = */ 95,
	/* [3] = */ 95,
	/* [4] = */ 95,
	/* [5] = */ 95,
	/* [6] = */ 95,
	/* [7] = */ 95,
	/* [8] = */ 95,
	/* [9] = */ 95,
	/* [10] = */ 97,
	/* [11] = */ 95,
	/* [12] = */ 95,
	/* [13] = */ 45,
	/* [14] = */ 95,
	/* [15] = */ 95,
	/* [16] = */ 95,
	/* [17] = */ 33,
	/* [18] = */ 95,
	/* [19] = */ 95,
	/* [20] = */ 95,
	/* [21] = */ 95,
	/* [22] = */ 95,
	/* [23] = */ 95,
	/* [24] = */ 95,
	/* [25] = */ 95,
	/* [26] = */ 97,
	/* [27] = */ 95,
	/* [28] = */ 95,
	/* [29] = */ 45,
	/* [30] = */ 95,
	/* [31] = */ 95,
	/* [32] = */ 95,
	/* [33] = */ 32,
	/* [34] = */ 95,
	/* [35] = */ 95,
	/* [36] = */ 95,
	/* [37] = */ 95,
	/* [38] = */ 95,
	/* [39] = */ 95,
	/* [40] = */ 95,
	/* [41] = */ 95,
	/* [42] = */ 97,
	/* [43] = */ 95,
	/* [44] = */ 95,
	/* [45] = */ 45,
	/* [46] = */ 95,
	/* [47] = */ 95,
	/* [48] = */ 32,
	/* [49] = */ 95,
	/* [50] = */ 95,
	/* [51] = */ 95,
	/* [52] = */ 95,
	/* [53] = */ 95,
	/* [54] = */ 95,
	/* [55] = */ 95,
	/* [56] = */ 184,
	/* [57] = */ 95,
	/* [58] = */ 32,
	/* [59] = */ 95,
	/* [60] = */ 95,
	/* [61] = */ 95,
	/* [62] = */ 95,
	/* [63] = */ 32,
	/* [64] = */ 65,
	/* [65] = */ 65,
	/* [66] = */ 65,
	/* [67] = */ 65,
	/* [68] = */ 65,
	/* [69] = */ 65,
	/* [70] = */ 65,
	/* [71] = */ 67,
	/* [72] = */ 69,
	/* [73] = */ 69,
	/* [74] = */ 69,
	/* [75] = */ 69,
	/* [76] = */ 73,
	/* [77] = */ 73,
	/* [78] = */ 73,
	/* [79] = */ 73,
	/* [80] = */ 68,
	/* [81] = */ 78,
	/* [82] = */ 79,
	/* [83] = */ 79,
	/* [84] = */ 79,
	/* [85] = */ 79,
	/* [86] = */ 79,
	/* [87] = */ 88,
	/* [88] = */ 48,
	/* [89] = */ 85,
	/* [90] = */ 85,
	/* [91] = */ 85,
	/* [92] = */ 85,
	/* [93] = */ 89,
	/* [94] = */ 80,
	/* [95] = */ 32,
	/* [96] = */ 97,
	/* [97] = */ 97,
	/* [98] = */ 97,
	/* [99] = */ 97,
	/* [100] = */ 97,
	/* [101] = */ 97,
	/* [102] = */ 97,
	/* [103] = */ 99,
	/* [104] = */ 101,
	/* [105] = */ 101,
	/* [106] = */ 101,
	/* [107] = */ 101,
	/* [108] = */ 105,
	/* [109] = */ 105,
	/* [110] = */ 105,
	/* [111] = */ 105,
	/* [112] = */ 95,
	/* [113] = */ 110,
	/* [114] = */ 111,
	/* [115] = */ 111,
	/* [116] = */ 111,
	/* [117] = */ 111,
	/* [118] = */ 111,
	/* [119] = */ 95,
	/* [120] = */ 48,
	/* [121] = */ 117,
	/* [122] = */ 117,
	/* [123] = */ 117,
	/* [124] = */ 117,
	/* [125] = */ 121,
	/* [126] = */ 112,
	/* [127] = */ 121
};

u8 asciicaps[128] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0,
	/* [10] = */ 0,
	/* [11] = */ 0,
	/* [12] = */ 0,
	/* [13] = */ 0,
	/* [14] = */ 0,
	/* [15] = */ 0,
	/* [16] = */ 0,
	/* [17] = */ 0,
	/* [18] = */ 0,
	/* [19] = */ 0,
	/* [20] = */ 0,
	/* [21] = */ 0,
	/* [22] = */ 0,
	/* [23] = */ 0,
	/* [24] = */ 0,
	/* [25] = */ 0,
	/* [26] = */ 0,
	/* [27] = */ 0,
	/* [28] = */ 0,
	/* [29] = */ 0,
	/* [30] = */ 0,
	/* [31] = */ 0,
	/* [32] = */ 0,
	/* [33] = */ 6,
	/* [34] = */ 0,
	/* [35] = */ 0,
	/* [36] = */ 0,
	/* [37] = */ 0,
	/* [38] = */ 0,
	/* [39] = */ 0,
	/* [40] = */ 0,
	/* [41] = */ 0,
	/* [42] = */ 0,
	/* [43] = */ 0,
	/* [44] = */ 0,
	/* [45] = */ 0,
	/* [46] = */ 0,
	/* [47] = */ 0,
	/* [48] = */ 8,
	/* [49] = */ 0,
	/* [50] = */ 0,
	/* [51] = */ 0,
	/* [52] = */ 0,
	/* [53] = */ 0,
	/* [54] = */ 0,
	/* [55] = */ 0,
	/* [56] = */ 0,
	/* [57] = */ 0,
	/* [58] = */ 8,
	/* [59] = */ 0,
	/* [60] = */ 0,
	/* [61] = */ 0,
	/* [62] = */ 0,
	/* [63] = */ 7,
	/* [64] = */ 2,
	/* [65] = */ 1,
	/* [66] = */ 3,
	/* [67] = */ 5,
	/* [68] = */ 4,
	/* [69] = */ 0,
	/* [70] = */ 0,
	/* [71] = */ 0,
	/* [72] = */ 2,
	/* [73] = */ 1,
	/* [74] = */ 3,
	/* [75] = */ 4,
	/* [76] = */ 2,
	/* [77] = */ 1,
	/* [78] = */ 3,
	/* [79] = */ 4,
	/* [80] = */ 0,
	/* [81] = */ 4,
	/* [82] = */ 2,
	/* [83] = */ 1,
	/* [84] = */ 3,
	/* [85] = */ 5,
	/* [86] = */ 4,
	/* [87] = */ 0,
	/* [88] = */ 0,
	/* [89] = */ 2,
	/* [90] = */ 1,
	/* [91] = */ 3,
	/* [92] = */ 4,
	/* [93] = */ 1,
	/* [94] = */ 0,
	/* [95] = */ 9,
	/* [96] = */ 2,
	/* [97] = */ 1,
	/* [98] = */ 3,
	/* [99] = */ 5,
	/* [100] = */ 4,
	/* [101] = */ 0,
	/* [102] = */ 0,
	/* [103] = */ 0,
	/* [104] = */ 2,
	/* [105] = */ 1,
	/* [106] = */ 3,
	/* [107] = */ 4,
	/* [108] = */ 2,
	/* [109] = */ 1,
	/* [110] = */ 3,
	/* [111] = */ 4,
	/* [112] = */ 5,
	/* [113] = */ 5,
	/* [114] = */ 2,
	/* [115] = */ 1,
	/* [116] = */ 3,
	/* [117] = */ 5,
	/* [118] = */ 4,
	/* [119] = */ 0,
	/* [120] = */ 0,
	/* [121] = */ 2,
	/* [122] = */ 1,
	/* [123] = */ 3,
	/* [124] = */ 4,
	/* [125] = */ 1,
	/* [126] = */ 0,
	/* [127] = */ 4
};

static capsinfo_t capsinfo[0] = {
};

int texnum_text_gfx[8] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0
};

int legacyfontflags = 0;
static boolean outlining;

boolean textShouldLoad(fontsel *fontSel) {}

void textPreload() {
	static texinfo ti;
}

void textRestart() {}

void textReset() {
	letter_s *let;
	static u8 done = 0;
	int i;
}

void textEnd() {}

void textCalcScreenToWorldRelation(textSettings3D *settings, mtx_u *matrix, float z, float frustrumHalfWidth, float frustrumHalfHeight) {
	mtx_u inverse;
	float pixel[3];
	float result[4];
	float qx;
	float qy;
	float zRatio;
	float x;
	float y;
}

int textSelect(int fontStyle) {
	int oldFontStyle;
}

static int GetXOffset(u8 *s) {
	u8 next;
	int offset;
	int letterindex;
	int nextindex;
	int lettershape;
	int nextshape;
	int index;
	letterextra *extra;
	int *grid;
}

int textWidth(u8 *s) {
	int width;
	int height;
}

int textHeight(u8 *s) {
	int width;
	int height;
}

void textSize(int *width, int *height, u8 *s) {
	letter *curlet;
	float curx;
	float cury;
	float maxx;
	float maxy;
	int rows;
	int halfrows;
	letter *fontletters;
	float scalex;
	float scaley;
	float fontheight;
	int h;
	int cap;
}

static void textParse(int *x, int *y, u8 *s, void (*callback)(/* parameters unknown */), textCallbackData *cbd) {
	float startx;
	float curx;
	float cury;
	letter *fontletters;
	float scalex;
	float scaley;
	int num;
	int h;
	int index;
	int letw;
	letter *let;
	int cap;
	int cap;
	int tx;
	int ty;
	int oy;
	int ox;
	int fontcaps_texnum;
}

static void textPrintCallback(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, textCallbackData *cbd, boolean specialchar) {
	textCallbackData *cbd;
	boolean specialchar;
	u32 rgba;
}

void textPrint(int *x, int *y, u8 *s, u32 colour) {
	int oldzbmode;
	textCallbackData cbd;
	textfx fx;
}

static void textNormalFadeCallback(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, textCallbackData *cbd, boolean specialchar) {
	textCallbackData *cbd;
	boolean specialchar;
	u32 alpha;
	u32 col;
	u32 rgba;
	int letterSize;
	int topSize;
	int starty;
	int endy;
	float startScalarV;
	float endScalarV;
	int vTop;
	int vBottom;
	float startScalar;
	float endScalar;
	u32 rgbaTop;
	u32 rgbaBottom;
	u32 abgrTop;
	u32 abgrBottom;
	int letterSize;
	int bottomSize;
	int starty;
	int endy;
	float startScalarV;
	float endScalarV;
	int vTop;
	int vBottom;
	float startScalar;
	float endScalar;
	u32 rgbaTop;
	u32 rgbaBottom;
	u32 abgrTop;
	u32 abgrBottom;
}

void textNormalFade(int x, int y, u8 *s, u32 colour, int yFadeTopStart, int yFadeTopEnd, int yFadeBottomStart, int yFadeBottomEnd) {
	int oldzbmode;
	int cx;
	int cy;
	textCallbackData cbd;
	textfx fx;
}

void textNormal(int x, int y, u8 *s, u32 colour) {
	int tx;
	int ty;
}

void textOutline(int x, int y, u8 *s, u32 textcolour, u32 bordercolour) {
	int tx;
	int ty;
}

void textOutlineFade(int x, int y, u8 *s, u32 textcolour, u32 bordercolour, int yFadeTopStart, int yFadeTopEnd, int yFadeBottomStart, int yFadeBottomEnd) {
	int yFadeBottomEnd;
}

void textShadow(int x, int y, u8 *s, u32 textcolour, u32 shadowcolour) {
	int tx;
	int ty;
}

static void textRender3DCallback(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, textCallbackData *cbd, boolean specialchar) {
	textCallbackData *cbd;
	float pos1[3];
	float pos2[3];
	float pos3[3];
	float pos4[3];
	float newpos1[4];
	float newpos2[4];
	float newpos3[4];
	float newpos4[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float x1w;
	float y1w;
	float x2w;
	float y2w;
	u32 abgr;
	u32 *ref;
	int u1new;
	int u2new;
	int v1new;
	int v2new;
	void *addr;
}

void textRender3D(u8 *s, float *pos, mtx_u *screenMatrix, mtx_u *matrix, textSettings3D *settings, textfx *fx) {
	int x;
	int y;
	float posA[3];
	float newpos[4];
	float q;
}

void textRender3DScr(u8 *s, int *x, int *y, mtx_u *matrix, textSettings3D *settings, textfx *fx) {
	textCallbackData cbd;
}
