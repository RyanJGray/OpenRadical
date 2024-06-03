// STATUS: NOT STARTED

#ifndef GAME_MEM_MEMDB_H
#define GAME_MEM_MEMDB_H


void memdbRestart(int state);
void memdbReset(int state);
void memdbTick();
u8* memdbAlloc(int length);
void memdbPrintFree();

#endif // GAME_MEM_MEMDB_H
