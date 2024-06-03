// STATUS: NOT STARTED

#include "zbtest.h"

typedef struct {
	u32 vifcode[4];
	sceGifTag giftag;
	sceGsBitbltbuf bitbltbuf;
	u64 bitbltbufaddr;
	sceGsTrxpos trxpos;
	u64 trxposaddr;
	sceGsTrxreg trxreg;
	u64 trxregaddr;
	sceGsSignal signal;
	u64 signaladdr;
	sceGsTrxdir trxdir;
	u64 trxdiraddr;
} gsStoreImage;

struct glowinfo_s {
	int player;
	int lighttype;
	int texture;
	int type;
	float x;
	float y;
	int sizex;
	int sizey;
	u32 col;
};

typedef glowinfo_s glowinfo;
u8 *zbuffer = NULL;

static zbtestval *zbval[4] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL
};

int extraglow1type = -1;
int extraglow2type = -1;

static u8 *glowtextures[5] = {
	/* [0] = */ 0x451698,
	/* [1] = */ 0x451678,
	/* [2] = */ 0x451650,
	/* [3] = */ 0x451628,
	/* [4] = */ 0x451600
};

static int CurrentAddIndex = 0;
static int vif1done_sid = -1;
static int gs_simagenum = 0;
static int lasttestframe;
static int addptr;
static int testptr;
static int drawptr;
static int numzbvals[4];
static int zbvalsaddframe[4];
static glowinfo glows[60];
static int numglows;
static texinfo glowtex[5];
static int s_VIF1DMAHandlerID;
static gsStoreImage gs_simage[2];

static void gsExecStoreImage(gsStoreImage *sp, int sbp, int sbw, int spsm, int x, int y, int w, int h, u128 *dstaddr) {
	u128 *dstaddr;
	static u32 init_mp3[4] = {
		/* [0] = */ 0,
		/* [1] = */ 0,
		/* [2] = */ 0,
		/* [3] = */ 0
	};
	int dmasizeq;
	int sizeb;
}

void zbtestPreload() {
	int g;
}

void zbtestSetExtraGlowTypes(int type1, int type2) {}

void zbtestRestart() {
	int i;
}

void zbtestReset() {
	int i;
}

void zbtestRestartAfter() {}

void zbtestResetAfter() {}

void zbtestEnd() {
	int i;
}

void zbtestGfx() {
	int i;
	int oldzbmode;
	glowinfo *g;
	float sizey;
	int alpha;
	int glowtexwidth;
	int glowtexheight;
	float x1;
	float y1;
	float x2;
	float y2;
	float sx;
	float sy;
}

boolean zbtestStartAddGlow() {
	int i;
	zbtestval *zt;
}

void zbtestEndAddGlow() {}

u32 zbtestGetOffset(int x, int y) {}

void zbtestAddPoint(int player, void *ref, void *ref2, int x, int y, u32 expect, int Bias) {
	u32 offset;
	int AddIndex;
}

void zbtestDrawGlow(int player, int texture, int type, float x, float y, int sizex, int sizey, u32 col) {
	glowinfo *g;
}

void zbtestDrawFlareFx(int player, int type, float *worldpos, u32 alpha) {}

void zbtestAdvanceAddPtr() {}

static int vif1Handler(int ch) {}

void zbtestMake() {
	SemaParam s;
}

void zbtestCopyZB() {}

void zbtestDoTest(int Frame) {
	int i;
	int Total;
	int x;
	int y;
	boolean Found;
	zbtestval *zt;
}

boolean zbtestIsCorrectFrame() {}

boolean zbtestIsVisible(zbtestval *zt) {
	float actualscalar;
}

int zbtestGetVisibleBias(int player, void *ref, void *ref2) {
	int i;
	int num;
	zbtestval *zt;
	int j;
}
