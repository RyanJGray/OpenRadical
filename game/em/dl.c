// STATUS: NOT STARTED

#include "dl.h"

static int zbmode = -1;
static int dlBlendMode = -1;
static u32 dlFixedRGBA = 65535;
dlDmaTag *pushgfxtag = NULL;

u32 ucodestart[6][2] = {
	/* [0] = */ {
		/* [0] = */ 0,
		/* [1] = */ 1480
	},
	/* [1] = */ {
		/* [0] = */ 440,
		/* [1] = */ 440
	},
	/* [2] = */ {
		/* [0] = */ 800,
		/* [1] = */ 800
	},
	/* [3] = */ {
		/* [0] = */ 1000,
		/* [1] = */ 1000
	},
	/* [4] = */ {
		/* [0] = */ 1400,
		/* [1] = */ 1400
	},
	/* [5] = */ {
		/* [0] = */ 1200,
		/* [1] = */ 1200
	}
};

u32 ucode_loadxyzw[6] = {
	/* [0] = */ 8,
	/* [1] = */ 8,
	/* [2] = */ 8,
	/* [3] = */ 8,
	/* [4] = */ 8,
	/* [5] = */ 8
};

u32 ucode_loadst[6] = {
	/* [0] = */ 80,
	/* [1] = */ 80,
	/* [2] = */ 80,
	/* [3] = */ 80,
	/* [4] = */ 80,
	/* [5] = */ 68
};

u32 ucode_loadrgba[6] = {
	/* [0] = */ 152,
	/* [1] = */ 152,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0
};

u32 ucode_loadnorm[6] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 152,
	/* [3] = */ 152,
	/* [4] = */ 152,
	/* [5] = */ 128
};

static u32 texturekick[24] = {
	/* [0] = */ 32768,
	/* [1] = */ 32771,
	/* [2] = */ 16384,
	/* [3] = */ 1042,
	/* [4] = */ 0,
	/* [5] = */ 32776,
	/* [6] = */ 32768,
	/* [7] = */ 0,
	/* [8] = */ 0,
	/* [9] = */ 0,
	/* [10] = */ 32768,
	/* [11] = */ 0,
	/* [12] = */ 0,
	/* [13] = */ 0,
	/* [14] = */ 32768,
	/* [15] = */ 0,
	/* [16] = */ 0,
	/* [17] = */ 0,
	/* [18] = */ 49304,
	/* [19] = */ 65535,
	/* [20] = */ 65535,
	/* [21] = */ 65535,
	/* [22] = */ 0,
	/* [23] = */ 0
};

static u32 cliptagvifpackets[2][8] = {
	/* [0] = */ {
		/* [0] = */ 49152,
		/* [1] = */ 1042,
		/* [2] = */ 0,
		/* [3] = */ 32768,
		/* [4] = */ 0,
		/* [5] = */ 0,
		/* [6] = */ 0,
		/* [7] = */ 1964
	},
	/* [1] = */ {
		/* [0] = */ 49152,
		/* [1] = */ 1042,
		/* [2] = */ 0,
		/* [3] = */ 32768,
		/* [4] = */ 0,
		/* [5] = */ 0,
		/* [6] = */ 0,
		/* [7] = */ 1964
	}
};

static u32 zbvifpackets[7][12] = {
	/* [0] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 1,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	},
	/* [1] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 0,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	},
	/* [2] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 1,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	},
	/* [3] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 0,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	},
	/* [4] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 779,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 0,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	},
	/* [5] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 49152,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 1,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	},
	/* [6] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 0,
		/* [4] = */ 0,
		/* [5] = */ 71,
		/* [6] = */ 0,
		/* [7] = */ 224,
		/* [8] = */ 0,
		/* [9] = */ 78,
		/* [10] = */ 0,
		/* [11] = */ 2042
	}
};

static u32 dlSetBlendVif[9][16] = {
	/* [0] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 136,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [1] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 68,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [2] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 72,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [3] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 65,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [4] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 9,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [5] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 73,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [6] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 70,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [7] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 8,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	},
	/* [8] = */ {
		/* [0] = */ 0,
		/* [1] = */ 14,
		/* [2] = */ 0,
		/* [3] = */ 129,
		/* [4] = */ 0,
		/* [5] = */ 66,
		/* [6] = */ 0,
		/* [7] = */ 0,
		/* [8] = */ 0,
		/* [9] = */ 73,
		/* [10] = */ 0,
		/* [11] = */ 0,
		/* [12] = */ 0,
		/* [13] = */ 59,
		/* [14] = */ 0,
		/* [15] = */ 2042
	}
};

static u32 texrect_begin[4] = {
	/* [0] = */ 32769,
	/* [1] = */ 16384,
	/* [2] = */ 13617,
	/* [3] = */ 0
};

static u32 dlFixedRGBA_Pending;

void dlSignal(u32 sigid) {
	u32 *ref;
	void *addr;
}

void dlSelectTextureKick(int num) {
	emTexture *pTex;
	void *addr;
}

void dlSelectTextureDB(int num) {
	emTexture *pTex;
	void *addr;
}

void dlSelectTextureKickDB(int num) {}

void dlSetClipTag(int textured) {}

int dlSetZB(int mode) {
	int oldmode;
}

void dlLabel(u32 id) {
	u32 *ref;
	void *addr;
}

void dlFBA(u32 destinationAlpha) {
	u32 *ref;
	void *addr;
}

void dlSetFrame(u32 noBufferUpdate) {
	u32 *ref;
	void *addr;
}

void dlSetFixedRGBA(u32 rgba) {}

int dlSetBlend(int mode) {
	int oldmode;
	u32 *ref;
	void *addr;
}

void dlSetClip(int left, int top, int right, int bottom) {
	u32 *ref;
	void *addr;
}

void dlClearFB(int x1, int y1, int x2, int y2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlSetFBMSK(int mask) {
	sceGsDrawEnv1 *p_env;
	sceGsFrame frame_reg;
	u32 *ref;
	void *addr;
}

void dlFillRectangle(int x1, int y1, int x2, int y2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlFillRectangleFloat(float x1, float y1, float x2, float y2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlFillRectangleColFloat(float x1, float y1, float x2, float y2, u32 abgrTL, u32 abgrTR, u32 abgrBL, u32 abgrBR) {
	u32 *ref;
	void *addr;
}

void dlFillQuad3D(float *pos1, float *pos2, float *pos3, float *pos4, u32 abgr1, u32 abgr2, u32 abgr3, u32 abgr4) {
	u32 *ref;
	void *addr;
}

void dlDrawPoint(int x, int y, int rgba) {
	u32 *ref;
	void *addr;
}

void dlDrawLine(int x1, int y1, int x2, int y2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlDrawLineFloat(float x1, float y1, float x2, float y2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlDrawAALine(int x1, int y1, int x2, int y2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlDrawTriangleStrip(int *rgbaxy, int numpts, boolean textured) {
	int i;
	u32 *ref;
	void *addr;
	u32 vif2;
	u32 rgba;
	float x;
	float y;
}

void dlTextureRectangle(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, int rgba) {
	int rgba;
	u32 *ref;
	void *addr;
}

void dlTextureRectangleZ(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, int rgba, float cameraZ) {
	int rgba;
	u32 *ref;
	int z;
	void *addr;
}

void dlTextureRectangleFloat(float x1, float y1, float x2, float y2, int u1, int v1, int u2, int v2, int rgba) {
	u32 *ref;
	void *addr;
}

void dlTextureRectangleFloatZ(float x1, float y1, float x2, float y2, int u1, int v1, int u2, int v2, int rgba, float cameraZ) {
	u32 *ref;
	int z;
	void *addr;
}

void dlTextureRectangleColFloat(float x1, float y1, float x2, float y2, int u1, int v1, int u2, int v2, u32 abgrTL, u32 abgrTR, u32 abgrBL, u32 abgrBR) {
	int u1a;
	int u2a;
	int v1a;
	int v2a;
	u32 *ref;
	void *addr;
}

void dlTextureQuadFloatZ(float z, float xTL, float yTL, float xTR, float yTR, float xBL, float yBL, float xBR, float yBR, int uTL, int vTL, int uTR, int vTR, int uBL, int vBL, int uBR, int vBR, u32 abgrTL, u32 abgrTR, u32 abgrBL, u32 abgrBR) {
	float yBR;
	u32 abgrTL;
	u32 abgrTR;
	u32 abgrBL;
	u32 abgrBR;
	u32 *ref;
	void *addr;
}

void dlTextureQuad3D(int texturenum, float *pos1, float *pos2, float *pos3, float *pos4, u32 abgr1, u32 abgr2, u32 abgr3, u32 abgr4, float u1, float v1, float u2, float v2) {
	u32 abgr4;
	u32 *ref;
	int num;
	emTexture *pTex;
	void *addr;
	void *addr;
}

void dlPushDmaTag(dlDmaTag *push) {}

void dlPopDmaTag() {}

void dlSetPerspectiveMatrix(mtx_u *mtx) {
	u32 *ref;
	void *addr;
	u32 vif2;
}
