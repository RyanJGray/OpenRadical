// STATUS: NOT STARTED

#ifndef GAME_UTIL_TIMER_H
#define GAME_UTIL_TIMER_H

extern int framenum;
extern int tickframesi;
extern int tickframenum;
extern int updateframesi;
extern float tickframesf;
extern float updateframesf;
extern int perfstats_numframes;
extern int perfstats_framedrops;
extern float cpuStartTime[5];
extern int cpuStartFrame[5];
extern float cpuEndTime[5];

void timeMake();
void timeTickRetrace();
float timeGet();
void timeTickStart();
void timePause(int state);
int timeGetPause();
void timeTickEnd();

#endif // GAME_UTIL_TIMER_H
