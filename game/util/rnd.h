// STATUS: NOT STARTED

#ifndef GAME_UTIL_RND_H
#define GAME_UTIL_RND_H

typedef long long unsigned int u64;
extern u64 newrndseedval;
extern int rndcount;

u32 newrnd();
void newrndseed(u32 seed);

#endif // GAME_UTIL_RND_H
