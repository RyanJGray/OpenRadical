//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "timers.h"

static int numtimers = 0;

timer timers[75] = {0};

void timerRestart() {}

void timerReset() {}

int timerNew(int type, float time, void *data, void (*function)(/* parameters unknown */)) {}

void timerTick() {
	int i;
	int deltatime;
}

void timerEnd() {}

void timerRelease(int id) {}
