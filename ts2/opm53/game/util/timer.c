//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "timer.h"
#include "eeregs.h"

int framenum = 0;
int tickframesi = -1;
int tickframenum = 0;
int updateframesi = -1;
float tickframesf = -1.f;
float updateframesf = -1.f;

static int gamepaused = 0;

int perfstats_numframes = 0;
int perfstats_framedrops = 0;

float cpuStartTime[5] = {0.f};

int cpuStartFrame[5] = {0};

float cpuEndTime[5] = {0.f};

void timeMake() {
  // Set Timer1 to use H-BLNK (CLKS) + start the counter (CUE)
  DPUT_T1_MODE(T_MODE_CLKS_M | T_MODE_CUE_M);
  DPUT_T1_COUNT(0);
}

void timeTickRetrace() {
  framenum++;

  // Is this the 128th frame?
  if ((framenum & 127) == 0) {
    // Set Timer1 to use H-BLNK (CLKS) + start the counter (CUE)
    DPUT_T1_MODE(T_MODE_CLKS_M | T_MODE_CUE_M);
    DPUT_T1_COUNT(0);
  }
}

float timeGet() {
  // Set Timer1 to use H-BLNK (CLKS) + start the counter (CUE)
  DPUT_T1_MODE(T_MODE_CLKS_M | T_MODE_CUE_M);
  return DGET_T1_COUNT() / 262.5f;
}

void timeTickStart() {
  int i = 0;

  float *l_cpuEndTime = cpuEndTime;
  int *l_cpuStartFrame = cpuStartFrame;
  float *l_cpuStartTime = cpuStartTime;

  // Confusion...
  do {
    i++;

    *l_cpuStartTime = l_cpuStartTime[1];
    *l_cpuStartFrame = l_cpuStartFrame[1];
    l_cpuStartTime++;
    *l_cpuEndTime = l_cpuEndTime[1];
    l_cpuStartFrame++;
    l_cpuEndTime++;
  } while (i < 4);

  cpuStartTime[4] = timeGet();
  tickframesi = framenum - cpuStartFrame[3];
  cpuStartFrame[4] = framenum;
  tickframesf = (float)tickframesi;

  if (tickframesi > 5) {
    tickframesi = 5;
  }

  if (tickframesi == 0) {
    tickframesi = 1;
  }

  perfstats_numframes++;

  if (tickframesi > 1) {
    perfstats_framedrops++;
  }

  if (tickframesf > 5.0f) {
    tickframesf = 5.0f;
  }

  if (tickframesf < 1.0) {
    tickframesf = 1.0f;
  }

  if (gamepaused == -1) {
    updateframesf = 1.0f;
    tickframesi = 1;
    updateframesi = 1;
    tickframesf = 1.0f;
    gamepaused = 0;
  } else if (gamepaused == 0) {
    updateframesf = (float)tickframesi;
    updateframesi = tickframesi;
  } else {
    updateframesi = 0;
    updateframesf = 0.0f;
  }

  tickframenum += tickframesi;
}

void timePause(int state) {
  if (gamepaused == FALSE) {
    if (state != 0) {
      gamepaused = TRUE;
    }
    if (gamepaused == FALSE) {
      return;
    }
  }
  if (state == 0) {
    gamepaused = -1;
  }
}

int timeGetPause() { return (int)(gamepaused != FALSE); }

void timeTickEnd() { cpuEndTime[4] = timeGet(); }
