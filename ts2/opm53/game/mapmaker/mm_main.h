//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_MAPMAKER_MM_MAIN_H
#define GAME_MAPMAKER_MM_MAIN_H

#include "common.h"
#include "mapmaker/mm_draw.h"
#include "mapmaker/mm_objs.h"

typedef struct {
	object_t *pObj;
	int padextref;
} routenode_t;

typedef struct {
	int length;
	int mode;
	routenode_t nodes[8];
} patrolroute_t;

typedef struct editmodeinfo_s {
	char *desc;
	int icon;
} editmodeinfo_t;

extern editmodeinfo_t editmodeinfo[4];
extern u8 *mmtempbuffer;
extern int numpatrols;
extern patrolroute_t patrols[8];
extern s16 iHoldPatrol;
extern s16 iHoldPatrolPt;
extern int editmode;
extern u32 editflags;
extern int editlevel;
extern int otherlevel;
extern int warnlevel;
extern int mapcost;
extern int flyingobjcost;
extern object_t *highlightobj;
extern s16 highlightobjpad;
extern item_t *highlightobjitem;
extern int iHoldItem;
extern int iHoldItemAngle;
extern object_t *highlightplugtile;
extern int highlightplugnum;
extern object_t *usedobj;
extern object_t *mmcellobject;
extern fix_t lasso_x;
extern fix_t lasso_y;
extern int lassocount;
extern int highlightobjpatrol;
extern fix_t savemouse_x;
extern fix_t savemouse_y;

object_t* MM_CheckObject(fix_t mapcol, fix_t maprow);
u8 MM_CellBits(fix_t mx, fix_t my);
u16 MM_CellIPad(fix_t mx, fix_t my);
u16 MM_PadExtRefUnderCursor();
int MM_PadIndexUnderCursor();
item_t* MM_ItemUnderCursor();
int MM_FindPlug(object_t *ob, int pluginx, int pluginy, int pluginz, int plugindir, int pluginlen);
void MM_FindFacingPlug(object_t *pObjIn, int iPlugIn, object_t **pObjOut, int *iPlugOut);
boolean MM_CheckTilesConnect(object_t *pOb1, object_t *pOb2);
void MM_ClearTilePatrolPoints(object_t *pObj);
void MM_FindLassoed();
void MM_PlaceItemOnPad(object_t *pObj, int iPadExtRef, int itemnum, itemangle_t itemangle);
void MM_CenterFlyingObj();
void MM_ClearDoors(object_t *ob);
void MM_SetTileLight(object_t *ob, u8 type, u8 phase, u32 colour);
void MM_ClearMap();
void MM_ClampMouse(fix_t *margins);
void mapmakerTick();
u32 MM_WriteChunk(u8 *buffer, u32 bufpos, int chkid, int size);
int MM_CheckGameModes(int showmessage, u8 **returnmsg);
int MM_CalcFileSize();
void MM_GetTranslation(object_t *obj, int *trans);
int MM_SaveMapFile(u8 *buffer, boolean quicktestsave);
int MM_LoadMapFile(u8 *buffer, boolean undoload);
boolean MM_BackupMap();
void MM_UndoMap();
void mapmakerMake();
void mapmakerPreload();
void mapmakerReset();
void mapmakerEnd();

#endif // GAME_MAPMAKER_MM_MAIN_H
