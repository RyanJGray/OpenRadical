//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "hud.h"

enum {
	BAGICON_DEFAULT = 0,
	BAGICON_NUM = 1
};

struct spot_s {
	float ang;
	float dis;
	u32 rgba;
};

hudHealthArmourSegment hudHealth[21] = {
	/* [0] = */ {
		/* .healthArmourThreshold = */ 1.f,
		/* .gfxThreshold = */ 0.f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 0
		}
	},
	/* [1] = */ {
		/* .healthArmourThreshold = */ 0.97f,
		/* .gfxThreshold = */ 0.15f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 0
		}
	},
	/* [2] = */ {
		/* .healthArmourThreshold = */ 0.94f,
		/* .gfxThreshold = */ 0.2f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 127,
			/* [2] = */ 0
		}
	},
	/* [3] = */ {
		/* .healthArmourThreshold = */ 0.9f,
		/* .gfxThreshold = */ 0.25f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 119,
			/* [2] = */ 0
		}
	},
	/* [4] = */ {
		/* .healthArmourThreshold = */ 0.86f,
		/* .gfxThreshold = */ 0.3f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 110,
			/* [2] = */ 0
		}
	},
	/* [5] = */ {
		/* .healthArmourThreshold = */ 0.82f,
		/* .gfxThreshold = */ 0.35f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 100,
			/* [2] = */ 0
		}
	},
	/* [6] = */ {
		/* .healthArmourThreshold = */ 0.78f,
		/* .gfxThreshold = */ 0.4f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 90,
			/* [2] = */ 0
		}
	},
	/* [7] = */ {
		/* .healthArmourThreshold = */ 0.74f,
		/* .gfxThreshold = */ 0.45f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 82,
			/* [2] = */ 0
		}
	},
	/* [8] = */ {
		/* .healthArmourThreshold = */ 0.7f,
		/* .gfxThreshold = */ 0.5f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 75,
			/* [2] = */ 0
		}
	},
	/* [9] = */ {
		/* .healthArmourThreshold = */ 0.66f,
		/* .gfxThreshold = */ 0.55f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 67,
			/* [2] = */ 0
		}
	},
	/* [10] = */ {
		/* .healthArmourThreshold = */ 0.62f,
		/* .gfxThreshold = */ 0.6f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 60,
			/* [2] = */ 0
		}
	},
	/* [11] = */ {
		/* .healthArmourThreshold = */ 0.57f,
		/* .gfxThreshold = */ 0.64f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 52,
			/* [2] = */ 0
		}
	},
	/* [12] = */ {
		/* .healthArmourThreshold = */ 0.53f,
		/* .gfxThreshold = */ 0.68f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 45,
			/* [2] = */ 0
		}
	},
	/* [13] = */ {
		/* .healthArmourThreshold = */ 0.48f,
		/* .gfxThreshold = */ 0.73f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 37,
			/* [2] = */ 0
		}
	},
	/* [14] = */ {
		/* .healthArmourThreshold = */ 0.43f,
		/* .gfxThreshold = */ 0.75f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 30,
			/* [2] = */ 0
		}
	},
	/* [15] = */ {
		/* .healthArmourThreshold = */ 0.37f,
		/* .gfxThreshold = */ 0.78f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 25,
			/* [2] = */ 0
		}
	},
	/* [16] = */ {
		/* .healthArmourThreshold = */ 0.3f,
		/* .gfxThreshold = */ 0.81f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 20,
			/* [2] = */ 0
		}
	},
	/* [17] = */ {
		/* .healthArmourThreshold = */ 0.2f,
		/* .gfxThreshold = */ 0.84f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 20,
			/* [2] = */ 0
		}
	},
	/* [18] = */ {
		/* .healthArmourThreshold = */ 0.1f,
		/* .gfxThreshold = */ 0.87f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 10,
			/* [2] = */ 0
		}
	},
	/* [19] = */ {
		/* .healthArmourThreshold = */ 0.0001f,
		/* .gfxThreshold = */ 0.9f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 10,
			/* [2] = */ 0
		}
	},
	/* [20] = */ {
		/* .healthArmourThreshold = */ 0.f,
		/* .gfxThreshold = */ 1.f,
		/* .col = */ {
			/* [0] = */ 127,
			/* [1] = */ 0,
			/* [2] = */ 0
		}
	}
};

hudHealthArmourSegment hudArmour[21] = {
	/* [0] = */ {
		/* .healthArmourThreshold = */ 1.f,
		/* .gfxThreshold = */ 0.f,
		/* .col = */ {
			/* [0] = */ 54,
			/* [1] = */ 127,
			/* [2] = */ 0
		}
	},
	/* [1] = */ {
		/* .healthArmourThreshold = */ 0.95f,
		/* .gfxThreshold = */ 0.05f,
		/* .col = */ {
			/* [0] = */ 52,
			/* [1] = */ 120,
			/* [2] = */ 5
		}
	},
	/* [2] = */ {
		/* .healthArmourThreshold = */ 0.9f,
		/* .gfxThreshold = */ 0.1f,
		/* .col = */ {
			/* [0] = */ 51,
			/* [1] = */ 115,
			/* [2] = */ 10
		}
	},
	/* [3] = */ {
		/* .healthArmourThreshold = */ 0.85f,
		/* .gfxThreshold = */ 0.15f,
		/* .col = */ {
			/* [0] = */ 49,
			/* [1] = */ 107,
			/* [2] = */ 20
		}
	},
	/* [4] = */ {
		/* .healthArmourThreshold = */ 0.8f,
		/* .gfxThreshold = */ 0.2f,
		/* .col = */ {
			/* [0] = */ 48,
			/* [1] = */ 100,
			/* [2] = */ 30
		}
	},
	/* [5] = */ {
		/* .healthArmourThreshold = */ 0.75f,
		/* .gfxThreshold = */ 0.25f,
		/* .col = */ {
			/* [0] = */ 46,
			/* [1] = */ 95,
			/* [2] = */ 35
		}
	},
	/* [6] = */ {
		/* .healthArmourThreshold = */ 0.7f,
		/* .gfxThreshold = */ 0.3f,
		/* .col = */ {
			/* [0] = */ 44,
			/* [1] = */ 90,
			/* [2] = */ 40
		}
	},
	/* [7] = */ {
		/* .healthArmourThreshold = */ 0.65f,
		/* .gfxThreshold = */ 0.35f,
		/* .col = */ {
			/* [0] = */ 43,
			/* [1] = */ 82,
			/* [2] = */ 45
		}
	},
	/* [8] = */ {
		/* .healthArmourThreshold = */ 0.6f,
		/* .gfxThreshold = */ 0.4f,
		/* .col = */ {
			/* [0] = */ 42,
			/* [1] = */ 75,
			/* [2] = */ 50
		}
	},
	/* [9] = */ {
		/* .healthArmourThreshold = */ 0.55f,
		/* .gfxThreshold = */ 0.45f,
		/* .col = */ {
			/* [0] = */ 41,
			/* [1] = */ 65,
			/* [2] = */ 57
		}
	},
	/* [10] = */ {
		/* .healthArmourThreshold = */ 0.5f,
		/* .gfxThreshold = */ 0.5f,
		/* .col = */ {
			/* [0] = */ 40,
			/* [1] = */ 55,
			/* [2] = */ 65
		}
	},
	/* [11] = */ {
		/* .healthArmourThreshold = */ 0.45f,
		/* .gfxThreshold = */ 0.55f,
		/* .col = */ {
			/* [0] = */ 39,
			/* [1] = */ 53,
			/* [2] = */ 72
		}
	},
	/* [12] = */ {
		/* .healthArmourThreshold = */ 0.4f,
		/* .gfxThreshold = */ 0.6f,
		/* .col = */ {
			/* [0] = */ 38,
			/* [1] = */ 50,
			/* [2] = */ 80
		}
	},
	/* [13] = */ {
		/* .healthArmourThreshold = */ 0.35f,
		/* .gfxThreshold = */ 0.65f,
		/* .col = */ {
			/* [0] = */ 37,
			/* [1] = */ 47,
			/* [2] = */ 85
		}
	},
	/* [14] = */ {
		/* .healthArmourThreshold = */ 0.3f,
		/* .gfxThreshold = */ 0.7f,
		/* .col = */ {
			/* [0] = */ 36,
			/* [1] = */ 45,
			/* [2] = */ 90
		}
	},
	/* [15] = */ {
		/* .healthArmourThreshold = */ 0.25f,
		/* .gfxThreshold = */ 0.75f,
		/* .col = */ {
			/* [0] = */ 35,
			/* [1] = */ 43,
			/* [2] = */ 95
		}
	},
	/* [16] = */ {
		/* .healthArmourThreshold = */ 0.2f,
		/* .gfxThreshold = */ 0.8f,
		/* .col = */ {
			/* [0] = */ 34,
			/* [1] = */ 40,
			/* [2] = */ 100
		}
	},
	/* [17] = */ {
		/* .healthArmourThreshold = */ 0.15f,
		/* .gfxThreshold = */ 0.85f,
		/* .col = */ {
			/* [0] = */ 33,
			/* [1] = */ 37,
			/* [2] = */ 105
		}
	},
	/* [18] = */ {
		/* .healthArmourThreshold = */ 0.1f,
		/* .gfxThreshold = */ 0.9f,
		/* .col = */ {
			/* [0] = */ 32,
			/* [1] = */ 35,
			/* [2] = */ 110
		}
	},
	/* [19] = */ {
		/* .healthArmourThreshold = */ 0.05f,
		/* .gfxThreshold = */ 0.95f,
		/* .col = */ {
			/* [0] = */ 31,
			/* [1] = */ 33,
			/* [2] = */ 115
		}
	},
	/* [20] = */ {
		/* .healthArmourThreshold = */ 0.f,
		/* .gfxThreshold = */ 1.f,
		/* .col = */ {
			/* [0] = */ 30,
			/* [1] = */ 30,
			/* [2] = */ 120
		}
	}
};

static char* DEFAULT = "icon";
static u8 *bagiconfiles[BAGICON_NUM] = {
	/* [0] = */ (u8*)&"icon",
};

hudparms_t hudparms = {0};

static float bludangle;
static int txbag;
static int bagicon;
static int txammo[17];
static char *txfilenames[17];
static int numHudHealthArmourData;
static hudHealthArmourData healthArmourData[17];
static int maxMessages[6];

static u8* hudGetBagIconFileName(int bagicon) {}

void hudPreload() {
	int i;
	setupheader *setup;
	setuppickup *sp;
}

void hudRestart() {
	int i;
}

void hudReset() {}

hudHealthArmourData* hudAllocHealthArmourData() {}

void hudResetHealthArmourData(hudHealthArmourData *haData, prop *p) {
	int seg;
	chrdata *cd;
}

void hudRestartMessages() {
	int t;
}

void hudAddMessage(int localnum, int type, u8 *message, float delay) {
	hudplrparms_t *hudplr;
	hudMessage *msg;
	int m;
	int previous;
	hudMessage *testMsg;
}

void hudObjectiveMessage(int localnum, objective_s *obj, float delay) {
	hudplrparms_t *hudplr;
	hudMessage *msg;
}

void hudClearAllMessages(int localplayer) {
	hudplrparms_t *hudplr;
	int m;
}

void hudClearMessages(int localplayer, int type) {
	hudplrparms_t *hudplr;
	int m;
}

void hudMainMessageGfx(hudMessage *msg) {
	float scalar;
	int xc;
	int yc;
	int width;
	int height;
}

void hudFadeMessageGfx(hudMessage *msg) {
	u32 alpha;
	u32 fgcol;
	u32 bgcol;
	float alphaf;
}

int hudGetSmallMessageY() {
	int y;
}

void hudSmallFadeMessageGfx(hudMessage *msg, float offsetScalar) {
	int x1;
	u32 alpha;
	u32 fgcol;
	u32 bgcol;
	float alphaf;
}

void hudObjectiveMessageGfx(hudMessage *msg) {
	int y;
	u32 alpha;
	float alphaf;
	float timeScalar;
}

void hudScrollMessageGfx(hudMessage *msg) {
	int y1;
	int xofs;
	int font;
	int pos;
	int numlines;
	int len;
	u32 fg;
	u32 bg;
	u8 *newline;
}

void hudMessagesTick() {
	hudplrparms_t *hudplr;
	float secpassed;
	int t;
	int m;
	int numMessages[6];
	int numMessagesBefore[6];
	int c;
	hudMessage *msg;
	int c;
	hudMessage *msg;
	int c;
	hudMessage *msg;
}

void hudMessagesGfx() {
	hudplrparms_t *hudplr;
	int t;
	int m;
	int numMessagesBefore[6];
	float smallFadeAmount;
	int c;
	hudMessage *msg;
	float moveUpTime;
}

void hudKillMessage(chrdata *attackerchr) {
	int p;
	u8 *msg;
}

void hudTick() {
	hudplrparms_t *hudplr;
	float secpassed;
}

void hudShowScore(int playernum, int time) {
	hudplrparms_t *hudp;
}

static void drawTitleBox(u8 *text, int x1, int y1, int width, int height, u32 bgcolour) {
	int font;
	int x2;
	int y2;
	int texture;
}

static void hudBaseGfx() {
	int i;
	int x;
	int y;
	int h;
	int life;
	int xmid;
	int y1;
	u32 colour;
}

static void drawValueBox(u8 *head, u8 *sub, int x1, int y1, int width, int height, u32 boxcolour, u32 subcolour, int fixedwidthscore) {
	int fixedwidthscore;
	int font;
	int y2;
	int ymid;
}

static int hudScoreWidth() {}

static void hudScoreGfx(chrdata *chr, int basey, int ofsx, u32 alpha) {
	u8 *head;
	int xo;
	int w;
	u32 subcol;
	int value;
}

static void hudChallengeTimeLeftGfx(int basey) {
	int x;
}

static boolean hudChallengeScoreGfx(int basey) {
	u8 *head;
	u8 *sub;
	int x;
}

static void hudLSScoreGfx(chrdata *chr, int basey, int ofsx) {
	int x;
}

static void hudRankGfx(chrdata *chr, int basey, int ofsx) {
	static u8 *nth[5][4] = {
		/* [0] = */ {
			/* [0] = */ 0x45de18,
			/* [1] = */ 0x45de10,
			/* [2] = */ 0x45de08,
			/* [3] = */ 0x45de00
		},
		/* [1] = */ {
			/* [0] = */ 0x45ddf8,
			/* [1] = */ 0x45ddf0,
			/* [2] = */ 0x45dde8,
			/* [3] = */ 0x45dde0
		},
		/* [2] = */ {
			/* [0] = */ 0x45ddd8,
			/* [1] = */ 0x45ddd0,
			/* [2] = */ 0x45ddc8,
			/* [3] = */ 0x45ddc0
		},
		/* [3] = */ {
			/* [0] = */ 0x45ddd8,
			/* [1] = */ 0x45ddd0,
			/* [2] = */ 0x45ddc8,
			/* [3] = */ 0x45ddc0
		},
		/* [4] = */ {
			/* [0] = */ 0x45ddd8,
			/* [1] = */ 0x45ddd0,
			/* [2] = */ 0x45ddc8,
			/* [3] = */ 0x45ddc0
		}
	};
	int x;
	int rank;
	u8 *s;
}

static void hudBagIconGfx(int basey) {
	chrdata *cd;
	pickupdata *pd;
	int x;
	int w;
	int h;
	u32 bagcol;
}

static void hudKeycardGfx(int basey) {
	chrdata *cd;
	int x;
	int w;
	int h;
	int iKey;
	int texture;
	u32 keycol;
}

void hudAmmoIcon(int ammoType, int x, int y) {
	int w;
	int h;
}

static void hudAmmoGfx(chrdata *chr, remotedata *rd, chrgun *gun, boolean right, int marginx, int marginbottom) {
	int x;
	int y;
	u8 *text;
	gunInfo_t *gi;
	int fireMode;
	int basex;
	int ammoType;
	int clipCount;
	boolean bar;
	int ammo;
	int offset;
	float amount;
}

static void hudMinesGfx(prop *p, int y) {
	int x;
	int xend;
	int yend;
	int ygap;
	int proximitymines;
	int remotemines;
	int timedmines;
	int splitx;
	int num;
	int w;
	int h;
	int whitecol;
	int num;
	int w;
	int h;
	int whitecol;
	int num;
	int w;
	int h;
	int whitecol;
}

static int hudRadarGfx() {
	int texture;
	int i;
	int n;
	float cx;
	float cy;
	float radarsize;
	float angle;
	hudplrparms_t *hudplr;
	float radarRot;
	static spot_s spots[78];
	float px;
	float pz;
	prop *prop;
	float px;
	float pz;
	prop *prop;
	float px;
	float pz;
	float fcos;
	float fsin;
	float x;
	float y;
	u32 rgba;
	float radarNextRot;
	float x;
	float y;
	float x2;
	float y2;
	float pos1[3];
	float pos2[3];
	float pos3[3];
	float pos4[3];
}

void hudPainGfx(u32 rgba, float bludang) {
	int pts[190];
	float xrad1;
	float xrad2;
	float yrad1;
	float yrad2;
	float angle;
	int i;
	int *ppts;
	float bludfrad;
	float frad;
	float fcos;
	float fsin;
	int x;
	int y;
	int bludx;
	int bludy;
}

void hudMeterTick() {
	hudplrparms_t *hudplr;
	int m;
}

void hudDrawFixedGunMeter(int barLeft, int top, int barRight, int bottom, int meter, u8 *title) {
	hudplrparms_t *hudplr;
	int height;
	int healthY;
	int oldHealthY;
	int b;
	int middle;
}

void hudFixedGunGfx() {
	int texture;
	int left;
	int right;
	int top;
	int bottom;
	int width;
	int height;
	int xDistInMain;
	int yDistInMain;
	int offsetx;
	int offsety;
	int e;
	float step;
	u8 *s;
	int yIn;
	float dist;
	int xIn;
	float dist;
}

void hudRemoteDeviceGfx() {
	int texture;
	int left;
	int right;
	int top;
	int bottom;
	int width;
	int height;
	int xDistInMain;
	int yDistInMain;
	int offsetx;
	int offsety;
	int e;
	float step;
	u8 *s;
	chrdata *cd;
	remotedata *rd;
	int yIn;
	float dist;
	int xIn;
	float dist;
}

void hudDrawCrossHair() {
	hudplrparms_t *hudplr;
	int midx;
	int midy;
	int rangex;
	int rangey;
	int x;
	int y;
	int xOffset;
	int yOffset;
	int xLineOffset;
	int yLineOffset;
	int x1;
	int y1;
	int x2;
	int y2;
	int xLine1;
	int yLine1;
	int xLine2;
	int yLine2;
	int texture;
	int texwidth;
	int texheight;
	u32 sightrgba;
	int texture;
	u32 sightrgba;
	int texture;
}

boolean hudShouldShowGuns() {
	hudplrparms_t *hudplr;
}

void hudFRDLogoGfx(int offsety) {
	int texture;
	u32 alpha;
}

void hudFlyIntroText() {
	int x;
	int y;
	u8 *s;
}

void hudGfx() {
	hudplrparms_t *hudplr;
	int logoOffsetY;
	u32 colour[4];
	int value;
	int curdispy;
	int ofsx;
	int time;
	int width;
	u32 scoreAlpha;
	chrdata *cd;
	int topry;
	int ammoHeightFromBottom;
	remotedata *rd;
	int x1;
	int y1;
	int life;
	u32 lifecol;
	int y1;
	int time;
	u8 *dText;
	static int flashcount = 0;
	int x1;
	int font;
}

void hudEnd() {}

void hudSetDamage(int localplayer, float damage) {
	hudplrparms_t *hudplr;
}

void hudAddDamage(int localplayer, float damage) {
	hudplrparms_t *hudplr;
}

void hudPlayerSpawn(player *pl) {}

void hudHealthArmourTick(hudHealthArmourData *haData, prop *p) {
	float secpassed;
	int seg;
	int healthOn;
	int armourOn;
	chrdata *cd;
}

void hudPropHealthBarGfx(prop *p, u8 *s, int x1, int y1, int x2, int y2, u32 barOnAlpha, u32 barOffAlpha) {
	int width;
	int height;
	int middley;
	int seg;
	float step;
	hudHealthArmourSegment *hudSeg;
	hudHealthArmourSegment *hudSegNext;
	u32 abgrStart;
	u32 abgrEnd;
	int rOn;
	int gOn;
	int bOn;
	int rOff;
	int gOff;
	int bOff;
	int r;
	int g;
	int b;
	u32 alpha;
	boolean segOn;
	float segmentIntensity;
	int xS;
	int xE;
}

void hudPlayerHealthBarGfx() {
	hudHealthArmourData *haData;
	float upintensity;
}

float hudGetHealthSegmentIntensity(hudHealthArmourData *haData, int segment) {
	float timeScalar;
}

float hudGetArmourSegmentIntensity(hudHealthArmourData *haData, int segment) {
	float timeScalar;
}

float hudGetSegmentIntensity(int type, hudHealthArmourData *haData, int segment) {}

void hudIgmPlayerHealthGfx(hudHealthArmourData *haData, float movex, float movey, float scale, u32 barOnAlpha, u32 barOffAlpha, u32 borderAlpha) {
	float normalHalfWidth;
	float normalHalfHeight;
	float mx;
	float sx;
	float ex;
	float my;
	float sy;
	float ey;
	int texture;
	int texwidth;
	int texheight;
	int rgba;
	int pass;
	int type;
	u32 *ref;
	int seg;
	int halfSegments;
	boolean segOn;
	hudHealthArmourSegment *hudSeg;
	hudHealthArmourSegment *hudSegNext;
	float segmentIntensity;
	float texXStart;
	float texXEnd;
	float texYStart;
	float texYEnd;
	float xStart;
	float xEnd;
	int rOn;
	int gOn;
	int bOn;
	int rOff;
	int gOff;
	int bOff;
	int r;
	int g;
	int b;
	float ysize;
	float yStart;
	float yEnd;
	u32 abgrStart;
	u32 abgrEnd;
	u32 alpha;
	float thisSegmentIntensity;
	float halfNext;
	float nextSegmentIntensity;
	float nextNextSegmentIntensity;
	void *addr;
}

void hudPropApacheLaunchers(u8 *s, int x1, int y1, int x2, int y2) {
	int width;
	int height;
	int middley;
	int seg;
	float step;
	int xS;
	u32 rgbaBg;
	u32 rgbaFg;
}
