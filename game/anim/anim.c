// STATUS: NOT STARTED

#include "anim.h"

static int animMTX_stackpos = 0;
static int animMTX_offset = 0;
static u8 *animtagsBuffer = NULL;
static int calOverwrite = 0;
animRawHeader_t *csAnimHeader = NULL;

animRawHeader_t *animHeaders[5] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL
};

static int animHeaderIndex = 0;
static int loadedgamepak = 0;

skeleton skeletons[5] = {
	/* [0] = */ {
		/* .matrices = */ NULL,
		/* .ad = */ NULL,
		/* .id = */ 0,
		/* .type = */ 0,
		/* .bindfile = */ NULL
	},
	/* [1] = */ {
		/* .matrices = */ NULL,
		/* .ad = */ NULL,
		/* .id = */ 0,
		/* .type = */ 0,
		/* .bindfile = */ NULL
	},
	/* [2] = */ {
		/* .matrices = */ NULL,
		/* .ad = */ NULL,
		/* .id = */ 0,
		/* .type = */ 0,
		/* .bindfile = */ NULL
	},
	/* [3] = */ {
		/* .matrices = */ NULL,
		/* .ad = */ NULL,
		/* .id = */ 0,
		/* .type = */ 0,
		/* .bindfile = */ NULL
	},
	/* [4] = */ {
		/* .matrices = */ NULL,
		/* .ad = */ NULL,
		/* .id = */ 0,
		/* .type = */ 0,
		/* .bindfile = */ NULL
	}
};

animInfoProp *pAnimations[168] = {
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
	/* [29] = */ NULL,
	/* [30] = */ NULL,
	/* [31] = */ NULL,
	/* [32] = */ NULL,
	/* [33] = */ NULL,
	/* [34] = */ NULL,
	/* [35] = */ NULL,
	/* [36] = */ NULL,
	/* [37] = */ NULL,
	/* [38] = */ NULL,
	/* [39] = */ NULL,
	/* [40] = */ NULL,
	/* [41] = */ NULL,
	/* [42] = */ NULL,
	/* [43] = */ NULL,
	/* [44] = */ NULL,
	/* [45] = */ NULL,
	/* [46] = */ NULL,
	/* [47] = */ NULL,
	/* [48] = */ NULL,
	/* [49] = */ NULL,
	/* [50] = */ NULL,
	/* [51] = */ NULL,
	/* [52] = */ NULL,
	/* [53] = */ NULL,
	/* [54] = */ NULL,
	/* [55] = */ NULL,
	/* [56] = */ NULL,
	/* [57] = */ NULL,
	/* [58] = */ NULL,
	/* [59] = */ NULL,
	/* [60] = */ NULL,
	/* [61] = */ NULL,
	/* [62] = */ NULL,
	/* [63] = */ NULL,
	/* [64] = */ NULL,
	/* [65] = */ NULL,
	/* [66] = */ NULL,
	/* [67] = */ NULL,
	/* [68] = */ NULL,
	/* [69] = */ NULL,
	/* [70] = */ NULL,
	/* [71] = */ NULL,
	/* [72] = */ NULL,
	/* [73] = */ NULL,
	/* [74] = */ NULL,
	/* [75] = */ NULL,
	/* [76] = */ NULL,
	/* [77] = */ NULL,
	/* [78] = */ NULL,
	/* [79] = */ NULL,
	/* [80] = */ NULL,
	/* [81] = */ NULL,
	/* [82] = */ NULL,
	/* [83] = */ NULL,
	/* [84] = */ NULL,
	/* [85] = */ NULL,
	/* [86] = */ NULL,
	/* [87] = */ NULL,
	/* [88] = */ NULL,
	/* [89] = */ NULL,
	/* [90] = */ NULL,
	/* [91] = */ NULL,
	/* [92] = */ NULL,
	/* [93] = */ NULL,
	/* [94] = */ NULL,
	/* [95] = */ NULL,
	/* [96] = */ NULL,
	/* [97] = */ NULL,
	/* [98] = */ NULL,
	/* [99] = */ NULL,
	/* [100] = */ NULL,
	/* [101] = */ NULL,
	/* [102] = */ NULL,
	/* [103] = */ NULL,
	/* [104] = */ NULL,
	/* [105] = */ NULL,
	/* [106] = */ NULL,
	/* [107] = */ NULL,
	/* [108] = */ NULL,
	/* [109] = */ NULL,
	/* [110] = */ NULL,
	/* [111] = */ NULL,
	/* [112] = */ NULL,
	/* [113] = */ NULL,
	/* [114] = */ NULL,
	/* [115] = */ NULL,
	/* [116] = */ NULL,
	/* [117] = */ NULL,
	/* [118] = */ NULL,
	/* [119] = */ NULL,
	/* [120] = */ NULL,
	/* [121] = */ NULL,
	/* [122] = */ NULL,
	/* [123] = */ NULL,
	/* [124] = */ NULL,
	/* [125] = */ NULL,
	/* [126] = */ NULL,
	/* [127] = */ NULL,
	/* [128] = */ NULL,
	/* [129] = */ NULL,
	/* [130] = */ NULL,
	/* [131] = */ NULL,
	/* [132] = */ NULL,
	/* [133] = */ NULL,
	/* [134] = */ NULL,
	/* [135] = */ NULL,
	/* [136] = */ NULL,
	/* [137] = */ NULL,
	/* [138] = */ NULL,
	/* [139] = */ NULL,
	/* [140] = */ NULL,
	/* [141] = */ NULL,
	/* [142] = */ NULL,
	/* [143] = */ NULL,
	/* [144] = */ NULL,
	/* [145] = */ NULL,
	/* [146] = */ NULL,
	/* [147] = */ NULL,
	/* [148] = */ NULL,
	/* [149] = */ NULL,
	/* [150] = */ NULL,
	/* [151] = */ NULL,
	/* [152] = */ NULL,
	/* [153] = */ NULL,
	/* [154] = */ NULL,
	/* [155] = */ NULL,
	/* [156] = */ NULL,
	/* [157] = */ NULL,
	/* [158] = */ NULL,
	/* [159] = */ NULL,
	/* [160] = */ NULL,
	/* [161] = */ NULL,
	/* [162] = */ NULL,
	/* [163] = */ NULL,
	/* [164] = */ NULL,
	/* [165] = */ NULL,
	/* [166] = */ NULL,
	/* [167] = */ NULL
};

static mtx_u animMTX[50];
static mtx_u *animMTXarray;

animinfoheader_t *pAnimInfo[168] = {
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
	/* [29] = */ NULL,
	/* [30] = */ NULL,
	/* [31] = */ NULL,
	/* [32] = */ NULL,
	/* [33] = */ NULL,
	/* [34] = */ NULL,
	/* [35] = */ NULL,
	/* [36] = */ NULL,
	/* [37] = */ NULL,
	/* [38] = */ NULL,
	/* [39] = */ NULL,
	/* [40] = */ NULL,
	/* [41] = */ NULL,
	/* [42] = */ NULL,
	/* [43] = */ NULL,
	/* [44] = */ NULL,
	/* [45] = */ NULL,
	/* [46] = */ NULL,
	/* [47] = */ NULL,
	/* [48] = */ NULL,
	/* [49] = */ NULL,
	/* [50] = */ NULL,
	/* [51] = */ NULL,
	/* [52] = */ NULL,
	/* [53] = */ NULL,
	/* [54] = */ NULL,
	/* [55] = */ NULL,
	/* [56] = */ NULL,
	/* [57] = */ NULL,
	/* [58] = */ NULL,
	/* [59] = */ NULL,
	/* [60] = */ NULL,
	/* [61] = */ NULL,
	/* [62] = */ NULL,
	/* [63] = */ NULL,
	/* [64] = */ NULL,
	/* [65] = */ NULL,
	/* [66] = */ NULL,
	/* [67] = */ NULL,
	/* [68] = */ NULL,
	/* [69] = */ NULL,
	/* [70] = */ NULL,
	/* [71] = */ NULL,
	/* [72] = */ NULL,
	/* [73] = */ NULL,
	/* [74] = */ NULL,
	/* [75] = */ NULL,
	/* [76] = */ NULL,
	/* [77] = */ NULL,
	/* [78] = */ NULL,
	/* [79] = */ NULL,
	/* [80] = */ NULL,
	/* [81] = */ NULL,
	/* [82] = */ NULL,
	/* [83] = */ NULL,
	/* [84] = */ NULL,
	/* [85] = */ NULL,
	/* [86] = */ NULL,
	/* [87] = */ NULL,
	/* [88] = */ NULL,
	/* [89] = */ NULL,
	/* [90] = */ NULL,
	/* [91] = */ NULL,
	/* [92] = */ NULL,
	/* [93] = */ NULL,
	/* [94] = */ NULL,
	/* [95] = */ NULL,
	/* [96] = */ NULL,
	/* [97] = */ NULL,
	/* [98] = */ NULL,
	/* [99] = */ NULL,
	/* [100] = */ NULL,
	/* [101] = */ NULL,
	/* [102] = */ NULL,
	/* [103] = */ NULL,
	/* [104] = */ NULL,
	/* [105] = */ NULL,
	/* [106] = */ NULL,
	/* [107] = */ NULL,
	/* [108] = */ NULL,
	/* [109] = */ NULL,
	/* [110] = */ NULL,
	/* [111] = */ NULL,
	/* [112] = */ NULL,
	/* [113] = */ NULL,
	/* [114] = */ NULL,
	/* [115] = */ NULL,
	/* [116] = */ NULL,
	/* [117] = */ NULL,
	/* [118] = */ NULL,
	/* [119] = */ NULL,
	/* [120] = */ NULL,
	/* [121] = */ NULL,
	/* [122] = */ NULL,
	/* [123] = */ NULL,
	/* [124] = */ NULL,
	/* [125] = */ NULL,
	/* [126] = */ NULL,
	/* [127] = */ NULL,
	/* [128] = */ NULL,
	/* [129] = */ NULL,
	/* [130] = */ NULL,
	/* [131] = */ NULL,
	/* [132] = */ NULL,
	/* [133] = */ NULL,
	/* [134] = */ NULL,
	/* [135] = */ NULL,
	/* [136] = */ NULL,
	/* [137] = */ NULL,
	/* [138] = */ NULL,
	/* [139] = */ NULL,
	/* [140] = */ NULL,
	/* [141] = */ NULL,
	/* [142] = */ NULL,
	/* [143] = */ NULL,
	/* [144] = */ NULL,
	/* [145] = */ NULL,
	/* [146] = */ NULL,
	/* [147] = */ NULL,
	/* [148] = */ NULL,
	/* [149] = */ NULL,
	/* [150] = */ NULL,
	/* [151] = */ NULL,
	/* [152] = */ NULL,
	/* [153] = */ NULL,
	/* [154] = */ NULL,
	/* [155] = */ NULL,
	/* [156] = */ NULL,
	/* [157] = */ NULL,
	/* [158] = */ NULL,
	/* [159] = */ NULL,
	/* [160] = */ NULL,
	/* [161] = */ NULL,
	/* [162] = */ NULL,
	/* [163] = */ NULL,
	/* [164] = */ NULL,
	/* [165] = */ NULL,
	/* [166] = */ NULL,
	/* [167] = */ NULL
};

static int animtagsBufferPos;
static int owkey1;
static int owkey2;
static int owkey3;
static int owkey4;
static float owfrac;
static float owfrac2;

void animUpdate(obinst *inst) {
	int i;
}

static void calMatrices(obinst *inst) {
	int i;
	int key1;
	int key2;
	int key3;
	int key4;
	int mindex;
	int calmat;
	quaternion q;
	quaternion q1;
	quaternion q2;
	quaternion q3;
	quaternion q4;
	quaternion qOut1;
	quaternion qOut2;
	animinfo *ai1;
	animinfo *ai2;
	animData ad1;
	animData ad2;
	animData ad3;
	animData ad4;
	float key1Time;
	float key2Time;
	float frac;
	float frac2;
	float tx1;
	float ty1;
	float tz1;
	float tx2;
	float ty2;
	float tz2;
	float scale;
	animInfoProp *pAnimCycle;
	animInfoProp *pAnimCycle2;
	mtx_u mtxscale;
	chrdata *cd;
	mtx_u tmpmtx;
	mtx_u *localwaistmtx;
	mtx_u tmpmtx;
	mtx_u *localwaistmtx;
	mtx_u tmpmtx;
	mtx_u *localwaistmtx;
	mtx_u tmpmtx;
	mtx_u *localwaistmtx;
	int animframe;
	int tagframe;
	corpsedata *cor;
	mtx_u mtx;
	player *pPlayer;
}

void calPropMatrices(cs_animheader *cs, int slotnum, obinst *inst, float scale) {
	int i;
	int key1;
	int key2;
	int frame;
	quaternion q;
	quaternion q1;
	quaternion q2;
	animinfo *ai1;
	animData ad1;
	animData ad2;
	float animLength;
	float frac;
	animInfoProp *pAnimCycle;
}

void animUpdateTime(animinfo *ai, float scale) {
	animData adt1;
	animData adt2;
	float animLength;
	animInfoProp *pAnimCycle;
}

static void calOverwriteKeys(prop *p) {
	chrdata *cd;
	float overwriteanglex;
	float overwriteangley;
	float ad;
}

void calOverwriteKeyFrame(prop *p, animData *ad, int part) {
	chrdata *cd;
	animData ad1;
	animData ad2;
	animData ad3;
	animData ad4;
	quaternion q;
	quaternion q1;
	quaternion q2;
	quaternion q3;
	quaternion q4;
	quaternion qOut1;
	quaternion qOut2;
	float scale;
}

void animSetOverwriteAngles(prop *p) {
	chrdata *cd;
	float dx;
	float dy;
	float dz;
	float localaimpos[3];
	mtx_u tmpmtx;
	mtx_u mat;
	mtx_u *localwaistmtx;
}

int animTestDestPos(prop *p, int anim, float *destpos) {
	chrdata *cd;
	float movepos[3];
	float dx;
	float dz;
	mtx_u rotmtx;
	animInfoProp *pAnimCycle;
	animData ad1;
	animData ad2;
}

void loadAnimation(char *filename, int tabEntry) {
	animInfoProp *pAnimCycle;
	u8 *animBuffer;
	float *data;
	int i;
	channel *pChannel;
}

void loadAnimationRawEx(char *filename, int tabEntry, u8 *bufferloaddynamic) {
	animInfoProp *pAnimCycle;
	channel *pChannel;
	u8 *pFileData;
	float *data;
	int i;
	u8 infofile[1024];
}

void setAnimProp(int tabEntry, int fProp) {}

int getAnimProp(int tabEntry) {}

animInfoProp* getAnimation(int tabEntry) {}

void calGlobalMatrices(obinst *inst, mtx_u *m, int partnum, int parent) {
	partdef *parts;
	partdef *part;
	int nextparent;
}

void calGlobalFilletMatrices(obinst *inst, mtx_u *m, int partnum, int parent) {
	partdef *parts;
	partdef *part;
	int nextparent;
}

void calDoubleFillets(obinst *inst, int partnum, int relocating) {
	partdef *parts;
	partdef *part;
	partdef *childpart;
}

void getKeyFrames(animinfo *ai, float animLength, int *key1, int *key2) {
	animInfoProp *pAnimCycle;
	int i;
	float keyTime;
}

boolean animIsPaused(obinst *inst) {}

boolean animIsEnded(obinst *inst) {
	animinfo *ai;
}

boolean animIsBlended(obinst *inst) {}

void animPause(obinst *inst) {}

void animContinue(obinst *inst, float speed) {}

void animRewind(obinst *inst) {
	animinfo *ai;
}

void animSetKeyframe(obinst *inst, int keyframenum) {
	animinfo *ai;
	animInfoProp *pAnimCycle;
	float keyTime;
}

int animGetKeyframe(obinst *inst) {
	animinfo *ai;
	int key1;
	int key2;
}

int animGetTag(int animnum, u16 keyframetag, int nth) {
	int i;
}

int animGetCurKeyframeTags(obinst *inst) {
	animinfo *ai;
	animInfoProp *an;
	animinfoheader_t *aih;
	int i;
	int key1;
	int key2;
}

void setAnim(prop *p, int anim, float blendtime, float speed) {
	chrdata *cd;
	animData ad;
	float scale;
	int key1;
	int key2;
}

void animSetAiming(obinst *inst, int status, float tweentime) {}

void setAnimOverwrite(obinst *inst, int overwriteparts, int animnum) {}

void extractAnimData(animInfoProp *pAnimCycle, int channelnum, int key, animData *ad, float scale) {
	int offset;
	channel *pChannel;
}

void extractAnimRoot(prop *p, float *t1, float *t2, float *frames, int daxis) {
	animInfoProp *pAnimCycle;
	float scale;
}

void extractAnimRootData(prop *p, int animnum, float *t1, float *t2, float *frames, int daxis) {
	animInfoProp *pAnimCycle;
	float scale;
}

void anim_LoadMatrix(int num) {}

void anim_SetMatrixArray(mtx_u *m) {}

void anim_SetModelview(mtx_u *m, int multpush) {}

void anim_PopModelview() {}

mtx_u* anim_GetModelview() {}

int curAnim(prop *p, int anim) {}

int curAnimType(prop *p) {}

int curAnimSlot1(prop *p, int anim) {}

int curAnimSlot2(prop *p, int anim) {}

int curAnimComplete(obinst *ob) {}

int curAnimLeadingOut(obinst *inst, float leadout) {}

void curAnimSpeed(obinst *ob, float speed) {}

void animHitReact(prop *p, int parthit) {
	chrdata *cd;
}

static void animHitReactUpdate(prop *p) {
	float frac1;
}

static void loadSkeleton(int skeltype, char *bindfile, int nummatrices) {
	skeleton *skel;
}

void animRestart() {}

void animReset(int cutscene) {}

void animMake(int makeCutscene) {}
