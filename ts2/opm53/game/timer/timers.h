//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_TIMER_TIMERS_H
#define GAME_TIMER_TIMERS_H

typedef struct timer_s {
	int type;
	int time;
	int lasttime;
	float duration;
	void *data;
	void (*function)(/* parameters unknown */);
} timer;

extern timer timers[75];

void timerRestart();
void timerReset();
int timerNew(int type, float time, void *data, void (*function)(/* parameters unknown */));
void timerTick();
void timerEnd();
void timerRelease(int id);

#endif // GAME_TIMER_TIMERS_H
