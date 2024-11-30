// STATUS: NOT STARTED

#ifndef GAME_MAPMAKER_MM_OBJS_H
#define GAME_MAPMAKER_MM_OBJS_H

struct item_s {
	u16 padextref;
	u16 itemnum;
	itemangle_t angle;
	item_s *next;
};

typedef item_s item_t;
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
