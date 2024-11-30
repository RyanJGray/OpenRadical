// STATUS: NOT STARTED

#include "mm_draw.h"

typedef enum {
	LIGHT_FIXED = 0,
	LIGHT_SINE = 1,
	LIGHT_SQUARE = 2,
	LIGHT_RANDOM = 3,
	LIGHT_NUM = 4
};

static char *doortype_desc[5] = {
	/* [0] = */ 0x45c4b8,
	/* [1] = */ 0x4449b0,
	/* [2] = */ 0x4449a0,
	/* [3] = */ 0x444988,
	/* [4] = */ 0x444970
};

drawdoor_t *drawdoors = NULL;

u32 patrolcolour[8] = {
	/* [0] = */ 6271,
	/* [1] = */ 7039,
	/* [2] = */ 6527,
	/* [3] = */ 6783,
	/* [4] = */ 29055,
	/* [5] = */ 32127,
	/* [6] = */ 31871,
	/* [7] = */ 29311
};

int w_x = 0;
int w_y = 0;
int w_w = 0;
int w_h = 0;
fix_t m_x = 0;
fix_t m_y = 0;
fix_t m_x2 = 0;
fix_t m_y2 = 0;
fix_t m_w = 0;
fix_t m_h = 0;
fix_t scale_mtowx = 0;
fix_t scale_mtowy = 0;
fix_t scale_wtomx = 0;
fix_t scale_wtomy = 0;

u8 mapname[32] = {
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
	/* [31] = */ 0
};

u8 mapdesc[128] = {
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
	/* [63] = */ 0,
	/* [64] = */ 0,
	/* [65] = */ 0,
	/* [66] = */ 0,
	/* [67] = */ 0,
	/* [68] = */ 0,
	/* [69] = */ 0,
	/* [70] = */ 0,
	/* [71] = */ 0,
	/* [72] = */ 0,
	/* [73] = */ 0,
	/* [74] = */ 0,
	/* [75] = */ 0,
	/* [76] = */ 0,
	/* [77] = */ 0,
	/* [78] = */ 0,
	/* [79] = */ 0,
	/* [80] = */ 0,
	/* [81] = */ 0,
	/* [82] = */ 0,
	/* [83] = */ 0,
	/* [84] = */ 0,
	/* [85] = */ 0,
	/* [86] = */ 0,
	/* [87] = */ 0,
	/* [88] = */ 0,
	/* [89] = */ 0,
	/* [90] = */ 0,
	/* [91] = */ 0,
	/* [92] = */ 0,
	/* [93] = */ 0,
	/* [94] = */ 0,
	/* [95] = */ 0,
	/* [96] = */ 0,
	/* [97] = */ 0,
	/* [98] = */ 0,
	/* [99] = */ 0,
	/* [100] = */ 0,
	/* [101] = */ 0,
	/* [102] = */ 0,
	/* [103] = */ 0,
	/* [104] = */ 0,
	/* [105] = */ 0,
	/* [106] = */ 0,
	/* [107] = */ 0,
	/* [108] = */ 0,
	/* [109] = */ 0,
	/* [110] = */ 0,
	/* [111] = */ 0,
	/* [112] = */ 0,
	/* [113] = */ 0,
	/* [114] = */ 0,
	/* [115] = */ 0,
	/* [116] = */ 0,
	/* [117] = */ 0,
	/* [118] = */ 0,
	/* [119] = */ 0,
	/* [120] = */ 0,
	/* [121] = */ 0,
	/* [122] = */ 0,
	/* [123] = */ 0,
	/* [124] = */ 0,
	/* [125] = */ 0,
	/* [126] = */ 0,
	/* [127] = */ 0
};

u8 panning = 0;

u8 *button_text[6] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL
};

int min_x = 0;
int min_y = 0;
int max_x = 0;
int max_y = 0;
int min_w = 0;
int min_h = 0;
int max_w = 0;
int max_h = 0;
static int numdrawdoors;

void MM_DrawRect(fix_t mx, fix_t my, fix_t mx2, fix_t my2, u32 colour) {
	fix_t b;
	fix_t b;
}

void MM_DrawLine(fix_t mx, fix_t my, fix_t mx2, fix_t my2, u32 colour) {
	fix_t b;
	fix_t b;
}

static void MM_FindBoundaries() {
	object_t *obj;
	fix_t x2;
	fix_t y2;
	tiledef *tile;
}

void MM_CenterMap() {
	fix_t a;
	fix_t a;
	fix_t a;
	fix_t b;
	fix_t b;
	fix_t b;
}

void MM_InitView() {
	fix_t a;
	fix_t a;
	fix_t a;
	fix_t b;
	fix_t b;
	fix_t b;
}

void MM_PanWindow(fix_t x, fix_t y) {}

static void MM_DrawPatrolPoint(object_t *pTileObj, int iPadExtRef, u32 rgba, int iDisplayNr) {
	u16 *ipadse;
	int floor;
	int i;
	int j;
	int w;
	fix_t mx;
	fix_t my;
	tiledef *pTile;
	int x;
	int y;
	int w;
	int h;
	fix_t b;
	fix_t b;
}

static void MM_DrawPatrols() {
	int iPatrol;
	int iFont;
	int i;
	patrolroute_t *pr;
	routenode_t *rn;
	u32 rgba;
	int iPatrolNr;
}

static void MM_DrawScaledItem(fix_t mx, fix_t my, int itemnum, u32 rgba) {
	int alpha;
	fix_t b;
	float w;
	float h;
	float x;
	float y;
	int texnum;
	fix_t b;
}

static void MM_DrawItems(object_t *pObj) {
	fix_t mx;
	fix_t my;
	tiledef *pTile;
	int i;
	int j;
	int w;
	u16 *ipadse;
	int floor;
	int iPadExtRef;
	item_t *item;
	int itemnum;
	u32 rgba;
}

u32 MM_WYSIWYGTileColour(int lighttype, int lightphase, u32 col) {
	int type;
	float speed;
	float frac;
	int g1;
	int b1;
	int rd;
	int gd;
	int bd;
}

void MM_DrawTile(fix_t mx, fix_t my, tiledef *tile, tiledrmd_t drawmode, object_t *mapobj) {
	fix_t x;
	fix_t y;
	u32 floorcol;
	u32 wallcol;
	u32 dropcol;
	int i;
	int j;
	int floor;
	int tilew;
	int tileh;
	u8 *cells;
	u16 *ipads;
	u32 rgba;
	u8 corners;
	u8 bits;
	fix_t px;
	fix_t py;
	u8 doormask;
	u32 doorwaycol;
	int connectedplug;
	fix_t tw;
	fix_t th;
	fix_t x1;
	fix_t y1;
	u32 col;
}

void MM_DrawGrid() {
	fix_t x;
	fix_t y;
	fix_t starth;
	fix_t endh;
	fix_t startv;
	fix_t endv;
	u32 colour;
	int cols;
	int rows;
	int pels;
	int fx;
	fix_t b;
	fix_t b;
	int fy;
	fix_t b;
	fix_t b;
}

static void MM_DrawRooms() {
	object_t *ob;
	int savelevel;
	boolean highlightfulltile;
	tiledef *tile;
	fix_t x2;
	fix_t y2;
	tiledef *tile;
	fix_t x2;
	fix_t y2;
	int drmd;
}

static void MM_DrawDoors() {
	drawdoor_t *dd;
	int count;
	fix_t mx;
	fix_t my;
	fix_t mw;
	fix_t mh;
	u32 col;
}

static void MM_DrawUsedObject() {
	fix_t mx;
	fix_t my;
	object_t *ob;
	object_t fakeobj;
	int drawmode;
	fix_t b;
	fix_t b;
}

void MM_DrawButtonHelp(int x, int y) {
	int left;
	int top;
	int font;
	int w;
	u8 *s1;
	u8 *s2;
}

void MM_DrawLasso() {
	fix_t mx;
	fix_t my;
	u32 colour;
	fix_t b;
	fix_t b;
}

void mmDraw2DView() {
	object_t *ob;
	fix_t mx;
	fix_t my;
	u32 rgba;
	int blend;
	fix_t b;
	fix_t b;
	int texnum;
	float w;
	float h;
	float x;
	float y;
	fix_t b;
	fix_t b;
	tiledef *pTile;
	plugdef *pPlug;
	fix_t x1;
	fix_t y1;
	fix_t w;
	fix_t h;
	u32 col;
}

void MM_DrawLevelBox() {
	int i;
	int y;
	u32 image;
	u32 colour;
}

void MM_DrawPopup(u8 *text, rect_t *r, int bgcol) {
	int h;
	int font;
}

void MM_DrawMemFree(int x1, int y1) {
	float freemem_amount;
	u32 usecol;
	u32 bgcol;
	int font;
	u8 *s;
}

void mapmakerGfx() {
	int zbold;
	int x;
	int y;
	int phase;
	u8 *text;
	item_t *it;
	rect_t r;
	int i;
	u32 rgba;
}

fix_t FMul(fix_t a, fix_t b) {}

fix_t FDiv(fix_t a, fix_t b) {}
