// STATUS: NOT STARTED

#include "mm_objs.h"

int nummapobjects = 0;
object_t *mapobjects = NULL;
object_t *objects = NULL;
item_t *itemspool = NULL;
static object_t *freeobjs;
int numfreeobjs = 0;
static item_t *freeitems;
static int numfreeitems;

int debugitems() {}

void MM_ClearObjects() {
	int i;
}

object_t* MM_AllocObject() {
	object_t *obj;
}

void MM_FreeSingleObject(object_t *obj) {
	object_t *ob;
}

void MM_FreeObject(object_t *obj) {
	object_t *next;
}

boolean MM_PlaceObject(object_t *obj) {
	object_t *ob;
	int tiles;
	int items;
	int objcost;
	int nitems;
}

object_t* MM_NewTile(int tilenum, fix_t x, fix_t y, int up, int anglerot) {
	object_t *ob;
}

static item_t* MM_AllocItem() {
	item_t *item;
}

void MM_FreeItem(object_t *ob, item_t *item) {
	item_t *l;
	item_t *tmp;
	item_t *previtem;
}

void MM_DuplicateItems(object_t *srcob, object_t *destob) {
	item_t *srcitems;
	item_t *destitems;
	item_t *newitem;
}

item_t* MM_NewItem(object_t *ob, u16 padextref, int itemnum, itemangle_t angle) {
	item_t *item;
	item_t *itemtmp;
}

item_t* objFindItem(object_t *obj, int padextref, int itemnum) {
	item_t *it;
}

int MM_ObjCount(objtype_t type) {
	int count;
	object_t *ob;
}

int MM_MapCost() {
	object_t *ob;
	int cost;
}

int MM_ItemListCount(item_t *list, int itemnum) {
	int count;
}

int MM_ItemCount(int itemnum) {
	int numitems;
	object_t *obj;
}

void MM_ItemGroupCount(item_t *items, int *groupcounts) {}

u8* MM_ItemGroupName(int itemgroup) {}
