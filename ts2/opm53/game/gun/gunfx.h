// STATUS: NOT STARTED

#ifndef GAME_GUN_GUNFX_H
#define GAME_GUN_GUNFX_H

extern char *fireTextureNames[8];
extern char *bwFlameTextureNames[8];

void gunfxPreload();
void gunfxReset();
void gunfxRestart();
void gunfxEnd();
void gunfxTickPlayer();
void gunfxGfxPlayer();
void gunfxTick();
void gunfxGfx();
void gunfxNewFlameProp(int gunfxType, prop *p, float *pos, float *dir, float lifetime);
void gunfxNewFlameBg(int gunfxType, int room, float *pos, float *dir, float timeStart);
void gunfxNewFlameChrThirdPerson(int gunfxType, chrdata *cd, float *pos, float *dir);
void gunfxNewFlameThrowFirstPerson(int gunfxType, chrdata *cd, float *pos, float *dir);
void gunfxNewFlameThrowThirdPerson(int gunfxType, chrdata *cd, float *pos, float *dir);
void gunfxNewFlameCorpse(int gunfxType, prop *corpse, float *pos, float *dir, float sizeScalar);
void gunfxMakeChrfxThirdPersonToCorpse(int chrnum);

#endif // GAME_GUN_GUNFX_H
