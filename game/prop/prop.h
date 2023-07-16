// STATUS: NOT STARTED

#ifndef GAME_PROP_PROP_H
#define GAME_PROP_PROP_H

typedef void void;

struct glassResults_s {
	int numHits;
	int hitReverse;
	glassHit hits[5];
};

typedef glassResults_s glassResults;

struct s_PropBoundingBox {
	boolean calculated;
	float CentrePos[3];
	float Radius[3];
};

typedef s_PropBoundingBox PropBoundingBox;

struct PropBoundingInfo_s {
	PropBoundingBox overallBounds;
	int numExtraBounds;
	PropBoundingBox *extraBounds;
};

typedef PropBoundingInfo_s PropBoundingInfo;
typedef void (*handlerfunc)(/* parameters unknown */);
typedef prop_s prop;

struct pickupdata_s {
	int dataID;
	int type;
	int status;
	float data;
	int data2;
	int team;
	float dy;
	float homepos[3];
	float floorrotx;
	float floorrotz;
	int padnum;
	int homepadnum;
	int ammotype;
	int ammo;
	float targetpos[3];
	int destpad;
	int droppedstate;
	int dropperid;
	int framesleft;
	float rotvel[3];
	int pickupposindex;
	float pickupscale;
	float unique;
	float tailRotation;
	float lefthandRotation;
	float righthandRotation;
};

typedef pickupdata_s pickupdata;
extern propdef proptable[812];
extern int lastreactionframenum;
extern prop *p_roomprops[226][100];
extern int p_numroomprops[226];
extern pickupdata tmpPickupData[20];
extern int tmpPickupDataUsed[20];
extern prop *tmpPickupDataProp[20];
extern int tmpPickupDataFramenum[20];
extern PropBoundingInfo *propBoundingInfo[812];
extern int num_props;
extern int num_deleted_props;
extern int num_activate_props;
extern prop *ActiveProps[400];
extern int NumActiveProps;
extern boolean DrawBoundsRoom[225];

int propGetPropIndex(prop *p);
prop* propGetPropPtr(int p);
prop* propGetPropPtrAttachTo(int p, int m);
void propCollisionPreProcess();
void propDump(prop *pr, int n);
void propRestart();
void propReset();
void propEnd();
char* propGetName(int num);
void propSetOb(int num, obdef *ob);
void propSetHandler(prop *p, int event, handlerfunc pFunc);
void propSetDamageHandler(prop *p, void (*damageHandler)(/* parameters unknown */));
int getPropType(int propnum);
void propAddPreLoad(int num);
boolean propIsRoomsDrawnByAnyPlayer(prop *p);
boolean propIsOverPortal(prop *p);
prop* propGetAimProp();
void propCalcBoundsForPart(prop *pProp, int PartNum, float *Min, float *Max);
void propSetRadiusCentrePos(prop *pProp, float *Min, float *Max, float *Radius, float *CentrePos);
void propTransformBoundingBox(prop *pProp, int partNum, PropBoundingBox *box, float *Radius, float *CentrePos);
void propCalculateCentrePos(prop *pProp);
void propAllocateWallsFloorsGlassSpecial(prop *p);
void propSetupWallsFloorsGlassSpecial(prop *thisprop);
void propSetupBoundingInfo(prop *p);
prop* propNew(int num, float x, float y, float z, float roty);
prop* propXZRotNew(int num, float x, float y, float z, float *rot);
void propSwapNew(prop *p, int num);
void propChangeMesh(prop *p);
void propSetupSpecialfx(prop *p);
void propSetupMisc(prop *thisprop);
int getPropViewportDrawFlags();
void WritePropKeyFile();
void propDelete(prop *p);
void propDeleteCore(prop *p);
void propGlassTick(prop *p);
void propGlassGfx(prop *p);
prop* gunNew(int num, float x, float y, float z, float roty);
void propCalcRooms(prop *p);
void propSetRoom(prop *p);
void propUpdateRooms();
void tlhSwapDropColour(obinst *oi, int pdef);
boolean pickupChrProcess(prop *pickup, prop *chrprop);
void propEvictLimb(prop *p);
void propDeleteLimb(prop *p);
prop* propNewLimb(prop *chrattach, float *bulletnorm, float bulletspeed, int limbtype);
void propDrop(prop *oldprop, chrdata *cd, chrgun *cgun);
void propSetDrawFlags();
int propGetPopupbotListIndex();
void propSetupPopupbot(prop *p, int cindex);
void propSpawnProp(setuppropspawn *sps);
void propAlarmInform(int alarmnum);
void propCheckSpawnProp();
void propTickBefore();
void propTickAfter();
void propTickPlayer();
void propSetMatrices(prop *p);
void propGfxRoomPreproc();
void propGfxRoomClipProps(int room);
void propDrawLine(mtx_u *pView, float *v1, float *v2, int rgba);
void propDrawRec(mtx_u *pView, float *v1, float *v2, float *v3, float *v4, int rgba);
void propDrawBounds(prop *p);
void propDrawWalls(prop *p);
void propDrawFloors(prop *p);
void propDrawDebug();
void propGfxRoom(int room, int gfxtype);
void propSetAttached(prop *p, obinst *ob, int mtxnum, int flag);
void propSetMtxRoll(prop *p, obinst *ob, float *vel, float rotinc);
prop* propGetNext(prop *start, int proptype);
prop* propGetNum(int num);
prop* propLineTestRoom(int room, float *startpos, float *dir, int infinite, float *hitpos, float *hitnorm, int excludeflag, int CollisionTypeFlag, glassResults *glassRes);
int propMoveTestRoom(int Chr, int Room, float *bb[3], float *StartPos, float Radius, float Height, float *MoveDirXZ, float *pHitFrac, float *HitNormFrac, float *pHitDist, float *HitNormDist, boolean CanNotPush, int ExcludeFlag);
float propFindFloorHeightRoom(int Room, float *Pos, floordef **ppFloor, prop **ppProp);
prop* propSwipeTest(prop *pSwipeProp, float *SwipePosCentre, float *SwipePosStart, float *SwipePosEnd, float *HitPos, float *HitNorm);
void propGlassLineTest(prop *p, float *startpos, float *dir, int infinite, glassResults *glassRes);
void propGlassSwipeTest(prop *testProp, prop *pSwipeProp, float *SwipePosCentre, float *SwipePosStart, float *SwipePosEnd);
void propGlassSwipeTestRoom(int room, prop *pSwipeProp, float *SwipePosCentre, float *SwipePosStart, float *SwipePosEnd);
void propGlassMoveTest(int Chr, prop *p, float *StartPos, float *EndPos, float Height, float Radius);
void propGlassMoveTestRoom(int Chr, int room, float *StartPos, float *EndPos, float Height, float Radius);
void glassSmash(prop *p, glassdef *pGlass, float *HitPos, float *HitNorm, float *HitDir, float Amount, float *Col);
void glassProcessHits(glassResults *glassRes, int bullettype, float amount, float *col);
int propInPropList(prop *p);
prop* propNewPickupOnPadExtref(int propnum, int type, float data, int data2, int team, int extref, float rx, float ry, float rz, float dy, int ammotype, int ammo, int temporary);
void pickupposRestart();
void pickupposReset();
int pickupposAdd(float *pos);
void pickupposGfx();
float propPickupGetZRotation(prop *p, boolean dropped);
prop* propNewPickup(int propnum, int type, float data, int data2, int team, float x, float y, float z, float rx, float ry, float rz, float dy, int ammotype, int ammo, int temporary);
void propDeletePickup(prop *p);
void propMakeVisible(void *pickup);
void animMtxTick();
boolean propMovingPropInRange(float *Pos, int Room, float Dist);
void drumDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void plantDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void fruitDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void popupbotDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void crateDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void metalcrateDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void baseDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void damRadarDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void fileCabinetDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void propGenericTwoStateDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void propGenericThreeStateDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
int propNumBallelsNotBlownUp();
int propAllBallelsBlownUp();
void propBurningTick(prop *p);
void propRockingTick(prop *p);
void setupRockingProp(prop *p, float UpPulse);
boolean propRoomForMoreProps(int n);
void propSetFloorLevelForAllProps();
boolean propIsCloseToFloor(prop *p);

#endif // GAME_PROP_PROP_H
