// STATUS: NOT STARTED

#ifndef GAME_CHR_INVENTORY_H
#define GAME_CHR_INVENTORY_H

struct inventoryItem_s {
	int pickupType;
	int subType;
	int propnum;
	inventoryDef *def;
	prop_s *pickupProp;
	inventoryItem_s *previous;
	inventoryItem_s *next;
};

typedef inventoryItem_s inventoryItem;

struct inventory_s {
	inventoryItem itemArray[20];
	inventoryItem *items;
	inventoryItem *freeItems;
	int numItems;
};

typedef inventory_s inventory;

void inventoryReset(inventory *inventory);
inventoryItem* inventoryAllocateItem(inventory *inventory);
void inventoryFreeItem(inventory *inventory, inventoryItem *item);
inventoryItem* inventoryAdd(inventory *inventory, int pickupType, int subType);
inventoryItem* inventoryAddItem(inventory *inventory, prop *pickupProp);
inventoryItem* inventoryGet(inventory *inventory, int pickupType, int subType);
void inventoryRemove(inventory *inventory, int pickupType, int subType);

#endif // GAME_CHR_INVENTORY_H
