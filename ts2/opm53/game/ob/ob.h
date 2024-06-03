// STATUS: NOT STARTED

#ifndef GAME_OB_OB_H
#define GAME_OB_OB_H

typedef unsigned int u32;

struct bglighttest_s {
	int Room;
	int ID;
	float Col[3];
	float Dir[3];
	float Dir1[3];
	float Dist;
	float Brightness;
};

typedef bglighttest_s bglighttest;
typedef light_s light;

struct partdef_s {
	char type;
	char matrixnum;
	char parent;
	char child;
	char next;
	char prev;
	char numlights;
	char numdofs;
	s16 numfloors;
	s16 numwalls;
	s16 numglass;
	s16 numspecial;
	s16 numbumppolys;
	s16 spare;
	gfxchunk *chunklists[3];
	light *lights;
	gfxpointers pointers[3];
	u16 switchmask;
	u16 numvtxs;
	u16 numtris;
	u16 pad;
	dof *dofs;
	floordef_s **floors;
	walldef_s **walls;
	glassdef **glass;
	specialdef **special;
	bumppolydef **bumppolys;
	obbounds *bounds[3];
	float weight;
};

typedef partdef_s partdef;

struct obdef_s {
	int numparts;
	int nummatrices;
	int lit;
	texinfo *texlist;
	u32 ***dmapointers[2][3];
	float globalscale;
	void *bounds;
};

typedef obdef_s obdef;

struct manualLighting_s {
	float ambient[3];
	float col1[3];
	float col2[3];
	float col3[3];
	float theta1;
	float theta2;
	float theta3;
	float phi1;
	float phi2;
	float phi3;
	float dist1;
	float dist2;
	float dist3;
};

typedef manualLighting_s manualLighting;

typedef struct {
	obinst *pInst;
	int Part;
	int GFXType;
	int Chunk;
	int Poly;
} HitInfoDef;

struct propdef_s {
	int type;
	obdef *ob;
	u8 *propname;
	u8 *filename;
	int skeletontype;
	skelmatrices *skelmtx;
	int OffScreenTickTime;
	int Flags;
};

typedef propdef_s propdef;
extern u32 vif_entry_loadlcol[0];
extern u32 vif_entry_loadm[0];
extern u32 vif_entry_loadm2[0];
extern u32 vif_entry_loadm3[0];
extern u32 vif_entry_loadm4[0];
extern u32 vif_entry_loadm5[0];
extern u32 vif_entry_loadm6[0];
extern u32 vif_entry_loadm7[0];
extern u32 vif_entry_loadm8[0];
extern u32 vif_entry_loadm9[0];
extern u32 vif_entry_loadm10[0];
extern u32 vif_entry_loadm11[0];
extern u32 vif_entry_loadm12[0];
extern u32 vif_entry_loadm13[0];
extern u32 vif_entry_loadm14[0];
extern u32 vif_entry_loadm15[0];
extern u32 vif_entry_loadm16[0];
extern u32 vif_entry_loadm17[0];
extern u32 vif_entry_loadm18[0];
extern u32 vif_entry_loadm19[0];
extern u32 vif_entry_loadm20[0];
extern u32 vif_entry_loadm21[0];
extern u32 vif_entry_loadldir1[0];
extern u32 vif_entry_loadldir2[0];
extern u32 vif_entry_loadldir3[0];
extern u32 vif_entry_loadldir4[0];
extern u32 vif_entry_loadldir5[0];
extern u32 vif_entry_loadldir6[0];
extern u32 vif_entry_loadldir7[0];
extern u32 vif_entry_loadldir8[0];
extern u32 vif_entry_loadldir9[0];
extern u32 vif_entry_loadldir10[0];
extern u32 vif_entry_loadldir11[0];
extern u32 vif_entry_loadldir12[0];
extern u32 vif_entry_loadldir13[0];
extern u32 vif_entry_loadldir14[0];
extern u32 vif_entry_loadldir15[0];
extern u32 vif_entry_loadldir16[0];
extern u32 vif_entry_loadldir17[0];
extern u32 vif_entry_loadldir18[0];
extern u32 vif_entry_loadldir19[0];
extern u32 vif_entry_loadldir20[0];
extern u32 vif_entry_loadldir21[0];
extern u32 *vif_entry_loadldir_num[21];
extern u32 *vif_entry_loadm_num[21];
extern u32 vifdata_loadxyzw[6][72];
extern u32 vifdata_loadnorm[6][72];
extern manualLighting manualLights[4];
extern int num_instances;
extern int num_deleted_instances;

void v3Normalize(float *out, float *in);
void v3NormalizeFaster(float *out, float *in);
void bglightCalculatePos();
void bglightRestart();
void bglightReset();
void bgSetCanAddLight(boolean CanAdd);
void bgInsertLightIntoList(bglighttest **pList, bglighttest **ppTest);
void bgLightsKeepVisible(bglighttest **pList, float *Pos, int PosRoom, int NumKeep);
void obInstLightUpdate(obinst *inst);
void obResetManualLight(int manualLightIndex);
void obEditFrontLights(int manualLightIndex);
void obRestart();
void obReset();
void obEnd();
void obRelocate(obdef *ob, u32 *base);
void obPreloadTextures(u8 *filename);
void obPreloadTexturesAfter(u8 *filename);
void obLoadSetClip(int clip);
void texinfoRelocate(texinfo *tex, u32 *base);
void obResetTextures();
void obLoadTextures(obdef *ob);
void obFreeTextures(obdef *ob);
obdef* obLoad(u8 *filename);
float obGetScale(obdef *p_ob);
void obPrecalcGfxData(obdef *ob);
void obPrecalcDbufGfxData(obinst *inst);
void obSetTexList(obdef *ob, texinfo *texlist, int offset);
void obTransform(obdef *ob, mtx_u *transmtx);
void obColour(obdef *ob, u32 col);
obinst* obInstNew(prop *p, propdef *pd);
void obInstResetOverride(obinst *inst);
void obInstDelete(obinst *inst);
void obInstSetAnim(obinst *inst, int animnum, float speed);
boolean obInstIsAnimSoftware(obinst *inst);
void obProcessGlows(prop *p, int partnum, partdef *part, mtx_u *pMat, mtx_u *worldMtx);
void obInstGfxAll(obinst *inst, int clipflag);
void obInstGfx(obinst *inst, int gfxtype, int clipflag);
void transformLimb(obinst *inst, partdef *part, mtx_u *mat);
void obConfirmLastHitInfo();
void obSetLastHitInfo(HitInfoDef *pInfo);
void obGetLastHitInfo(HitInfoDef *pInfo);
int obInstLineTest(obinst *inst, float *StartPosOrig, float *DirOrig, int infinite, float *hitpos, float *hitnorm);
void obInstSetOverrideStates(obinst *inst, int overridealphastate, int overrideditherstate, int overridezbstate, u8 fixedalpha);
void obInstSetOverrideCol(obinst *inst, float overrideambientscale, int colr, int colg, int colb);
void obInstAllocateOverridePointers(obinst *inst);
void obInstNullOverridePointers(obinst *inst);
u32* obInstGetOverrideChunk(obinst *inst, int partIndex, int gfxtype, int overrideFlag, int *numchunkptr, int *numgiftagsptr, int *numvtxptr);
void obInstAllocateOverrideChunk(obinst *inst, int partIndex, int gfxtype, int overrideFlags);
int partGetNumVertices(partdef *part, int gfxtype);
void partPrecalcSpecialfx(obinst *inst, int partnum, int gfxtype);
void obInstPrecalcSpecialfx(obinst *inst);

#endif // GAME_OB_OB_H
