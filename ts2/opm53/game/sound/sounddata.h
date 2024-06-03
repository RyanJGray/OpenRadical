// STATUS: NOT STARTED

#ifndef GAME_SOUND_SOUNDDATA_H
#define GAME_SOUND_SOUNDDATA_H

struct sound_s {
	char *tooldesc;
	char *filename;
	s16 envelope[5];
	u16 pitch;
	u16 volume;
	u16 flags;
	int loadpos;
	int memloadpos;
	int size;
};

typedef sound_s sound;
extern sound sounds[1381];


#endif // GAME_SOUND_SOUNDDATA_H
