//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "profile.h"

profiledata profdata[20] = {0};

static int profilenumtiming = 0;

void profileMake() {}

void profileRestart() {}

void profileReset() {}

void profileTick() {}

static void profileSimpleTimeBar(int x, int y, float endframes, float filtmax, u32 col) {
	int i;
	float efr;
	float f;
}

void profileGfx() {}

void profileEnd() {}

void profileStartTiming() {}

void profileStopTiming() {}

float profileTimeGet() {}

void profileStart(int num, char *id, u32 col) {}

void profileFinish(int num) {}

void profileTimeStart(int num) {}

void profileTimeEnd(int num) {}

void profileTimeBar(int x, int y, float startframes, float endframes, u32 col) {
	int i;
	float sfr;
	float efr;
	float f;
}

void profileTimeBarDrawTicks(int x, int y) {
	float f;
	int i;
}

void profileTimeBarDrawBar(int x, int y, float startframes, float endframes, u32 col1, u32 col2) {
	float sfr;
	float efr;
}
