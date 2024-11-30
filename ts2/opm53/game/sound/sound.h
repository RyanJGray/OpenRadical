//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_SOUND_SOUND_H
#define GAME_SOUND_SOUND_H

#include "common.h"

void soundMake();
void soundSelectBuffer(int num);
void soundResetBuffer(int num);
void soundCreateBuffer(int num, u32 start, u32 end);
void soundRestart();
void soundReset();
void soundRestartAfter();
void soundResetAfter();
void soundPreload();
void soundEnd();
void announceTick();
void soundPauseLoopedSounds();
void soundResumeLoopedSounds();
void soundTick();
void soundLoad(int sfxnum);
void soundStop(int voice);
void soundDelayStop(int sounddelaynum);
int soundStart(int sfxnum, float *pos);
int soundStartRange(int sfxnum, float *pos, float range, int minvolume);
int soundDelayStartEx(int sfxnum, float *pos, int delay, int lock);
int soundStartLoop(int sfxnum, float *pos);
int soundStartLoopRange(int sfxnum, float *pos, float range);
void soundSetLoopPos(int voice, float *pos);
void soundAddPreLoad(int sfxnum);

#endif // GAME_SOUND_SOUND_H
