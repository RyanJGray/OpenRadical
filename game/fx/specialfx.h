// STATUS: NOT STARTED

#ifndef GAME_FX_SPECIALFX_H
#define GAME_FX_SPECIALFX_H

typedef specialpointdef_s specialpointdef;

struct specialdef_s {
	int type;
	int subtype;
	int flags;
	u32 numpoints;
	specialpointdef points[0];
};

struct specialfx_s {
	float pos[4];
	specialfx_s *nextUsed;
	specialfx_s *previousUsed;
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
	prop_s *prop[4];
	particlegroup_s *pg[4];
	particleClone clone;
	float onduration;
	float offduration;
	float translatex;
	float translatey;
	float intensity;
	void *extraInfo;
};

typedef specialfx_s specialfx;
extern specialfx *specialfxUsed;
extern particleClone *manHoleSmokeClones;
extern particleClone *flameTorchCindersClones;
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
specialfx* specialfxNewFromDef(specialdef_s *special, int room);
void specialfxDrawBird(float *pos, float rotyRad, float wingsClosed, float size);

#endif // GAME_FX_SPECIALFX_H
