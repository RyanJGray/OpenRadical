//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_BG_BG_H
#define GAME_BG_BG_H

#include "common.h"
#include "fx/weather.h"
#include "fx/particle.h"

typedef struct room_s {
	obdef *ob;
	int *portals;
	weatherdef **weather;
	float bb[2][3];
} room;

typedef struct portal_s {
	int room1;
	int room2;
	float normal[3];
	short int numpoints;
	short int flags;
	float points[0][3];
} portal;

typedef struct volume_s {
	int num;
	int room;
	float pos[3];
	float size[3];
	float angle[3];
} volume;

typedef struct roombbinfo_s {
	float floorbb[2][3];
	float wallbb[2][3];
	float polybb[2][3];
	float overallbb[2][3];
	float roomsize[3];
	float centrepos[3];
	float bbRadius;
	float volume;
	float totalfloorvolume;
	float totalweatherfloorvolume;
	int numfloors;
} roombbinfo;

typedef struct leveltile_s {
	int tilenum;
	float trans[3];
	int rot;
	u16 switchmask;
	u32 lightcolour;
	int lighttype;
	int lightphase;
} leveltile;

typedef struct tileloadinfo_s {
	room *rooms;
	portal **portals;
	texinfo *textures;
	volume *volumes;
	int numrooms;
	int numportals;
	int numtextures;
	int numvolumes;
	int roomstart;
	int portalstart;
	int texturestart;
	int lighttype;
	int lightphase;
	u16 seals;
	u32 col;
} tileloadinfo;

extern roombbinfo *roombb;
extern int bgNumRooms;
extern int bgNumPortals;
extern int bgNumVolumes;
extern prop **roomprops;
extern int *roomVisibilityAllViews;

int bgGetLevelTextureID(int leveltextureindex);
void bgLoad(u8 *filename);
void bgCalcRoomVisibility();
void bgTileLoad(tileloadinfo *tile, leveltile *lt, int tileset);
void bgTileSetRoomNums(tileloadinfo *tile);
void bgTileSetPortalNums(tileloadinfo *tile);
void bgTileSetTextureNums(tileloadinfo *tile);
void bgPreload();
void bgPreloadTextures();
void bgRestart();
void bgReset();
void bgEnd();
void bgGetPropRoomClipRec(prop *p);
void bgGfx();
void bgGetRoomsTick();
int bgRoomGetLevel(int room);
int bgRoomBBIntersectionNumRooms(float *bb[3]);
int bgPosGetRooms(float *pos, int *rooms, int maxrooms);
void bgRoomBBIntersectionArray(int *therooms, float *bb[3]);
int bgRoomBBIntersection(float *bb[3], int *rooms, int maxrooms);
int bgFloorBBIntersection(float *bb[3], int *rooms, int maxrooms);
int bgFloorBBIntersectionXZ(float *bb[3], int *rooms, int maxrooms);
int bgWallBBIntersection(float *bb[3], int *rooms, int maxrooms);
int bgPortalBBIntersection(float *bb[3], int *rooms, int maxrooms);
int bgGetNeighbours(int room, int *rooms, int maxrooms);
partdef* bgGetPart(int room);
int bgGetNumFloors(int room);
floordef** bgGetFloors(int room);
int bgGetNumWalls(int room);
walldef** bgGetWalls(int room);
int bgGetNumGlass(int room);
glassdef** bgGetGlass(int room);
int bgGetNumSpecial(int room);
specialdef** bgGetSpecial(int room);
weatherdef** bgGetWeather(int room);
volume* bgGetVolume(int num);
void bgPortalDisable(int num);
void bgPortalEnable(int num);
void bgPortalDisableFromRooms(int r1, int r2);
void bgPortalEnableFromRooms(int r1, int r2);
void bgPortalTick();
void bgPortalGfx();
void bgPortalRectGfx();
void bgVolumeGfx();
void bgFloorGfx();
void bgWallGfx();
void bgBBGfx();
void bgWeatherBBGfx();
int bgPortalCrossed(float *startpos, float *dir, int startroom, int notroom, int infinite, float *hitpos, float *newdir);
int bgLineGetEndRoom(float *Pos, int PosRoom, float *Dir, int Infinite);
prop* bgLineTest(int startroom, float *startpos, float *dir, int infinite, float *hitpos, float *hitnorm, int *newroom, int excludeflag, int CollisionTypeFlag, glassResults *glassRes);
int bgAmountGlassLeft();
int bgAllGlassBroken();
void bgTick();
float bgCalcFloorVolume(floordef *floor);

#endif // GAME_BG_BG_H
