//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_PARTICLE_H
#define GAME_FX_PARTICLE_H

#include "common.h"
#include "util/matrix.h"
#include "decal.h"

enum {
	PARTICLEID_ROCKETSMOKETRAIL = 0,
	PARTICLEID_TNTSMOKETRAIL = 1,
	PARTICLEID_TNTSPARKTRAIL = 2,
	PARTICLEID_CLUSTER_GRENADESMOKETRAIL = 3,
	PARTICLEID_EMP_GRENADESMOKETRAIL = 4,
	PARTICLEID_GAS_GRENADESMOKETRAIL = 5,
	PARTICLEID_TIMED_GRENADESMOKETRAIL = 6,
	PARTICLEID_ROCKETSMOKESTREAM = 7,
	PARTICLEID_PLANETSPAWN = 8,
	PARTICLEID_SPHEREROTATESPAWN = 9,
	PARTICLEID_RINGSPAWN1 = 10,
	PARTICLEID_RINGSPAWN2 = 11,
	PARTICLEID_EXPLOSIONSMOKE = 12,
	PARTICLEID_EXPLOSIONSMOKETHICK = 13,
	PARTICLEID_BLASTSHARDORANGE = 14,
	PARTICLEID_CRATESMOKE = 15,
	PARTICLEID_CRATESMOKEQUICK = 16,
	PARTICLEID_PICKUPSPAWN = 17,
	PARTICLEID_TOXIC = 18,
	PARTICLEID_CRYSTAL = 19,
	PARTICLEID_TIMESPLITTER_HANDS = 20,
	PARTICLEID_TIMESPLITTER_RADIUS = 21,
	PARTICLEID_CRANESPARKS = 22,
	PARTICLEID_THICKCHIMNEYSMOKESTREAM = 23,
	PARTICLEID_MANHOLESMOKESTREAM = 24,
	PARTICLEID_DAMTUNNEL_THICKSTEAMSTREAM = 25,
	PARTICLEID_DAMSTAIRCASE_THICKSTEAMSTREAM = 26,
	PARTICLEID_FIREEXT_THICKFOAMSTREAM = 27,
	PARTICLEID_FLAMETORCHCINDERS = 28,
	PARTICLEID_TRAINSPARKS = 29,
	PARTICLEID_REDBLOOD = 30,
	PARTICLEID_GREENBLOOD = 31,
	PARTICLEID_SPLITTERBLOOD = 32,
	PARTICLEID_ROBOTBLOOD = 33,
	PARTICLEID_REDBLOODTHICK = 34,
	PARTICLEID_GREENBLOODTHICK = 35,
	PARTICLEID_SPLITTERBLOODTHICK = 36,
	PARTICLEID_ROBOTBLOODTHICK = 37,
	PARTICLEID_ELECTRICHIT = 38,
	PARTICLEID_BLUEGLOW = 39,
	PARTICLEID_REDHIT = 40,
	PARTICLEID_CHARHIT = 41,
	PARTICLEID_LASERSPARKS_GREEN = 42,
	PARTICLEID_LASERSPARKS_BLUE = 43,
	PARTICLEID_LASERSPARKS_PURPLE = 44,
	PARTICLEID_LASERSPARKS_ORANGE = 45,
	PARTICLEID_LASERSPARKS_RED = 46,
	PARTICLEID_GUIDEDROCKETSTRIPTRAIL = 47,
	PARTICLEID_FIXEDROCKETSTRIPTRAIL = 48,
	PARTICLEID_COPTERROCKETSTRIPTRAIL = 49,
	PARTICLEID_BULLETTRAIL = 50,
	PARTICLEID_ARCLASERTRAIL = 51,
	PARTICLEID_ARCLASERHIT_SPRITE = 52,
	PARTICLEID_WALLHUGGERTRAIL = 53,
	PARTICLEID_BREATH = 54,
	PARTICLEID_DAMAGESPARKS_PINK = 55,
	PARTICLEID_DAMAGESPARKS_YELLOW = 56,
	PARTICLEID_DAMAGESMOKE = 57,
	PARTICLEID_SHOWER = 58,
	PARTICLEID_INVSHOWER = 59,
	NUM_PARTICLE_ID = 60
};

enum {
	PARTICLE_SMOKE_TEXTURE = 0,
	PARTICLE_THICKSMOKE_TEXTURE = 1,
	PARTICLE_SPARK_TEXTURE = 2,
	PARTICLE_EXPLOSION_TEXTURE1 = 3,
	PARTICLE_EXPLOSION_TEXTURE2 = 4,
	PARTICLE_STAR_TEXTURE = 5,
	PARTICLE_GLOW_TEXTURE = 6,
	PARTICLE_BLAST_TEXTURE = 7,
	PARTICLE_LASER_TEXTURE = 8,
	PARTICLE_ELECTRIC_TEXTURE = 9,
	PARTICLE_ELECTRICHIT_TEXTURE = 10,
	PARTICLE_TRACER_TEXTURE = 11,
	PARTICLE_LASERHIT_TEXTURE = 12,
	PARTICLE_SPARKGREY_TEXTURE = 13,
	PARTICLE_CHARHIT_TEXTURE = 14,
	PARTICLE_MUZZLE_TEXTURE = 15,
	PARTICLE_LASERFOG_TEXTURE = 16,
	PARTICLE_LASERSTATIC_TEXTURE = 17,
	NUM_PARTICLE_TEXTURES = 18
};

enum {
	PARTICLETYPE_NONE = -1,
	PARTICLETYPE_BULLETSPARKS = 0,
	PARTICLETYPE_SPRITESPARKS = 1,
	PARTICLETYPE_BULLETSMOKE = 2,
	PARTICLETYPE_TRACER = 3,
	PARTICLETYPE_SPRITEBURST_RGBA = 4,
	PARTICLETYPE_SPRITEBURST_ADDRGBA = 5,
	PARTICLETYPE_SPRITESTREAM_RGBA = 6,
	PARTICLETYPE_SPRITESTREAM_ADDRGBA = 7,
	PARTICLETYPE_SPRITETRAIL_RGBA = 8,
	PARTICLETYPE_SPRITETRAIL_ADDRGBA = 9,
	PARTICLETYPE_GLASS = 10,
	PARTICLETYPE_SPRITEMANUAL_RGBA = 11,
	PARTICLETYPE_SPRITEMANUAL_ADDRGBA = 12,
	PARTICLETYPE_GLOW = 13,
	PARTICLETYPE_SPRITE = 14,
	PARTICLETYPE_IMPACTEXPLOSION = 15,
	PARTICLETYPE_BLASTEXPLOSION = 16,
	PARTICLETYPE_PULSE = 17,
	PARTICLETYPE_SPARKBURST_RGBA = 18,
	PARTICLETYPE_SPARKBURST_ADDRGBA = 19,
	PARTICLETYPE_SPARKSTREAM_RGBA = 20,
	PARTICLETYPE_SPARKSTREAM_ADDRGBA = 21,
	PARTICLETYPE_SPARKSTREAM_INVISIBLE = 22,
	PARTICLETYPE_STRIPTRAIL_RGBA = 23,
	PARTICLETYPE_STRIPTRAIL_ADDRGBA = 24,
	PARTICLETYPE_STRAIGHTTRAIL_RGBA = 25,
	PARTICLETYPE_STRAIGHTTRAIL_ADDRGBA = 26,
	PARTICLETYPE_NUM = 27
};

typedef struct glasspointdef_s {
	float pos[3];
	float stnorm[3];
	u32 rgba;
} glasspointdef;

typedef struct glassdef_s {
	float state;
	int texture;
	int reflect;
	DecalID glassdecalID[4];
	int flags;
	u32 numpoints;
	glasspointdef points[0];
} glassdef;

typedef struct glassData_s {
	mtx mat[80];
	float xyz[80][4][4];
	float stnorm[80][4][4];
	u32 abgr[80][4];
	float vel[80][3];
	float rot[80][3];
	float rotvel[80][3];
	float time[80];
	int texnum;
	int reflect;
	int glassPieces;
	int ucodetype;
} glassData;

typedef struct particleClone_s {
	mtx matrix;
	struct particleClone_s *next;
	int flags;
	int numRooms;
	int rooms[20];
} particleClone;

typedef struct particlegroup_s {
	int type;
	int particleID;
	int flags;
	float time;
	float endTime;
	void *ref;
	u8 *data;
	int numPoints;
	float pos[3];
	float groundHeight;
	float ratePerSecond;
	int viewMask;
	float delay;
	float velocity[3];
	float velocityRandom[3];
	float velocityBias[3];
	struct particlegroup_s *previous;
	struct particlegroup_s *next;
	float bbRelative[2][3];
	float bbAbsolute[2][3];
	int numRooms;
	int rooms[20];
	particleClone *clones;
} particlegroup;

typedef struct particleTypeInfo_s {
	char *name;
	int autoend;
	int maximum;
	int size;
} particleTypeInfo;

typedef struct particleTimeData_s {
	float lifeTime;
	float fadeInTime;
	float fadeOutTime;
	float deltaTime;
} particleTimeData;

typedef struct particleSizeData_s {
	float size;
	float sizey;
	float screenSizeMax;
	float screenSizeMaxy;
	float zBias;
	float aspect;
	float expansionRate[2];
} particleSizeData;

typedef struct particleMoveData_s {
	float rotation;
	float gravity;
	float velocity[3];
	float velocityRandom[3];
	float velocityBias[3];
	float trailDispersalRate[3];
	float bounceElasticityXZ;
	float bounceElasticityY;
} particleMoveData;

typedef struct particleInfo_s {
	int particleTextureIndex;
	int blendMode;
	int number;
	u32 abgr;
	particleTimeData timeData;
	particleSizeData sizeData;
	particleMoveData moveData;
} particleInfo;

typedef struct tracerDef_s {
	u32 colour;
	int particleTextureIndex;
	float lengthFP;
	float lengthTP;
	float screenWidthFP;
	float screenWidthTP;
} tracerDef;

typedef struct pulseDef_s {
	u32 colour;
	int particleTextureIndex;
} pulseDef;

extern char *particleTextureName[18];
extern particleTypeInfo particleTypeInfos[27];
extern particleInfo particleInfos[60];
extern tracerDef tracerDefs[1];
extern pulseDef pulseDefs[0];
extern float particleNumScale;
extern int particleTextureNum[18];
extern int impactExplosionTextureNum[8];
extern float particleSizeScale;

int particleGetTextureNum(int particleTexture);
void particlePreload();
void particleRestart();
void particleReset();
void particleEnd();
void particlePrintList(particlegroup *list);
void particlePrintSizes();
void particleFree(particlegroup *pg);
particlegroup* particleGetLastInUsedList(int type);
void particleDebug();
void particleSetClones(particlegroup *pg, particleClone *clones);
void particleSetViewmask(particlegroup *pg, int viewMask);
void particleSetDelay(particlegroup *pg, float delay);
void particleUpdateVelocity(particlegroup *pg, float *velocity);
void particleUpdateVelocityRandom(particlegroup *pg, float *velocityRandom);
void particleUpdateVelocityBias(particlegroup *pg, float *velocityBias);
void particleUpdateRate(particlegroup *pg, float ratePerSecond);
void particleUpdatePos(particlegroup *pg, float *pos);
void particleMoveSpriteStream(particlegroup *pg, float *pos);
void particleUpdateGroundHeight(particlegroup *pg, float groundHeight);
boolean particleIsTrailFull(particlegroup *pg);
boolean particleGroupIsVisible(particlegroup *pg, int flag);
boolean particleCloneIsVisible(particlegroup *pg, particleClone *clone, int flag);
particlegroup* particleNewBulletSparks(void *ref, float *startpos, float *bias);
particlegroup* particleNewSpriteSparks(void *ref, int type, float *startpos, float *bias);
particlegroup* particleNewBlastExplosion(void *ref, int explosionrendertype, float *startpos, u32 colour, float size);
void particleBlastExplosionTick(particlegroup *pg);
particlegroup* particleNewImpactExplosion(void *ref, int explosionrendertype, float *startpos, u32 colour, float size);
void particleImpactExplosionTick(particlegroup *pg);
particlegroup* particleNewBulletSmoke(void *ref, float *startpos);
particlegroup* particleNewPulse(void *ref, int type, float *startpos, float *dir, int viewMask);
particlegroup* particleNewTracer(void *ref, int subtype, float *pos, float *dir, int viewMask);
void particleTracerTick(particlegroup *pg);
particlegroup* particleNewSpriteTrail(void *ref, int particleID, int flags, float *pos);
particlegroup* particleNewSpriteManual(void *ref, int particleID, int flags, float *pos);
particlegroup* particleNewSpriteBurst(void *ref, int particleID, int flags, float *pos, float *velocityBias, float groundHeight);
particlegroup* particleNewSpriteStream(void *ref, int particleID, int flags, float *pos, float *velocity, float *velocityRandom, float *velocityBias, float groundHeight);
particlegroup* particleNewSparkBurst(void *ref, int particleID, int flags, float *pos, float *velocityBias, float groundHeight);
particlegroup* particleNewSparkStream(void *ref, int particleID, int flags, float *pos, float *velocityBias, float groundHeight);
particlegroup* particleNewStripTrail(void *ref, int particleID, int flags, float *pos);
void particleStripTrailTick(particlegroup *pg);
particlegroup* particleNewStraightTrail(void *ref, int particleID, int flags, float *pos, float *dir);
void particleStraightTrailTick(particlegroup *pg);
void particleStraightTrailGfx(particlegroup *pg);
void glassSetQuad(glassData *gd, int trianglenum, glasspointdef *point1, glasspointdef *point2, glasspointdef *point3, glasspointdef *point4, float *dir1, float *dir2, float *vertice1, float *vertice2, float *vertice3, float *vertice4, float *hitpos, float *smashamount, float *averageline, int endpiece, int flags);
particlegroup* particleNewGlass(void *pgref, int flags, int texnum, int reflect, float *velocity, glasspointdef *point1, glasspointdef *point2, glasspointdef *point3, glasspointdef *point4, float *hitpos, float *smashdir, float amount, float *specialcol, float *hitnorm);
particlegroup* particleNewSprite(void *ref, int particleID, int flags, float *pos, float *normal);
particlegroup* particleNewGlow(void *ref, int particleID, int flags, float *pos, float *dir, int viewMask);
void particleGlowTick(particlegroup *pg);
void particleGlowGfx(particlegroup *pg);
void particleSpriteTrailTick(particlegroup *pg);
void particleSpriteManualTick(particlegroup *pg);
void particleSpriteBurstTick(particlegroup *pg);
void particleSpriteStreamTick(particlegroup *pg);
void particleSparkBurstTick(particlegroup *pg);
void particleSparkStreamTick(particlegroup *pg);
void particleGlassTick(particlegroup *pg);
void particleTick();
void particleSparkBurstGfx(particlegroup *pg, mtx *matrix);
void particleSparkStreamGfx(particlegroup *pg, mtx *matrix);
void particleDraw(int texwidth, int texheight, u32 abgr, float *scrpos1, float *scrpos2, float *scrpos3, float *scrpos4);
void particleRender(int texture, float *passpos, float size, float rot, u32 abgr);
void particleSpriteGfx(particlegroup *pg);
void particleBeamGfx(float *startpos, float *normal, float *axis1, float *axis2, float length, float radius, float angle, u32 abgr, float *fadeScalarArray);
void particleGfx();
void particleGetClosestLight(obinst *inst, int InstID, float *pos, int PosRoom, bglighttest **Lights);
void fxBBGfx(float *pos, float *bb[3]);

#endif // GAME_FX_PARTICLE_H
