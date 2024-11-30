//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_SOUND_SOUNDDATA_H
#define GAME_SOUND_SOUNDDATA_H

#include "common.h"

typedef struct sound_s {
	char *tooldesc;
	char *filename;
	s16 envelope[5];
	u16 pitch;
	u16 volume;
	u16 flags;
	int loadpos;
	int memloadpos;
	int size;
} sound;

extern sound sounds[1381];

#endif // GAME_SOUND_SOUNDDATA_H
