//
// The OpenRadical Project
// 2024
//

#ifndef GAME_MEM_MEMDB_H
#define GAME_MEM_MEMDB_H

#include "common.h"

void memdbRestart(int state);
void memdbReset(int state);
void memdbTick();
u8 *memdbAlloc(int length);
void memdbPrintFree();

#endif // GAME_MEM_MEMDB_H
