// STATUS: NOT STARTED

#ifndef GAME_MEM_MEM_H
#define GAME_MEM_MEM_H

extern u8 *mem_eternal_at;
extern u8 *mem_eternal_end;
extern int mem_eternal_free;
extern u8 *mem_level_at;
extern u8 *mem_level_end;
extern int mem_level_free;
extern u8 *mem_local_at;
extern int mem_allow_eter;
extern u8 *memBuffer;
extern int memBufferSize;

void memMake(u8 *buffer, int length);
void memRestart();
void memReset();
void memEnd();
void memTick();
u8* memAlloc(int length, int period);
u8* memAllocAlign64(int length, int period);
void memFree(void *localmem);
void memLocalFree();
int memGetFreeLevel();
int memGetFreeEter();
void memPrintFree();

#endif // GAME_MEM_MEM_H
