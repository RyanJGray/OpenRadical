//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_SPECIALFX_H
#define GAME_FX_SPECIALFX_H

#include "common.h"
#include "fx/particle.h"

// Forward-declarations.
struct prop_s;
struct particlegroup_s;
struct particleClone_s;

typedef struct specialpointdef_s {
	float pos[3];
	float norm[3];
} specialpointdef;

typedef struct specialdef_s {
	int type;
	int subtype;
	int flags;
	u32 numpoints;
	specialpointdef points[0];
} specialdef;

typedef struct specialfx_s {
	float pos[4];
	struct specialfx_s *nextUsed;
	struct specialfx_s *previousUsed;
	int type;
	int subtype;
	int flags;
	void *ref;
	void (*callback)(/* parameters unknown */);
	float param;
	float time;
	int closestRoom[16];
	int numRooms;
	int rooms[10];
	struct prop_s *prop[4];
	struct particlegroup_s *pg[4];
	struct particleClone_s clone;
	float onduration;
	float offduration;
	float translatex;
	float translatey;
	float intensity;
	void *extraInfo;
} specialfx;

extern specialfx *specialfxUsed;
extern struct particleClone_s *manHoleSmokeClones;
extern struct particleClone_s *flameTorchCindersClones;
extern specialfx specialfxGroups[30];
extern int specialfxNumInRoom[226];
extern specialfx *specialfxRooms[226][5];

void specialfxPreload();
void specialfxRestart();
void specialfxReset();
void specialfxEnd();
void specialfxFree(specialfx *spfx);
void specialfxOccasionalRocketSmokeNewParticles(specialfx *spfx);
void specialfxOccasionalRocketSmokeNew(specialfx *spfx);
void specialfxOccasionalRocketSmokeTick(specialfx *spfx);
void specialfxThickChimneySmokeNewParticles(specialfx *spfx);
void specialfxThickChimneySmokeNew(specialfx *spfx);
void specialfxThickChimneySmokeTick(specialfx *spfx, boolean visible);
void specialfxManHoleSmokeNew(specialfx *spfx);
void specialfxManHoleSmokeProtoTick(specialfx *spfx);
void specialfxThickSteamNew(specialfx *spfx);
void specialfxThickSteamTick(specialfx *spfx, boolean visible);
void specialfxPickupSpawnNew(specialfx *spfx);
void specialfxPickupSpawnTick(specialfx *spfx);
void specialfxFlameTorchNew(specialfx *spfx);
void specialfxFlameTorchProtoTick(specialfx *spfx, boolean visible);
void specialfxShowerTick(specialfx *spfx, boolean visible);
void specialfxTimePortalNew(specialfx *spfx);
void specialfxTimePortalTick(specialfx *spfx, boolean visible);
void specialfxTimePortalGfx(specialfx *spfx);
void specialfxLaserBeamNew(specialfx *spfx);
void specialfxLaserBeamTick(specialfx *spfx);
void specialfxLaserBeamGfx(specialfx *spfx);
void specialfxMoveTestRoom(int Chr, int Room, float *bb[3], float *StartPos, float Radius, float Height);
void specialfxTick();
void specialfxUpdatePos(specialfx *spfx, float *pos);
void specialfxFlameTorchGfx(specialfx *spfx);
void specialfxGfxRoom(int room);
boolean specialfxDoesTypeExist(int type);
specialfx* specialfxNew(int type, int subtype, float *pos, float param, void *extraInfo, void *ref, void (*callback)(/* parameters unknown */));
specialfx* specialfxNewFromDef(specialdef *special, int room);
void specialfxDrawBird(float *pos, float rotyRad, float wingsClosed, float size);

#endif // GAME_FX_SPECIALFX_H
