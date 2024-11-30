//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_GUN_BULLET_H
#define GAME_GUN_BULLET_H

#include "gun/cartridge.h"
#include "ob/ob.h"
#include "prop/prop.h"

typedef struct fireInfo_s {
	int fireFlags;
	int bulletType;
	int numShots;
	int fireDelay;
	int singleShotTime;
	int repeatShotTime;
	float ricochet;
	float bulletSpeed;
	float inaccuracy;
	int singleShotAmmo;
	int repeatShotAmmo;
	int fireSoundNum;
	int repeatFireSoundNum;
	float repeatFireSoundTime;
	int cheatFireSoundNum;
	int cheatRepeatFireSoundNum;
	float cheatRepeatFireSoundTime;
	int cartridgeSoundNum;
	int cartridgeType;
	float cartridgeVelocityVariance[3];
	float cartridgeVelocityScale;
	int damageType;
	float dualShockPower;
	float dualShockPowerSlowdown;
	playerGunAnimationInfo_t plAnimationInfo;
} fireInfo_t;

typedef struct explosionDef_s {
	int explosionRenderType1;
	int explosionRenderType2;
	float damageFactor;
	float damageDist;
} explosionDef;

typedef struct laserNode_s {
	float origin[3];
	float pos[3];
	u32 alpha;
} laserNode;

typedef struct laserCoil_s {
	int numNodes;
	laserNode nodes[16];
	float angle;
	float cosangle;
	float sinangle;
	float radius;
	float timedelay;
	float speed1;
	float speed2;
} laserCoil;

typedef struct laserData_s {
	int numCoils;
	laserCoil coils[5];
	float endpos[3];
	float length;
} laserData;

typedef struct laserBoltDef_s {
	float radius;
	float length;
	u32 abgr;
	int repetitions;
} laserBoltDef;

typedef struct electricData_s {
	float discardTime;
	float translate;
	float endpos[3];
	float length;
	u32 randAlpha;
} electricData;

typedef struct bullet_s {
	int type;
	int subType;
	int damageType;
	int flags;
	int next;
	int prev;
	boolean ticked;
	float pos[3];
	float dir[3];
	float rotvel[3];
	float time;
	prop *hitprop;
	prop *prop;
	particlegroup *particlefx[4];
	int room;
	float ricochet;
	int isricochet;
	int ownertype;
	chrdata *firedByChr;
	prop *firedByProp;
	prop *attackerProp;
	float RoomHitPos[3];
	float RoomHitNorm[3];
	prop *pRoomHitProp;
	HitInfoDef RoomHitInfo;
	boolean FirstUpdate;
	prop *pPropAttachedTo;
	int MatrixNumAttachedTo;
	float AttachedPos[3];
	float AttachedNorm[3];
	int detonationStage;
	float normal[3];
	prop *clip;
	prop *mine;
	float basepos;
	int bounces;
	prop *target;
	float targetpos[3];
	int retargetcount;
	int voice;
	int soundsdone;
	float alpha;
	int aiming;
	int shellsfx;
	int explosionCauseType;
	laserData laser;
	electricData electric;
	float axis1[3];
	float axis2[3];
	float angle;
} bullet;

typedef struct bulletInfo_s {
	int groupType;
	float lightCol[3];
	float dualShockDamage;
	float dualShockSlowdown;
	int decalType;
	float decalScale;
	int paintballabgr;
	float paintballScale;
	int flags;
} bulletInfo;

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
