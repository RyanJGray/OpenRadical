//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_UTIL_RND_H
#define GAME_UTIL_RND_H

#include "common.h"

extern u64 newrndseedval;
extern int rndcount;

u32 newrnd();
void newrndseed(u32 seed);

#endif // GAME_UTIL_RND_H
