// STATUS: NOT STARTED

#include "inflate.h"

struct huft {
	u8 e;
	u8 b;
	union {
		u16 n;
		huft *t;
	} v;
};

static u32 border[0] = {
};

static u16 cplens[0] = {
};

static u16 cplext[0] = {
};

static u16 cpdist[0] = {
};

static u16 cpdext[0] = {
};

static u16 mask_bits[0] = {
};

static int lbits = 9;
static int dbits = 6;
static u8 *spadalloc;
static u8 *inbuf;
static u32 inptr;
static u32 insize;
static u8 *slide;
static u32 outcnt;
static u32 bytes_out;
static u8 *bufferout;
static u32 bb;
static u32 bk;

static void* AllocMem(u32 nbytes) {
	u8 *ptr;
}

static void AllocReset() {}

static int huft_build(u32 *b, u32 n, u32 s, u16 *d, u16 *e, huft **t, int *m) {
	u32 a;
	u32 c[17];
	u32 f;
	int g;
	int h;
	u32 i;
	u32 j;
	int k;
	int l;
	u32 *p;
	huft *q;
	huft r;
	huft *u[16];
	u32 v[288];
	int w;
	u32 x[17];
	u32 *xp;
	int y;
	u32 z;
}

static int inflate_codes(huft *tl, huft *td, int bl, int bd) {
	u32 e;
	u32 n;
	u32 d;
	u32 w;
	huft *t;
	u32 ml;
	u32 md;
	u32 b;
	u32 k;
}

static int inflate_stored() {
	u32 n;
	u32 w;
	u32 b;
	u32 k;
}

static int inflate_fixed() {
	int i;
	huft *tl;
	huft *td;
	int bl;
	int bd;
	u32 l[288];
}

static int inflate_dynamic() {
	int i;
	u32 j;
	u32 l;
	u32 m;
	u32 n;
	huft *tl;
	huft *td;
	int bl;
	int bd;
	u32 nb;
	u32 nl;
	u32 nd;
	u32 ll[316];
	u32 b;
	u32 k;
}

static int inflate_block(int *e) {
	u32 t;
	u32 b;
	u32 k;
}

static void FlushOut() {}

static void GetHeader() {
	u8 magic[2];
	u32 len;
}

static int Inflate() {
	int e;
}

int fileInflate(u8 *gzippos, int gzipsize, u8 *destbuffer) {}
