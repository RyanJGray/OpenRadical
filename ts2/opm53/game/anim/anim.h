//
// The OpenRadical Project
// A project by Ryan J. Gray - 2024
// TS2 OPM53 Tree
//

#ifndef GAME_ANIM_ANIM_H
#define GAME_ANIM_ANIM_H

typedef struct animData_s {
	float x;
	float y;
	float z;
	float qx;
	float qy;
	float qz;
	float qw;
} animData;

enum {
	SKELTYPE_NONE = -1,
	SKELTYPE_HUMAN19 = 0,
	SKELTYPE_BARRELROBOT = 1,
	SKELTYPE_RAILSPIDER = 2,
	SKELTYPE_SPIDER = 3,
	SKELTYPE_LIMBRELOCATED = 4,
	SKELTYPE_NUM = 5
};

enum {
	CHANNEL_TYPE_NULL = 0,
	CHANNEL_TYPE_QUATERNION_LINEAR = 1,
	CHANNEL_TYPE_QUATERNION_SPHERICAL = 2,
	CHANNEL_TYPE_MATRIX = 3,
	CHANNEL_TYPE_TRANSFORM_XYZ = 4,
	CHANNEL_TYPE_TRANSFORM_X = 5,
	CHANNEL_TYPE_TRANSFORM_Y = 6,
	CHANNEL_TYPE_TRANSFORM_Z = 7,
	CHANNEL_TYPE_QUATERNION_SPHERICAL_TRANSFORM_XYZ = 8,
	CHANNEL_TYPE_NUM = 9
};

typedef struct channel_s {
	int id;
	int type;
	float duration;
	int numKeyframes;
	int *keyframeList;
	float *data;
	struct channel_s *prev;
	struct channel_s *next;
} channel;

typedef struct {
	float m[4][4];
	float m2[4][4];
} animRawCSCam_t;

typedef struct {
	float dx;
	float dy;
	float dz;
	float r;
	float g;
	float b;
} animRawCSLight_t;

typedef struct animHeader_s {
	int totalFrames;
	int numKeyframes;
	int numJoints;
	int fAnimProp;
	float length;
	int *pKeyframes;
	int unused;
	int numChannels;
	channel *pChannel;
} animHeader;

typedef struct animChannel_s {
	int id;
	int type;
	float duration;
	int numKeyframes;
	int *keyframeList;
	float *data;
	channel *prev;
	channel *next;
} animChannel;

typedef struct {
	int totalFrames;
	int numKeyframes;
	int numJoints;
	int fAnimProp;
	float length;
	int *pKeyframes;
	int framelastplayed;
	int numChannels;
	channel *pChannel;
} animInfoProp;

typedef struct {
	char id[4];
	int animHeaderOfs;
	int animRawCSCamOfs;
	int animRawCSCamLen;
	int animRawCSLightOfs[3];
	int animRawCSLightLen[3];
} animRawHeader_t;

typedef struct animinfo_s {
	int num;
	float time;
	float curpos[3];
	float lastpos[3];
	float relpos[3];
	float speed;
	float tagtime;
	float lastrot;
	int fAnimLooped;
	int flag;
} animinfo;

typedef struct skeleton_s {
	mtx_u *matrices;
	animData *ad;
	int id;
	int type;
	u8 *bindfile;
} skeleton;

typedef struct jointanimframe_s {
	float trans[3];
	float rot[3];
} jointanimframe;

typedef struct jointanimframequat_s {
	float trans[3];
	quaternion q;
} jointanimframequat;

typedef struct keyframe_s {
	float time;
	keyframe_s *next;
	jointanimframe data[0];
} keyframe;

typedef struct anim_s {
	int numjoints;
	int numkeyframes;
	float length;
	keyframe *firstkeyframe;
	float rootTrans[3];
} anim;

enum {
	ANIM_NONE = 0,
	ANIM_SOFTWARE = 1,
	ANIM_BIND_POSE = 2,
	ANIM_STAND = 3,
	ANIM_RUN = 4,
	ANIM_RUNBACK = 5,
	ANIM_RUNLEFT = 6,
	ANIM_RUNRIGHT = 7,
	ANIM_WALK = 8,
	ANIM_WALKBACK = 9,
	ANIM_WALKLEFT = 10,
	ANIM_WALKRIGHT = 11,
	ANIM_PATROL = 12,
	ANIM_PATROL2 = 13,
	ANIM_PATROL3 = 14,
	ANIM_PATROL4 = 15,
	ANIM_SEARCHINGPATROL = 16,
	ANIM_SEARCHINGPATROL2 = 17,
	ANIM_SEARCHINGPATROL3 = 18,
	ANIM_SEARCHINGPATROL4 = 19,
	ANIM_ACTINGPATROL = 20,
	ANIM_PATROLREACTION = 21,
	ANIM_PATROLREACTSHORT = 22,
	ANIM_PATROLWALKTOSTAND = 23,
	ANIM_PATROLIDLE1 = 24,
	ANIM_PATROLIDLE2 = 25,
	ANIM_PATROLIDLE3 = 26,
	ANIM_PATROLSTANDTOWALKLEFT = 27,
	ANIM_PATROLSTANDTOWALKRIGHT = 28,
	ANIM_PATROLSTANDTOWALK180 = 29,
	ANIM_PATROLSTANDTOWALK = 30,
	ANIM_PATROLTURN90LEFT = 31,
	ANIM_PATROLTURN90LEFT2 = 32,
	ANIM_PATROLTURN90RIGHT = 33,
	ANIM_PATROLTURN90RIGHT2 = 34,
	ANIM_PATROLTURN90RIGHT3 = 35,
	ANIM_PATROLTURN90RIGHT4 = 36,
	ANIM_DIVE = 37,
	ANIM_SHUFFLE_LEFT = 38,
	ANIM_SHUFFLE = 39,
	ANIM_SIDESTEP_RIGHT = 40,
	ANIM_SIDESTEP_RIGHTLITTLE = 41,
	ANIM_SLIDE = 42,
	ANIM_SUMMERSAULT = 43,
	ANIM_LOWLEFT = 44,
	ANIM_BACKFLIP = 45,
	ANIM_CARTWHEEL = 46,
	ANIM_DIAGBACKRIGHT2 = 47,
	ANIM_DIAGFORLEFT = 48,
	ANIM_DIAGLEFTRIGHT = 49,
	ANIM_DOUBLEDODGE = 50,
	ANIM_DOUBLEDODGE_FLIPPED = 51,
	ANIM_ROLLRIGHT = 52,
	ANIM_ROLLLEFT_FLIPPED = 53,
	ANIM_STEPRIGHT = 54,
	ANIM_SMALLSTEP10 = 55,
	ANIM_SMALLSTEP9 = 56,
	ANIM_STEPBACK5 = 57,
	ANIM_SMALLSTEPBACK = 58,
	ANIM_FAINTLEFT = 59,
	ANIM_FAINTRIGHT_FLIPPED = 60,
	ANIM_STRAFEFARRIGHT = 61,
	ANIM_DODGELEFTRIGHT = 62,
	ANIM_STRAFEFARLEFT = 63,
	ANIM_TURNANDRUN = 64,
	ANIM_RETREAT = 65,
	ANIM_MOVEFORWARD = 66,
	ANIM_MOVELEFT = 67,
	ANIM_MOVERIGHT = 68,
	ANIM_STANDFEINTLEFT = 69,
	ANIM_STANDFEINTRIGHT = 70,
	ANIM_DROPTOKNEE = 71,
	ANIM_ONKNEE = 72,
	ANIM_STANDFROMKNEE = 73,
	ANIM_AMBUSH_SAL = 74,
	ANIM_AMBUSH_SALB = 75,
	ANIM_AMBUSH_STANDPOSE_FLIP = 76,
	ANIM_AMBUSH_STANDPOSE = 77,
	ANIM_AMBUSH_CRATE_TOSTAND = 78,
	ANIM_AMBUSH_CRATE_TOCROUCH = 79,
	ANIM_AMBUSH_CRATE_STAND = 80,
	ANIM_AMBUSH_CRATE_CROUCH = 81,
	ANIM_AMBUSH_CRATE_GRENADE = 82,
	ANIM_AMBUSH_CRATE_SHOOTOVER = 83,
	ANIM_AMBUSH_CROUCHATTACK_BACK_FLIP = 84,
	ANIM_AMBUSH_CROUCHATTACK_BACK = 85,
	ANIM_AMBUSH_CROUCHATTACK_FLIP = 86,
	ANIM_AMBUSH_CROUCHATTACK = 87,
	ANIM_AMBUSH_ROLLATTACK_BACK_FLIP = 88,
	ANIM_AMBUSH_ROLLATTACK_BACK = 89,
	ANIM_AMBUSH_ROLLATTACK_FLIP = 90,
	ANIM_AMBUSH_ROLLATTACK = 91,
	ANIM_AMBUSH_SPRAYATTACK_BACK_FLIP = 92,
	ANIM_AMBUSH_SPRAYATTACK_BACK = 93,
	ANIM_AMBUSH_SPRAYATTACK_FLIP = 94,
	ANIM_AMBUSH_SPRAYATTACK = 95,
	ANIM_AMBUSH_WALL1_BACK_FLIP = 96,
	ANIM_AMBUSH_WALL1_BACK = 97,
	ANIM_AMBUSH_WALL1_FLIP = 98,
	ANIM_AMBUSH_WALL1 = 99,
	ANIM_AMBUSH_WALL2_BACK = 100,
	ANIM_AMBUSH_WALL2_FLIP = 101,
	ANIM_AMBUSH_WALL2 = 102,
	ANIM_AMBUSH_WALL3_BACK_FLIP = 103,
	ANIM_AMBUSH_WALL3_BACK = 104,
	ANIM_AMBUSH_WALL3_FLIP = 105,
	ANIM_AMBUSH_WALL3 = 106,
	ANIM_HR_LEFTSHOULDER = 107,
	ANIM_HR_LEFTSTOMACH = 108,
	ANIM_HR_RIGHTLEG = 109,
	ANIM_HR_RIGHTSHOULDER = 110,
	ANIM_HR_RIGHTSTOMACH = 111,
	ANIM_SHOTHEAD = 112,
	ANIM_SHOTHEAD2 = 113,
	ANIM_SHOTHEAD3 = 114,
	ANIM_SHOTSHOULDER = 115,
	ANIM_CHESTSHOT1 = 116,
	ANIM_CHESTSHOT2 = 117,
	ANIM_HEARTSHOT = 118,
	ANIM_RIGHTFRONT = 119,
	ANIM_SHOTSHOULDER2 = 120,
	ANIM_OVERWRITE = 121,
	ANIM_OVERWRITE2 = 122,
	ANIM_BARRELOVERWRITE = 123,
	ANIM_PUNCH = 124,
	ANIM_CUTSCENE = 125,
	ANIM_CS_INTRO_DAM_1 = 126,
	ANIM_CS_INTRO_DAM_2 = 127,
	ANIM_CS_INTRO_DAM_3 = 128,
	ANIM_CS_INTRO_DAM_4 = 129,
	ANIM_CS_INTRO_DAM_5 = 130,
	ANIM_CS_INTRO_DAM_6 = 131,
	ANIM_CS_INTRO_DAM_7 = 132,
	ANIM_CS_INTRO_DAM_8 = 133,
	ANIM_CS_INTRO_DAM_9 = 134,
	ANIM_CS_INTRO_DAM_10 = 135,
	ANIM_CS_INTRO_DAM_11 = 136,
	ANIM_CS_INTRO_DAM_12 = 137,
	ANIM_CS_INTRO_DAM_13 = 138,
	ANIM_CS_INTRO_DAM_14 = 139,
	ANIM_CS_INTRO_DAM_15 = 140,
	ANIM_CS_INTRO_DAM_16 = 141,
	ANIM_CS_INTRO_DAM_17 = 142,
	ANIM_CS_INTRO_DAM_18 = 143,
	ANIM_BARRELWALK = 144,
	ANIM_BARRELTOTURRET = 145,
	ANIM_BARRELDROPTOTURN = 146,
	ANIM_BARRELENDTURN = 147,
	ANIM_BARRELSTANDTOWALK = 148,
	ANIM_BARRELSTARTTURN = 149,
	ANIM_BARRELTURNTOSTAND = 150,
	ANIM_BARRELTURRETTOSTAND = 151,
	ANIM_ZOMBIESTAND = 152,
	ANIM_ZOMBIESTAND2 = 153,
	ANIM_ZOMBIEGETUP1 = 154,
	ANIM_ZOMBIEGETUP2 = 155,
	ANIM_ZOMBIESWIPE1 = 156,
	ANIM_ZOMBIESWIPE2 = 157,
	ANIM_ZOMBIESWIPE3 = 158,
	ANIM_ZOMBIESWIPE4 = 159,
	ANIM_ZOMBIEWALK1 = 160,
	ANIM_ZOMBIEWALK2 = 161,
	ANIM_ZOMBIEWALK3 = 162,
	ANIM_NUM = 163
};

enum {
	ANIM_FE_NONE = 163,
	ANIM_FE_SOFTWARE = 164,
	ANIM_FE_BIND_POSE = 165,
	ANIM_FE_STAND = 166,
	ANIM_FE_FSTAND = 167,
	ANIM_FE_NUM = 168,
	ANIM_ALL_NUM = 168
};

// Actually a bitmask, these are flags.
enum {
	ANIMPROP_NULL = 0,
	ANIMPROP_LOOPING = 1,
	ANIMPROP_ROOT_TRANSLATE = 2,
	ANIMPROP_NOTAG = 4,
	ANIMPROP_NOINTERRUPT = 8,
	ANIMPROP_NOTWEENFROM = 16,
	ANIMPROP_DEATH = 32,
	ANIMPROP_POINTING = 256,
	ANIMPROP_TRAVERSAL = 512,
	ANIMPROP_ANGLE_L90 = 1024,
	ANIMPROP_ANGLE_R90 = 2048,
	ANIMPROP_ANGLE_180 = 4096,
	ANIMPROP_PATROLCANROTATE = 8192,
	ANIMPROP_NOROTATE = 16384,
	ANIMPROP_TAGAIMING = 32768,
	ANIMPROP_NUM = 32769
};


typedef struct obinst_s {
	obdef *ob;
	mtx_u *matrices;
	mtx_u *rmatrices;
	mtx_u *lightdir;
	mtx_u *lightcol;
	int lastlight[2];
	float lastlightpos[2][3];
	float lastlightcol[2][3];
	skeleton_s *skel;
	skelmatrices *skelmtx;
	int overwriteparts;
	int overwriteanimnum;
	float overwriteanglex;
	float overwriteangley;
	float lastoverwriteanglex;
	float lastoverwriteangley;
	float aimingtweentime;
	float aimingtweencurrtime;
	int aimingStatus;
	animinfo anim1;
	animinfo anim2;
	int animdelaynum;
	float animdelayblendtime;
	float animdelayspeed;
	float animblendtime;
	float animblendfrac;
	float animblendcurrtime;
	prop_s *prop;
	gfxpointers *override;
	u32 ***overridedma[2][2][3];
	u32 **overridergb[2][3];
	int overridetile;
	int overridebuf;
	u16 switchflags;
	u16 overrideflags;
	s8 overridealphastate;
	s8 overridezbstate;
	s8 spare;
	u8 fixedalpha;
	float overrideambientscale;
	u8 overrideambientCol[4];
} obinst;

typedef struct {
	u16 keyframenum;
	u16 tags;
} kftaginfo_t;

typedef struct {
	int version;
	int animProperties;
	int numKeyframes;
	int numTaggedKeyframes;
	kftaginfo_t tags[0];
} animinfoheader_t;

extern animRawHeader_t *csAnimHeader;
extern animRawHeader_t *animHeaders[5];
extern skeleton skeletons[5];
extern animInfoProp *pAnimations[168];
extern animinfoheader_t *pAnimInfo[168];

void animUpdate(obinst *inst);
void calPropMatrices(cs_animheader *cs, int slotnum, obinst *inst, float scale);
void animUpdateTime(animinfo *ai, float scale);
void calOverwriteKeyFrame(prop *p, animData *ad, int part);
void animSetOverwriteAngles(prop *p);
int animTestDestPos(prop *p, int anim, float *destpos);
void loadAnimation(char *filename, int tabEntry);
void loadAnimationRawEx(char *filename, int tabEntry, u8 *bufferloaddynamic);
void setAnimProp(int tabEntry, int fProp);
int getAnimProp(int tabEntry);
animInfoProp* getAnimation(int tabEntry);
void calGlobalMatrices(obinst *inst, mtx_u *m, int partnum, int parent);
void calGlobalFilletMatrices(obinst *inst, mtx_u *m, int partnum, int parent);
void calDoubleFillets(obinst *inst, int partnum, int relocating);
void getKeyFrames(animinfo *ai, float animLength, int *key1, int *key2);
boolean animIsPaused(obinst *inst);
boolean animIsEnded(obinst *inst);
boolean animIsBlended(obinst *inst);
void animPause(obinst *inst);
void animContinue(obinst *inst, float speed);
void animRewind(obinst *inst);
void animSetKeyframe(obinst *inst, int keyframenum);
int animGetKeyframe(obinst *inst);
int animGetTag(int animnum, u16 keyframetag, int nth);
int animGetCurKeyframeTags(obinst *inst);
void setAnim(prop *p, int anim, float blendtime, float speed);
void animSetAiming(obinst *inst, int status, float tweentime);
void setAnimOverwrite(obinst *inst, int overwriteparts, int animnum);
void extractAnimData(animInfoProp *pAnimCycle, int channelnum, int key, animData *ad, float scale);
void extractAnimRoot(prop *p, float *t1, float *t2, float *frames, int daxis);
void extractAnimRootData(prop *p, int animnum, float *t1, float *t2, float *frames, int daxis);
void anim_LoadMatrix(int num);
void anim_SetMatrixArray(mtx_u *m);
void anim_SetModelview(mtx_u *m, int multpush);
void anim_PopModelview();
mtx_u* anim_GetModelview();
int curAnim(prop *p, int anim);
int curAnimType(prop *p);
int curAnimSlot1(prop *p, int anim);
int curAnimSlot2(prop *p, int anim);
int curAnimComplete(obinst *ob);
int curAnimLeadingOut(obinst *inst, float leadout);
void curAnimSpeed(obinst *ob, float speed);
void animHitReact(prop *p, int parthit);
void animRestart();
void animReset(int cutscene);
void animMake(int makeCutscene);

#endif // GAME_ANIM_ANIM_H
