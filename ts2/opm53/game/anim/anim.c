//
// The OpenRadical Project
// A project by Ryan J. Gray - 2024
// TS2 OPM53 Tree
//

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
    /* [4] = */ NULL};

static int animHeaderIndex = 0;
static int loadedgamepak = 0;

skeleton skeletons[5] = {
    /* [0] = */ {/* .matrices = */ NULL,
                 /* .ad = */ NULL,
                 /* .id = */ 0,
                 /* .type = */ 0,
                 /* .bindfile = */ NULL},
    /* [1] = */
    {/* .matrices = */ NULL,
     /* .ad = */ NULL,
     /* .id = */ 0,
     /* .type = */ 0,
     /* .bindfile = */ NULL},
    /* [2] = */
    {/* .matrices = */ NULL,
     /* .ad = */ NULL,
     /* .id = */ 0,
     /* .type = */ 0,
     /* .bindfile = */ NULL},
    /* [3] = */
    {/* .matrices = */ NULL,
     /* .ad = */ NULL,
     /* .id = */ 0,
     /* .type = */ 0,
     /* .bindfile = */ NULL},
    /* [4] = */
    {/* .matrices = */ NULL,
     /* .ad = */ NULL,
     /* .id = */ 0,
     /* .type = */ 0,
     /* .bindfile = */ NULL}};

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
    /* [167] = */ NULL};

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
    /* [167] = */ NULL};

static int animtagsBufferPos;
static int owkey1;
static int owkey2;
static int owkey3;
static int owkey4;
static float owfrac;
static float owfrac2;

void animUpdate(obinst *inst) { int i; }

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

void calPropMatrices(cs_animheader *cs, int slotnum, obinst *inst,
                     float scale) {
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

animInfoProp *getAnimation(int tabEntry) {}

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

boolean animIsEnded(obinst *inst) { animinfo *ai; }

boolean animIsBlended(obinst *inst) {}

void animPause(obinst *inst) {}

void animContinue(obinst *inst, float speed) {}

void animRewind(obinst *inst) { animinfo *ai; }

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

int animGetTag(int animnum, u16 keyframetag, int nth) { int i; }

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

void extractAnimData(animInfoProp *pAnimCycle, int channelnum, int key,
                     animData *ad, float scale) {
  int offset;
  channel *pChannel;
}

void extractAnimRoot(prop *p, float *t1, float *t2, float *frames, int daxis) {
  animInfoProp *pAnimCycle;
  float scale;
}

void extractAnimRootData(prop *p, int animnum, float *t1, float *t2,
                         float *frames, int daxis) {
  animInfoProp *pAnimCycle;
  float scale;
}

void anim_LoadMatrix(int num) {}

void anim_SetMatrixArray(mtx_u *m) {}

void anim_SetModelview(mtx_u *m, int multpush) {}

void anim_PopModelview() {}

mtx_u *anim_GetModelview() {}

int curAnim(prop *p, int anim) {}

int curAnimType(prop *p) {}

int curAnimSlot1(prop *p, int anim) {}

int curAnimSlot2(prop *p, int anim) {}

int curAnimComplete(obinst *ob) {}

int curAnimLeadingOut(obinst *inst, float leadout) {}

void curAnimSpeed(obinst *ob, float speed) {}

void animHitReact(prop *p, int parthit) { chrdata *cd; }

static void animHitReactUpdate(prop *p) { float frac1; }

/// <summary>
/// Loads a specific type of skeleton from a file, in bind pose.
/// </summary>
static void loadSkeleton(int skeltype, char *bindfile, int nummatrices) {
  skeleton *skel;

  if (skeltype != SKELTYPE_NONE) {
    _game_assert_fail("skeltype!=SKELTYPE_NONE", "anim/anim.c", 0x908,
                      "loadSkeleton");
  }

  skel = skeletons[skeltype];
  skel->type = skeltype;
  skel->id = 1;

  size_t filenamelen = strlen(bindfile);
  u8 *__dest = memAlloc(filenamelen + 15 & 0xfffffff0, 2);
  skel->bindfile = __dest;
  strcpy(__dest, bindfile);

  mtx_u *matrices;
  matrices = memAlloc(nummatrices * 64, 2);
  skel->matrices = matrices;

  if (!skel->matrices) {
    _game_assert_fail("skel->matrices", "anim/anim.c", 0x90f, "loadSkeleton");
  }

  animData *ad = memAlloc(nummatrices * 28 + 15 & 0xfffffff0, 2);
  skel->ad = ad;

  if (!skel->ad) {
    _game_assert_fail("skel->ad", "anim/anim.c", 0x911, "loadSkeleton");
  }
}

void animRestart() {}

void animReset(int cutscene) {}

/// <summary>
/// Initialise the animation system, and optionally initialise the system for
/// cutscenes.
/// </summary>
void animMake(int makeCutscene) {
  boolean isPlayingGame = gameIsPlayingGame();
  if ((isPlayingGame != FALSE) && (loadedgamepak == 0)) {
    memset(pAnimations, 0, 0x2a0);
    animtagsBuffer = memAlloc(0x28c0, 1);
    animtagsBufferPos = 0;
  }

  isPlayingGame = gameIsPlayingGame();
  if ((isPlayingGame != FALSE) && (loadedgamepak == 0)) {
    packfileload("cdrom0:\\TS2\\PAK\\ANIM.PAK;1", 1, 1);
  }

  isPlayingGame = gameIsPlayingGame();
  if ((isPlayingGame != FALSE) && (loadedgamepak == 0)) {
    loadSkeleton(SKELTYPE_HUMAN19, "host0:anim/data/ts2/human_19_bindpose.raw",
                 19);
    loadSkeleton(SKELTYPE_BARRELROBOT, "host0:anim/data/ts2/barrelbindpose.raw",
                 13);
    loadSkeleton(SKELTYPE_RAILSPIDER,
                 "host0:anim/data/ts2/railspiderbindpose.raw", 8);
    loadAnimationRawEx("host0:anim/data/ts2/standpose_m0.raw", ANIM_STAND,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/run_m0.raw", ANIM_RUN, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/runback_m0.raw", ANIM_RUNBACK,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/runleft_m0.raw", ANIM_RUNLEFT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/runright_m0.raw", ANIM_RUNRIGHT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walk_m0.raw", ANIM_WALK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walkback_m0.raw", ANIM_WALKBACK,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walkleft_m0.raw", ANIM_WALKLEFT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walkright_m0.raw", ANIM_WALKRIGHT,
                       NULL);
    setAnimProp(ANIM_STAND, PROP_BIGSHIP);
    setAnimProp(ANIM_RUN, PROP_ROOM160);
    setAnimProp(ANIM_RUNBACK, PROP_ROOM160);
    setAnimProp(ANIM_RUNLEFT, PROP_ROOM160);
    setAnimProp(ANIM_RUNRIGHT, PROP_ROOM160);
    setAnimProp(ANIM_WALK, PROP_ROOM160);
    setAnimProp(ANIM_WALKBACK, PROP_ROOM160);
    setAnimProp(ANIM_WALKLEFT, PROP_ROOM160);
    setAnimProp(ANIM_WALKRIGHT, PROP_ROOM160);
    loadAnimationRawEx("host0:anim/data/ts2/patrol_m0.raw", ANIM_PATROL, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/patrol2_m0.raw", ANIM_PATROL2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/patrol3_m0.raw", ANIM_PATROL3,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/patrol4_m0.raw", ANIM_PATROL4,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/search_patrol_m0.raw",
                       ANIM_SEARCHINGPATROL, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/searchpatrol2_flipped_m0.raw",
                       ANIM_SEARCHINGPATROL2, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/searchpatrol2_gun_m0.raw",
                       ANIM_SEARCHINGPATROL3, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/alertpatrol_m0.raw",
                       ANIM_SEARCHINGPATROL4, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/acting_patrol_m0.raw",
                       ANIM_ACTINGPATROL, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/reaction_3_m0.raw",
                       ANIM_PATROLREACTION, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/reaction_2_m0.raw",
                       ANIM_PATROLREACTSHORT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walktostand_m0.raw",
                       ANIM_PATROLWALKTOSTAND, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/restani1_m0.raw", ANIM_PATROLIDLE1,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/restani2_m0.raw", ANIM_PATROLIDLE2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standtowalkleft_m0.raw",
                       ANIM_PATROLSTANDTOWALKLEFT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standtowalkright_m0.raw",
                       ANIM_PATROLSTANDTOWALKRIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standtowalk180_m0.raw",
                       ANIM_PATROLSTANDTOWALK180, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standtowalk_m0.raw",
                       ANIM_PATROLSTANDTOWALK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turn90_l1_m0.raw",
                       ANIM_PATROLTURN90LEFT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turn90_l2_m0.raw",
                       ANIM_PATROLTURN90LEFT2, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turn90_r1_m0.raw",
                       ANIM_PATROLTURN90RIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turn90_r2_m0.raw",
                       ANIM_PATROLTURN90RIGHT2, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turn90_r3_m0.raw",
                       ANIM_PATROLTURN90RIGHT3, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turn90_stretchright_m0.raw",
                       ANIM_PATROLTURN90RIGHT4, NULL);
    setAnimProp(ANIM_PATROL, 0x2303);
    setAnimProp(ANIM_PATROL2, 0x2203);
    setAnimProp(ANIM_PATROL3, 0x2203);
    setAnimProp(ANIM_PATROL4, 0x2203);
    setAnimProp(ANIM_SEARCHINGPATROL, 0x2203);
    setAnimProp(ANIM_SEARCHINGPATROL2, 0x2203);
    setAnimProp(ANIM_SEARCHINGPATROL3, 0x2203);
    setAnimProp(ANIM_SEARCHINGPATROL4, 0x2203);
    setAnimProp(ANIM_ACTINGPATROL, 0x2203);
    setAnimProp(ANIM_PATROLREACTION, 0x2302);
    setAnimProp(ANIM_PATROLREACTSHORT, PROP_DISCTHROWER_PH);
    setAnimProp(ANIM_PATROLWALKTOSTAND, PROP_DISCTHROWER_PH);
    setAnimProp(ANIM_PATROLIDLE1, 0x4202);
    setAnimProp(ANIM_PATROLIDLE2, 0x4202);
    setAnimProp(ANIM_PATROLSTANDTOWALKLEFT, 0x4602);
    setAnimProp(ANIM_PATROLSTANDTOWALKRIGHT, 0x4a02);
    setAnimProp(ANIM_PATROLSTANDTOWALK180, 0x5202);
    setAnimProp(ANIM_PATROLSTANDTOWALK, PROP_DISCTHROWER_PH);
    setAnimProp(ANIM_PATROLTURN90LEFT, 0x4602);
    setAnimProp(ANIM_PATROLTURN90LEFT2, 0x4602);
    setAnimProp(ANIM_PATROLTURN90RIGHT, 0x4a02);
    setAnimProp(ANIM_PATROLTURN90RIGHT2, 0x4a02);
    setAnimProp(ANIM_PATROLTURN90RIGHT3, 0x4a02);
    setAnimProp(ANIM_PATROLTURN90RIGHT4, 0x4a02);
    loadAnimationRawEx("host0:anim/data/ts2/dive_m0.raw", ANIM_DIVE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/shuffle_left_m0.raw",
                       ANIM_SHUFFLE_LEFT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/shuffle_m0.raw", ANIM_SHUFFLE,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/sidestep_right_m0.raw",
                       ANIM_SIDESTEP_RIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/sidestep_rightlittle_m0.raw",
                       ANIM_SIDESTEP_RIGHTLITTLE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/slide_m0.raw", ANIM_SLIDE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/summersault2_m0.raw",
                       ANIM_SUMMERSAULT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/lowandleft_m0.raw", ANIM_LOWLEFT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/backflip5_m0.raw", ANIM_BACKFLIP,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cartwheel_m0.raw", ANIM_CARTWHEEL,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/diagbackright2_m0.raw",
                       ANIM_DIAGBACKRIGHT2, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/diagforleft_m0.raw",
                       ANIM_DIAGFORLEFT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/dodgeleftright_m0.raw",
                       ANIM_DIAGLEFTRIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/doubledodge4_m0.raw",
                       ANIM_DOUBLEDODGE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/flipped_doubledodge_m0.raw",
                       ANIM_DOUBLEDODGE_FLIPPED, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rollright_m0.raw", ANIM_ROLLRIGHT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/flipped_rollleft_m0.raw",
                       ANIM_ROLLLEFT_FLIPPED, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/stepright_m0.raw", ANIM_STEPRIGHT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/smallstep9_m0.raw", ANIM_SMALLSTEP9,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/smallstep10_m0.raw",
                       ANIM_SMALLSTEP10, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/stepback5_m0.raw", ANIM_STEPBACK5,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/smallstepback_m0.raw",
                       ANIM_SMALLSTEPBACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/faintleft3_m0.raw", ANIM_FAINTLEFT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/flipped_faintright_m0.raw",
                       ANIM_FAINTRIGHT_FLIPPED, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/straifforright_m0.raw",
                       ANIM_STRAFEFARRIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/dodgeleftright_m0.raw",
                       ANIM_DODGELEFTRIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/straifforleft_m0.raw",
                       ANIM_STRAFEFARLEFT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/turnnrun_m0.raw", ANIM_TURNANDRUN,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/retreat_m0.raw", ANIM_RETREAT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/moveforward_m0.raw",
                       ANIM_MOVEFORWARD, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/moveleft_m0.raw", ANIM_MOVELEFT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/moveright_m0.raw", ANIM_MOVERIGHT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standfaintleft_m0.raw",
                       ANIM_STANDFEINTLEFT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standfaintright_m0.raw",
                       ANIM_STANDFEINTRIGHT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/droptoknee_m0.raw", ANIM_DROPTOKNEE,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/onknee_m0.raw", ANIM_ONKNEE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/standfromknee_m0.raw",
                       ANIM_STANDFROMKNEE, NULL);
    setAnimProp(ANIM_DIVE, 0x4002);
    setAnimProp(ANIM_SHUFFLE_LEFT, PROP_GREENTHING);
    setAnimProp(ANIM_SHUFFLE, PROP_GREENTHING);
    setAnimProp(ANIM_SIDESTEP_RIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_SIDESTEP_RIGHTLITTLE, PROP_GREENTHING);
    setAnimProp(ANIM_SLIDE, 0x4002);
    setAnimProp(ANIM_SUMMERSAULT, 0x4002);
    setAnimProp(ANIM_LOWLEFT, PROP_GREENTHING);
    setAnimProp(ANIM_BACKFLIP, 0x4002);
    setAnimProp(ANIM_CARTWHEEL, 0x4002);
    setAnimProp(ANIM_DIAGBACKRIGHT2, PROP_GREENTHING);
    setAnimProp(ANIM_DIAGFORLEFT, PROP_GREENTHING);
    setAnimProp(ANIM_DIAGLEFTRIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_DOUBLEDODGE, PROP_GREENTHING);
    setAnimProp(ANIM_DOUBLEDODGE_FLIPPED, PROP_GREENTHING);
    setAnimProp(ANIM_ROLLRIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_ROLLLEFT_FLIPPED, PROP_GREENTHING);
    setAnimProp(ANIM_STEPRIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_SMALLSTEP9, PROP_GREENTHING);
    setAnimProp(ANIM_SMALLSTEP10, PROP_GREENTHING);
    setAnimProp(ANIM_STEPBACK5, PROP_GREENTHING);
    setAnimProp(ANIM_SMALLSTEPBACK, PROP_GREENTHING);
    setAnimProp(ANIM_FAINTLEFT, PROP_GREENTHING);
    setAnimProp(ANIM_FAINTRIGHT_FLIPPED, PROP_GREENTHING);
    setAnimProp(ANIM_STRAFEFARRIGHT, 0x4102);
    setAnimProp(ANIM_DODGELEFTRIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_STRAFEFARLEFT, 0x4102);
    setAnimProp(ANIM_TURNANDRUN, 0x4002);
    setAnimProp(ANIM_RETREAT, PROP_GREENTHING);
    setAnimProp(ANIM_MOVEFORWARD, PROP_GREENTHING);
    setAnimProp(ANIM_MOVELEFT, PROP_GREENTHING);
    setAnimProp(ANIM_MOVERIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_STANDFEINTLEFT, PROP_GREENTHING);
    setAnimProp(ANIM_STANDFEINTRIGHT, PROP_GREENTHING);
    setAnimProp(ANIM_DROPTOKNEE, PROP_GREENTHING);
    setAnimProp(ANIM_ONKNEE, PROP_GREENTHING);
    setAnimProp(ANIM_STANDFROMKNEE, PROP_GREENTHING);
    loadAnimationRawEx("host0:anim/data/ts2/ambush_standpose_flipped_m0.raw",
                       ANIM_AMBUSH_STANDPOSE_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/ambush_standpose_m0.raw",
                       ANIM_AMBUSH_STANDPOSE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/c_2_s_m0.raw",
                       ANIM_AMBUSH_CRATE_TOSTAND, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/c_s_2_c_m0.raw",
                       ANIM_AMBUSH_CRATE_TOCROUCH, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/c_s_m0.raw",
                       ANIM_AMBUSH_CRATE_STAND, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/csp_m0.raw",
                       ANIM_AMBUSH_CRATE_CROUCH, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/c_gran_m0.raw",
                       ANIM_AMBUSH_CRATE_GRENADE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/c_s_noi_m0.raw",
                       ANIM_AMBUSH_CRATE_SHOOTOVER, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/crouch_attack_back_flipped_m0.raw",
                       ANIM_AMBUSH_CROUCHATTACK_BACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/crouch_attack_back_m0.raw",
                       ANIM_AMBUSH_CROUCHATTACK_BACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/crouch_attack_flipped_m0.raw",
                       ANIM_AMBUSH_CROUCHATTACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/crouch_attack_m0.raw",
                       ANIM_AMBUSH_CROUCHATTACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rollattack_back_flipped_m0.raw",
                       ANIM_AMBUSH_ROLLATTACK_BACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rollattack_back_m0.raw",
                       ANIM_AMBUSH_ROLLATTACK_BACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rollattack_flipped_m0.raw",
                       ANIM_AMBUSH_ROLLATTACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rollattack_m0.raw",
                       ANIM_AMBUSH_ROLLATTACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/salb_flipped_m0.raw",
                       ANIM_AMBUSH_SPRAYATTACK_BACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/salb_m0.raw",
                       ANIM_AMBUSH_SPRAYATTACK_BACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/sal_flipped_m0.raw",
                       ANIM_AMBUSH_SPRAYATTACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/sal_m0.raw",
                       ANIM_AMBUSH_SPRAYATTACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wa1_lb_flipped_m0.raw",
                       ANIM_AMBUSH_WALL1_BACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wa1_lb_m0.raw",
                       ANIM_AMBUSH_WALL1_BACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wa1_l_flipped_m0.raw",
                       ANIM_AMBUSH_WALL1_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wa1_l_m0.raw", ANIM_AMBUSH_WALL1,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wallambushleft2_back_m0.raw",
                       ANIM_AMBUSH_WALL2_BACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wallambushleft2_flipped_m0.raw",
                       ANIM_AMBUSH_WALL2_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wallambushleft2_m0.raw",
                       ANIM_AMBUSH_WALL2, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wap_lb_flipped_m0.raw",
                       ANIM_AMBUSH_WALL3_BACK_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wap_lb_m0.raw",
                       ANIM_AMBUSH_WALL3_BACK, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wap_l_flipped_m0.raw",
                       ANIM_AMBUSH_WALL3_FLIP, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/wap_l_m0.raw", ANIM_AMBUSH_WALL3,
                       NULL);
    setAnimProp(ANIM_AMBUSH_STANDPOSE_FLIP, PROP_CHR04);
    setAnimProp(ANIM_AMBUSH_STANDPOSE, PROP_CHR04);
    setAnimProp(ANIM_AMBUSH_CRATE_TOSTAND, 0x4102);
    setAnimProp(ANIM_AMBUSH_CRATE_TOCROUCH, 0x4002);
    setAnimProp(ANIM_AMBUSH_CRATE_STAND, 0x4103);
    setAnimProp(ANIM_AMBUSH_CRATE_CROUCH, 0x4003);
    setAnimProp(ANIM_AMBUSH_CRATE_GRENADE, 0x4002);
    setAnimProp(ANIM_AMBUSH_CRATE_SHOOTOVER, 0xc002);
    setAnimProp(ANIM_AMBUSH_CROUCHATTACK_BACK_FLIP, 0x1002);
    setAnimProp(ANIM_AMBUSH_CROUCHATTACK_BACK, 0x1002);
    setAnimProp(ANIM_AMBUSH_CROUCHATTACK_FLIP, 0x1102);
    setAnimProp(ANIM_AMBUSH_CROUCHATTACK, 0x1102);
    setAnimProp(ANIM_AMBUSH_ROLLATTACK_BACK_FLIP, 0x1002);
    setAnimProp(ANIM_AMBUSH_ROLLATTACK_BACK, 0x1002);
    setAnimProp(ANIM_AMBUSH_ROLLATTACK_FLIP, 0x1102);
    setAnimProp(ANIM_AMBUSH_ROLLATTACK, 0x1102);
    setAnimProp(ANIM_AMBUSH_SPRAYATTACK_BACK_FLIP, 0x1002);
    setAnimProp(ANIM_AMBUSH_SPRAYATTACK_BACK, 0x1002);
    setAnimProp(ANIM_AMBUSH_SPRAYATTACK_FLIP, 0x1102);
    setAnimProp(ANIM_AMBUSH_SPRAYATTACK, 0x1102);
    setAnimProp(ANIM_AMBUSH_WALL1_BACK_FLIP, 0x1002);
    setAnimProp(ANIM_AMBUSH_WALL1_BACK, 0x1002);
    setAnimProp(ANIM_AMBUSH_WALL1_FLIP, 0x1102);
    setAnimProp(ANIM_AMBUSH_WALL1, 0x1102);
    setAnimProp(ANIM_AMBUSH_WALL2_BACK, 0x1002);
    setAnimProp(ANIM_AMBUSH_WALL2_FLIP, 0x1102);
    setAnimProp(ANIM_AMBUSH_WALL2, 0x1102);
    setAnimProp(ANIM_AMBUSH_WALL3_BACK_FLIP, 0x1002);
    setAnimProp(ANIM_AMBUSH_WALL3_BACK, 0x1002);
    setAnimProp(ANIM_AMBUSH_WALL3_FLIP, 0x1102);
    setAnimProp(ANIM_AMBUSH_WALL3, 0x1102);
    loadAnimationRawEx("host0:anim/data/ts2/shothead_m0.raw", ANIM_SHOTHEAD,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/shothead2_m0.raw", ANIM_SHOTHEAD2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/shothead3_m0.raw", ANIM_SHOTHEAD3,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/shouldershot_m0.raw",
                       ANIM_SHOTSHOULDER, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/chestshot1_m0.raw", ANIM_CHESTSHOT1,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/chestshot2_m0.raw", ANIM_CHESTSHOT2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/heartshot_m0.raw", ANIM_HEARTSHOT,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rightfronthit_m0.raw",
                       ANIM_RIGHTFRONT, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/sholdershot2_m0.raw",
                       ANIM_SHOTSHOULDER2, NULL);
    setAnimProp(ANIM_SHOTHEAD, PROP_CHR35);
    setAnimProp(ANIM_SHOTHEAD2, PROP_CHR35);
    setAnimProp(ANIM_SHOTHEAD3, PROP_CHR35);
    setAnimProp(ANIM_SHOTSHOULDER, PROP_CHR35);
    setAnimProp(ANIM_CHESTSHOT1, PROP_CHR35);
    setAnimProp(ANIM_CHESTSHOT2, PROP_CHR35);
    setAnimProp(ANIM_HEARTSHOT, PROP_CHR35);
    setAnimProp(ANIM_RIGHTFRONT, PROP_CHR35);
    setAnimProp(ANIM_SHOTSHOULDER2, PROP_CHR35);
    loadAnimationRawEx("host0:anim/data/ts2/leftshoulder_m0.raw",
                       ANIM_HR_LEFTSHOULDER, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/leftstomach_m0.raw",
                       ANIM_HR_LEFTSTOMACH, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rightleg_m0.raw", ANIM_HR_RIGHTLEG,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rightshoulder_m0.raw",
                       ANIM_HR_RIGHTSHOULDER, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/rightstomach_m0.raw",
                       ANIM_HR_RIGHTSTOMACH, NULL);
    setAnimProp(ANIM_HR_LEFTSHOULDER, 0x400a);
    setAnimProp(ANIM_HR_LEFTSTOMACH, 0x400a);
    setAnimProp(ANIM_HR_RIGHTLEG, 0x400a);
    setAnimProp(ANIM_HR_RIGHTSHOULDER, 0x400a);
    setAnimProp(ANIM_HR_RIGHTSTOMACH, 0x400a);
    loadAnimationRawEx("host0:anim/data/ts2/zombiestand_m0.raw",
                       ANIM_ZOMBIESTAND, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/getup1_m0.raw", ANIM_ZOMBIEGETUP1,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/getup2_m0.raw", ANIM_ZOMBIEGETUP2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/spose_m0.raw", ANIM_ZOMBIESTAND,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/swipe_1_m0.raw", ANIM_ZOMBIESWIPE1,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/swipe_2_m0.raw", ANIM_ZOMBIESWIPE2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/swipe_3_m0.raw", ANIM_ZOMBIESWIPE3,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/swipe_4_m0.raw", ANIM_ZOMBIESWIPE4,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walk2_m0.raw", ANIM_ZOMBIEWALK1,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walk3_m0.raw", ANIM_ZOMBIEWALK2,
                       NULL);
    loadAnimationRawEx("host0:anim/data/ts2/walk4_m0.raw", ANIM_ZOMBIEWALK3,
                       NULL);
    setAnimProp(ANIM_ZOMBIEGETUP1, 0x400a);
    setAnimProp(ANIM_ZOMBIEGETUP2, 0x400a);
    setAnimProp(ANIM_ZOMBIESTAND, PROP_CHR04);
    setAnimProp(ANIM_ZOMBIESWIPE1, PROP_CHR11);
    setAnimProp(ANIM_ZOMBIESWIPE2, PROP_CHR11);
    setAnimProp(ANIM_ZOMBIESWIPE3, PROP_CHR11);
    setAnimProp(ANIM_ZOMBIESWIPE4, PROP_CHR11);
    setAnimProp(ANIM_ZOMBIEWALK1, PROP_DISCTHROWER_CL);
    setAnimProp(ANIM_ZOMBIEWALK2, PROP_DISCTHROWER_CL);
    setAnimProp(ANIM_ZOMBIEWALK3, PROP_DISCTHROWER_CL);
    setAnimProp(ANIM_ZOMBIESTAND, 0x4003);
    loadAnimationRawEx("host0:anim/data/ts2/pistolpointing_m0.raw",
                       ANIM_OVERWRITE, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/pointalngls2handed_m0.raw",
                       ANIM_OVERWRITE2, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/punch_m0.raw", ANIM_PUNCH, NULL);
    setAnimProp(ANIM_PUNCH, PROP_CHR03);
    loadedgamepak = 1;
  }

  if (makeCutscene != 0) {
    loadAnimation("host0:anim/data/ts2/cs_gasmask_bindpose.raw",
                  ANIM_CS_INTRO_DAM_1);
    loadAnimation("host0:anim/data/ts2/cs_helmetsold_bindpose.raw",
                  ANIM_CS_INTRO_DAM_2);
    loadAnimation("host0:anim/data/ts2/cs_beret_bindpose.raw",
                  ANIM_CS_INTRO_DAM_3);
    loadAnimation("host0:anim/data/ts2/cs_beretzombie_bindpose.raw",
                  ANIM_CS_INTRO_DAM_4);
    loadAnimation("host0:anim/data/ts2/cs_ilsanadir_bindpose.raw",
                  ANIM_CS_INTRO_DAM_5);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m00.raw",
                       ANIM_CS_INTRO_DAM_6, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m01.raw",
                       ANIM_CS_INTRO_DAM_7, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m02.raw",
                       ANIM_CS_INTRO_DAM_8, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m03.raw",
                       ANIM_CS_INTRO_DAM_9, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m10.raw",
                       ANIM_CS_INTRO_DAM_10, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m11.raw",
                       ANIM_CS_INTRO_DAM_11, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m12.raw",
                       ANIM_CS_INTRO_DAM_12, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m13.raw",
                       ANIM_CS_INTRO_DAM_13, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m14.raw",
                       ANIM_CS_INTRO_DAM_14, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m15.raw",
                       ANIM_CS_INTRO_DAM_15, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m16.raw",
                       ANIM_CS_INTRO_DAM_16, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m18.raw",
                       ANIM_CS_INTRO_DAM_17, NULL);
    loadAnimationRawEx("host0:anim/data/ts2/cs_dam2_m17.raw",
                       ANIM_CS_INTRO_DAM_18, NULL);
    setAnimProp(ANIM_CS_INTRO_DAM_1, PROP_CHR11);
    setAnimProp(ANIM_CS_INTRO_DAM_2, PROP_CHR11);
    setAnimProp(ANIM_CS_INTRO_DAM_3, PROP_CHR11);
    setAnimProp(ANIM_CS_INTRO_DAM_4, PROP_CHR11);
    setAnimProp(ANIM_CS_INTRO_DAM_5, PROP_CHR11);
    setAnimProp(ANIM_CS_INTRO_DAM_6, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_7, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_8, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_9, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_10, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_11, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_12, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_13, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_14, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_15, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_16, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_17, PROP_CHR12);
    setAnimProp(ANIM_CS_INTRO_DAM_18, PROP_CHR12);
    return;
  }

  return;
}
