// STATUS: NOT STARTED

#include "timer.h"

int framenum = 0;
int tickframesi = -1;
int tickframenum = 0;
int updateframesi = -1;
float tickframesf = -1.f;
float updateframesf = -1.f;
static int gamepaused = 0;
int perfstats_numframes = 0;
int perfstats_framedrops = 0;

float cpuStartTime[5] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f,
	/* [3] = */ 0.f,
	/* [4] = */ 0.f
};

int cpuStartFrame[5] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0
};

float cpuEndTime[5] = {
	/* [0] = */ 0.f,
	/* [1] = */ 0.f,
	/* [2] = */ 0.f,
	/* [3] = */ 0.f,
	/* [4] = */ 0.f
};

void timeMake() {}

void timeTickRetrace() {}

float timeGet() {}

void timeTickStart() {
	int i;
}

void timePause(int state) {}

int timeGetPause() {}

void timeTickEnd() {}
