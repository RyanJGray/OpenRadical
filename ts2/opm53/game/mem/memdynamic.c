// STATUS: NOT STARTED

#include "memdynamic.h"

struct dynamicMemoryNode_s {
	int type;
	int length;
	int previousLength;
	void *ref;
	void (*callback)(/* parameters unknown */);
};

typedef dynamicMemoryNode_s dynamicMemoryNode;
int dynamicMemoryFreeSS = 0;
int dynamicMemorySSBufferSize = 0;
u8 *dynamicMemoryBufferSS = NULL;
u8 *dynamicMemoryAllocSS = NULL;
u8 *dynamicMemoryStartSS = NULL;
u8 *dynamicMemoryEndSS = NULL;

void memDynamicRestart() {}

void memDynamicReset() {}

void memDynamicEnd() {}

void memDynamicFreeInternal(u8 *address) {
	dynamicMemoryNode *freeNode;
	u8 *nextAddress;
	u8 *afterAddress;
	dynamicMemoryNode *prevNode;
}

void memDynamicEvict(u8 *address) {
	dynamicMemoryNode *freeNode;
}

void memDynamicFree(u8 *address) {}

void memDynamicNextFreeNodeMinLength(int minLength) {
	dynamicMemoryNode *allocNode;
	u8 *originalAlloc;
	boolean found;
}

void memDynamicNextFreeNode() {}

u8* memDynamicAllocSS(int desiredLength, void *ref, void (*callback)(/* parameters unknown */)) {
	u8 *address;
	u8 *nextAddress;
	dynamicMemoryNode *allocNode;
}

u8* memDynamicAllocResident(int desiredLength) {
	dynamicMemoryNode *allocNode;
	u8 *address;
}

u8* memDynamicAlloc(int length, int type, void *ref, void (*callback)(/* parameters unknown */)) {
	u8 *address;
}
