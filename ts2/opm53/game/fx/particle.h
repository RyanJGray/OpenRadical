// STATUS: NOT STARTED

#ifndef GAME_FX_PARTICLE_H
#define GAME_FX_PARTICLE_H

struct glasspointdef_s {
	float pos[3];
	float stnorm[3];
	u32 rgba;
};

typedef glasspointdef_s glasspointdef;

struct glassData_s {
	mtx_u mat[80];
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
};

typedef glassData_s glassData;

struct particleClone_s {
	mtx_u matrix;
	particleClone_s *next;
	int flags;
	int numRooms;
	int rooms[20];
};

typedef particleClone_s particleClone;
typedef particlegroup_s particlegroup;
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
void particleSparkBurstGfx(particlegroup *pg, mtx_u *matrix);
void particleSparkStreamGfx(particlegroup *pg, mtx_u *matrix);
void particleDraw(int texwidth, int texheight, u32 abgr, float *scrpos1, float *scrpos2, float *scrpos3, float *scrpos4);
void particleRender(int texture, float *passpos, float size, float rot, u32 abgr);
void particleSpriteGfx(particlegroup *pg);
void particleBeamGfx(float *startpos, float *normal, float *axis1, float *axis2, float length, float radius, float angle, u32 abgr, float *fadeScalarArray);
void particleGfx();
void particleGetClosestLight(obinst *inst, int InstID, float *pos, int PosRoom, bglighttest **Lights);
void fxBBGfx(float *pos, float *bb[3]);

#endif // GAME_FX_PARTICLE_H
