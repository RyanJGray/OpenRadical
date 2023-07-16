// STATUS: NOT STARTED

#ifndef GAME_GUN_BULLET_H
#define GAME_GUN_BULLET_H

typedef fireInfo_s fireInfo_t;

struct explosionDef_s {
	int explosionRenderType1;
	int explosionRenderType2;
	float damageFactor;
	float damageDist;
};

typedef explosionDef_s explosionDef;
typedef bullet_s bullet;

struct bulletInfo_s {
	int groupType;
	float lightCol[3];
	float dualShockDamage;
	float dualShockSlowdown;
	int decalType;
	float decalScale;
	int paintballabgr;
	float paintballScale;
	int flags;
};

typedef bulletInfo_s bulletInfo;
extern laserBoltDef laserBolts[5];
extern explosionRender explosionRenders[6];
extern explosionDef explosionDefs[5];
extern bulletInfo bulletInfos[35];

bullet* bulletGetFromArray(int bulletIndex);
void bulletClearData(bullet *b);
void bulletRestart();
void bulletReset();
void bulletDetachParticlefx(bullet *b, int index);
void bulletFreeParticlefx(bullet *b, int index);
int bulletTypeExplosive(int bullettype);
bullet* bulletNew(int type);
void bulletFree(bullet *b);
void bulletNewBlood(int bloodType, prop *hitprop, float *hitpos, float *blooddir);
void bulletExplodeMines(float *Pos, float Dist);
void bulletGetMinesAttachedToProp(prop *p, int *proximitymines, int *remotemines, int *timedmines);
void bulletGetMinesAttachedToPropMatrix(prop *p, int matrixnum, int *proximitymines, int *remotemines, int *timedmines);
void bulletExplodeMine(bullet *b);
void bulletExplodeMineAtPos(bullet *b, float *pos);
bullet* bulletNewFromGun(int bulletType, float *fpShootPos, float *tpShootPos, float *dir, fireInfo_t *fi, prop *firedByProp, chrdata *firedByChr, int ownerType, int repeatFire, int bulletflag);
bullet* bulletNewExplosion(int explosionType, int bulletType, float *pos, float *hitnorm, prop *attackerProp, prop *hitprop);
void updateProximityProps(bullet *b, prop *owner);
void bulletRegularTick(bullet *b);
void bulletRocketTick(bullet *b);
void bulletGrenadeTick(bullet *b);
void bulletTNTTick(bullet *b);
void bulletBrickTick(bullet *b);
void bulletDiscTick(bullet *b);
void bulletMineTick(bullet *b);
void bulletPetrolTick(bullet *b);
void bulletPetrolGfx(bullet *b);
void bulletFlameTick(bullet *b);
void bulletNewLaserCoils(bullet *b);
void bulletLaserCoilsTick(bullet *b);
void bulletLaserCoilsGfx(bullet *b);
void bulletFlareTick(bullet *b);
void bulletElectroRocketTick(bullet *b);
void bulletElectricTickBefore(bullet *b);
void bulletElectricTickAfter(bullet *b);
void bulletElectricGfx(bullet *b);
void bulletNewWallHugger(bullet *b);
void bulletWallHuggerTick(bullet *b);
void bulletWallHuggerGfx(bullet *b);
void bulletLaserBoltTick(bullet *b);
void bulletLaserBoltGfx(bullet *b);
void bulletNewArcLaser(bullet *b);
void bulletArcLaserTick(bullet *b);
void bulletArcLaserGfx(bullet *b);
void bulletTickBefore();
void bulletTickAfter();
void bulletArcadeRocketGfx(bullet *b);
void bulletGfx();
void bulletEnd();
bullet* bulletFind(chrdata *firedByChr, int type);
void bulletGetBulletColour(int BulletType, float *Col);
void bulletGetClosestLight(obinst *inst, int InstID, float *pos, int PosRoom, bglighttest **Lights);
void bulletProcessGlasshits(bullet *b, glassResults *glassRes);
void bulletMakeAttachedMinesInvisible(prop *pProp);

#endif // GAME_GUN_BULLET_H
