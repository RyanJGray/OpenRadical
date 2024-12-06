//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_MAPMAKER_MM_OBJS_H
#define GAME_MAPMAKER_MM_OBJS_H

#include "common.h"
#include "mapmaker/mm_draw.h"
#include "mapmaker/mm_tiles.h"

enum {
	ITEM_NONE = -1,
	ITEM_START_FIRST = 0,
	ITEM_START_ALL = 0,
	ITEM_START_TEAM_A = 1,
	ITEM_START_TEAM_B = 2,
	ITEM_START_TEAM_C = 3,
	ITEM_START_TEAM_D = 4,
	ITEM_TELEPORT_FIRST = 5,
	ITEM_TELEPORT_A = 5,
	ITEM_TELEPORT_B = 6,
	ITEM_TELEPORT_C = 7,
	ITEM_TELEPORT_D = 8,
	ITEM_TELEPORT_E = 9,
	ITEM_TELEPORT_F = 10,
	ITEM_TELEPORT_G = 11,
	ITEM_TELEPORT_H = 12,
	ITEM_TELEPORT_I = 13,
	ITEM_TELEPORT_J = 14,
	ITEM_PICKUP_FIRST = 15,
	ITEM_DROP_TEAM_A = 15,
	ITEM_DROP_TEAM_B = 16,
	ITEM_DROP_TEAM_C = 17,
	ITEM_DROP_TEAM_D = 18,
	ITEM_PICKUP_GUN1 = 19,
	ITEM_PICKUP_GUN2 = 20,
	ITEM_PICKUP_GUN3 = 21,
	ITEM_PICKUP_GUN4 = 22,
	ITEM_PICKUP_GUN5 = 23,
	ITEM_PICKUP_AMMO1 = 24,
	ITEM_PICKUP_AMMO2 = 25,
	ITEM_PICKUP_AMMO3 = 26,
	ITEM_PICKUP_AMMO4 = 27,
	ITEM_PICKUP_AMMO5 = 28,
	ITEM_PICKUP_KEYCARD1 = 29,
	ITEM_PICKUP_KEYCARD2 = 30,
	ITEM_PICKUP_KEYCARD3 = 31,
	ITEM_PICKUP_KEYCARD4 = 32,
	ITEM_PICKUP_BAG = 33,
	ITEM_KNOCKOUT_BAG = 34,
	ITEM_PICKUP_HEALTH_LO = 35,
	ITEM_PICKUP_HEALTH_HI = 36,
	ITEM_PICKUP_ARMOUR_LO = 37,
	ITEM_PICKUP_ARMOUR_HI = 38,
	ITEM_POWERUP_1 = 39,
	ITEM_POWERUP_2 = 40,
	ITEM_POWERUP_3 = 41,
	ITEM_POWERUP_4 = 42,
	ITEM_POWERUP_5 = 43,
	ITEM_PROP_FIRST = 44,
	ITEM_PROP_CRATE = 44,
	ITEM_REMOTE_FIRST = 45,
	ITEM_REMOTE_GUNTURRET = 45,
	ITEM_REMOTE_AUTOGUN = 46,
	ITEM_NPC_FIRST = 47,
	ITEM_NPC_1 = 47,
	ITEM_NPC_2 = 48,
	ITEM_NPC_3 = 49,
	ITEM_NPC_4 = 50,
	ITEM_NPC_5 = 51,
	ITEM_NPC_6 = 52,
	NUM_ITEMS = 53
};

enum {
	ITEMGROUP_START = 0,
	ITEMGROUP_BASE1 = 1,
	ITEMGROUP_BASE2 = 2,
	ITEMGROUP_BASE3 = 3,
	ITEMGROUP_BASE4 = 4,
	ITEMGROUP_GUN = 5,
	ITEMGROUP_AMMO = 6,
	ITEMGROUP_KEYCARD1 = 7,
	ITEMGROUP_KEYCARD2 = 8,
	ITEMGROUP_KEYCARD3 = 9,
	ITEMGROUP_KEYCARD4 = 10,
	ITEMGROUP_TELEPORT = 11,
	ITEMGROUP_HEALTH = 12,
	ITEMGROUP_ARMOUR = 13,
	ITEMGROUP_POWERUP = 14,
	ITEMGROUP_BAGTAGBAG = 15,
	ITEMGROUP_KNOCKOUTBAG = 16,
	ITEMGROUP_PROP = 17,
	ITEMGROUP_REMOTE = 18,
	ITEMGROUP_NPCS = 19,
	ITEMGROUP_NUM = 20
};

typedef enum {
	ITEMANGLE_SOUTH = 0,
	ITEMANGLE_SOUTHWEST = 1,
	ITEMANGLE_WEST = 2,
	ITEMANGLE_NORTHWEST = 3,
	ITEMANGLE_NORTH = 4,
	ITEMANGLE_NORTHEAST = 5,
	ITEMANGLE_EAST = 6,
	ITEMANGLE_SOUTHEAST = 7,
	ITEMANGLE_NUM = 8
} itemangle_t;

typedef enum {
	OBJTYPE_UNDEFINED = 0,
	OBJTYPE_TILE = 1,
	OBJTYPE_NUM = 2
} objtype_t;

typedef struct item_s {
	u16 padextref;
	u16 itemnum;
	itemangle_t angle;
	struct item_s *next;
} item_t;

typedef struct object_s {
	objtype_t type;
	fix_t x;
	fix_t y;
	fix_t z;
	int angle;
	int cost;
	u16 flags;
	u8 lighttype;
	u8 lightphase;
	u32 lightcolour;
	u16 doors;
	u16 drawndoors;
	u8 doortype[8];
	tiledef *tile[4];
	item_t *items;
	struct object_s *next;
} object_t;

extern int nummapobjects;
extern object_t *mapobjects;
extern object_t *objects;
extern item_t *itemspool;
extern int numfreeobjs;

int debugitems();
void MM_ClearObjects();
object_t* MM_AllocObject();
void MM_FreeSingleObject(object_t *obj);
void MM_FreeObject(object_t *obj);
boolean MM_PlaceObject(object_t *obj);
object_t* MM_NewTile(int tilenum, fix_t x, fix_t y, int up, int anglerot);
void MM_FreeItem(object_t *ob, item_t *item);
void MM_DuplicateItems(object_t *srcob, object_t *destob);
item_t* MM_NewItem(object_t *ob, u16 padextref, int itemnum, itemangle_t angle);
item_t* objFindItem(object_t *obj, int padextref, int itemnum);
int MM_ObjCount(objtype_t type);
int MM_MapCost();
int MM_ItemListCount(item_t *list, int itemnum);
int MM_ItemCount(int itemnum);
void MM_ItemGroupCount(item_t *items, int *groupcounts);
u8* MM_ItemGroupName(int itemgroup);

#endif // GAME_MAPMAKER_MM_OBJS_H
