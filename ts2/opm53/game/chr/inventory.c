// STATUS: NOT STARTED

#include "inventory.h"

static inventoryDef itemInfo[1] = {
	/* [0] = */ {
		/* .propnum = */ 388,
		/* .name = */ 883,
		/* .flags = */ 0,
		/* .inventoryScale = */ 0.6f
	}
};

void inventoryReset(inventory *inventory) {
	int i;
}

inventoryItem* inventoryAllocateItem(inventory *inventory) {
	inventoryItem *oldHead;
}

void inventoryFreeItem(inventory *inventory, inventoryItem *item) {
	inventoryItem *oldFreeHead;
}

inventoryItem* inventoryAdd(inventory *inventory, int pickupType, int subType) {
	inventoryItem *item;
}

inventoryItem* inventoryAddItem(inventory *inventory, prop *pickupProp) {
	inventoryItem *item;
	pickupdata *pd;
}

inventoryItem* inventoryGet(inventory *inventory, int pickupType, int subType) {
	inventoryItem *item;
}

void inventoryRemove(inventory *inventory, int pickupType, int subType) {
	inventoryItem *item;
}
