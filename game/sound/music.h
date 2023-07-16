// STATUS: NOT STARTED

#ifndef GAME_SOUND_MUSIC_H
#define GAME_SOUND_MUSIC_H

extern int tunenum;
extern char *tunefilenames[34];
extern char streamFilename[64];

void musicPrintState();
int musicDefinitelyStopped();
void musicSetVol(int vol, int rightnow);
void musicSetFrontEndVolume();
void musicMake();
void musicRestart();
void musicReset();
void musicEnd();
void musicTick();
void musicSet(int tuneEnumValue);
void musicPause();
void musicResume();

#endif // GAME_SOUND_MUSIC_H
