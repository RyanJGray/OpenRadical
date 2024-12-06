//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_CHR_INVENTORY_H
#define GAME_CHR_INVENTORY_H

// Forward-declarations.
struct prop_s;

enum {
	INVENTORY_CANSELECT = 1,
	INVENTORY_ROTATEINARCADE = 2
};

typedef struct inventoryDef_s {
	int propnum;
	int name;
	int flags;
	float inventoryScale;
} inventoryDef;

typedef struct inventoryItem_s {
	int pickupType;
	int subType;
	int propnum;
	inventoryDef *def;
	struct prop_s *pickupProp;
	struct inventoryItem_s *previous;
	struct inventoryItem_s *next;
} inventoryItem;

typedef struct inventory_s {
	inventoryItem itemArray[20];
	inventoryItem *items;
	inventoryItem *freeItems;
	int numItems;
} inventory;

void inventoryReset(inventory *inventory);
inventoryItem* inventoryAllocateItem(inventory *inventory);
void inventoryFreeItem(inventory *inventory, inventoryItem *item);
inventoryItem* inventoryAdd(inventory *inventory, int pickupType, int subType);
inventoryItem* inventoryAddItem(inventory *inventory, struct prop_s *pickupProp);
inventoryItem* inventoryGet(inventory *inventory, int pickupType, int subType);
void inventoryRemove(inventory *inventory, int pickupType, int subType);

#endif // GAME_CHR_INVENTORY_H
