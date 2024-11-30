// STATUS: NOT STARTED

#include "mm_gen.h"

typedef enum {
	D_NORTH = 0,
	D_EAST = 1,
	D_SOUTH = 2,
	D_WEST = 3,
	D_NUM = 4
};

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
} coord_t;

struct tinfo_s {
	s8 tile;
	s8 rot;
	u8 occ;
	s8 traffic;
};

typedef tinfo_s tinfo_t;

typedef struct {
	int dx;
	int dy;
	u8 doorbit;
} d_info_t;

typedef struct {
	s16 startx;
	s16 starty;
	s16 d_dir;
	s16 length;
	s16 connectlength;
	s16 plugs;
	s16 connectplugs;
	s16 intersections;
	float ratio;
	float connectratio;
} branch_t;

struct pos_s {
	s8 x;
	s8 y;
	u8 rotation;
	u8 score;
};

typedef enum {
	NORTH = 1,
	EAST = 2,
	SOUTH = 4,
	WEST = 8
};

static d_info_t d_info[4] = {
	/* [0] = */ {
		/* .dx = */ 0,
		/* .dy = */ -1,
		/* .doorbit = */ 1
	},
	/* [1] = */ {
		/* .dx = */ 1,
		/* .dy = */ 0,
		/* .doorbit = */ 2
	},
	/* [2] = */ {
		/* .dx = */ 0,
		/* .dy = */ 1,
		/* .doorbit = */ 4
	},
	/* [3] = */ {
		/* .dx = */ -1,
		/* .dy = */ 0,
		/* .doorbit = */ 8
	}
};

static int starttiles[0] = {
};

static int roomtiles[0] = {
};

static int xinc[0] = {
};

static int yinc[0] = {
};

static tinfo_t maptinfo[12][12];
static branch_t branches[64];
static int numbranches;

static void shootroute(int x, int y, int d_dir) {
	int iRouteLength;
	int iRoutePlugs;
	int startx;
	int starty;
	int tx;
	int ty;
	int tdir;
}

static void crossroad(int x, int y, int d_dir) {
	int dir;
	int i;
}

static void getcoord(branch_t *b, coord_t *c) {}

static void connectroutes() {
	int i;
	int j;
	int k;
	int total;
	int numselectroutes;
	branch_t *sortedroutes[8];
	float sortedratios[8];
	branch_t *b;
	coord_t c1;
	branch_t *b2;
	coord_t c2;
	float ratio;
	branch_t *b;
	int x;
	int y;
	branch_t *b;
	int x;
	int y;
	int x;
	int y;
	u8 doorways;
	branch_t *b;
	int x;
	int y;
	int tile;
	int rot;
}

static int checkPlacement(int tilenum, int x, int y, int rot) {
	tiledef *pTile;
	int i;
	int xi;
	int yi;
	int w;
	int h;
	int numplugged;
	u8 *cells;
	u8 doors;
}

static void placeTile(int tilenum, int x, int y, int rot) {
	tiledef *pTile;
	int i;
	int xi;
	int yi;
	int w;
	int h;
	u8 *cells;
}

static void mapcreate(int numcells) {
	int bricks;
	int tilenum;
	int rot;
	int i;
	int x;
	int y;
	pos_s q_data[32];
	int q_head;
	int q_size;
	int ri;
	int score;
	pos_s *p;
}

static void mapconvert() {
	int x;
	int y;
	object_t *ob;
}

static void mazecreate(u8 *cells, int cols, int rows) {
	int x;
	int y;
	int i;
	int xnew;
	int ynew;
	int dirx;
	int diry;
	int count;
	int d;
	boolean hunt;
	int xmaz;
	int ymaz;
}

static void mazeconvert(u8 *cells, int cols, int rows) {
	int x;
	int y;
	int xmaz;
	fix_t mx;
	fix_t my;
	int i;
	u8 poo[64];
	int wallmask;
	int tilenum;
	int tilerot;
	object_t *ob;
}

void MM_GenerateMap(int type, int size, int lights) {
	int cols;
	int rows;
	int xmaz;
	int ymaz;
	int bufsize;
	u8 *temp;
	int cells;
}
