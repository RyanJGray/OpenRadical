// STATUS: NOT STARTED

#ifndef GAME_ANIM_ANIM_H
#define GAME_ANIM_ANIM_H

struct animData_s {
	float x;
	float y;
	float z;
	float qx;
	float qy;
	float qz;
	float qw;
};

typedef animData_s animData;
typedef channel_s channel;

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

struct animinfo_s {
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
};

typedef animinfo_s animinfo;

struct skeleton_s {
	mtx_u *matrices;
	animData *ad;
	int id;
	int type;
	u8 *bindfile;
};

typedef skeleton_s skeleton;

struct obinst_s {
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
};

typedef obinst_s obinst;

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
