// STATUS: NOT STARTED

#ifndef GAME_UTIL_PROFILE_H
#define GAME_UTIL_PROFILE_H

extern profiledata profdata[20];

void profileMake();
void profileRestart();
void profileReset();
void profileTick();
void profileGfx();
void profileEnd();
void profileStartTiming();
void profileStopTiming();
float profileTimeGet();
void profileStart(int num, char *id, u32 col);
void profileFinish(int num);
void profileTimeStart(int num);
void profileTimeEnd(int num);
void profileTimeBar(int x, int y, float startframes, float endframes, u32 col);
void profileTimeBarDrawTicks(int x, int y);
void profileTimeBarDrawBar(int x, int y, float startframes, float endframes, u32 col1, u32 col2);

#endif // GAME_UTIL_PROFILE_H
