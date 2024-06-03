// STATUS: NOT STARTED

#ifndef GAME_TIMER_TIMERS_H
#define GAME_TIMER_TIMERS_H

struct timer_s {
	int type;
	int time;
	int lasttime;
	float duration;
	void *data;
	void (*function)(/* parameters unknown */);
};

typedef timer_s timer;
extern timer timers[75];

void timerRestart();
void timerReset();
int timerNew(int type, float time, void *data, void (*function)(/* parameters unknown */));
void timerTick();
void timerEnd();
void timerRelease(int id);

#endif // GAME_TIMER_TIMERS_H
