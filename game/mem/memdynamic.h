// STATUS: NOT STARTED

#ifndef GAME_MEM_MEMDYNAMIC_H
#define GAME_MEM_MEMDYNAMIC_H

extern int dynamicMemoryFreeSS;
extern int dynamicMemorySSBufferSize;
extern u8 *dynamicMemoryBufferSS;
extern u8 *dynamicMemoryAllocSS;
extern u8 *dynamicMemoryStartSS;
extern u8 *dynamicMemoryEndSS;

void memDynamicRestart();
void memDynamicReset();
void memDynamicEnd();
void memDynamicFreeInternal(u8 *address);
void memDynamicEvict(u8 *address);
void memDynamicFree(u8 *address);
void memDynamicNextFreeNodeMinLength(int minLength);
void memDynamicNextFreeNode();
u8* memDynamicAllocSS(int desiredLength, void *ref, void (*callback)(/* parameters unknown */));
u8* memDynamicAllocResident(int desiredLength);
u8* memDynamicAlloc(int length, int type, void *ref, void (*callback)(/* parameters unknown */));

#endif // GAME_MEM_MEMDYNAMIC_H
