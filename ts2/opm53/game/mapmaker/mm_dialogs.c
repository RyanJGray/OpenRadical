// STATUS: NOT STARTED

#include "mm_dialogs.h"

typedef enum {
	ID_EDITMODE_0 = 1,
	ID_EDITMODE_LAST = 4,
	ID_TILES_0 = 5,
	ID_TILES_LAST = 34,
	ID_TILES_NEXTPAGE = 35,
	ID_ITEMS_0 = 36,
	ID_ITEMS_LAST = 88,
	ID_ITEMS_NEXTPAGE = 89,
	ID_RESETPALETTE = 90,
	ID_PALETTE_0 = 91,
	ID_PALETTE_LAST = 154,
	ID_LIGHTMODE_0 = 155,
	ID_LIGHTMODE_LAST = 158,
	ID_LIGHTSPEED_0 = 159,
	ID_LIGHTSPEED_LAST = 161,
	ID_LIGHTPHASE = 162,
	ID_NEWPATROL = 163,
	ID_PATROL_0 = 164,
	ID_PATROL_LAST = 171,
	ID_PATROLMODE_0 = 172,
	ID_PATROLMODE_LAST = 179,
	ID_DRAWMISC0 = 180,
	ID_DRAWMISC1 = 181,
	ID_DRAWMISC2 = 182,
	ID_COLOUR_HS = 183,
	ID_COLOUR_V = 184,
	ID_COLOUR_R = 185,
	ID_COLOUR_G = 186,
	ID_COLOUR_B = 187
};

struct neattext_s {
	u32 flags;
	u32 fgpen;
	u32 fillpen;
	u32 bgpen;
};

typedef neattext_s neattext_t;

struct storepointer_s {
	e_icon picture;
	fix_t savexy[2];
};

typedef storepointer_s storepointer_t;

static u8 tileorder[30] = {
	/* [0] = */ 2,
	/* [1] = */ 17,
	/* [2] = */ 1,
	/* [3] = */ 9,
	/* [4] = */ 0,
	/* [5] = */ 4,
	/* [6] = */ 3,
	/* [7] = */ 5,
	/* [8] = */ 14,
	/* [9] = */ 8,
	/* [10] = */ 18,
	/* [11] = */ 10,
	/* [12] = */ 12,
	/* [13] = */ 11,
	/* [14] = */ 13,
	/* [15] = */ 19,
	/* [16] = */ 16,
	/* [17] = */ 20,
	/* [18] = */ 22,
	/* [19] = */ 23,
	/* [20] = */ 7,
	/* [21] = */ 25,
	/* [22] = */ 21,
	/* [23] = */ 26,
	/* [24] = */ 24,
	/* [25] = */ 6,
	/* [26] = */ 15,
	/* [27] = */ 27,
	/* [28] = */ 28,
	/* [29] = */ 29
};

static u8 itemorder[53] = {
	/* [0] = */ 0,
	/* [1] = */ 1,
	/* [2] = */ 2,
	/* [3] = */ 3,
	/* [4] = */ 4,
	/* [5] = */ 19,
	/* [6] = */ 20,
	/* [7] = */ 21,
	/* [8] = */ 22,
	/* [9] = */ 23,
	/* [10] = */ 24,
	/* [11] = */ 25,
	/* [12] = */ 26,
	/* [13] = */ 27,
	/* [14] = */ 28,
	/* [15] = */ 35,
	/* [16] = */ 36,
	/* [17] = */ 37,
	/* [18] = */ 38,
	/* [19] = */ 34,
	/* [20] = */ 39,
	/* [21] = */ 40,
	/* [22] = */ 41,
	/* [23] = */ 42,
	/* [24] = */ 43,
	/* [25] = */ 5,
	/* [26] = */ 6,
	/* [27] = */ 7,
	/* [28] = */ 8,
	/* [29] = */ 9,
	/* [30] = */ 10,
	/* [31] = */ 11,
	/* [32] = */ 12,
	/* [33] = */ 13,
	/* [34] = */ 14,
	/* [35] = */ 15,
	/* [36] = */ 16,
	/* [37] = */ 17,
	/* [38] = */ 18,
	/* [39] = */ 33,
	/* [40] = */ 29,
	/* [41] = */ 30,
	/* [42] = */ 31,
	/* [43] = */ 32,
	/* [44] = */ 45,
	/* [45] = */ 46,
	/* [46] = */ 47,
	/* [47] = */ 48,
	/* [48] = */ 49,
	/* [49] = */ 50,
	/* [50] = */ 51,
	/* [51] = */ 52,
	/* [52] = */ 44
};

static char *s_lighttypes[4] = {
	/* [0] = */ 0x45c6d0,
	/* [1] = */ 0x45c6c8,
	/* [2] = */ 0x45c6c0,
	/* [3] = */ 0x45c6b8
};

static char *s_lightspeed[3] = {
	/* [0] = */ 0x45c6e8,
	/* [1] = */ 0x45c6e0,
	/* [2] = */ 0x45c6d8
};

u32 lightpalette[64] = {
	/* [0] = */ 32640,
	/* [1] = */ 28800,
	/* [2] = */ 24704,
	/* [3] = */ 20608,
	/* [4] = */ 16512,
	/* [5] = */ 12416,
	/* [6] = */ 8320,
	/* [7] = */ 4224,
	/* [8] = */ 32640,
	/* [9] = */ 28800,
	/* [10] = */ 24704,
	/* [11] = */ 20608,
	/* [12] = */ 16512,
	/* [13] = */ 12416,
	/* [14] = */ 8320,
	/* [15] = */ 4224,
	/* [16] = */ 16512,
	/* [17] = */ 14464,
	/* [18] = */ 12416,
	/* [19] = */ 10368,
	/* [20] = */ 8320,
	/* [21] = */ 6272,
	/* [22] = */ 4224,
	/* [23] = */ 2176,
	/* [24] = */ 16512,
	/* [25] = */ 14464,
	/* [26] = */ 12416,
	/* [27] = */ 10368,
	/* [28] = */ 8320,
	/* [29] = */ 6272,
	/* [30] = */ 4224,
	/* [31] = */ 2176,
	/* [32] = */ 16512,
	/* [33] = */ 14464,
	/* [34] = */ 12416,
	/* [35] = */ 10368,
	/* [36] = */ 8320,
	/* [37] = */ 6272,
	/* [38] = */ 4224,
	/* [39] = */ 2176,
	/* [40] = */ 16512,
	/* [41] = */ 14464,
	/* [42] = */ 12416,
	/* [43] = */ 10368,
	/* [44] = */ 8320,
	/* [45] = */ 6272,
	/* [46] = */ 4224,
	/* [47] = */ 2176,
	/* [48] = */ 24704,
	/* [49] = */ 23680,
	/* [50] = */ 18560,
	/* [51] = */ 15488,
	/* [52] = */ 12416,
	/* [53] = */ 9344,
	/* [54] = */ 6272,
	/* [55] = */ 3200,
	/* [56] = */ 32640,
	/* [57] = */ 28800,
	/* [58] = */ 24704,
	/* [59] = */ 20608,
	/* [60] = */ 16512,
	/* [61] = */ 12416,
	/* [62] = */ 8320,
	/* [63] = */ 4224
};

static neattext_t nt_simple = {
	/* .flags = */ 0,
	/* .fgpen = */ 25728,
	/* .fillpen = */ 0,
	/* .bgpen = */ 0
};

static neattext_t nt_center = {
	/* .flags = */ 1,
	/* .fgpen = */ 25728,
	/* .fillpen = */ 0,
	/* .bgpen = */ 0
};

static neattext_t nt_lmodeon = {
	/* .flags = */ 13,
	/* .fgpen = */ 25728,
	/* .fillpen = */ 20608,
	/* .bgpen = */ 0
};

static neattext_t nt_lmodeoff = {
	/* .flags = */ 13,
	/* .fgpen = */ 16512,
	/* .fillpen = */ 15488,
	/* .bgpen = */ 0
};

static neattext_t nt_lspeedon = {
	/* .flags = */ 13,
	/* .fgpen = */ 25728,
	/* .fillpen = */ 10368,
	/* .bgpen = */ 0
};

static neattext_t nt_lspeedoff = {
	/* .flags = */ 13,
	/* .fgpen = */ 16512,
	/* .fillpen = */ 5248,
	/* .bgpen = */ 0
};

static neattext_t nt_lspeednot = {
	/* .flags = */ 13,
	/* .fgpen = */ 8320,
	/* .fillpen = */ 5248,
	/* .bgpen = */ 0
};

static neattext_t nt_editmodeon = {
	/* .flags = */ 9,
	/* .fgpen = */ 32640,
	/* .fillpen = */ 20608,
	/* .bgpen = */ 0
};

static neattext_t nt_editmodeoff = {
	/* .flags = */ 9,
	/* .fgpen = */ 12416,
	/* .fillpen = */ 10368,
	/* .bgpen = */ 0
};

static neattext_t nt_nextpage = {
	/* .flags = */ 9,
	/* .fgpen = */ 25728,
	/* .fillpen = */ 10368,
	/* .bgpen = */ 0
};

prop *itemprop = NULL;

static pageinit_t mapmakercolour_page = {
	/* .tick = */ &mapmakercolour_pageTick,
	/* .draw_before = */ &mapmakercolour_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

static pageinit_t mapmakermain_page = {
	/* .tick = */ &mapmakermain_pageTick,
	/* .draw_before = */ &mapmakermain_pageDraw,
	/* .initfocusid = */ 0,
	/* .pad = */ 0,
	/* .draw_after = */ &mapmakermain_pageDrawAfter,
	/* .construct = */ NULL
};

pageinit_t zoomtile_page = {
	/* .tick = */ &zoomtile_pageTick,
	/* .draw_before = */ &zoomtile_pageDraw,
	/* .initfocusid = */ 1,
	/* .pad = */ 0,
	/* .draw_after = */ NULL,
	/* .construct = */ NULL
};

fix_t pagemargins[4] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0
};

e_icon mmcursor = icon_1;
u8 lighttype = 0;
u8 lightphase = 0;

float lightHSV[3] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f
};

int curlightcol = 0;

u32 custompalette[64] = {
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
	/* [33] = */ 0,
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
	/* [48] = */ 0,
	/* [49] = */ 0,
	/* [50] = */ 0,
	/* [51] = */ 0,
	/* [52] = */ 0,
	/* [53] = */ 0,
	/* [54] = */ 0,
	/* [55] = */ 0,
	/* [56] = */ 0,
	/* [57] = */ 0,
	/* [58] = */ 0,
	/* [59] = */ 0,
	/* [60] = */ 0,
	/* [61] = */ 0,
	/* [62] = */ 0,
	/* [63] = */ 0
};

zoomview_t zoomview = {
	/* .wcx = */ 0,
	/* .wcy = */ 0,
	/* .ww = */ 0,
	/* .wh = */ 0,
	/* .dest = */ {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0
	},
	/* .destframes = */ 0,
	/* .dist = */ 0.f,
	/* .roty = */ 0.f,
	/* .tilt = */ 0.f,
	/* .flags = */ 0,
	/* .prop = */ NULL,
	/* .itemnum = */ 0,
	/* .obj = */ NULL,
	/* .tilenum = */ 0
};

tilepadinfo_t *aimpadinfo = NULL;
static int firsttile;
static int firstitem;

prop *tileprops[30] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL,
	/* [20] = */ NULL,
	/* [21] = */ NULL,
	/* [22] = */ NULL,
	/* [23] = */ NULL,
	/* [24] = */ NULL,
	/* [25] = */ NULL,
	/* [26] = */ NULL,
	/* [27] = */ NULL,
	/* [28] = */ NULL,
	/* [29] = */ NULL
};

prop *circleprop = NULL;

obdef *iconobs[21] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL,
	/* [10] = */ NULL,
	/* [11] = */ NULL,
	/* [12] = */ NULL,
	/* [13] = */ NULL,
	/* [14] = */ NULL,
	/* [15] = */ NULL,
	/* [16] = */ NULL,
	/* [17] = */ NULL,
	/* [18] = */ NULL,
	/* [19] = */ NULL,
	/* [20] = */ NULL
};

static tilepadinfo_t padinfo[64];
static int numpadinfo;
static float tilerotyinc;
static float lastrotydir;
static struct {
	int lock;
	float fRGB[3];
} editcolour;

char* getLightDesc(int mask) {
	static char s_lightdesc[32];
	int speed;
}

u8* MM_GetFullName(int itemnum) {
	int ammotype;
}

static void draw_neattext(hitbox_t *hb) {
	neattext_t *nt;
	int x1;
	int y1;
	u8 *text;
	u32 fgpen;
	u32 bgpen;
	int font;
	int x2;
	int y2;
	int texnum;
	u32 fillpen;
}

static void exitDialogs() {}

void MM_PointerSet(int push, int pop) {
	static storepointer_t pointersave[4];
}

void MM_DrawCursor(hitbox_t *hb) {
	int top;
	int left;
	u32 colour;
	u32 col;
	int x1;
	int y1;
	int x2;
	int y2;
}

static void preloadGunSet(int gunsetnum) {
	int g;
	gunset *gunset;
	int combo;
	guncombo *gc;
	gunInfo_t *gi;
}

void zoomviewPreload() {
	int i;
}

void zoomviewReset() {
	int i;
	preloadinfo *pl;
}

static void mm_makepadinfo(int tilenum) {
	padfile *pPads;
	int numpads;
	pad *tmppad;
	int i;
}

static int MM_GetItemIcon(int itemnum) {
	int icon;
}

static float MM_GetItemScale(int itemnum) {
	float f;
}

void mm_setpadicon(tilepadinfo_t *pi) {
	item_t *it;
}

void zoomviewWindow(int cx, int cy, int width) {}

void zoomviewWindowDest(int cx, int cy, int width, int nframes) {}

static void zoomviewWindowTick() {}

boolean zoomviewZoomed() {}

float zoomviewSizeToDist(int tilenum) {
	static float sizetodist[4] = {
		/* [0] = */ 9.5f,
		/* [1] = */ 13.5f,
		/* [2] = */ 17.f,
		/* [3] = */ 50.5f
	};
	tiledef *t;
	int i;
}

void zoomviewViewSet(int tilenum, float roty) {}

void zoomviewTick() {
	float zoomtiletrans[3];
	prop *p;
	int i;
	float tileorig[3];
	mtx_u mty;
	pad *tmppad;
	prop *p;
	float *pos;
}

static void findHighlightPad() {
	int i;
	int mousex;
	int mousey;
	int bestdist;
	float bestz;
	float padpos[3];
	float transpos[4];
	int x;
	int y;
	int z;
	int dx;
	int dy;
	int dist;
}

void zoomviewGfx() {
	int floor;
	int curfloor;
	tiledef *tile;
	int i;
	prop *p;
}

static void rotate3dView() {
	float joyx;
	float absfjoyx;
}

static void draw_colourwheel(hitbox_t *hb) {
	float cx;
	float cy;
	float cw;
	float ch;
	float frad;
	float fcos;
	float fsin;
	int i;
	int x;
	int y;
	float angle;
	int pts[294];
	int *ppts;
	float hsv[3];
}

static void draw_colourslide(hitbox_t *hb) {
	int pts[12];
	int *ppts;
	u32 colour;
	float value;
	int x1;
	int x2;
	float hsv[3];
}

static int makecolourdialog(hitbox_t *box) {
	hitbox_t *startbox;
	int x;
	int y;
}

static void mapmakercolour_pageDraw(pagedef_t *page) {}

static void mapmakercolour_pageTick(pagedef_t *page) {
	fix_t margins[4];
	float dx;
	float dy;
	float cx;
	float cy;
	float dist;
	float angle;
	float frad;
	float fcos;
	float fsin;
	int x;
	int y;
	float value;
}

static void draw_selectbrick(hitbox_t *hb) {
	int tilenum;
	fix_t savescale[4];
	object_t *save;
	object_t objfake;
	fix_t px;
	fix_t py;
	boolean focused;
	int i;
	int x1;
	int y1;
	int x2;
	int y2;
	int cols;
	int rows;
}

static void draw_selectitem(hitbox_t *hb) {
	int itemnum;
	boolean focused;
	u32 itemcol;
	u32 fgcol;
	rect_t r;
	int font;
	int itemcount;
	u8 *s;
	float hsv[3];
}

static void draw_colourbox(hitbox_t *hb) {
	int iCol;
	int x1;
	int y1;
	int x2;
	int y2;
}

static void draw_lightphase(hitbox_t *hb) {
	int texnum;
	int w;
	int h;
	u32 col;
}

static void draw_lightmisc(hitbox_t *hb) {
	char *s;
	int font;
}

static void draw_patrolbar(hitbox_t *hb) {
	int iPatrol;
	int iHighlightPatrol;
	int x;
	int y;
	int j;
	int font;
	u8 letter[2];
	u32 rgba;
	int x1;
	int y1;
}

static void draw_patrolmodebox(hitbox_t *hb) {
	int iPatrol;
}

static int makedialog(pagedef_t *page, hitbox_t *box) {
	hitbox_t *startbox;
	hitbox_t *pBoxCaptions[4];
	int i;
	int barx;
	int iCaptions;
	char *sCaptions[4];
	int x1;
	int w;
	int spacing;
	int bx;
	int by;
	int bh;
	int tilenum;
	tiledef *tdef;
	int bx;
	int by;
	int itemnum;
	int i;
	int x1;
	int y1;
	boolean highlight;
	boolean highlight;
	int iPatrolFocus;
	int i;
	int y1;
}

static void mapmakermain_pageDraw(pagedef_t *page) {
	int y1;
	int itemnum;
	int font;
	itemdef *pDef;
	int count;
	u8 *s;
}

static void mapmakermain_pageDrawAfter(pagedef_t *page) {}

static void cycleTilePage() {}

static void cycleItemPage() {}

static void mapmakermain_pageTick(pagedef_t *page) {
	int tilenum;
	int itemnum;
	float promoPropScale;
	int propnum;
	int guncombo;
	int guntype;
	manualLighting *lighting;
	int m;
	float scale;
	int x0;
	int y0;
	int x1;
	int y1;
	int nCols;
	int nRows;
	int iSteps;
	int i;
	int j;
	int n;
	u32 colstart;
	u32 colend;
	tiledef *tile;
	int iPatrol;
	int iPatrolPt;
	object_t *pObj;
	int iPatrol;
}

void MM_StartMainDialog() {}

static void zoomtile_pageDraw(pagedef_t *page) {
	item_t *it;
	rect_t r;
}

static void zoomtile_pageTick(pagedef_t *page) {
	boolean toppage;
}

void MM_StartZoomTileView(object_t *tileobj) {
	int tilenum;
	float roty;
}

void MM_DialogsMake() {}

void MM_DialogsReset() {}
